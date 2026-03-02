#ifndef __V_DDYNCLK_H_
#define __V_DDYNCLK_H_

#include "drivers/v_dynclk/ddynclk.h"

//#define DYNCLK_BASEADDR XPAR_DYNCLK_0_S_AXI_LITE_BASEADDR 

int V_DDYNCLK_Init(DDynClk *x_dclk,
					uintptr_t bAddress,
					uintptr_t x_dclk_ptr);
int V_DDYNCLK_Start(uint32_t pixelrate);

#endif /* DYNCLK_H_ */
