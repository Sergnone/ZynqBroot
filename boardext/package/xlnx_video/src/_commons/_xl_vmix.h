#ifndef __V_VMIX_H_
#define __V_VMIX_H_

#include "../include/xparameters.h"
#include "../include/xstatus.h"
#include "../drivers/v_mix/xv_mix_l2.h"
#include "../drivers/v_vidc/xvidc.h"
#include "../drivers/v_mix/xv_mix.h"
#include "_pl_addresses.h"

int V_VMIX_Init(XV_Mix_l2 *x_mix,
                uintptr_t bAddress,
                uintptr_t x_mix_ptr);
int V_VMIX_Init_LL(XV_Mix_l2 *x_mix,
                uintptr_t bAddress,
                uintptr_t x_mix_ptr);
void V_VMIX_ConfigStream(XVidC_VideoStream *StreamPtr);

#endif