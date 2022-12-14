/****************************************************************************
 * arch/risc-v/src/bl702/bl702_romapi.h
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

#ifndef __ARCH_RISCV_SRC_BL702_BL702_ROMAPI_H
#define __ARCH_RISCV_SRC_BL702_BL702_ROMAPI_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

#define BL702_ROMAPI_BASE      (0x21010800)
#define BL702_ROMAPI_FUNC(idx) (*(uintptr_t *)(BL702_ROMAPI_BASE + (idx)*4))

#define BL702_ROMAPI_ASM_DELAY_US              BL702_ROMAPI_FUNC(20)
#define BL702_ROMAPI_EFUSE_CTRL_LOAD_R0        BL702_ROMAPI_FUNC(31)
#define BL702_ROMAPI_RST_SYSTEM                BL702_ROMAPI_FUNC(47)
#define BL702_ROMAPI_RST_CPU_SW                BL702_ROMAPI_FUNC(48)
#define BL702_ROMAPI_RST_POR                   BL702_ROMAPI_FUNC(49)
#define BL702_ROMAPI_SFLASH_EREASE_NEEDLOCK    BL702_ROMAPI_FUNC(163)
#define BL702_ROMAPI_SFLASH_WRITE_NEEDLOCK     BL702_ROMAPI_FUNC(164)
#define BL702_ROMAPI_SFLASH_READ_NEEDLOCK      BL702_ROMAPI_FUNC(165)
#define BL702_ROMAPI_SFLASH_GET_JEDECID_NOLOCK BL702_ROMAPI_FUNC(166)
#define BL702_ROMAPI_SFLASH_READ_WITHLOCK      BL702_ROMAPI_FUNC(170)
#define BL702_ROMAPI_SFLASH_WRITE_WITHLOCK     BL702_ROMAPI_FUNC(171)
#define BL702_ROMAPI_SFLASH_EREASE_WITHLOCK    BL702_ROMAPI_FUNC(172)

#endif /* __ARCH_RISCV_SRC_BL702_BL702_ROMAPI_H */
