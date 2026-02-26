// ==============================================================
// Copyright (c) 2015 - 2021 Xilinx Inc. All rights reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// SPDX-License-Identifier: MIT
// ==============================================================

#include "xstatus.h"
#include "xv_tpg.h"

#ifndef XPAR_XV_TPG_NUM_INSTANCES
#define XPAR_XV_TPG_NUM_INSTANCES   0
#endif

extern XV_tpg_Config XV_tpg_ConfigTable[];

XV_tpg_Config *XV_tpg_LookupConfig(uint32_t BaseAddress) {
	XV_tpg_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0U; XV_tpg_ConfigTable[Index].Name != NULL; Index++) {
		if ((XV_tpg_ConfigTable[Index].BaseAddress == BaseAddress) ||
			!BaseAddress) {
			ConfigPtr = &XV_tpg_ConfigTable[Index];
		break;
		}
	}

	return ConfigPtr;
}

int XV_tpg_Initialize(XV_tpg *InstancePtr, uint32_t BaseAddress) {
	XV_tpg_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XV_tpg_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XV_tpg_CfgInitialize(InstancePtr,
                                ConfigPtr,
                                ConfigPtr->BaseAddress);
}
