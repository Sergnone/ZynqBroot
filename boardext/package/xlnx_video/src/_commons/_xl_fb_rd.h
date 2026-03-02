#ifndef __V_FBRD_H_
#define __V_FBRD_H_

#include "include/xparameters.h"
//#include "platform.h"
//#include "sleep.h"
#include "xinterrupt_wrap.h"
#include "drivers/v_frmbuf_rd/xv_frmbufrd_l2.h"
#include "xvidc.h"
#include "_pl_addresses.h"

int V_FBRD_Init(XV_FrmbufRd_l2 *x_fb,
                uintptr_t bAddress,
                uintptr_t x_fb_ptr);
int V_FBRD_SetupInterrupts(void);
int V_FBRD_SetCallback(void);
uint32_t V_FBRD_CalcStride(XVidC_ColorFormat Cfmt,
                            uint16_t AXIMMDataWidth,
                            XVidC_VideoStream *StreamPtr);
int V_FBRD_ConfigBuf(uint32_t StrideInBytes,
                       XVidC_ColorFormat Cfmt,
                       XVidC_VideoStream *StreamPtr);

#endif
