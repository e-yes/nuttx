/****************************************************************************
 * arch/arm/src/s32k3xx/s32k3xx_periphclocks.h
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

/* Copyright 2022 NXP */

#ifndef __ARCH_ARM_SRC_S32K3XX_S32K3XX_PERIPHCLOCKS_H
#define __ARCH_ARM_SRC_S32K3XX_S32K3XX_PERIPHCLOCKS_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/arch.h>

#include "arm_internal.h"

#include "s32k3xx_config.h"

#include "s32k3xx_clocknames.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Values for peripheral_clock_source_t.  An enumeration is not appropriate
 * because some of the values are duplicates.
 */

#define CLK_SRC_OFF                    0  /* Clock is off */
#define CLK_SRC_SOSC                   1  /* OSCCLK - System Oscillator Bus Clock */
#define CLK_SRC_SIRC                   2  /* SCGIRCLK - Slow IRC Clock */
#define CLK_SRC_FIRC                   3  /* SCGFIRCLK - Fast IRC Clock */
#define CLK_SRC_SPLL                   6  /* SCGPCLK System PLL clock */

#define CLK_SRC_SOSC_DIV1              1  /* OSCCLK - System Oscillator Bus Clock */
#define CLK_SRC_SIRC_DIV1              2  /* SCGIRCLK - Slow IRC Clock */
#define CLK_SRC_FIRC_DIV1              3  /* SCGFIRCLK - Fast IRC Clock */
#define CLK_SRC_SPLL_DIV1              6  /* SCGPCLK System PLL clock */

#define CLK_SRC_SOSC_DIV2              1  /* OSCCLK - System Oscillator Bus Clock */
#define CLK_SRC_SIRC_DIV2              2  /* SCGIRCLK - Slow IRC Clock */
#define CLK_SRC_FIRC_DIV2              3  /* SCGFIRCLK - Fast IRC Clock */
#define CLK_SRC_SPLL_DIV2              6  /* SCGPCLK System PLL clock */

/* PCC index offsets (all S32K1xx families).  These are used in in the
 * family-specific mapping table g_clkname_mapping[] that is used to map a
 * clock name to a PCC control register index.
 */

#define PCC_INVALID_INDEX              0

#define PCC_FTFC_INDEX                 32
#define PCC_DMAMUX_INDEX               33
#define PCC_FLEXCAN0_INDEX             36
#define PCC_FLEXCAN1_INDEX             37
#define PCC_FTM3_INDEX                 38
#define PCC_ADC1_INDEX                 39
#define PCC_FLEXCAN2_INDEX             43
#define PCC_LPSPI0_INDEX               44
#define PCC_LPSPI1_INDEX               45
#define PCC_LPSPI2_INDEX               46
#define PCC_PDB1_INDEX                 49
#define PCC_CRC_INDEX                  50
#define PCC_PDB0_INDEX                 54
#define PCC_LPIT_INDEX                 55
#define PCC_FTM0_INDEX                 56
#define PCC_FTM1_INDEX                 57
#define PCC_FTM2_INDEX                 58
#define PCC_ADC0_INDEX                 59
#define PCC_RTC_INDEX                  61
#define PCC_CMU0_INDEX                 62
#define PCC_CMU1_INDEX                 63
#define PCC_LPTMR0_INDEX               64
#define PCC_PORTA_INDEX                73
#define PCC_PORTB_INDEX                74
#define PCC_PORTC_INDEX                75
#define PCC_PORTD_INDEX                76
#define PCC_PORTE_INDEX                77
#define PCC_SAI0_INDEX                 84
#define PCC_SAI1_INDEX                 85
#define PCC_FLEXIO_INDEX               90
#define PCC_EWM_INDEX                  97
#define PCC_LPI2C0_INDEX               102
#define PCC_LPI2C1_INDEX               103
#define PCC_LPUART0_INDEX              106
#define PCC_LPUART1_INDEX              107
#define PCC_LPUART2_INDEX              108
#define PCC_FTM4_INDEX                 110
#define PCC_FTM5_INDEX                 111
#define PCC_FTM6_INDEX                 112
#define PCC_FTM7_INDEX                 113
#define PCC_CMP0_INDEX                 115
#define PCC_QSPI_INDEX                 118
#define PCC_ENET_INDEX                 121

/* Peripheral instance features. */

#define NO_PERIPHERAL_FEATURE          (0)      /* No peripheral feature */
#define HAS_CLOCK_GATING_IN_SIM        (1 << 0) /* Clock gating implemented in SIM */
#define HAS_MULTIPLIER                 (1 << 1) /* Multiplier implemented in PCC */
#define HAS_DIVIDER                    (1 << 2) /* Divider implemented in PCC */
#define HAS_PROTOCOL_CLOCK_FROM_ASYNC1 (1 << 3) /* Clock source provided by first asynch clock */
#define HAS_PROTOCOL_CLOCK_FROM_ASYNC2 (1 << 4) /* Clock source iprovided by second asynch clock */
#define HAS_INT_CLOCK_FROM_BUS_CLOCK   (1 << 5) /* Clock is provided by the bus clock */
#define HAS_INT_CLOCK_FROM_SYS_CLOCK   (1 << 6) /* Clock is provided by the sys clock */
#define HAS_INT_CLOCK_FROM_SLOW_CLOCK  (1 << 7) /* Clock is provided by the slow clock */

/****************************************************************************
 * Public Types
 ****************************************************************************/

typedef uint8_t peripheral_clock_source_t;  /* See CLK_SRC_* definitions */

enum peripheral_clock_frac_e
{
  MULTIPLY_BY_ONE          = 0,        /* Fractional value is zero */
  MULTIPLY_BY_TWO          = 1         /* Fractional value is one */
};

struct peripheral_clock_config_s
{
  /* clkname is the name of the peripheral clock.  It must be one of the
   * values defined in the chip specific xxxxxx_configname.h header file.
   */

  enum clock_names_e clkname;          /* Peripheral clock name */
  bool clkgate;                        /* Peripheral clock gate */
  peripheral_clock_source_t clksrc;    /* Peripheral clock source */
  enum peripheral_clock_frac_e frac;   /* Peripheral clock fractional value */
  uint8_t divider;                     /* Peripheral clock divider, range 1..8 */
};

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Data
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/* Clock name mappings.
 *
 * Each S32K1xx architecture must provide this array.  This is a constant
 * array storing the mappings between clock names and peripheral clock
 * control indexes.  If there is no peripheral clock control index for a
 * clock name, then the corresponding value is PCC_INVALID_INDEX.
 */

EXTERN const uint16_t g_clkname_mapping[];

/* Peripheral Features.
 *
 * Each S32K1xx architecture must provide this array.  This is an array of
 * bit-encoded peripheral clocking features.  See the peripheral instance
 * feature definitions above
 */

EXTERN const uint8_t g_periph_features[];

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: s32k3xx_periphclocks
 *
 * Description:
 *   This function configures peripheral clocks in the PCC block.
 *
 * Input Parameters:
 *   count - Number of peripheral clocks to be configured
 *   pclks - Pointer to an array of peripheral clock configurations
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void s32k3xx_periphclocks(unsigned int count,
                          const struct peripheral_clock_config_s *pclks);

/****************************************************************************
 * Name: s32k3xx_get_pclkfreq
 *
 * Description:
 *   This function returns the clock frequency of the specified peripheral
 *   functional clock.
 *
 * Input Parameters:
 *   clkname   - Identifies the peripheral clock of interest
 *   frequency - The location where the peripheral clock frequency will be
 *              returned
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.  -ENODEV is returned if the clock is not enabled or is not
 *   being clocked.
 *
 ****************************************************************************/

int s32k3xx_get_pclkfreq(enum clock_names_e clkname, uint32_t *frequency);

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_S32K3XX_S32K3XX_PERIPHCLOCKS_H */
