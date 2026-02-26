// ==============================================================
// Copyright (c) 1986 - 2023 Xilinx Inc. All rights reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// SPDX-License-Identifier: MIT
// ==============================================================

/**
*
* @file xv_frmbufrd.h
* @addtogroup v_frmbuf_rd Overview
*/
#ifndef XV_FRMBUFRD_H
#define XV_FRMBUFRD_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"

#include "xv_frmbufrd_hw.h"

/**************************** Type Definitions ******************************/

/**
* This typedef contains configuration information for the frame buffer read core
* Each core instance should have a configuration structure associated.
*/
typedef struct {
  char *Name;		    /**< Unique Name of device */
  uintptr_t BaseAddress;      /**< The base address of the core instance. */
  uint16_t PixPerClk;            /**< Samples Per Clock */
  uint16_t MaxWidth;             /**< Maximum columns supported by core instance */
  uint16_t MaxHeight;            /**< Maximum rows supported by core instance */
  uint16_t MaxDataWidth;         /**< Maximum Data width of each channel */
  uint16_t AXIMMDataWidth;       /**< AXI-MM data width */
  uint16_t AXIMMAddrWidth;       /**< AXI-MM address width */
  uint16_t RGBX8En;              /**< RGBX8      support */
  uint16_t YUVX8En;              /**< YUVX8      support */
  uint16_t YUYV8En;              /**< YUYV8      support */
  uint16_t RGBA8En;              /**< RGBA8      support */
  uint16_t YUVA8En;              /**< YUVA8      support */
  uint16_t RGBX10En;             /**< RGBX10     support */
  uint16_t YUVX10En;             /**< YUVX10     support */
  uint16_t Y_UV8En;              /**< Y_UV8      support */
  uint16_t Y_UV8_420En;          /**< Y_UV8_420  support */
  uint16_t RGB8En;               /**< RGB8       support */
  uint16_t YUV8En;               /**< YUV8       support */
  uint16_t Y_UV10En;             /**< Y_UV10     support */
  uint16_t Y_UV10_420En;         /**< Y_UV10_420 support */
  uint16_t Y8En;                 /**< Y8         support */
  uint16_t Y10En;                /**< Y10        support */
  uint16_t BGRA8En;              /**< BGRA8      support */
  uint16_t BGRX8En;              /**< BGRX8      support */
  uint16_t UYVY8En;              /**< UYVY8      support */
  uint16_t BGR8En;               /**< BGR8       support */
  uint16_t RGBX12En;             /**< RGBX12     support */
  uint16_t RGB16En;              /**< RGB16      support */
  uint16_t YUVX12En;             /**< YUVX12     support */
  uint16_t Y_UV12En;             /**< Y_UV12     support */
  uint16_t Y_UV12_420En;         /**< Y_UV12_420 support */
  uint16_t Y12En;                /**< Y12      support */
  uint16_t YUV16En;              /**< YUV16      support */
  uint16_t Y_UV16En;             /**< Y_UV16     support */
  uint16_t Y_UV16_420En;         /**< Y_UV16_420 support */
  uint16_t Y16En;                /**< Y16      support */
  uint16_t Y_U_V8En;             /**< Y_U_V8 support */
  uint16_t Y_U_V10En;            /**< Y_U_V10 support */
  uint16_t Y_U_V8_420En;         /**< Y_U_V8_420   support */
  uint16_t Y_U_V12En;            /**< Y_U_V12 support */
  uint16_t Interlaced;           /**< Interlaced support */
  uint16_t IsTileFormat;           /**< Tile format support */
  uint16_t IntrId; 		    /**< Interrupt ID */
  uintptr_t IntrParent; 	    /**< Bit[0] Interrupt parent type Bit[64/32:1] Parent base address */
} XV_frmbufrd_Config;


/**
* Driver instance data. An instance must be allocated for each core in use.
*/
typedef struct {
  XV_frmbufrd_Config Config;    /**< Hardware Configuration */
  uint32_t IsReady;                  /**< Device is initialized and ready */
} XV_frmbufrd;

/***************** Macros (Inline Functions) Definitions *********************/
#define XV_frmbufrd_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (uint32_t)(Data))
#define XV_frmbufrd_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))


/************************** Function Prototypes *****************************/
int XV_frmbufrd_Initialize(XV_frmbufrd *InstancePtr, uintptr_t BaseAddress);
XV_frmbufrd_Config* XV_frmbufrd_LookupConfig(uintptr_t BaseAddress);
int XV_frmbufrd_CfgInitialize(XV_frmbufrd *InstancePtr,
                               XV_frmbufrd_Config *ConfigPtr,
                               uintptr_t EffectiveAddr);


void XV_frmbufrd_Start(XV_frmbufrd *InstancePtr);
uint32_t XV_frmbufrd_IsDone(XV_frmbufrd *InstancePtr);
uint32_t XV_frmbufrd_IsIdle(XV_frmbufrd *InstancePtr);
uint32_t XV_frmbufrd_IsReady(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_EnableAutoRestart(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_DisableAutoRestart(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_SetFlushbit(XV_frmbufrd *InstancePtr);
uint32_t XV_frmbufrd_Get_FlushDone(XV_frmbufrd *InstancePtr);

void XV_frmbufrd_Set_HwReg_width(XV_frmbufrd *InstancePtr, uint32_t Data);
uint32_t XV_frmbufrd_Get_HwReg_width(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_height(XV_frmbufrd *InstancePtr, uint32_t Data);
uint32_t XV_frmbufrd_Get_HwReg_height(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_stride(XV_frmbufrd *InstancePtr, uint32_t Data);
uint32_t XV_frmbufrd_Get_HwReg_stride(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_video_format(XV_frmbufrd *InstancePtr, uint32_t Data);
uint32_t XV_frmbufrd_Get_HwReg_video_format(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_frm_buffer_V(XV_frmbufrd *InstancePtr, uint64_t Data);
uint64_t XV_frmbufrd_Get_HwReg_frm_buffer_V(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_frm_buffer2_V(XV_frmbufrd *InstancePtr, uint64_t Data);
uint64_t XV_frmbufrd_Get_HwReg_frm_buffer2_V(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_frm_buffer3_V(XV_frmbufrd *InstancePtr, uint64_t Data);
uint64_t XV_frmbufrd_Get_HwReg_frm_buffer3_V(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_field_id(XV_frmbufrd *InstancePtr, uint32_t Data);
uint32_t XV_frmbufrd_Get_HwReg_field_id(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_Set_HwReg_fidOutMode(XV_frmbufrd *InstancePtr, uint32_t Data);
uint32_t XV_frmbufrd_Get_HwReg_fidOutMode(XV_frmbufrd *InstancePtr);
uint32_t XV_frmbufrd_Get_HwReg_fid_error(XV_frmbufrd *InstancePtr);
uint32_t XV_frmbufrd_Get_HwReg_field_out(XV_frmbufrd *InstancePtr);

void XV_frmbufrd_InterruptGlobalEnable(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_InterruptGlobalDisable(XV_frmbufrd *InstancePtr);
void XV_frmbufrd_InterruptEnable(XV_frmbufrd *InstancePtr, uint32_t Mask);
void XV_frmbufrd_InterruptDisable(XV_frmbufrd *InstancePtr, uint32_t Mask);
void XV_frmbufrd_InterruptClear(XV_frmbufrd *InstancePtr, uint32_t Mask);
uint32_t XV_frmbufrd_InterruptGetEnabled(XV_frmbufrd *InstancePtr);
uint32_t XV_frmbufrd_InterruptGetStatus(XV_frmbufrd *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
