#ifndef __V_VTC_H_
#define __V_VTC_H_

#include "xparameters.h"
#include "v_vidc/xvidc.h"
#include "v_vtc/xvtc.h"

#include "_pl_addresses.h"

int V_VTC_Init(void);
void V_VTC_Config(XVidC_VideoMode videoMode, uint16_t pixClock);
void V_VTC_ConfigStream(XVidC_VideoStream *StreamPtr);

#endif