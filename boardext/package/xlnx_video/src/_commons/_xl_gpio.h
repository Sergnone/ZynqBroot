#ifndef __V_GPIO_H_
#define __V_GPIO_H_

#include "include/xparameters.h"
//#include "platform.h"
#include "drivers/v_gpiops/xgpiops.h"

#define   GPIO_FB_RD            54;
#define   GPIO_FB_WR            55;
#define   GPIO_TPG_0            56;
#define   GPIO_TPG_1            57;

int V_GPIO_Init(XGpioPs *x_gpio,
				uintptr_t bAddress,
			 	uintptr_t x_gpio_ptr);
int V_GPIO_SetHigh(XGpioPs *x_gpio);
#endif