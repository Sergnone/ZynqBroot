#include "_xl_vmix.h"
#include <stdio.h>
#include <xv_mix_l2.h>

XV_Mix_l2           mix;


//XVMix_GetLayerColorFormat(&mix, XVMIX_LAYER_MASTER, &Cfmt);

/*--------------------------------------------------------------------*/
void V_VMIX_ConfigStream(XVidC_VideoStream *StreamPtr)
{
  XV_Mix_l2 *MixerPtr = &mix;
  int NumLayers = 0;
  int index = 0;
  XVidC_ColorFormat Cfmt;
  XVMix_LayerDisable(MixerPtr, XVMIX_LAYER_MASTER);
  XVMix_SetVidStream(MixerPtr, StreamPtr);
  NumLayers = XVMix_GetNumLayers(MixerPtr);
  for(index = XVMIX_LAYER_1; index < NumLayers; ++index)
  {
      XVMix_GetLayerColorFormat(MixerPtr, index, &Cfmt);
      XVMix_LayerDisable(MixerPtr, XVMIX_LAYER_1);
      XV_mix_Set_HwReg_layerStartX_1(&MixerPtr->Mix, 0);
      XV_mix_Set_HwReg_layerStartY_1(&MixerPtr->Mix, 0);
      XV_mix_Set_HwReg_layerWidth_1(&MixerPtr->Mix, 1920);
      XV_mix_Set_HwReg_layerHeight_1(&MixerPtr->Mix, 1080);
      XV_mix_Set_HwReg_layerAlpha_1(&MixerPtr->Mix, 0);
      XVMix_LayerEnable(MixerPtr, XVMIX_LAYER_1);
  }
  XVMix_SetBackgndColor(MixerPtr, XVMIX_BKGND_WHITE, StreamPtr->ColorDepth);
  XVMix_LayerEnable(MixerPtr, XVMIX_LAYER_MASTER);
  XVMix_InterruptDisable(MixerPtr);
  XVMix_Start(MixerPtr);
  printf("INFO: Mixer configured\r\n");
}
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
int V_VMIX_Init(XV_Mix_l2 *x_mix,
                uintptr_t bAddress,
                uintptr_t x_mix_ptr)
{
    int Status = -1;
    Status = XVMix_Initialize(x_mix, bAddress, x_mix_ptr);
    if (Status != XST_SUCCESS)
    {
        printf("ERROR:: VMIXERinitialization failed\r\n");
        return(XST_FAILURE);
    }
	  printf("VMIXER: Initialized OK\r\n");
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
int V_VMIX_Init_LL(XV_Mix_l2 *x_mix,
                uintptr_t bAddress,
                uintptr_t x_mix_ptr)
{
    int Status = -1;
    XV_mix_Config		*mix_Config;
    mix_Config = XV_mix_LookupConfig(bAddress);
    if(mix_Config == NULL)
    {
        printf("ERR:: VMIXER device not found\r\n");
        return(XST_DEVICE_NOT_FOUND);
    }
    mix_Config->BaseAddress = x_mix_ptr;
    Status = XV_mix_CfgInitialize(&x_mix->Mix,
                                  mix_Config,
                                  mix_Config->BaseAddress);
    if(Status != XST_SUCCESS)
    {
        printf("ERR:: VMIXER Initialization failed %d\r\n", Status);
        return(XST_FAILURE);
    }
    //printf("TPG: Initialized OK\r\n");
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------------------*/

