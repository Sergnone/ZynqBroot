#include "_xl_dynclk.h"
#include <stdio.h>

DDynClk					dClk;

/*--------------------------------------------------------------------------------*/
int V_DDYNCLK_Init(DDynClk *x_dclk,
					uintptr_t bAddress,
					uintptr_t x_dclk_ptr)
{
    int Status = -1;
	DDynClk_Config			*dCfg;
	dCfg = DDynClk_LookupConfig(0);
	if(dCfg == NULL)
	{
		printf("ERR:: DYNCLK device not found\r\n");
		return(XST_DEVICE_NOT_FOUND);
	}
	dCfg->BaseAddress = x_dclk_ptr;
	Status = DDynClk_CfgInitialize(x_dclk, dCfg, dCfg->BaseAddress);
	if(Status != XST_SUCCESS)
	{
		printf("ERR:: DYNCLK Initialization failed %d\r\n", Status);
		return(XST_FAILURE);
	}
	printf("DYNCLK: Initialized OK\r\n");
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
int V_DDYNCLK_Start(uint32_t pixelrate)
{
    int Status = -1;
	Status = DDynClk_SetRate(&dClk, pixelrate);
	if(Status != XST_SUCCESS)
	{
		printf("ERR:: DYNCLK Set Rate failed %d\r\n", Status);
		return(XST_FAILURE);
	}
    Status = DDynClk_Enable(&dClk);
	if(Status != XST_SUCCESS)
	{
		printf("ERR:: DYNCLK Enable failed %d\r\n", Status);
		return(XST_FAILURE);
	}
	printf("DYNCLK: Started OK\r\n");
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------------------*/