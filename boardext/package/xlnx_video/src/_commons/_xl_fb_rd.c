#include "_xl_fb_rd.h"

XV_FrmbufRd_l2          frmbufrd;

/*--------------------------------------------------------------------------------*/
/*
void *XVFrameBufferRdCallback(void *data)
{
	printf("\nFrame Buffer Read interrupt received.\r\n");
	XVFrmbufRd_Start(&frmbufrd);
}
*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
int V_FBRD_Init(XV_FrmbufRd_l2 *x_fb,
                uintptr_t bAddress,
                uintptr_t x_fb_ptr)
{
    int Status = -1;
    Status = XVFrmbufRd_Initialize(x_fb, bAddress, x_fb_ptr);
    if (Status != XST_SUCCESS) {
        printf("ERROR:: Frame Buffer Read initialization failed\r\n");
        return(XST_FAILURE);
    }
	  printf("FBRD: Initialized OK\r\n");
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
int V_FBRD_SetupInterrupts(void)
{
    int Status = -1;
    Status = XSetupInterruptSystem(&frmbufrd,&XVFrmbufRd_InterruptHandler,
                        frmbufrd.FrmbufRd.Config.IntrId,
                        frmbufrd.FrmbufRd.Config.IntrParent,
                        XINTERRUPT_DEFAULT_PRIORITY);
    if (Status == XST_FAILURE) {
        printf("ERROR:: frmbufrd Interrupt Setup Failed\r\n");
        printf("ERROR:: Test could not be completed\r\n");
        return(1);
    }
    printf("FBRD: Setup Interrupts OK\r\n");
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
int V_FBRD_SetCallback(void)
{
    /*
    XVFrmbufRd_SetCallback(&frmbufrd,
                            XVFRMBUFRD_HANDLER_DONE,
                            XVFrameBufferRdCallback,
		                    (void *)&frmbufrd);
    printf("FBRD: Set Callbacks OK\r\n");
    */
    return(XST_SUCCESS);
}
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
uint32_t V_FBRD_CalcStride(XVidC_ColorFormat Cfmt,
                            uint16_t AXIMMDataWidth,
                            XVidC_VideoStream *StreamPtr)
{
    uint32_t stride;
    int width = StreamPtr->Timing.HActive;
    uint16_t MMWidthBytes = AXIMMDataWidth/8;
    uint8_t bpp_numerator;
    uint8_t bpp_denominator = 1;

    switch (Cfmt) {
        case XVIDC_CSF_MEM_Y_UV10:
        case XVIDC_CSF_MEM_Y_UV10_420:
        case XVIDC_CSF_MEM_Y10:
        /* 4 bytes per 3 pixels (Y_UV10, Y_UV10_420, Y10) */
        bpp_numerator = 4;
        bpp_denominator = 3;
        break;
        case XVIDC_CSF_MEM_Y_UV8:
        case XVIDC_CSF_MEM_Y_UV8_420:
        case  XVIDC_CSF_MEM_Y8:
        case  XVIDC_CSF_MEM_Y_U_V8:
        case  XVIDC_CSF_MEM_Y_U_V10:
        /* 1 byte per pixel (Y_UV8, Y_UV8_420, Y8, Y_U_V10) */
        bpp_numerator = 1;
        break;
        case XVIDC_CSF_MEM_RGB8:
        case  XVIDC_CSF_MEM_YUV8:
        case XVIDC_CSF_MEM_BGR8:
        /* 3 bytes per pixel (RGB8, YUV8, BGR8) */
        bpp_numerator = 3;
        break;
        case XVIDC_CSF_MEM_RGBX12:
        case  XVIDC_CSF_MEM_YUVX12:
        /* 5 bytes per pixel (RGBX12, YUVX12) */
        bpp_numerator = 5;
        break;
        case XVIDC_CSF_MEM_Y_UV12:
        case  XVIDC_CSF_MEM_Y_UV12_420:
        case XVIDC_CSF_MEM_Y12:
        /* 3 bytes per 2 pixels (Y_UV12, Y_UV12_420, Y12) */
        bpp_numerator = 3;
        bpp_denominator = 2;
        break;
        case XVIDC_CSF_MEM_RGB16:
        case XVIDC_CSF_MEM_YUV16:
        /* 6 bytes per pixel (RGB16, YUV16) */
        bpp_numerator = 6;
        break;
        case XVIDC_CSF_MEM_YUYV8:
        case XVIDC_CSF_MEM_UYVY8:
        case XVIDC_CSF_MEM_Y_UV16:
        case XVIDC_CSF_MEM_Y_UV16_420:
        case XVIDC_CSF_MEM_Y16:
        /* 2 bytes per pixel (YUYV8, UYVY8, Y_UV16, Y_UV16_420, Y16) */
        bpp_numerator = 2;
        break;
        default:
        /* 4 bytes per pixel */
        bpp_numerator = 4;
    }
    stride = ((((width * bpp_numerator) / bpp_denominator) +
    MMWidthBytes - 1) / MMWidthBytes) * MMWidthBytes;

    return(stride);
}

/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
int V_FBRD_ConfigBuf(uint32_t StrideInBytes,
                        XVidC_ColorFormat Cfmt,
                        XVidC_VideoStream *StreamPtr)
{
    int Status;

    /* Stop Frame Buffers */
    //XVFrmbufRd_Stop(&frmbufrd);
    //XVFrmbufWr_Stop(&frmbufwr);
    //resetIp();
    //XVFrmbufWr_WaitForIdle(&frmbufwr);
    XVFrmbufRd_WaitForIdle(&frmbufrd);

    /* Configure Frame Buffers */
    Status = XVFrmbufRd_SetMemFormat(&frmbufrd, StrideInBytes, Cfmt, StreamPtr);
    if (Status != XST_SUCCESS) {
        printf("ERROR:: Unable to configure Frame Buffer Read\r\n");
        return(XST_FAILURE);
    }

    Status = XVFrmbufRd_SetBufferAddr(&frmbufrd, XVFRMBUFRD_BUFFER_BASEADDR);
    if (Status != XST_SUCCESS) {
        printf("ERROR:: Unable to configure Frame Buffer Read buffer address\r\n");
        return(XST_FAILURE);
    }

    /* Set Chroma Buffer Address for semi-planar color formats */
    if ((Cfmt == XVIDC_CSF_MEM_Y_UV8) || (Cfmt == XVIDC_CSF_MEM_Y_UV8_420) ||
        (Cfmt == XVIDC_CSF_MEM_Y_UV10) || (Cfmt == XVIDC_CSF_MEM_Y_UV10_420) ||
        (Cfmt == XVIDC_CSF_MEM_Y_UV12) || (Cfmt == XVIDC_CSF_MEM_Y_UV12_420) ||
        (Cfmt == XVIDC_CSF_MEM_Y_UV16) || (Cfmt == XVIDC_CSF_MEM_Y_UV16_420) ||
        (Cfmt == XVIDC_CSF_MEM_Y_U_V8) || (Cfmt == XVIDC_CSF_MEM_Y_U_V10) ||
        (Cfmt == XVIDC_CSF_MEM_Y_U_V8_420)) {
        Status = XVFrmbufRd_SetChromaBufferAddr(&frmbufrd, XVFRMBUFRD_BUFFER_BASEADDR+CHROMA_ADDR_OFFSET);
        if (Status != XST_SUCCESS) {
            printf("ERROR:: Unable to configure Frame Buffer Read chroma buffer address\r\n");
            return(XST_FAILURE);
        }
    }

    /* Set V Buffer Address for 3 planar color formats */
    if ((Cfmt == XVIDC_CSF_MEM_Y_U_V8) || (Cfmt == XVIDC_CSF_MEM_Y_U_V10) || (Cfmt == XVIDC_CSF_MEM_Y_U_V8_420)) {
        Status = XVFrmbufRd_SetVChromaBufferAddr(&frmbufrd, XVFRMBUFRD_BUFFER_BASEADDR+V_CHROMA_ADDR_OFFSET);
        if (Status != XST_SUCCESS) {
            printf("ERROR:: Unable to configure Frame Buffer Read V buffer address\r\n");
            return(XST_FAILURE);
        }
    }

    /* Enable Interrupt */
    //XVFrmbufRd_InterruptEnable(&frmbufrd, XVFRMBUFRD_IRQ_DONE_MASK);

    XV_frmbufrd_EnableAutoRestart(&frmbufrd.FrmbufRd);
    /* Start Frame Buffers */
    XVFrmbufRd_Start(&frmbufrd);

    printf("FBRD: Configured OK\r\n");
    return(Status);
}
/*--------------------------------------------------------------------------------*/