// ==============================================================
// Copyright (c) 1986 - 2022 Xilinx Inc. All rights reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// SPDX-License-Identifier: MIT
// ==============================================================

/**
*
* @file xv_mix.h
* @addtogroup v_mix Overview
*/

#ifndef XV_MIX_H
#define XV_MIX_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "../../include/xil_types.h"
#include "../../include/xil_assert.h"
#include "../../include/xstatus.h"
#include "../../include/xil_io.h"
#include "xv_mix_hw.h"

/**************************** Type Definitions ******************************/

#define XV_MIX_MAX_MEMORY_LAYERS    (16)

/**
* This typedef contains Alpha feature enable flag per memory layer
*/
typedef struct {
  uint8_t  Layer1AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer2AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer3AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer4AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer5AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer6AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer7AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer8AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer9AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer10AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer11AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer12AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer13AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer14AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer15AlphaEn;     /**< Layer Alpha support indicator flag  */
  uint8_t  Layer16AlphaEn;     /**< Layer Alpha support indicator flag  */
}XVMix_AlphaFlag;

/**
* This typedef contains Scaling feature enable flag per memory layer
*/
typedef struct {
  uint8_t  Layer1ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer2ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer3ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer4ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer5ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer6ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer7ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer8ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer9ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer10ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer11ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer12ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer13ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer14ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer15ScalingEn;  /**< Layer scaling support indicator flag  */
  uint8_t  Layer16ScalingEn;  /**< Layer scaling support indicator flag  */
}XVMix_ScaleFlag;

/**
* This typedef contains Interface Type per layer
*/
typedef struct {
  uint8_t  Layer1IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer2IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer3IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer4IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer5IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer6IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer7IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer8IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer9IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer10IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer11IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer12IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer13IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer14IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer15IntfType;  /**< Layer Interface type (Memory/Stream)  */
  uint8_t  Layer16IntfType;  /**< Layer Interface type (Memory/Stream)  */
}XVMix_LayerIntfType;

/**
* This typedef contains color format per memory layer
*/
typedef struct {
  uint8_t  Layer1ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer2ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer3ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer4ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer5ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer6ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer7ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer8ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer9ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer10ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer11ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer12ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer13ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer14ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer15ColorFmt;  /**< Layer Video Color Format  */
  uint8_t  Layer16ColorFmt;  /**< Layer Video Color Format  */
}XVMix_LayerColorFormat;

/**
* This typedef contains maximum width per memory layer
*/
typedef struct {
  uint16_t Layer1MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer2MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer3MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer4MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer5MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer6MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer7MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer8MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer9MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer10MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer11MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer12MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer13MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer14MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer15MaxWidth;    /**< Layer maximum column width  */
  uint16_t Layer16MaxWidth;    /**< Layer maximum column width  */
}XVMix_LayerMaxWidth;

/**
* This typedef contains configuration information for the mixer core
* Each core instance should have a configuration structure associated.
*/
typedef struct {
  char *Name;
  uintptr_t BaseAddress;   /**< The base address of the core instance. */
  uint16_t PixPerClk;         /**< Samples Per Clock supported by core instance */
  uint16_t MaxWidth;          /**< Maximum columns supported by core instance */
  uint16_t MaxHeight;         /**< Maximum rows supported by core instance */
  uint16_t MaxDataWidth;      /**< Maximum Data width of each channel */
  uint16_t ColorFormat;       /**< Master layer color format */
  uint8_t  NumLayers;         /**< Number of layers supported */
  uint8_t  LogoEn;            /**< Logo layer support indicator flag  */
  uint16_t MaxLogoWidth;      /**< Maximum columns supported by log layer */
  uint16_t MaxLogoHeight;     /**< Maximum rows supported by log layer */
  uint16_t LogoColorKeyEn;    /**< Logo layer color key feature indicator flag */
  uint16_t LogoPixAlphaEn;    /**< Logo layer per pixel alpha feature indicator flag */
  uint16_t CscCoeffsRegsEn;   /**< CSC coefficients registers enable flag */
  union {                /**< Alpha feature enable flag per memory layer */
	  XVMix_AlphaFlag AlphaFlag;
	  uint8_t AlphaEn[XV_MIX_MAX_MEMORY_LAYERS];
  };
  union {                /**< Scaling feature enable flag per memory layer */
	  XVMix_ScaleFlag ScaleFlag;
	  uint8_t ScalingEn[XV_MIX_MAX_MEMORY_LAYERS];
  };
  union {                /**< Maximum width per memory layer */
	  XVMix_LayerMaxWidth LyrMaxWidth;
	  uint16_t LayerMaxWidth[XV_MIX_MAX_MEMORY_LAYERS];
  };
  union {                /**< Layer Interface Type */
	  XVMix_LayerIntfType LyrIntfType;
	  uint8_t LayerIntrfType[XV_MIX_MAX_MEMORY_LAYERS];
  };
  union {                /**< Layer Interface Type */
	  XVMix_LayerColorFormat LyrColorFmt;
	  uint8_t LayerColorFmt[XV_MIX_MAX_MEMORY_LAYERS];
  };
  uint16_t IsTileFormat; 	/**< Tile format support indicator flag */
  uint16_t IntrId; 		    /**< Interrupt ID */
  uintptr_t IntrParent;	/**< Bit[0] Interrupt parent type Bit[64/32:1] Parent base address */
} XV_mix_Config;



/**
* Driver instance data. An instance must be allocated for each core in use.
*/
typedef struct {
  XV_mix_Config Config;  /**< Hardware Configuration */
  uint32_t IsReady;           /**< Device is initialized and ready */
} XV_mix;

/***************** Macros (Inline Functions) Definitions *********************/
#define XV_mix_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (uint32_t)(Data))
#define XV_mix_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))


/************************** Function Prototypes *****************************/
int XV_mix_Initialize(XV_mix *InstancePtr,
                      uintptr_t BaseAddress,
                      uintptr_t remapAddress);
XV_mix_Config* XV_mix_LookupConfig(uintptr_t BaseAddress);
int XV_mix_CfgInitialize(XV_mix *InstancePtr,
		                 XV_mix_Config *ConfigPtr,
						 uintptr_t EffectiveAddr);

void XV_mix_Start(XV_mix *InstancePtr);
uint32_t XV_mix_IsDone(XV_mix *InstancePtr);
uint32_t XV_mix_IsIdle(XV_mix *InstancePtr);
uint32_t XV_mix_IsReady(XV_mix *InstancePtr);
void XV_mix_EnableAutoRestart(XV_mix *InstancePtr);
void XV_mix_DisableAutoRestart(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_width(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_width(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_height(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_height(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_video_format(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_video_format(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_background_Y_R(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_background_Y_R(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_background_U_G(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_background_U_G(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_background_V_B(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_background_V_B(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerEnable(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerEnable(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_0(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_0(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_1(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_1(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer1_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer1_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer1_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer1_buf2_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_2(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_2(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer2_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer2_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer2_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer2_buf2_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_3(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_3(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer3_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer3_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer3_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer3_buf2_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_4(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_4(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer4_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer4_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer4_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer4_buf2_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_5(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_5(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer5_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer5_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer5_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer5_buf2_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_6(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_6(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer6_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer6_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer6_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer6_buf2_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerAlpha_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_7(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_7(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer7_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer7_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer7_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer7_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_8(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_8(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer8_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer8_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer8_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer8_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_9(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_9(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer9_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer9_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer9_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer9_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_10(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_10(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer10_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer10_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer10_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer10_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_11(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_11(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer11_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer11_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer11_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer11_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_12(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_12(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer12_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer12_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer12_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer12_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_13(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_13(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer13_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer13_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer13_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer13_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_14(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_14(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer14_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer14_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer14_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer14_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_15(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_15(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer15_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer15_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer15_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer15_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_layerAlpha_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerAlpha_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartX_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartX_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStartY_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStartY_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerWidth_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerWidth_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerStride_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerStride_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerHeight_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerHeight_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerScaleFactor_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerScaleFactor_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layerVideoFormat_16(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_layerVideoFormat_16(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer16_buf1_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer16_buf1_V(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_layer16_buf2_V(XV_mix *InstancePtr, uint64_t Data);
uint64_t XV_mix_Get_HwReg_layer16_buf2_V(XV_mix *InstancePtr);

void XV_mix_Set_HwReg_reserve(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_reserve(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoStartX(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoStartX(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoStartY(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoStartY(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoWidth(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoWidth(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoHeight(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoHeight(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoScaleFactor(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoScaleFactor(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoAlpha(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoAlpha(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoClrKeyMin_R(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoClrKeyMin_R(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoClrKeyMin_G(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoClrKeyMin_G(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoClrKeyMin_B(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoClrKeyMin_B(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoClrKeyMax_R(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoClrKeyMax_R(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoClrKeyMax_G(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoClrKeyMax_G(XV_mix *InstancePtr);
void XV_mix_Set_HwReg_logoClrKeyMax_B(XV_mix *InstancePtr, uint32_t Data);
uint32_t XV_mix_Get_HwReg_logoClrKeyMax_B(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoR_V_BaseAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoR_V_HighAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoR_V_TotalBytes(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoR_V_BitWidth(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoR_V_Depth(XV_mix *InstancePtr);
uint32_t XV_mix_Write_HwReg_logoR_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Read_HwReg_logoR_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Write_HwReg_logoR_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);
uint32_t XV_mix_Read_HwReg_logoR_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);
uint32_t XV_mix_Get_HwReg_logoG_V_BaseAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoG_V_HighAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoG_V_TotalBytes(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoG_V_BitWidth(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoG_V_Depth(XV_mix *InstancePtr);
uint32_t XV_mix_Write_HwReg_logoG_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Read_HwReg_logoG_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Write_HwReg_logoG_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);
uint32_t XV_mix_Read_HwReg_logoG_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);
uint32_t XV_mix_Get_HwReg_logoB_V_BaseAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoB_V_HighAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoB_V_TotalBytes(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoB_V_BitWidth(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoB_V_Depth(XV_mix *InstancePtr);
uint32_t XV_mix_Write_HwReg_logoB_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Read_HwReg_logoB_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Write_HwReg_logoB_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);
uint32_t XV_mix_Read_HwReg_logoB_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);
uint32_t XV_mix_Get_HwReg_logoA_V_BaseAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoA_V_HighAddress(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoA_V_TotalBytes(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoA_V_BitWidth(XV_mix *InstancePtr);
uint32_t XV_mix_Get_HwReg_logoA_V_Depth(XV_mix *InstancePtr);
uint32_t XV_mix_Write_HwReg_logoA_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Read_HwReg_logoA_V_Words(XV_mix *InstancePtr, int offset, int *data, int length);
uint32_t XV_mix_Write_HwReg_logoA_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);
uint32_t XV_mix_Read_HwReg_logoA_V_Bytes(XV_mix *InstancePtr, int offset, char *data, int length);

void XV_mix_InterruptGlobalEnable(XV_mix *InstancePtr);
void XV_mix_InterruptGlobalDisable(XV_mix *InstancePtr);
void XV_mix_InterruptEnable(XV_mix *InstancePtr, uint32_t Mask);
void XV_mix_InterruptDisable(XV_mix *InstancePtr, uint32_t Mask);
void XV_mix_InterruptClear(XV_mix *InstancePtr, uint32_t Mask);
uint32_t XV_mix_InterruptGetEnabled(XV_mix *InstancePtr);
uint32_t XV_mix_InterruptGetStatus(XV_mix *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
