#include "_xl_vtc.h"

XVtc				vtc;
XVtc_Config			*vtc_Config;
XVtc_Timing			vtc_timing;


int V_VTC_Init(void)
{
    int Status = -1;
	vtc_Config = XVtc_LookupConfig((uint32_t)XPAR_V_TC_0_BASEADDR);
	if(vtc_Config == NULL)
	{
		printf("ERR:: VTC device not found\r\n");
		return(XST_DEVICE_NOT_FOUND);
	}
	Status = XVtc_CfgInitialize(&vtc, vtc_Config, vtc_Config->BaseAddress);
	if(Status != XST_SUCCESS)
	{
		printf("ERR:: VTC Initialization failed %d\r\n", Status);
		return(XST_FAILURE);
	}
    return(XST_SUCCESS);
}


void V_VTC_Config(XVidC_VideoMode videoMode, uint16_t pixClock)
{
	XVidC_VideoTiming const *timing = XVidC_GetTimingInfo(videoMode);
	vtc_timing.HActiveVideo  = timing->HActive/pixClock;
	vtc_timing.HFrontPorch   = timing->HFrontPorch/pixClock;
	vtc_timing.HSyncWidth    = timing->HSyncWidth/pixClock;
	vtc_timing.HBackPorch    = timing->HBackPorch/pixClock;
	vtc_timing.HSyncPolarity = timing->HSyncPolarity;
	vtc_timing.VActiveVideo  = timing->VActive;
	vtc_timing.V0FrontPorch  = timing->F0PVFrontPorch;
	vtc_timing.V0SyncWidth   = timing->F0PVSyncWidth;
	vtc_timing.V0BackPorch   = timing->F0PVBackPorch;
	vtc_timing.VSyncPolarity = timing->VSyncPolarity;
	XVtc_SetGeneratorTiming(&vtc, &vtc_timing);
	XVtc_Enable(&vtc);
	XVtc_EnableGenerator(&vtc);
	XVtc_RegUpdateEnable(&vtc);
}



void V_VTC_ConfigStream(XVidC_VideoStream *StreamPtr)
{
  XVtc_Timing vtc_timing = {0};
  uint16_t PixelsPerClock = StreamPtr->PixPerClk;
  vtc_timing.HActiveVideo  = StreamPtr->Timing.HActive/PixelsPerClock;
  vtc_timing.HFrontPorch   = StreamPtr->Timing.HFrontPorch/PixelsPerClock;
  vtc_timing.HSyncWidth    = StreamPtr->Timing.HSyncWidth/PixelsPerClock;
  vtc_timing.HBackPorch    = StreamPtr->Timing.HBackPorch/PixelsPerClock;
  vtc_timing.HSyncPolarity = StreamPtr->Timing.HSyncPolarity;
  vtc_timing.VActiveVideo  = StreamPtr->Timing.VActive;
  vtc_timing.V0FrontPorch  = StreamPtr->Timing.F0PVFrontPorch;
  vtc_timing.V0SyncWidth   = StreamPtr->Timing.F0PVSyncWidth;
  vtc_timing.V0BackPorch   = StreamPtr->Timing.F0PVBackPorch;
  vtc_timing.VSyncPolarity = StreamPtr->Timing.VSyncPolarity;
  XVtc_SetGeneratorTiming(&vtc, &vtc_timing);
  XVtc_Enable(&vtc);
  XVtc_EnableGenerator(&vtc);
  XVtc_RegUpdateEnable(&vtc);
  printf("INFO: VTC configured\r\n");
}