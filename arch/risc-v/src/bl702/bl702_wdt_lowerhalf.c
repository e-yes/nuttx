/****************************************************************************
 * arch/risc-v/src/bl702/bl702_wdt_lowerhalf.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/arch.h>

#include <inttypes.h>
#include <stdint.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/clock.h>
#include <nuttx/timers/watchdog.h>
#include <arch/board/board.h>

#include "hardware/bl702_timer.h"
#include "bl702_tim.h"
#include "bl702_wdt_lowerhalf.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define WDT_MAXTIMEOUT (65535)

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure provides the private representation of the "lower-half"
 * driver state structure.  This structure must be cast-compatible with the
 * well-known watchdog_lowerhalf_s structure.
 */

struct bl702_wdt_lowerhalf_s
{
  const struct watchdog_ops_s  *ops; /* Lower half operations */
  uint32_t lastreset;                /* The last reset time */
  uint32_t timeout;
  uint8_t started;
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* "Lower half" driver methods **********************************************/

static int bl702_start(struct watchdog_lowerhalf_s *lower);
static int bl702_stop(struct watchdog_lowerhalf_s *lower);
static int bl702_keepalive(struct watchdog_lowerhalf_s *lower);
static int bl702_getstatus(struct watchdog_lowerhalf_s *lower,
                           struct watchdog_status_s *status);
static int bl702_settimeout(struct watchdog_lowerhalf_s *lower,
                            uint32_t timeout);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* "Lower half" driver methods */

static const struct watchdog_ops_s g_wdtops =
{
  .start      = bl702_start,
  .stop       = bl702_stop,
  .keepalive  = bl702_keepalive,
  .getstatus  = bl702_getstatus,
  .settimeout = bl702_settimeout,
  .capture    = NULL,
  .ioctl      = NULL,
};

/* "Lower half" driver state */

static struct bl702_wdt_lowerhalf_s g_wdtdev =
{
  .ops = &g_wdtops,
  .lastreset = 0,
  .started  = false,
  .timeout  = 10000,
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bl702_start
 *
 * Description:
 *   Start the watchdog timer, resetting the time to the current timeout,
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of the
 *           "lower-half" driver state structure.
 *
 * Returned Values:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

static int bl702_start(struct watchdog_lowerhalf_s *lower)
{
  struct bl702_wdt_lowerhalf_s *priv =
    (struct bl702_wdt_lowerhalf_s *)lower;
  irqstate_t flags;

  DEBUGASSERT(priv);

  /* Have we already been started? */

  if (!priv->started)
    {
      flags = enter_critical_section();
      bl702_wdt_disable();
      bl702_wdt_set_clock(TIMER_CLKSRC_32K, 31);
      bl702_wdt_setcompvalue(priv->timeout);
      bl702_wdt_resetcountervalue();
      bl702_wdt_intmask(WDT_INT, 1);
      bl702_wdt_enable();
      priv->lastreset = clock_systime_ticks();
      priv->started = true;
      leave_critical_section(flags);
    }

  return OK;
}

/****************************************************************************
 * Name: bl702_stop
 *
 * Description:
 *   Stop the watchdog timer
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of the
 *           "lower-half" driver state structure.
 *
 * Returned Values:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

static int bl702_stop(struct watchdog_lowerhalf_s *lower)
{
  struct bl702_wdt_lowerhalf_s *priv =
      (struct bl702_wdt_lowerhalf_s *)lower;

  bl702_wdt_disable();
  priv->started = false;
  return OK;
}

/****************************************************************************
 * Name: bl702_keepalive
 *
 * Description:
 *   Reset the watchdog timer to the current timeout value, prevent any
 *   imminent watchdog timeouts.  This is sometimes referred as "pinging"
 *   the watchdog timer or "petting the dog".
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of the
 *           "lower-half" driver state structure.
 *
 * Returned Values:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

static int bl702_keepalive(struct watchdog_lowerhalf_s *lower)
{
  struct bl702_wdt_lowerhalf_s *priv =
    (struct bl702_wdt_lowerhalf_s *)lower;
  irqstate_t flags;

  /* Reload the WDT timer */

  flags = enter_critical_section();

  priv->lastreset = clock_systime_ticks();
  bl702_wdt_resetcountervalue();

  leave_critical_section(flags);

  return OK;
}

/****************************************************************************
 * Name: bl702_getstatus
 *
 * Description:
 *   Get the current watchdog timer status
 *
 * Input Parameters:
 *   lower  - A pointer the publicly visible representation of
 *            the "lower-half" driver state structure.
 *   status - The location to return the watchdog status information.
 *
 * Returned Values:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

static int bl702_getstatus(struct watchdog_lowerhalf_s *lower,
                           struct watchdog_status_s *status)
{
  struct bl702_wdt_lowerhalf_s *priv =
    (struct bl702_wdt_lowerhalf_s *)lower;
  uint32_t ticks;
  uint32_t elapsed;

  DEBUGASSERT(priv);

  /* Return the status bit */

  status->flags = WDFLAGS_RESET;
  if (priv->started)
    {
      status->flags |= WDFLAGS_ACTIVE;
    }

  /* Return the actual timeout in milliseconds */

  status->timeout = priv->timeout;

  /* Get the elapsed time since the last ping */

  ticks   = clock_systime_ticks() - priv->lastreset;
  elapsed = (int32_t)TICK2MSEC(ticks);

  if (elapsed > status->timeout)
    {
      elapsed = status->timeout;
    }

  /* Return the approximate time until the watchdog timer expiration */

  status->timeleft = status->timeout - elapsed;

  return OK;
}

/****************************************************************************
 * Name: bl702_settimeout
 *
 * Description:
 *   Set a new timeout value (and reset the watchdog timer)
 *
 * Input Parameters:
 *   lower   - A pointer the publicly visible representation of
 *             the "lower-half" driver state structure.
 *   timeout - The new timeout value in milliseconds.
 *
 * Returned Values:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

static int bl702_settimeout(struct watchdog_lowerhalf_s *lower,
                           uint32_t timeout)
{
  struct bl702_wdt_lowerhalf_s *priv =
    (struct bl702_wdt_lowerhalf_s *)lower;

  DEBUGASSERT(priv);

  /* Can this timeout be represented? */

  if (timeout < 1 || timeout > WDT_MAXTIMEOUT)
    {
      wderr("ERROR: Cannot represent timeout=%" PRId32 " > %d\n",
            timeout, WDT_MAXTIMEOUT);
      return -ERANGE;
    }

  if (priv->started)
    {
      wdwarn("WARNING: Watchdog is already started\n");
      return -EBUSY;
    }

  priv->timeout = timeout;

  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bl702_wdt_initialize
 *
 * Description:
 *   Initialize the WDT watchdog time.  The watchdog timer is initialized and
 *   registers as 'devpath.  The initial state of the watchdog time is
 *   disabled.
 *
 * Input Parameters:
 *   devpath    - The full path to the watchdog.  This should be of the form
 *                /dev/watchdog0
 * Returned Values:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

int bl702_wdt_initialize(const char *devpath)
{
  struct bl702_wdt_lowerhalf_s *priv = &g_wdtdev;
  void *handle;

  /* Register the watchdog driver as /dev/watchdog0 */

  handle = watchdog_register(devpath,
                             (struct watchdog_lowerhalf_s *)priv);
  return (handle != NULL) ? OK : -ENODEV;
}
