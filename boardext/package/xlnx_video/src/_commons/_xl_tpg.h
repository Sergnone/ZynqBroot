#ifndef __V_TPG_H_
#define __V_TPG_H_

#include "../../include/xparameters.h"
#include "drivers/v_tpg/xv_tpg.h"
#include "drivers/v_vidc/xvidc.h"
#include "_pl_addresses.h"
#include "include/xstatus.h"

int V_TPG_Init(XV_tpg *x_tpg,
				uintptr_t bAddress,
			 	uintptr_t x_tpg_ptr);
uint16_t V_TPG_ConfigStream(XV_tpg *tpg,
							XVidC_VideoStream *StreamPtr);
//int V_TPG_Clock_Config(XVidC_VideoMode videoMode);

#endif