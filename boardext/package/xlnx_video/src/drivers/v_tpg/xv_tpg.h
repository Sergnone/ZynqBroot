// ==============================================================
// Copyright (c) 2015 - 2021 Xilinx Inc. All rights reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// SPDX-License-Identifier: MIT
// ==============================================================

#ifndef XV_TPG_H
#define XV_TPG_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "../../include/xil_types.h"
#include "../../include/xil_assert.h"
#include "../../include/xstatus.h"
#include "../../include/xil_io.h"
#include "xv_tpg_hw.h"
#include <stdio.h>

/**************************** Type Definitions ******************************/
/**
 * This typedef enumerates the different patterns supported by TPG
 */
typedef enum
{
  XTPG_BKGND_H_RAMP = 1,
  XTPG_BKGND_V_RAMP,
  XTPG_BKGND_TEMPORAL_RAMP,
  XTPG_BKGND_SOLID_RED,
  XTPG_BKGND_SOLID_GREEN,
  XTPG_BKGND_SOLID_BLUE,
  XTPG_BKGND_SOLID_BLACK,
  XTPG_BKGND_SOLID_WHITE,
  XTPG_BKGND_COLOR_BARS,
  XTPG_BKGND_ZONE_PLATE,
  XTPG_BKGND_TARTAN_COLOR_BARS,
  XTPG_BKGND_CROSS_HATCH,
  XTPG_BKGND_RAINBOW_COLOR,
  XTPG_BKGND_HV_RAMP,
  XTPG_BKGND_CHECKER_BOARD,
  XTPG_BKGND_PBRS,
  XTPG_BKGND_DP_COLOR_RAMP,
  XTPG_BKGND_DP_BW_VERTICAL_LINE,
  XTPG_BKGND_DP_COLOR_SQUARE,
  XTPG_BKGND_LAST
}XTpg_PatternId;

typedef void (*XVTpg_Callback)(void *InstancePtr);

/************************** Constant Definitions *****************************/
#define XVTPG_IRQ_DONE_MASK            (0x01)
#define XVTPG_IRQ_READY_MASK           (0x02)

typedef enum {
  XVTPG_HANDLER_DONE = 1,  /**< Handler for ap_done */
  XVTPG_HANDLER_READY      /**< Handler for ap_ready */
} XVTPG_HandlerType;

/**
* This typedef contains configuration information for the tpg core
* Each core instance should have a configuration structure associated.
*/
typedef struct {
    char *Name;
    uint32_t BaseAddress;   /**< The base address of the core instance. */
    uint16_t HasAxi4sSlave;     /**< Axi4s Slave capability indicator */
    uint16_t PixPerClk;         /**< Samples Per Clock supported by core instance */
    uint16_t NumVidComponents;  /**< Number of Video Components */
    uint16_t MaxWidth;          /**< Maximum columns supported by core instance */
    uint16_t MaxHeight;         /**< Maximum rows supported by core instance */
    uint16_t MaxDataWidth;      /**< Maximum Data width of each channel */
	uint16_t SolidColorEnable;  /**< Axi4s Slave capability indicator */
	uint16_t RampEnable;        /**< Axi4s Slave capability indicator */
	uint16_t ColorBarEnable;    /**< Axi4s Slave capability indicator */
	uint16_t DisplayPortEnable; /**< Axi4s Slave capability indicator */
	uint16_t ColorSweepEnable;  /**< Axi4s Slave capability indicator */
	uint16_t ZoneplateEnable;   /**< Axi4s Slave capability indicator */
	uint16_t ForegroundEnable;  /**< Axi4s Slave capability indicator */
    uint16_t IntrId; 		    /**< Interrupt ID */
    uint32_t IntrParent; 	/**< Bit[0] Interrupt parent type Bit[64/32:1] Parent base address */
} XV_tpg_Config;


/**
* Driver instance data. An instance must be allocated for each core in use.
*/
typedef struct {
    XV_tpg_Config Config;  /**< Hardware Configuration */
    uint32_t IsReady;           /**< Device is initialized and ready */
    XVTpg_Callback FrameDoneCallback;
    void *CallbackDoneRef;     /**< To be passed to the connect interrupt
                                callback */
    XVTpg_Callback FrameReadyCallback;
    void *CallbackReadyRef;     /**< To be passed to the connect interrupt
                                callback */
} XV_tpg;

/***************** Macros (Inline Functions) Definitions *********************/
#define XV_tpg_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (uint32_t)(Data))
#define XV_tpg_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))


/************************** Function Prototypes *****************************/
int XV_tpg_Initialize(XV_tpg *InstancePtr, uint32_t BaseAddress);
XV_tpg_Config* XV_tpg_LookupConfig(uint32_t BaseAddress);
int XV_tpg_CfgInitialize(XV_tpg *InstancePtr,
                         XV_tpg_Config *ConfigPtr,
                         uintptr_t EffectiveAddr);


void XV_tpg_Start(XV_tpg *InstancePtr);
uint32_t XV_tpg_IsDone(XV_tpg *InstancePtr);
uint32_t XV_tpg_IsIdle(XV_tpg *InstancePtr);
uint32_t XV_tpg_IsReady(XV_tpg *InstancePtr);
void XV_tpg_EnableAutoRestart(XV_tpg *InstancePtr);
void XV_tpg_DisableAutoRestart(XV_tpg *InstancePtr);

void XV_tpg_Set_height(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_height(XV_tpg *InstancePtr);
void XV_tpg_Set_width(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_width(XV_tpg *InstancePtr);
void XV_tpg_Set_bckgndId(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_bckgndId(XV_tpg *InstancePtr);
void XV_tpg_Set_motionEn(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_motionEnStatus(XV_tpg *InstancePtr);
void XV_tpg_Set_ovrlayId(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_ovrlayId(XV_tpg *InstancePtr);
void XV_tpg_Set_maskId(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_maskId(XV_tpg *InstancePtr);
void XV_tpg_Set_motionSpeed(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_motionSpeed(XV_tpg *InstancePtr);
void XV_tpg_Set_colorFormat(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_colorFormat(XV_tpg *InstancePtr);
void XV_tpg_Set_crossHairX(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_crossHairX(XV_tpg *InstancePtr);
void XV_tpg_Set_crossHairY(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_crossHairY(XV_tpg *InstancePtr);
void XV_tpg_Set_ZplateHorContStart(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_ZplateHorContStart(XV_tpg *InstancePtr);
void XV_tpg_Set_ZplateHorContDelta(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_ZplateHorContDelta(XV_tpg *InstancePtr);
void XV_tpg_Set_ZplateVerContStart(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_ZplateVerContStart(XV_tpg *InstancePtr);
void XV_tpg_Set_ZplateVerContDelta(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_ZplateVerContDelta(XV_tpg *InstancePtr);
void XV_tpg_Set_boxSize(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_boxSize(XV_tpg *InstancePtr);
void XV_tpg_Set_boxColorR(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_boxColorR(XV_tpg *InstancePtr);
void XV_tpg_Set_boxColorG(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_boxColorG(XV_tpg *InstancePtr);
void XV_tpg_Set_boxColorB(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_boxColorB(XV_tpg *InstancePtr);
void XV_tpg_Set_enableInput(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_enableInput(XV_tpg *InstancePtr);
void XV_tpg_Set_passthruStartX(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_passthruStartX(XV_tpg *InstancePtr);
void XV_tpg_Set_passthruStartY(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_passthruStartY(XV_tpg *InstancePtr);
void XV_tpg_Set_passthruEndX(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_passthruEndX(XV_tpg *InstancePtr);
void XV_tpg_Set_passthruEndY(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_passthruEndY(XV_tpg *InstancePtr);
void XV_tpg_Set_dpDynamicRange(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_dpDynamicRange(XV_tpg *InstancePtr);
void XV_tpg_Set_dpYUVCoef(XV_tpg *InstancePtr, uint32_t Data);
uint32_t XV_tpg_Get_dpYUVCoef(XV_tpg *InstancePtr);
void XV_tpg_Set_Interlaced(XV_tpg *InstancePtr, _Bool Data);
void XV_tpg_Set_Polarity(XV_tpg *InstancePtr, _Bool Data);
uint32_t XV_tpg_Get_fieldId(XV_tpg *InstancePtr);

void XV_tpg_InterruptGlobalEnable(XV_tpg *InstancePtr);
void XV_tpg_InterruptGlobalDisable(XV_tpg *InstancePtr);
void XV_tpg_InterruptEnable(XV_tpg *InstancePtr, uint32_t Mask);
void XV_tpg_InterruptDisable(XV_tpg *InstancePtr, uint32_t Mask);
void XV_tpg_InterruptClear(XV_tpg *InstancePtr, uint32_t Mask);
uint32_t XV_tpg_InterruptGetEnabled(XV_tpg *InstancePtr);
uint32_t XV_tpg_InterruptGetStatus(XV_tpg *InstancePtr);

void XVTpg_SetCallback(XV_tpg *InstancePtr, uint32_t HandlerType,
		void *CallbackFunc, void *CallbackRef);
void XVTpg_InterruptHandler(XV_tpg *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
