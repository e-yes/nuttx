/****************************************************************************
 * arch/arm/src/s32k3xx/hardware/s32k3xx_virtwrapper.h
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

#ifndef __ARCH_ARM_SRC_S32K3XX_HARDWARE_S32K3XX_VIRTWRAPPER_H
#define __ARCH_ARM_SRC_S32K3XX_HARDWARE_S32K3XX_VIRTWRAPPER_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <hardware/s32k3xx_memorymap.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* VIRTWRAPPER Register Offsets *********************************************/

#define S32K3XX_VIRTWRAPPER_REG_A15_0_OFFSET      (0x0000) /* Parameter_n Register (REG_A15_0) */
#define S32K3XX_VIRTWRAPPER_REG_A31_16_OFFSET     (0x0004) /* Parameter_n Register (REG_A31_16) */
#define S32K3XX_VIRTWRAPPER_REG_A47_32_OFFSET     (0x0008) /* Parameter_n Register (REG_A47_32) */
#define S32K3XX_VIRTWRAPPER_REG_A63_48_OFFSET     (0x000c) /* Parameter_n Register (REG_A63_48) */
#define S32K3XX_VIRTWRAPPER_REG_A79_64_OFFSET     (0x0010) /* Parameter_n Register (REG_A79_64) */
#define S32K3XX_VIRTWRAPPER_REG_A95_80_OFFSET     (0x0014) /* Parameter_n Register (REG_A95_80) */
#define S32K3XX_VIRTWRAPPER_REG_A111_96_OFFSET    (0x0018) /* Parameter_n Register (REG_A111_96) */
#define S32K3XX_VIRTWRAPPER_REG_A127_112_OFFSET   (0x001c) /* Parameter_n Register (REG_A127_112) */
#define S32K3XX_VIRTWRAPPER_REG_A143_128_OFFSET   (0x0020) /* Parameter_n Register (REG_A143_128) */
#define S32K3XX_VIRTWRAPPER_REG_A159_144_OFFSET   (0x0024) /* Parameter_n Register (REG_A159_144) */
#define S32K3XX_VIRTWRAPPER_REG_A175_160_OFFSET   (0x0028) /* Parameter_n Register (REG_A175_160) */
#define S32K3XX_VIRTWRAPPER_REG_A191_176_OFFSET   (0x002c) /* Parameter_n Register (REG_A191_176) */
#define S32K3XX_VIRTWRAPPER_REG_A207_192_OFFSET   (0x0030) /* Parameter_n Register (REG_A207_192) */
#define S32K3XX_VIRTWRAPPER_REG_A223_208_OFFSET   (0x0034) /* Parameter_n Register (REG_A223_208) */
#define S32K3XX_VIRTWRAPPER_REG_A239_224_OFFSET   (0x0038) /* Parameter_n Register (REG_A239_224) */
#define S32K3XX_VIRTWRAPPER_REG_A255_240_OFFSET   (0x003c) /* Parameter_n Register (REG_A255_240) */
#define S32K3XX_VIRTWRAPPER_REG_A271_256_OFFSET   (0x0040) /* Parameter_n Register (REG_A271_256) */
#define S32K3XX_VIRTWRAPPER_REG_A287_272_OFFSET   (0x0044) /* Parameter_n Register (REG_A287_272) */
#define S32K3XX_VIRTWRAPPER_REG_A303_288_OFFSET   (0x0048) /* Parameter_n Register (REG_A303_288) */
#define S32K3XX_VIRTWRAPPER_REG_A319_304_OFFSET   (0x004c) /* Parameter_n Register (REG_A319_304) */
#define S32K3XX_VIRTWRAPPER_REG_A335_320_OFFSET   (0x0050) /* Parameter_n Register (REG_A335_320) */
#define S32K3XX_VIRTWRAPPER_REG_A351_336_OFFSET   (0x0054) /* Parameter_n Register (REG_A351_336) */
#define S32K3XX_VIRTWRAPPER_REG_A367_352_OFFSET   (0x0058) /* Parameter_n Register (REG_A367_352) */
#define S32K3XX_VIRTWRAPPER_REG_A383_368_OFFSET   (0x005c) /* Parameter_n Register (REG_A383_368) */
#define S32K3XX_VIRTWRAPPER_REG_A399_384_OFFSET   (0x0060) /* Parameter_n Register (REG_A399_384) */
#define S32K3XX_VIRTWRAPPER_REG_A415_400_OFFSET   (0x0064) /* Parameter_n Register (REG_A415_400) */
#define S32K3XX_VIRTWRAPPER_REG_A431_416_OFFSET   (0x0068) /* Parameter_n Register (REG_A431_416) */
#define S32K3XX_VIRTWRAPPER_REG_A447_432_OFFSET   (0x006c) /* Parameter_n Register (REG_A447_432) */
#define S32K3XX_VIRTWRAPPER_REG_A463_448_OFFSET   (0x0070) /* Parameter_n Register (REG_A463_448) */
#define S32K3XX_VIRTWRAPPER_REG_A479_464_OFFSET   (0x0074) /* Parameter_n Register (REG_A479_464) */
#define S32K3XX_VIRTWRAPPER_REG_A495_480_OFFSET   (0x0078) /* Parameter_n Register (REG_A495_480) */
#define S32K3XX_VIRTWRAPPER_REG_A511_496_OFFSET   (0x007c) /* Parameter_n Register (REG_A511_496) */
#define S32K3XX_VIRTWRAPPER_REG_B527_512_OFFSET   (0x0080) /* Parameter_n Register (REG_B527_512) */
#define S32K3XX_VIRTWRAPPER_REG_B543_528_OFFSET   (0x0084) /* Parameter_n Register (REG_B543_528) */
#define S32K3XX_VIRTWRAPPER_REG_B559_544_OFFSET   (0x0088) /* Parameter_n Register (REG_B559_544) */
#define S32K3XX_VIRTWRAPPER_REG_B575_560_OFFSET   (0x008c) /* Parameter_n Register (REG_B575_560) */
#define S32K3XX_VIRTWRAPPER_REG_B591_576_OFFSET   (0x0090) /* Parameter_n Register (REG_B591_576) */
#define S32K3XX_VIRTWRAPPER_REG_B607_592_OFFSET   (0x0094) /* Parameter_n Register (REG_B607_592) */
#define S32K3XX_VIRTWRAPPER_REG_B623_608_OFFSET   (0x0098) /* Parameter_n Register (REG_B623_608) */
#define S32K3XX_VIRTWRAPPER_REG_B639_624_OFFSET   (0x009c) /* Parameter_n Register (REG_B639_624) */
#define S32K3XX_VIRTWRAPPER_REG_B655_640_OFFSET   (0x00a0) /* Parameter_n Register (REG_B655_640) */
#define S32K3XX_VIRTWRAPPER_REG_B671_656_OFFSET   (0x00a4) /* Parameter_n Register (REG_B671_656) */
#define S32K3XX_VIRTWRAPPER_REG_B687_672_OFFSET   (0x00a8) /* Parameter_n Register (REG_B687_672) */
#define S32K3XX_VIRTWRAPPER_REG_B703_688_OFFSET   (0x00ac) /* Parameter_n Register (REG_B703_688) */
#define S32K3XX_VIRTWRAPPER_REG_B719_704_OFFSET   (0x00b0) /* Parameter_n Register (REG_B719_704) */
#define S32K3XX_VIRTWRAPPER_REG_B735_720_OFFSET   (0x00b4) /* Parameter_n Register (REG_B735_720) */
#define S32K3XX_VIRTWRAPPER_REG_B751_736_OFFSET   (0x00b8) /* Parameter_n Register (REG_B751_736) */
#define S32K3XX_VIRTWRAPPER_REG_B767_752_OFFSET   (0x00bc) /* Parameter_n Register (REG_B767_752) */
#define S32K3XX_VIRTWRAPPER_REG_B783_768_OFFSET   (0x00c0) /* Parameter_n Register (REG_B783_768) */
#define S32K3XX_VIRTWRAPPER_REG_B799_784_OFFSET   (0x00c4) /* Parameter_n Register (REG_B799_784) */
#define S32K3XX_VIRTWRAPPER_REG_B815_800_OFFSET   (0x00c8) /* Parameter_n Register (REG_B815_800) */
#define S32K3XX_VIRTWRAPPER_REG_B831_816_OFFSET   (0x00cc) /* Parameter_n Register (REG_B831_816) */
#define S32K3XX_VIRTWRAPPER_REG_B847_832_OFFSET   (0x00d0) /* Parameter_n Register (REG_B847_832) */
#define S32K3XX_VIRTWRAPPER_REG_B863_848_OFFSET   (0x00d4) /* Parameter_n Register (REG_B863_848) */
#define S32K3XX_VIRTWRAPPER_REG_B879_864_OFFSET   (0x00d8) /* Parameter_n Register (REG_B879_864) */
#define S32K3XX_VIRTWRAPPER_REG_B895_880_OFFSET   (0x00dc) /* Parameter_n Register (REG_B895_880) */
#define S32K3XX_VIRTWRAPPER_REG_B911_896_OFFSET   (0x00e0) /* Parameter_n Register (REG_B911_896) */
#define S32K3XX_VIRTWRAPPER_REG_B927_912_OFFSET   (0x00e4) /* Parameter_n Register (REG_B927_912) */
#define S32K3XX_VIRTWRAPPER_REG_B943_928_OFFSET   (0x00e8) /* Parameter_n Register (REG_B943_928) */
#define S32K3XX_VIRTWRAPPER_REG_B959_944_OFFSET   (0x00ec) /* Parameter_n Register (REG_B959_944) */
#define S32K3XX_VIRTWRAPPER_REG_B975_960_OFFSET   (0x00f0) /* Parameter_n Register (REG_B975_960) */
#define S32K3XX_VIRTWRAPPER_REG_B991_976_OFFSET   (0x00f4) /* Parameter_n Register (REG_B991_976) */
#define S32K3XX_VIRTWRAPPER_REG_B1007_992_OFFSET  (0x00f8) /* Parameter_n Register (REG_B1007_99) */
#define S32K3XX_VIRTWRAPPER_REG_B1023_1008_OFFSET (0x00fc) /* Parameter_n Register (REG_B1023_1008) */
#define S32K3XX_VIRTWRAPPER_REG_C1039_1024_OFFSET (0x0100) /* Parameter_n Register (REG_C1039_1024) */
#define S32K3XX_VIRTWRAPPER_REG_D1055_1040_OFFSET (0x0104) /* Parameter_n Register (REG_D1055_1040) */

/* VIRTWRAPPER Register Addresses *******************************************/

#define S32K3XX_VIRTWRAPPER_REG_A15_0             (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A15_0_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A31_16            (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A31_16_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A47_32            (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A47_32_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A63_48            (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A63_48_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A79_64            (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A79_64_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A95_80            (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A95_80_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A111_96           (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A111_96_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A127_112          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A127_112_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A143_128          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A143_128_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A159_144          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A159_144_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A175_160          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A175_160_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A191_176          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A191_176_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A207_192          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A207_192_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A223_208          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A223_208_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A239_224          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A239_224_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A255_240          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A255_240_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A271_256          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A271_256_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A287_272          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A287_272_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A303_288          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A303_288_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A319_304          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A319_304_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A335_320          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A335_320_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A351_336          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A351_336_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A367_352          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A367_352_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A383_368          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A383_368_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A399_384          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A399_384_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A415_400          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A415_400_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A431_416          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A431_416_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A447_432          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A447_432_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A463_448          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A463_448_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A479_464          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A479_464_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A495_480          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A495_480_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A511_496          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_A511_496_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B527_512          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B527_512_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B543_528          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B543_528_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B559_544          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B559_544_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B575_560          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B575_560_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B591_576          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B591_576_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B607_592          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B607_592_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B623_608          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B623_608_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B639_624          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B639_624_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B655_640          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B655_640_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B671_656          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B671_656_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B687_672          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B687_672_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B703_688          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B703_688_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B719_704          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B719_704_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B735_720          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B735_720_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_A751_736          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B751_736_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B767_752          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B767_752_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B783_768          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B783_768_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B799_784          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B799_784_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B815_800          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B815_800_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B831_816          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B831_816_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B847_832          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B847_832_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B863_848          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B863_848_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B879_864          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B879_864_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B895_880          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B895_880_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B911_896          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B911_896_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B927_912          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B927_912_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B943_928          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B943_928_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B959_944          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B959_944_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B975_960          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B975_960_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B991_976          (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B991_976_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B1007_992         (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B1007_992_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_B1023_1008        (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_B1023_1008_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_C1039_1024        (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_C1039_1024_OFFSET)
#define S32K3XX_VIRTWRAPPER_REG_D1055_1040        (S32K3XX_VIRTWRAPPER_OFFSET + S32K3XX_VIRTWRAPPER_REG_D1055_1040_OFFSET)

/* VIRTWRAPPER Register Bitfield Definitions ********************************/

/* Parameter_n Register (REG_Annn_mmm) */

#define VIRTWRAPPER_REG_A_PAD_SHIFT(p)        ((p) << 1) /* Bits (2*p)-(2*p+1): PAD_p, p=0..15 */
#define VIRTWRAPPER_REG_A_PAD_MASK(p)         (0x03 << VIRTWRAPPER_REG_A_PAD_SHIFT(p))
#  define VIRTWRAPPER_REG_A_PAD_CORE0(p)      (0x00 << VIRTWRAPPER_REG_A_PAD_SHIFT(p)) /* SIUL2_VIRTWRAPPER_PDAC1 (Core 0) */
#  define VIRTWRAPPER_REG_A_PAD_CORE1(p)      (0x01 << VIRTWRAPPER_REG_A_PAD_SHIFT(p)) /* SIUL2_VIRTWRAPPER_PDAC2 (Core 1) */
#  define VIRTWRAPPER_REG_A_PAD_SECCORE(p)    (0x03 << VIRTWRAPPER_REG_A_PAD_SHIFT(p)) /* SIUL2_VIRTWRAPPER_PDAC0 (Secure Core) */

/* Parameter_n Register (REG_Bnnnn_mmmm) */

#define VIRTWRAPPER_REG_B_INMUX_SHIFT(i)      ((i) << 1) /* Bits (2*i)-(2*i+1): INMUX_i, i=0..15 */
#define VIRTWRAPPER_REG_B_INMUX_MASK(i)       (0x03 << VIRTWRAPPER_REG_B_INMUX_SHIFT(i))
#  define VIRTWRAPPER_REG_B_INMUX_CORE0(i)    (0x00 << VIRTWRAPPER_REG_B_INMUX_SHIFT(i)) /* SIUL2_VIRTWRAPPER_PDAC1 (Core 0) */
#  define VIRTWRAPPER_REG_B_INMUX_CORE1(i)    (0x01 << VIRTWRAPPER_REG_B_INMUX_SHIFT(i)) /* SIUL2_VIRTWRAPPER_PDAC2 (Core 1) */
#  define VIRTWRAPPER_REG_B_INMUX_SECCORE(i)  (0x03 << VIRTWRAPPER_REG_B_INMUX_SHIFT(i)) /* SIUL2_VIRTWRAPPER_PDAC0 (Secure Core) */

/* Parameter_n Register (REG_C1039_1024) */

#define VIRTWRAPPER_REG_C_INTC_CTRL_SHIFT     (0)   /* Bits 0-1: Interrupt register control (INTC_CTRL) */
#define VIRTWRAPPER_REG_C_INTC_CTRL_MASK      (0x03 << VIRTWRAPPER_REG_C_INTC_CTRL_SHIFT)
                                                    /* Bits 2-31: Reserved */

/* Parameter_n Register (REG_D1055_1040) */

                                                    /* Bits 0-29: Reserved */
#define VIRTWRAPPER_REG_D_REG_GCR_SHIFT       (30)  /* Bits 30-31: GCR Register Of REG_PROT (REG_GCR) */
#define VIRTWRAPPER_REG_D_REG_GCR_MASK        (0x03 << VIRTWRAPPER_REG_D_REG_GCR_SHIFT)

#endif /* __ARCH_ARM_SRC_S32K3XX_HARDWARE_S32K3XX_VIRTWRAPPER_H */
