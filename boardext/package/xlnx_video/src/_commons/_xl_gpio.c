#include "_xl_gpio.h"
#include <stdio.h>


XGpioPs 		gpio;

/*--------------------------------------------------------------------*/
int V_GPIO_Init(XGpioPs *x_gpio,
				uintptr_t bAddress,
			 	uintptr_t x_gpio_ptr)
{
    int Status = -1;
	XGpioPs_Config		*xgpio_Config;
	xgpio_Config = XGpioPs_LookupConfig(bAddress);
	if(xgpio_Config == NULL)
	{
		printf("ERR:: GPIOs not found\r\n");
		return(XST_DEVICE_NOT_FOUND);
	}
	xgpio_Config->BaseAddr = x_gpio_ptr;
	Status = XGpioPs_CfgInitialize(x_gpio,
									xgpio_Config,
									xgpio_Config->BaseAddr);
	if(Status != XST_SUCCESS)
	{
		printf("ERR:: GPIOsInitialization failed %d\r\n", Status);
		return(XST_FAILURE);
	}
	printf("GPIOs: Initialized OK\r\n");
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------*/


/****************************************************************************/
/*
static int GpioInputExample(uint32_t *DataRead)
{

	// Set the direction for the specified pin to be input. 
	XGpioPs_SetDirectionPin(&Gpio, Input_Pin, 0x0);
	// Read the state of the data so that it can be  verified. 
	*DataRead = XGpioPs_ReadPin(&Gpio, Input_Pin);

	return XST_SUCCESS;
}
*/
/****************************************************************************/
static int V_GPIO_SetOut(XGpioPs *x_gpio,
						uint32_t oPin,
						uint32_t level)
{
	XGpioPs_SetDirectionPin(x_gpio, oPin, 1);
	XGpioPs_SetOutputEnablePin(x_gpio, oPin, 1);
	/* Set the GPIO output to be low. */
	XGpioPs_WritePin(x_gpio, oPin, level);
	return XST_SUCCESS;
}

/****************************************************************************/
int V_GPIO_SetHigh(XGpioPs *x_gpio)
{
	int Status = -1;
	uint32_t Output_Pin = 0;
	Output_Pin = GPIO_FB_RD;
	Status = V_GPIO_SetOut(x_gpio,Output_Pin,1);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	Output_Pin = GPIO_FB_WR;
	Status = V_GPIO_SetOut(x_gpio,Output_Pin,1);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	Output_Pin = GPIO_TPG_0;
	Status = V_GPIO_SetOut(x_gpio,Output_Pin,1);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	Output_Pin = GPIO_TPG_1;
	Status = V_GPIO_SetOut(x_gpio,Output_Pin,1);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//Status = GpioInputExample(DataRead);
	//if (Status != XST_SUCCESS) {
	//	return XST_FAILURE;
	//}
	return XST_SUCCESS;
}


