/******************************************************************************
* Copyright (C) 2013 - 2021 Xilinx, Inc.  All rights reserved.
* Copyright (c) 2022 - 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xgpiops_hw.c
* @addtogroup gpiops Overview
* @{
*
* This file contains low level GPIO functions.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.02a hk   08/22/13 First Release
* 3.00  kvn  02/13/15 Modified code for MISRA-C:2012 compliance.
* 3.1	kvn  04/13/15 Add support for Zynq Ultrascale+ MP. CR# 856980.
* 3.5   sne  03/01/19 Fixes violations according to MISRAC-2012
*                     in safety mode and modified the code such as
*                     Use of mixed mode arithmetic,Declared the pointer param
*                     as Pointer to const,Casting operation to a pointer,
*                     Literal value requires a U suffix.
* 3.5   sne  03/14/19 Added versal support.
* </pre>
*
******************************************************************************/

/***************************** Include Files *********************************/

#include "xgpiops_hw.h"
#include "xgpiops.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Variable Definitions *****************************/

/************************** Function Prototypes ******************************/


/*****************************************************************************/
/**
*
* This function resets the GPIO module by writing reset values to
* all registers
*
* @param	BaseAddress address of GPIO module
*
* @return	None
*
* @note		None.
*
******************************************************************************/
void XGpioPs_ResetHw(uintptr_t BaseAddress)
{
	uint32_t BankCount;
	uint32_t Platform,MaxBanks;

	Platform = XGetPlatform_Info();
        if (Platform == (uint32_t)XPLAT_ZYNQ_ULTRA_MP) {
                MaxBanks = (uint32_t)6;
        }
        else if(Platform == (uint32_t)XPLAT_VERSAL)
        {
                if (BaseAddress == (uint32_t)XGPIOPS_PS_GPIO_BASEADDR)
                {
                        MaxBanks = (uint32_t)4;
                }
                else
                {
                        MaxBanks = (uint32_t)5;
                }
        }
        else {
                MaxBanks = (uint32_t)4;
        }

        if (Platform == (uint32_t)XPLAT_VERSAL)
        {
                /* Write reset values to all mask data registers */
                for(BankCount = 3U; BankCount < (uint32_t)MaxBanks; BankCount++) {

                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_DATA_MASK_OFFSET) +
                                         XGPIOPS_DATA_LSW_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_DATA_MASK_OFFSET) +
                                         XGPIOPS_DATA_MSW_OFFSET), 0x0U);
                }
                /* Write reset values to all output data registers */
                for(BankCount = 3U; BankCount < (uint32_t)MaxBanks; BankCount++) {

                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_DATA_BANK_OFFSET) +
                                         XGPIOPS_DATA_OFFSET), 0x0U);
                }

                /* Reset all registers of all GPIO banks */
                for(BankCount = 0U; BankCount < (uint32_t)MaxBanks; BankCount++) {


                        if((BaseAddress == (uint32_t)XGPIOPS_PS_GPIO_BASEADDR) && ((BankCount == (uint32_t)XGPIOPS_ONE) ||(BankCount == (uint32_t)XGPIOPS_TWO)))
                        {
                                continue;
                        }
                        else
                        {
                                if((BaseAddress != (uint32_t)XGPIOPS_PS_GPIO_BASEADDR) && (BankCount == (uint32_t)XGPIOPS_ONE))
                                {
                                        continue;
                                }
                        }
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_DIRM_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_OUTEN_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTMASK_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTEN_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTDIS_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTSTS_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTPOL_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTANY_OFFSET), 0x0U);

                }

                /* Bank 0 Int type */
                XGpioPs_WriteReg(BaseAddress, XGPIOPS_INTTYPE_OFFSET,
                                XGPIOPS_INTTYPE_BANK0_RESET);
                /* Bank 1 Int type */
                XGpioPs_WriteReg(BaseAddress,
                                ((uint32_t)XGPIOPS_REG_MASK_OFFSET + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                XGPIOPS_INTTYPE_BANK1_RESET);
                /* Bank 3 Int type */
                XGpioPs_WriteReg(BaseAddress,
                                (((uint32_t)3 * XGPIOPS_REG_MASK_OFFSET) + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                XGPIOPS_INTTYPE_BANK3_RESET);
                /* Bank 4 Int type */
                XGpioPs_WriteReg(BaseAddress,
                                (((uint32_t)4 * XGPIOPS_REG_MASK_OFFSET) + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                XGPIOPS_INTTYPE_BANK4_RESET);
        }
        else
        {
                /* Write reset values to all mask data registers */
                for(BankCount = 2U; BankCount < (uint32_t)MaxBanks; BankCount++) {

                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_DATA_MASK_OFFSET) +
                                         XGPIOPS_DATA_LSW_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_DATA_MASK_OFFSET) +
                                         XGPIOPS_DATA_MSW_OFFSET), 0x0U);
                }
                /* Write reset values to all output data registers */
                for(BankCount = 2U; BankCount < (uint32_t)MaxBanks; BankCount++) {

                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_DATA_BANK_OFFSET) +
                                         XGPIOPS_DATA_OFFSET), 0x0U);
                }
                /* Reset all registers of all GPIO banks */
                for(BankCount = 0U; BankCount < (uint32_t)MaxBanks; BankCount++) {

                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_DIRM_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_OUTEN_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTMASK_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTEN_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTDIS_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTSTS_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTPOL_OFFSET), 0x0U);
                        XGpioPs_WriteReg(BaseAddress,
                                        ((BankCount * XGPIOPS_REG_MASK_OFFSET) +
                                         XGPIOPS_INTANY_OFFSET), 0x0U);
                }
                /* Bank 0 Int type */
                XGpioPs_WriteReg(BaseAddress, XGPIOPS_INTTYPE_OFFSET,
                                XGPIOPS_INTTYPE_BANK0_RESET);
                /* Bank 1 Int type */
                XGpioPs_WriteReg(BaseAddress,
                                ((uint32_t)XGPIOPS_REG_MASK_OFFSET + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                XGPIOPS_INTTYPE_BANK1_RESET);
                /* Bank 2 Int type */
                XGpioPs_WriteReg(BaseAddress,
                                (((uint32_t)2 * XGPIOPS_REG_MASK_OFFSET) + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                XGPIOPS_INTTYPE_BANK2_RESET);
                /* Bank 3 Int type */
                XGpioPs_WriteReg(BaseAddress,
                                (((uint32_t)3 * XGPIOPS_REG_MASK_OFFSET) + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                XGPIOPS_INTTYPE_BANK3_RESET);

                if (Platform == (uint32_t)XPLAT_ZYNQ_ULTRA_MP) {
                        /* Bank 4 Int type */
                        XGpioPs_WriteReg(BaseAddress,
                                        (((uint32_t)4 * XGPIOPS_REG_MASK_OFFSET) + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                        XGPIOPS_INTTYPE_BANK4_RESET);
                        /* Bank 5 Int type */
                        XGpioPs_WriteReg(BaseAddress,
                                        (((uint32_t)5 * XGPIOPS_REG_MASK_OFFSET) + (uint32_t)XGPIOPS_INTTYPE_OFFSET),
                                        XGPIOPS_INTTYPE_BANK5_RESET);
                }
        }

}
/** @} */
