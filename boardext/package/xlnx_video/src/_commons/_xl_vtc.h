#ifndef __V_VTC_H_
#define __V_VTC_H_

#include "include/xparameters.h"
#include "drivers/v_vidc/xvidc.h"
#include "drivers/v_vtc/xvtc.h"

#include "_pl_addresses.h"

int V_VTC_Init(XVtc *x_vtc,
				uintptr_t bAddress,
			 	uintptr_t x_vtc_ptr);
void V_VTC_Config(XVidC_VideoMode videoMode, uint16_t pixClock);
void V_VTC_ConfigStream(XVidC_VideoStream *StreamPtr);

#endif