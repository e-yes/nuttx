/****************************************************************************
 * arch/risc-v/src/bl702/hardware/bl702_tzc.h
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

#ifndef __ARCH_RISCV_SRC_BL702_HARDWARE_BL702_TZC_H
#define __ARCH_RISCV_SRC_BL702_HARDWARE_BL702_TZC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "bl702_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register offsets *********************************************************/

#define BL702_SEC_ROM_CTRL_OFFSET  0x000040  /* tzc_rom_ctrl */
#define BL702_SEC_ROM0_R0_OFFSET   0x000044  /* tzc_rom0_r0 */
#define BL702_SEC_ROM0_R1_OFFSET   0x000048  /* tzc_rom0_r1 */
#define BL702_SEC_ROM1_R0_OFFSET   0x00004c  /* tzc_rom1_r0 */
#define BL702_SEC_ROM1_R1_OFFSET   0x000050  /* tzc_rom1_r1 */

#define BL702_NSEC_ROM_CTRL_OFFSET  0x000040  /* tzc_rom_ctrl */
#define BL702_NSEC_ROM0_R0_OFFSET   0x000044  /* tzc_rom0_r0 */
#define BL702_NSEC_ROM0_R1_OFFSET   0x000048  /* tzc_rom0_r1 */
#define BL702_NSEC_ROM1_R0_OFFSET   0x00004c  /* tzc_rom1_r0 */
#define BL702_NSEC_ROM1_R1_OFFSET   0x000050  /* tzc_rom1_r1 */

/* Register definitions *****************************************************/

#define BL702_SEC_ROM_CTRL  (BL702_SEC_BASE + BL702_SEC_ROM_CTRL_OFFSET)
#define BL702_SEC_ROM0_R0   (BL702_SEC_BASE + BL702_SEC_ROM0_R0_OFFSET)
#define BL702_SEC_ROM0_R1   (BL702_SEC_BASE + BL702_SEC_ROM0_R1_OFFSET)
#define BL702_SEC_ROM1_R0   (BL702_SEC_BASE + BL702_SEC_ROM1_R0_OFFSET)
#define BL702_SEC_ROM1_R1   (BL702_SEC_BASE + BL702_SEC_ROM1_R1_OFFSET)

#define BL702_NSEC_ROM_CTRL  (BL702_NSEC_BASE + BL702_NSEC_ROM_CTRL_OFFSET)
#define BL702_NSEC_ROM0_R0   (BL702_NSEC_BASE + BL702_NSEC_ROM0_R0_OFFSET)
#define BL702_NSEC_ROM0_R1   (BL702_NSEC_BASE + BL702_NSEC_ROM0_R1_OFFSET)
#define BL702_NSEC_ROM1_R0   (BL702_NSEC_BASE + BL702_NSEC_ROM1_R0_OFFSET)
#define BL702_NSEC_ROM1_R1   (BL702_NSEC_BASE + BL702_NSEC_ROM1_R1_OFFSET)

/* Register bit definitions *************************************************/

#define TZC_SEC_ROM_CTRL_SBOOT_DONE_SHIFT    (28)
#define TZC_SEC_ROM_CTRL_SBOOT_DONE_MASK     (0x0f << TZC_SEC_ROM_CTRL_SBOOT_DONE_SHIFT)
#define TZC_SEC_ROM_CTRL_ROM1_R1_LOCK        (1 << 27)
#define TZC_SEC_ROM_CTRL_ROM1_R0_LOCK        (1 << 26)
#define TZC_SEC_ROM_CTRL_ROM0_R1_LOCK        (1 << 25)
#define TZC_SEC_ROM_CTRL_ROM0_R0_LOCK        (1 << 24)
#define TZC_SEC_ROM_CTRL_ROM1_R1_EN          (1 << 19)
#define TZC_SEC_ROM_CTRL_ROM1_R0_EN          (1 << 18)
#define TZC_SEC_ROM_CTRL_ROM0_R1_EN          (1 << 17)
#define TZC_SEC_ROM_CTRL_ROM0_R0_EN          (1 << 16)
#define TZC_SEC_ROM_CTRL_ROM1_R1_ID1_EN      (1 << 11)
#define TZC_SEC_ROM_CTRL_ROM1_R0_ID1_EN      (1 << 10)
#define TZC_SEC_ROM_CTRL_ROM0_R1_ID1_EN      (1 << 9)
#define TZC_SEC_ROM_CTRL_ROM0_R0_ID1_EN      (1 << 8)
#define TZC_SEC_ROM_CTRL_ROM1_R1_ID0_EN      (1 << 3)
#define TZC_SEC_ROM_CTRL_ROM1_R0_ID0_EN      (1 << 2)
#define TZC_SEC_ROM_CTRL_ROM0_R1_ID0_EN      (1 << 1)
#define TZC_SEC_ROM_CTRL_ROM0_R0_ID0_EN      (1 << 0)

#define TZC_SEC_ROM0_R0_START_SHIFT  (16)
#define TZC_SEC_ROM0_R0_START_MASK   (0xffff << TZC_SEC_ROM0_R0_START_SHIFT)
#define TZC_SEC_ROM0_R0_END_MASK     (0xffff)

#define TZC_SEC_ROM0_R01_START_SHIFT  (16)
#define TZC_SEC_ROM0_R01_START_MASK   (0xffff << TZC_SEC_ROM0_R01_START_SHIFT)
#define TZC_SEC_ROM0_R01_END_MASK     (0xffff)

#define TZC_SEC_ROM1_R0_START_SHIFT  (16)
#define TZC_SEC_ROM1_R0_START_MASK   (0xffff << TZC_SEC_ROM1_R0_START_SHIFT)
#define TZC_SEC_ROM1_R0_END_MASK     (0xffff)

#define TZC_SEC_ROM1_R1_START_SHIFT  (16)
#define TZC_SEC_ROM1_R1_START_MASK   (0xffff << TZC_SEC_ROM1_R1_START_SHIFT)
#define TZC_SEC_ROM1_R1_END_MASK     (0xffff)

#define TZC_NSEC_ROM_CTRL_SBOOT_DONE_SHIFT    (28)
#define TZC_NSEC_ROM_CTRL_SBOOT_DONE_MASK     (0x0f << TZC_NSEC_ROM_CTRL_SBOOT_DONE_SHIFT)
#define TZC_NSEC_ROM_CTRL_ROM1_R1_LOCK        (1 << 27)
#define TZC_NSEC_ROM_CTRL_ROM1_R0_LOCK        (1 << 26)
#define TZC_NSEC_ROM_CTRL_ROM0_R1_LOCK        (1 << 25)
#define TZC_NSEC_ROM_CTRL_ROM0_R0_LOCK        (1 << 24)
#define TZC_NSEC_ROM_CTRL_ROM1_R1_EN          (1 << 19)
#define TZC_NSEC_ROM_CTRL_ROM1_R0_EN          (1 << 18)
#define TZC_NSEC_ROM_CTRL_ROM0_R1_EN          (1 << 17)
#define TZC_NSEC_ROM_CTRL_ROM0_R0_EN          (1 << 16)
#define TZC_NSEC_ROM_CTRL_ROM1_R1_ID1_EN      (1 << 11)
#define TZC_NSEC_ROM_CTRL_ROM1_R0_ID1_EN      (1 << 10)
#define TZC_NSEC_ROM_CTRL_ROM0_R1_ID1_EN      (1 << 9)
#define TZC_NSEC_ROM_CTRL_ROM0_R0_ID1_EN      (1 << 8)
#define TZC_NSEC_ROM_CTRL_ROM1_R1_ID0_EN      (1 << 3)
#define TZC_NSEC_ROM_CTRL_ROM1_R0_ID0_EN      (1 << 2)
#define TZC_NSEC_ROM_CTRL_ROM0_R1_ID0_EN      (1 << 1)
#define TZC_NSEC_ROM_CTRL_ROM0_R0_ID0_EN      (1 << 0)

#define TZC_NSEC_ROM0_R0_START_SHIFT  (16)
#define TZC_NSEC_ROM0_R0_START_MASK   (0xffff << TZC_NSEC_ROM0_R0_START_SHIFT)
#define TZC_NSEC_ROM0_R0_END_MASK     (0xffff)

#define TZC_NSEC_ROM0_R01_START_SHIFT  (16)
#define TZC_NSEC_ROM0_R01_START_MASK   (0xffff << TZC_NSEC_ROM0_R01_START_SHIFT)
#define TZC_NSEC_ROM0_R01_END_MASK     (0xffff)

#define TZC_NSEC_ROM1_R0_START_SHIFT  (16)
#define TZC_NSEC_ROM1_R0_START_MASK   (0xffff << TZC_NSEC_ROM1_R0_START_SHIFT)
#define TZC_NSEC_ROM1_R0_END_MASK     (0xffff)

#define TZC_NSEC_ROM1_R1_START_SHIFT  (16)
#define TZC_NSEC_ROM1_R1_START_MASK   (0xffff << TZC_NSEC_ROM1_R1_START_SHIFT)
#define TZC_NSEC_ROM1_R1_END_MASK     (0xffff)

#endif /* __ARCH_RISCV_SRC_BL702_HARDWARE_BL702_TZC_H */
