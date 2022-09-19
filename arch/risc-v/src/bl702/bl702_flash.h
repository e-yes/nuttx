/****************************************************************************
 * arch/risc-v/src/bl702/bl702_flash.h
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

#ifndef __ARCH_RISCV_SRC_BL702_BL702_FLASH_H
#define __ARCH_RISCV_SRC_BL702_BL702_FLASH_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: bl702_flash_erase
 ****************************************************************************/

int bl702_flash_erase(uint32_t addr, int len);

/****************************************************************************
 * Name: bl702_flash_write
 ****************************************************************************/

int bl702_flash_write(uint32_t addr, const uint8_t *src, int len);

/****************************************************************************
 * Name: bl702_flash_read
 ****************************************************************************/

int bl702_flash_read(uint32_t addr, uint8_t *dst, int len);

/****************************************************************************
 * Name: bl702_flash_getjedecid
 ****************************************************************************/

int bl702_flash_getjedecid(uint8_t *data);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_RISCV_SRC_BL702_BL702_FLASH_H */
