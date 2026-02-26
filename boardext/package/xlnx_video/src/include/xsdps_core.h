/******************************************************************************
* Copyright (C) 2013 - 2022 Xilinx, Inc.  All rights reserved.
* Copyright (c) 2022 - 2025 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xsdps_core.h
* @addtogroup sdps_api SDPS APIs
* @{
*
* The xsdps_core.h header file contains the identifiers and basic hardware access driver
* functions (or  macros) that can be used to access the device. Other driver
* functions are defined in xsdps.h.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who    Date     Changes
* ----- ---    -------- -----------------------------------------------
* 3.9   mn     03/03/20 Restructured the code for more readability and modularity
*       mn     03/16/20 Move XSdPs_Select_Card API to User APIs
* 3.12  sk     01/28/21 Added support for non-blocking write.
* 3.14  sk     10/22/21 Add support for Erase feature.
*       mn     11/28/21 Fix MISRA-C violations.
* 4.0   sk     02/25/22 Add support for eMMC5.1.
* 4.1   sa     01/06/23 Include xil_util.h in this file.
* 4.2   ap     08/09/23 Add XSdPs_SetTapDelay APIs.
* </pre>
*
******************************************************************************/

/** @cond INTERNAL */
#ifndef SDPS_INCLUDE_H_
#define SDPS_INCLUDE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "xsdps.h"
#if defined (__aarch64__)
#include "xil_smc.h"
#endif

#include "xil_util.h"

uint32_t XSdPs_SdCardInitialize(XSdPs *InstancePtr);
uint32_t XSdPs_MmcCardInitialize(XSdPs *InstancePtr);
uint32_t XSdPs_IdentifyCard(XSdPs *InstancePtr);
uint32_t XSdPs_CmdTransfer(XSdPs *InstancePtr, uint32_t Cmd, uint32_t Arg, uint32_t BlkCnt);
uint32_t XSdPs_SetupTransfer(XSdPs *InstancePtr);
uint32_t XSdPs_Read(XSdPs *InstancePtr, uint32_t Arg, uint32_t BlkCnt, uint8_t *Buff);
uint32_t XSdPs_Write(XSdPs *InstancePtr, uint32_t Arg, uint32_t BlkCnt, const uint8_t *Buff);
uint32_t XSdPs_CheckTransferComplete(XSdPs *InstancePtr);
void XSdPs_Identify_UhsMode(XSdPs *InstancePtr, uint8_t *ReadBuff);
uint32_t XSdPs_DllReset(XSdPs *InstancePtr);
uint32_t XSdPs_Switch_Voltage(XSdPs *InstancePtr);
void XSdPs_SetupADMA2DescTbl64Bit(XSdPs *InstancePtr, uint32_t BlkCnt);
void XSdPs_SetupADMA2DescTbl(XSdPs *InstancePtr, uint32_t BlkCnt, const uint8_t *Buff);
void XSdPs_DllRstCtrl(XSdPs *InstancePtr, uint8_t EnRst);
void XSdPs_ConfigTapDelay(XSdPs *InstancePtr);
uint32_t XSdPs_Execute_Tuning(XSdPs *InstancePtr);
void XSdPs_Setup32ADMA2DescTbl(XSdPs *InstancePtr, uint32_t BlkCnt, const uint8_t *Buff);
void XSdPs_Setup64ADMA2DescTbl(XSdPs *InstancePtr, uint32_t BlkCnt, const uint8_t *Buff);
uint32_t XSdPs_FrameCmd(XSdPs *InstancePtr, uint32_t Cmd);
void XSdPs_SetTapDelay(XSdPs *InstancePtr);
uint32_t XSdPs_CheckResetDone(XSdPs *InstancePtr, uint8_t Value);
uint32_t XSdPs_CheckVoltage18(XSdPs *InstancePtr);
uint32_t XSdPs_SetupCmd(XSdPs *InstancePtr, uint32_t Arg, uint32_t BlkCnt);
void XSdPs_SetExecTuning(XSdPs *InstancePtr);
uint32_t XSdPs_CheckCardDetect(XSdPs *InstancePtr);
uint32_t XSdPs_CardReset(XSdPs *InstancePtr);
uint32_t XSdPs_CardIfCond(XSdPs *InstancePtr);
uint32_t XSdPs_CardOpCond(XSdPs *InstancePtr);
uint32_t XSdPs_GetCardId(XSdPs *InstancePtr);
uint32_t XSdPs_GetCsd(XSdPs *InstancePtr);
uint32_t XSdPs_CardSetVoltage18(XSdPs *InstancePtr);
uint32_t XSdPs_SdModeInit(XSdPs *InstancePtr);
uint32_t XSdPs_SdCardEnum(XSdPs *InstancePtr);
uint32_t XSdPs_MmcCardEnum(XSdPs *InstancePtr);
uint32_t XSdPs_MmcModeInit(XSdPs *InstancePtr);
uint32_t XSdPs_EmmcModeInit(XSdPs *InstancePtr);
uint32_t XSdPs_ResetConfig(XSdPs *InstancePtr);
void XSdPs_HostConfig(XSdPs *InstancePtr);
uint32_t XSdPs_Reset(XSdPs *InstancePtr, uint8_t Value);
void XSdPs_DisableBusPower(XSdPs *InstancePtr);
void XSdPs_EnableBusPower(XSdPs *InstancePtr);
uint32_t XSdPs_CheckBusIdle(XSdPs *InstancePtr, uint32_t Value);
uint32_t XSdPs_CheckBusHigh(XSdPs *InstancePtr);
uint32_t XSdPs_SetupVoltageSwitch(XSdPs *InstancePtr);
uint32_t XSdPs_AutoTuning(XSdPs *InstancePtr);
uint32_t XSdPs_SetClock(XSdPs *InstancePtr, uint32_t SelFreq);
uint32_t XSdPs_CalcClock(XSdPs *InstancePtr, uint32_t SelFreq);
uint32_t XSdPs_EnableClock(XSdPs *InstancePtr, uint16_t ClockReg);
uint32_t XSdps_CheckTransferDone(XSdPs *InstancePtr);
uint32_t XSdPs_Change_SdBusSpeed(XSdPs *InstancePtr);
uint32_t XSdPs_Change_MmcBusSpeed(XSdPs *InstancePtr);
uint32_t XSdPs_CalcBusSpeed(XSdPs *InstancePtr, uint32_t *Arg);
void XSdPs_SetupReadDma(XSdPs *InstancePtr, uint16_t BlkCnt, uint16_t BlkSize, uint8_t *Buff);
void XSdPs_SetupWriteDma(XSdPs *InstancePtr, uint16_t BlkCnt, uint16_t BlkSize, const uint8_t *Buff);
uint32_t XSdPs_SetVoltage18(XSdPs *InstancePtr);
uint32_t XSdPs_SendCmd(XSdPs *InstancePtr, uint32_t Cmd);
void XSdPs_IdentifyEmmcMode(XSdPs *InstancePtr, const uint8_t *ExtCsd);
uint32_t XSdPs_CheckEmmcTiming(XSdPs *InstancePtr, uint8_t *ExtCsd);
void XSdPs_ConfigPower(XSdPs *InstancePtr);
void XSdPs_ConfigDma(XSdPs *InstancePtr);
void XSdPs_ConfigInterrupt(XSdPs *InstancePtr);
uint32_t XSdPs_SendErase(XSdPs *InstancePtr);
uint32_t XSdPs_SetEndAddr(XSdPs *InstancePtr, uint32_t EndAddr);
uint32_t XSdPs_SetStartAddr(XSdPs *InstancePtr, uint32_t StartAddr);
void XSdPs_SetTapDelay_SDR104(XSdPs *InstancePtr);
void XSdPs_SetTapDelay_SDR50(XSdPs *InstancePtr);
void XSdPs_SetTapDelay_DDR50(XSdPs *InstancePtr);
void XSdPs_SetTapDelay_SDR25(XSdPs *InstancePtr);
#ifdef VERSAL_NET
uint32_t XSdPs_Select_HS400(XSdPs *InstancePtr);
#endif

#if defined (__aarch64__) && (EL1_NONSECURE == 1)
void XSdps_Smc(XSdPs *InstancePtr, uint32_t RegOffset, uint32_t Mask, uint32_t Val);
#endif

#ifdef __cplusplus
}
#endif

#endif
/** @endcond */
/** @} */
