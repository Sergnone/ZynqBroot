/******************************************************************************
* Copyright (c) 2014 - 2022 Xilinx, Inc.  All rights reserved.
* Copyright (c) 2023 - 2025 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xplatform_info.h
*
*
* @addtogroup common_platform_info APIs to Get Platform Information
*
*
* The xplatform_info.h file contains definitions for various available Xilinx&reg;
* platforms. Also, it contains prototype of APIs, which can be used to get the
* platform information.
*
* @{
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who    Date    Changes
* ----- ---- --------- -------------------------------------------------------
* 6.4    ms   05/23/17 Added PSU_PMU macro to support XGetPSVersion_Info
*                      function for PMUFW.
* 7.2    adk  08/01/20 Added versal support for the XGetPSVersion_Info function.
* 7.6    mus  08/23/21 Updated prototypes for functions which are not taking any
*                      arguments with void keyword. This has been done to fix
*                      compilation warnings with "-Wstrict-prototypes" flag.
*                      It fixes CR#1108601.
* 7.6    mus  08/30/21 Updated flag checking to fix compilation warnings
*                      reported with "-Wundef" flag.
* 7.7	 sk   01/10/22 Update XPLAT_INFO_MASK from signed to unsigned to fix
*		       misra_c_2012_rule_10_4 violation.
* 8.1    mus  02/13/23 Added new API's XGetCoreId and XGetClusterId. As of now
*                      they are supported only for VERSAL_NET APU and RPU.
* 9.0    mus 03/28/23 Added new API XGetBootStatus for VERSAL_NET. It can be
*                     used to identify type of boot (cold/warm).
* 9.0    mus 07/27/23 Updated XGetCoreId API to support A9, R5 and A53 processor
* 9.0    ml  09/14/23 Added U to numerical to fix MISRA-C violation for Rule
*                     10.1 and 10.4
* 9.2    ng  08/20/24 Added SpartanUP device support
* 9.2    mus 09/23/24 Add definitions related to cluster/core specific offsets
*                     for RPU_PCIL_X_PWRDWN register. They are applicable for
*                     cluster C, D and E in Versal 2VE and 2VM devices.
* 9.3    mus 01/07/25 Fix address of RPU_PCIL_C0_PWRDWN register.
* 9.3    tnt 02/10/25 versal_2ve_2vm: replace all RPU_PCI_[XY]_PWRDWN
                      with XPS_PSX_RPU_CLUSTER_XY_CORE_X_PWRDWN registers
* 9.4    vmt 28/10/25 Added XIOCoherencySupported() declaration to check cache
		      coherency support.
* </pre>
*
******************************************************************************/

/**
 *@cond nocomments
 */

#ifndef XPLATFORM_INFO_H		/* prevent circular inclusions */
#define XPLATFORM_INFO_H		/* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "../../include/xil_types.h"

/************************** Constant Definitions *****************************/
#define XPAR_CSU_BASEADDR 0xFFCA0000U
#define	XPAR_CSU_VER_OFFSET 0x00000044U
#define XPLAT_PS_VERSION_ADDRESS (XPAR_CSU_BASEADDR + \
				  XPAR_CSU_VER_OFFSET)
#define XPLAT_ZYNQ_ULTRA_MP_SILICON 0x0
#define XPLAT_ZYNQ_ULTRA_MP 0x1
#define XPLAT_ZYNQ_ULTRA_MPVEL 0x2
#define XPLAT_ZYNQ_ULTRA_MPQEMU 0x3
#define XPLAT_ZYNQ 0x4
#define XPLAT_MICROBLAZE 0x5
#define XPLAT_VERSAL 0x6U

#define XPS_VERSION_1 0x0
#define XPS_VERSION_2 0x1
#define XPLAT_INFO_MASK (0xFU)

#define XPS_VERSION_INFO_MASK  0xFU
#define XPS_VERSION_INFO_SHIFT 0x0U
#define XPLAT_INFO_SHIFT 0xCU

#define APU_EL1         1U

/**************************** Type Definitions *******************************/
/**
 *@endcond
 */
/***************** Macros (Inline Functions) Definitions *********************/


uint32_t XGetPlatform_Info(void);
#if ! defined(__microblaze__) && ! defined(__riscv)
uint8_t XGetCoreId(void);
#endif

#if defined (ARMR5) || defined (__aarch64__) || defined (ARMA53_32) || defined (PSU_PMU) || defined (versal)
uint32_t XGetPSVersion_Info(void);
#endif

#if defined (ARMR5) || defined (__aarch64__) || defined (ARMA53_32)
uint32_t XGet_Zynq_UltraMp_Platform_info(void);
#endif

#if (defined (__aarch64__) && defined (VERSAL_NET)) || defined (ARMR52)
uint8_t XGetClusterId(void);
uint8_t XGetCoreId(void);
uint8_t XGetBootStatus(void);
#endif

uint32_t XIOCoherencySupported(void);

/************************** Function Prototypes ******************************/


#ifdef __cplusplus
}
#endif

#endif /* end of protection macro */
/**
* @} End of "addtogroup common_platform_info".
*/
