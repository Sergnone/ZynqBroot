// ==============================================================
// Copyright (c) 1986 - 2023 Xilinx Inc. All rights reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// SPDX-License-Identifier: MIT
// ==============================================================

#ifndef XV_FRMBUFWR_H
#define XV_FRMBUFWR_H

#ifdef __cplusplus
extern "C" {
#endif
/**
 * *
* @file xv_frmbufwr.h
* @addtogroup v_frmbuf_wr Overview
*
**/
/***************************** Include Files *********************************/
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#include "xv_frmbufwr_hw.h"
#include "../../include/xil_io.h"
#include "../../include/xstatus.h"

/**************************** Type Definitions ******************************/
/**
* This typedef contains configuration information for the frame buffer write core
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
  uint16_t BGRA8En;              /**< YUVA8      support */
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
  uint16_t Y_U_V8En;             /**< Y_U_V8   support */
  uint16_t Y_U_V10En;            /**< Y_U_V10   support */
  uint16_t Y_U_V8_420En;         /**< Y_U_V8_420   support */
  uint16_t Y_U_V12En;            /**< Y_U_V12   support */
  uint16_t Interlaced;           /**< Interlaced support */
  uint16_t IsTileFormat;         /**< Tile format support */
  uint16_t EnSyncSignals;        /**< Low latency support */
  uint16_t IntrId; 		    /**< Interrupt ID */
  uintptr_t IntrParent; 	    /**< Bit[0] Interrupt parent type Bit[64/32:1] Parent base address */
} XV_frmbufwr_Config;

/**
* Driver instance data. An instance must be allocated for each core in use.
*/
typedef struct {
  XV_frmbufwr_Config Config;   /**< Hardware Configuration */
  uint32_t IsReady;                  /**< Device is initialized and ready */
} XV_frmbufwr;

/***************** Macros (Inline Functions) Definitions *********************/
#define XV_frmbufwr_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (uint32_t)(Data))
#define XV_frmbufwr_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))

/************************** Function Prototypes *****************************/
//int XV_frmbufwr_Initialize(XV_frmbufwr *InstancePtr, uintptr_t BaseAddress);
int XV_frmbufwr_Initialize(XV_frmbufwr *InstancePtr,
                            uintptr_t BaseAddress,
                            uintptr_t remapAddress);
XV_frmbufwr_Config* XV_frmbufwr_LookupConfig(uintptr_t BaseAddress);
int XV_frmbufwr_CfgInitialize(XV_frmbufwr *InstancePtr,
                               XV_frmbufwr_Config *ConfigPtr,
                               uintptr_t EffectiveAddr);


void XV_frmbufwr_Start(XV_frmbufwr *InstancePtr);
uint32_t XV_frmbufwr_IsDone(XV_frmbufwr *InstancePtr);
uint32_t XV_frmbufwr_IsIdle(XV_frmbufwr *InstancePtr);
uint32_t XV_frmbufwr_IsReady(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_EnableAutoRestart(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_DisableAutoRestart(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_SetFlushbit(XV_frmbufwr *InstancePtr);
uint32_t XV_frmbufwr_Get_FlushDone(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_Set_HwReg_width(XV_frmbufwr *InstancePtr, uint32_t Data);
uint32_t XV_frmbufwr_Get_HwReg_width(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_Set_HwReg_height(XV_frmbufwr *InstancePtr, uint32_t Data);
uint32_t XV_frmbufwr_Get_HwReg_height(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_Set_HwReg_stride(XV_frmbufwr *InstancePtr, uint32_t Data);
uint32_t XV_frmbufwr_Get_HwReg_stride(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_Set_HwReg_video_format(XV_frmbufwr *InstancePtr, uint32_t Data);
uint32_t XV_frmbufwr_Get_HwReg_video_format(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_Set_HwReg_frm_buffer_V(XV_frmbufwr *InstancePtr, uint64_t Data);
uint64_t XV_frmbufwr_Get_HwReg_frm_buffer_V(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_Set_HwReg_frm_buffer2_V(XV_frmbufwr *InstancePtr, uint64_t Data);
uint64_t XV_frmbufwr_Get_HwReg_frm_buffer2_V(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_Set_HwReg_frm_buffer3_V(XV_frmbufwr *InstancePtr, uint64_t Data);
uint64_t XV_frmbufwr_Get_HwReg_frm_buffer3_V(XV_frmbufwr *InstancePtr);
uint32_t XV_frmbufwr_Get_HwReg_field_id(XV_frmbufwr *InstancePtr);

void XV_frmbufwr_InterruptGlobalEnable(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_InterruptGlobalDisable(XV_frmbufwr *InstancePtr);
void XV_frmbufwr_InterruptEnable(XV_frmbufwr *InstancePtr, uint32_t Mask);
void XV_frmbufwr_InterruptDisable(XV_frmbufwr *InstancePtr, uint32_t Mask);
void XV_frmbufwr_InterruptClear(XV_frmbufwr *InstancePtr, uint32_t Mask);
uint32_t XV_frmbufwr_InterruptGetEnabled(XV_frmbufwr *InstancePtr);
uint32_t XV_frmbufwr_InterruptGetStatus(XV_frmbufwr *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
