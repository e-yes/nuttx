/****************************************************************************
 * arch/risc-v/src/bl702/bl702_lowputc.c
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

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/serial/serial.h>

#include <arch/board/board.h>

#include "hardware/bl702_hbn.h"
#include "hardware/bl702_uart.h"

#include "bl702_lowputc.h"
#include "bl702_gpio.h"
#include "bl702_hbn.h"
#include "riscv_internal.h"
#include "bl702_config.h"
#include "chip.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define UART_PARITY_NONE (0)
#define UART_PARITY_ODD  (1)   
#define UART_PARITY_EVEN (2)

/* Select UART parameters for the selected console */

#ifdef HAVE_SERIAL_CONSOLE
#if defined(CONFIG_UART0_SERIAL_CONSOLE)
#define BL702_CONSOLE_IDX    0
#define BL702_CONSOLE_BAUD   CONFIG_UART0_BAUD
#define BL702_CONSOLE_BITS   CONFIG_UART0_BITS
#define BL702_CONSOLE_PARITY CONFIG_UART0_PARITY
#define BL702_CONSOLE_2STOP  CONFIG_UART0_2STOP
#ifdef UART0_IFLOWCONTROL
#define BL702_CONSOLE_IFLOWCTL UART0_IFLOWCONTROL
#else
#define BL702_CONSOLE_IFLOWCTL 0
#endif
#ifdef UART0_OFLOWCONTROL
#define BL702_CONSOLE_OFLOWCTL UART0_OFLOWCONTROL
#else
#define BL702_CONSOLE_OFLOWCTL 0
#endif
#endif
#define HAVE_UART
#elif defined(CONFIG_UART1_SERIAL_CONSOLE)
#define BL702_CONSOLE_IDX    1
#define BL702_CONSOLE_BAUD   CONFIG_UART1_BAUD
#define BL702_CONSOLE_BITS   CONFIG_UART1_BITS
#define BL702_CONSOLE_PARITY CONFIG_UART1_PARITY
#define BL702_CONSOLE_2STOP  CONFIG_UART1_2STOP
#ifdef UART1_IFLOWCONTROL
#define BL702_CONSOLE_IFLOWCTL UART1_IFLOWCONTROL
#else
#define BL702_CONSOLE_IFLOWCTL 0
#endif
#ifdef UART1_OFLOWCONTROL
#define BL702_CONSOLE_OFLOWCTL UART1_OFLOWCONTROL
#else
#define BL702_CONSOLE_OFLOWCTL 0
#endif
#define HAVE_UART
#endif /* HAVE_CONSOLE */

#define _BL702_UART_CLOCK (160 * 1000 * 1000UL) /* UART clock */
#define HBN_UART_CLK_160M (1)

/****************************************************************************
 * Private Data
 ****************************************************************************/

#ifdef HAVE_SERIAL_CONSOLE
static const struct uart_config_s g_bl702_console_config =
{
  .idx       = BL702_CONSOLE_IDX,
  .baud      = BL702_CONSOLE_BAUD,
  .parity    = BL702_CONSOLE_PARITY,
  .data_bits = BL702_CONSOLE_BITS,
  .stop_bits = BL702_CONSOLE_2STOP,
#ifdef BL702_CONSOLE_IFLOWCTL
  .iflow_ctl = BL702_CONSOLE_IFLOWCTL,
#else
  .iflow_ctl = 0,
#endif

#ifdef BL702_CONSOLE_OFLOWCTL
  .oflow_ctl = BL702_CONSOLE_OFLOWCTL,
#else
  .oflow_ctl = 0,
#endif
};
#endif /* HAVE_SERIAL_CONSOLE */

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static void bl702_uart_gpio_init(uint8_t id)
{
  if (id == 0)
    {
#ifdef BOARD_UART_0_TX_PIN
      bl702_config_uart_sel(BOARD_UART_0_TX_PIN, UART_SIG_SEL_UART0_TXD);
      bl702_configgpio(BOARD_UART_0_TX_PIN);
#endif
#ifdef BOARD_UART_0_RX_PIN
      bl702_config_uart_sel(BOARD_UART_0_RX_PIN, UART_SIG_SEL_UART0_RXD);
      bl702_configgpio(BOARD_UART_0_RX_PIN);
#endif
#ifdef BOARD_UART_0_CTS_PIN
      bl702_config_uart_sel(BOARD_UART_0_CTS_PIN, UART_SIG_SEL_UART0_CTS);
      bl702_configgpio(BOARD_UART_0_CTS_PIN);
#endif
#ifdef BOARD_UART_0_RTS_PIN
      bl702_config_uart_sel(BOARD_UART_0_RTS_PIN, UART_SIG_SEL_UART0_RTS);
      bl702_configgpio(BOARD_UART_0_RTS_PIN);
#endif
    }
  else
    {
#ifdef BOARD_UART_1_TX_PIN
      bl702_config_uart_sel(BOARD_UART_1_TX_PIN, UART_SIG_SEL_UART1_TXD);
      bl702_configgpio(BOARD_UART_1_TX_PIN);
#endif
#ifdef BOARD_UART_1_RX_PIN
      bl702_config_uart_sel(BOARD_UART_1_RX_PIN, UART_SIG_SEL_UART1_RXD);
      bl702_configgpio(BOARD_UART_1_RX_PIN);
#endif
#ifdef BOARD_UART_1_CTS_PIN
      bl702_config_uart_sel(BOARD_UART_1_CTS_PIN, UART_SIG_SEL_UART1_CTS);
      bl702_configgpio(BOARD_UART_1_CTS_PIN);
#endif
#ifdef BOARD_UART_1_RTS_PIN
      bl702_config_uart_sel(BOARD_UART_1_RTS_PIN, UART_SIG_SEL_UART1_RTS);
      bl702_configgpio(BOARD_UART_1_RTS_PIN);
#endif
    }
}

static void bl702_enable_uart_clk(uint8_t enable, int clk_sel, uint8_t div)
{
  /* disable UART clock first */

  modifyreg32(BL702_CLK_CFG2, CLK_CFG2_UART_CLK_EN, 0);

  /* Set div */

  modifyreg32(BL702_CLK_CFG2, CLK_CFG2_UART_CLK_DIV_MASK, div);

  /* Select clock source for uart */

  bl702_set_uart_clk_sel(clk_sel);

  /* Set enable or disable */

  if (enable)
    {
      modifyreg32(BL702_CLK_CFG2, 0, CLK_CFG2_UART_CLK_EN);
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

void bl702_uart_configure(const struct uart_config_s *config)
{
  uint32_t div;
  uint32_t fraction;
  uint32_t tx_cfg;
  uint32_t rx_cfg;
  uint8_t clk_div = 3;

  bl702_enable_uart_clk(1, HBN_UART_CLK_160M, clk_div);

  bl702_uart_gpio_init(config->idx);

  /* Disable all interrupt */

  modifyreg32(BL702_UART_INT_MASK(config->idx), 0, 0xff);

  /* Disable uart before config */

  modifyreg32(BL702_UART_UTX_CONFIG(config->idx), UART_UTX_CONFIG_CR_EN, 0);
  modifyreg32(BL702_UART_URX_CONFIG(config->idx), UART_URX_CONFIG_CR_EN, 0);

  /* cal the baud rate divisor */

  fraction = (_BL702_UART_CLOCK / (clk_div + 1)) * 10 / config->baud % 10;
  div      = (_BL702_UART_CLOCK / (clk_div + 1)) / config->baud;
  if (fraction >= 5)
    {
      ++div;
    }

  /* set the baud rate register value */

  putreg32(((div - 1) << 0x10) | ((div - 1) & 0xffff),
           BL702_UART_BIT_PRD(config->idx));

  /* configure parity type */

  tx_cfg = getreg32(BL702_UART_UTX_CONFIG(config->idx));
  rx_cfg = getreg32(BL702_UART_URX_CONFIG(config->idx));

  switch (config->parity)
    {
    case UART_PARITY_NONE:
      tx_cfg &= ~UART_UTX_CONFIG_CR_PRT_EN;
      rx_cfg &= ~UART_URX_CONFIG_CR_PRT_EN;
      break;
    case UART_PARITY_ODD:
      tx_cfg |= UART_UTX_CONFIG_CR_PRT_EN;
      tx_cfg |= UART_UTX_CONFIG_CR_PRT_SEL;
      rx_cfg |= UART_URX_CONFIG_CR_PRT_EN;
      rx_cfg |= UART_URX_CONFIG_CR_PRT_SEL;
      break;
    case UART_PARITY_EVEN:
      tx_cfg |= UART_UTX_CONFIG_CR_PRT_EN;
      tx_cfg &= ~UART_UTX_CONFIG_CR_PRT_SEL;
      rx_cfg |= UART_URX_CONFIG_CR_PRT_EN;
      rx_cfg &= ~UART_URX_CONFIG_CR_PRT_SEL;
      break;
    default:
      break;
    }

  /* Configure data and stop bits */

  rx_cfg &= ~UART_URX_CONFIG_CR_BIT_CNT_D_MASK;
  rx_cfg |= ((uint32_t)config->data_bits - 1) << \
            UART_URX_CONFIG_CR_BIT_CNT_D_SHIFT;

  tx_cfg &= ~(UART_UTX_CONFIG_CR_BIT_CNT_D_MASK | \
              UART_UTX_CONFIG_CR_BIT_CNT_P_MASK);
  tx_cfg |= (((uint32_t)config->data_bits - 1) << \
             UART_UTX_CONFIG_CR_BIT_CNT_D_SHIFT) | \
            (((uint32_t)config->stop_bits + 1) << \
             UART_UTX_CONFIG_CR_BIT_CNT_P_SHIFT);

  /* Configure tx cts flow control function */

  if (config->oflow_ctl)
    {
      tx_cfg |= UART_UTX_CONFIG_CR_CTS_EN;
    }
  else
    {
      tx_cfg &= ~(UART_UTX_CONFIG_CR_CTS_EN);
    }

  /* Disable rx input de-glitch function */

  rx_cfg &= ~(UART_URX_CONFIG_CR_DEG_EN);

  /* Configure rx rts flow control function */

  /* TODO: What about UART_URX_CONFIG_CR_RTS_SW_VAL? */

  if (config->iflow_ctl)
    {
      rx_cfg |= UART_URX_CONFIG_CR_RTS_SW_MODE;
    }
  else
    {
      rx_cfg &= ~(UART_URX_CONFIG_CR_RTS_SW_MODE);
    }

  /* Write back */

  putreg32(rx_cfg, BL702_UART_URX_CONFIG(config->idx));
  putreg32(tx_cfg, BL702_UART_UTX_CONFIG(config->idx));

  /* Configure LSB-first */

  modifyreg32(BL702_UART_DATA_CONFIG(config->idx),
              UART_DATA_CONFIG_CR_UART_BIT_INV, 0);

  /* Enable tx free run mode */

  modifyreg32(BL702_UART_UTX_CONFIG(config->idx), 0,
              UART_UTX_CONFIG_CR_FRM_EN);

  /* Configure FIFO thresholds */

  modifyreg32(BL702_UART_FIFO_CONFIG_1(config->idx),
              (UART_FIFO_CONFIG_1_RX_TH_MASK | \
               UART_FIFO_CONFIG_1_TX_TH_MASK),
              ((0x10 - 1) << UART_FIFO_CONFIG_1_RX_TH_SHIFT) | \
              ((0x10 - 1) << UART_FIFO_CONFIG_1_TX_TH_SHIFT));

  /* Enable UART tx rx unit */

  modifyreg32(BL702_UART_UTX_CONFIG(config->idx), 0,
              UART_UTX_CONFIG_CR_EN);
  modifyreg32(BL702_UART_URX_CONFIG(config->idx), 0,
              UART_URX_CONFIG_CR_EN);
}

/****************************************************************************
 * Name: riscv_lowputc
 *
 * Description:
 *   Output one byte on the serial console
 *
 ****************************************************************************/

void riscv_lowputc(char ch)
{
#ifdef HAVE_SERIAL_CONSOLE
  /* Wait for FIFO */

  while ((getreg32(BL702_UART_FIFO_CONFIG_1(BL702_CONSOLE_IDX)) & \
         UART_FIFO_CONFIG_1_TX_CNT_MASK) == 0);

  putreg32(ch, BL702_UART_FIFO_WDATA(BL702_CONSOLE_IDX));
#endif /* HAVE_CONSOLE */
}

void bl702_lowsetup(void)
{
#ifdef HAVE_SERIAL_CONSOLE
  /* Configure the console UART (if any) */

  bl702_uart_configure(&g_bl702_console_config);

#endif /* HAVE_SERIAL_CONSOLE */
}
