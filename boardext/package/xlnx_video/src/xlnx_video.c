#include "xlnx_video.h"
#include "reg_proc_usr.h"


extern DDynClk				    dClk;
extern XVtc					    vtc;
extern XV_tpg				    tpg0;
extern XV_tpg				    tpg1;
extern XV_Mix_l2         	    mix;
extern XGpioPs 		            gpio;

extern XV_FrmbufWr_l2     	    frmbufwr;
extern XV_FrmbufRd_l2     	    frmbufrd;

extern uintptr_t	            vtc_ptr;
extern uintptr_t	            tpg0_ptr;
extern uintptr_t	            tpg1_ptr;
extern uintptr_t	            gpio_ptr;
extern uintptr_t 		        vmix_ptr;
extern uintptr_t                dclk_ptr;
extern uintptr_t                fbrd_ptr;
extern uintptr_t                fbwr_ptr;


static int xv_main_app(void)
{
    uint32_t pix_freq = 0;
    int stride = 0;
    //uint32_t i = 0;
    XVidC_VideoStream VidStream;
    XVidC_ColorFormat Cfmt = 0;
    XVidC_ColorFormat Mfmt = 0;
    XVidC_VideoTiming const *TimingPtr;
    //RGP_USR_FBWR_BASEADDR
    //RGP_USR_FBRD_BASEADDR
	printf("=========================================================\r\n");
	printf("Start Drivers\r\n");
	V_VTC_Init(&vtc, RGP_USR_VTC_BASEADDR, vtc_ptr);
	V_TPG_Init(&tpg0, RGP_USR_TPG_0_BASEADDR, tpg0_ptr);
	V_TPG_Init(&tpg1, RGP_USR_TPG_1_BASEADDR, tpg1_ptr);
	V_GPIO_Init(&gpio, RGP_USR_GPIO_BASEADDR, gpio_ptr);
    V_GPIO_SetHigh(&gpio);
	V_FBWR_Init(&frmbufwr, RGP_USR_FBWR_BASEADDR, fbwr_ptr);
    //frmbufwr.FrmbufWr.Config.BaseAddress = fbwr_ptr;
	V_FBRD_Init(&frmbufrd, RGP_USR_FBRD_BASEADDR, fbrd_ptr);
    //frmbufrd.FrmbufRd.Config.BaseAddress = fbrd_ptr;
	V_DDYNCLK_Init(&dClk, RGP_USR_DCLK_BASEADDR, dclk_ptr);
	V_VMIX_Init(&mix, RGP_USR_VMIX_BASEADDR, vmix_ptr);
    //mix.Mix.Config.BaseAddress = vmix_ptr;

	VidStream.VmId = XVIDC_VM_1080_60_P;
	pix_freq = (uint32_t)(XVidC_GetPixelClockHzByVmId(VidStream.VmId));
	printf("Pix Freq: %d\r\n", pix_freq);
	DDynClk_SetRate(&dClk, pix_freq);
    DDynClk_Enable(&dClk);

	XVMix_GetLayerColorFormat(&mix, XVMIX_LAYER_MASTER, &Cfmt);
	VidStream.PixPerClk     = tpg1.Config.PixPerClk;
	VidStream.ColorFormatId = Cfmt;
	VidStream.ColorDepth    = tpg1.Config.MaxDataWidth;
	
	TimingPtr = XVidC_GetTimingInfo(VidStream.VmId);
	VidStream.Timing = *TimingPtr;
	VidStream.FrameRate = XVidC_GetFrameRate(VidStream.VmId);
    printf("\r\n********************************************\r\n");
    printf("Test Input Stream: %s (%s)\r\n",
            XVidC_GetVideoModeStr(VidStream.VmId),
            XVidC_GetColorFormatStr(VidStream.ColorFormatId));
    printf("********************************************\r\n");

	V_VTC_ConfigStream(&VidStream);
	Mfmt = XVIDC_CSF_MEM_RGB8;
	stride = V_FBRD_CalcStride(Mfmt,
                           frmbufrd.FrmbufRd.Config.AXIMMDataWidth,
                            &VidStream);
	V_FBRD_ConfigBuf(stride, Mfmt, &VidStream);
	V_FBWR_ConfigBuf(stride, Mfmt, &VidStream);
	V_VMIX_ConfigStream(&VidStream);
	V_TPG_ConfigStream(&tpg1,&VidStream);
    return 0;
}


/*---------------------------------------------------------------*/
static void xv_check_help(char *cmd)
{
    if(!strcmp(cmd,"--help"))
    {
        printf("USAGE:\n");
        printf("   unmap [Addr in HEX]\n");
        printf("   remap [Addr in HEX] [Size in HEX]\n");
        printf("   rd [Addr in HEX]\n");
        printf("   wr [Addr in HEX] [Value in HEX]\n");
    }
    else
    {
        printf("XV: Wrong arguments or number of arguments.\n");
        printf("    Type --help for more details\n");
    }
}


/*---------------------------------------------------------------*/
/*
static uint32_t xv_parse_user_input(char *scmd, 
                                char *sarg1,
                                char *sarg2)
{
    int assign_stat = -1;
    int cid = 0;
    uint32_t result = 0;
    uint32_t xarg1 = 0;
    uint32_t xarg2 = 0;
    assign_stat = sscanf(sarg1, "%x", &xarg1);
    if(!assign_stat) {xv_check_help("empty"); return XV_ERR;}
    assign_stat = sscanf(sarg2, "%x", &xarg2);
    if(!assign_stat) {xv_check_help("empty"); return XV_ERR;}
    if(!strcmp(scmd,"unmap")) cid = 0;
    else if(!strcmp(scmd,"remap")) cid = 1;
    else if(!strcmp(scmd,"rd")) cid = 2;
    else if(!strcmp(scmd,"wr")) cid = 3;
    else
    {
        xv_check_help("empty");
        return XV_ERR;
    }
    return result;
}
*/
/*---------------------------------------------------------------*/





/*---------------------------------------------------------------*/
int main (int argc, char *argv[])
{
    int stat = 0;
    if(argc == 1)
    {
        printf("XV: Running without arguments (default code).\n");
        //reg_definit_krn();
        //reg_proc_usr_default();
        reg_proc_usr_default();
        xv_main_app();
        reg_proc_usr_close();
    }
    else
    {
        if(argc == 2)
        {
            xv_check_help(argv[1]);
        }
        else if(argc == 4)
        {
            //xv_parse_user_input(argv[1],argv[2],argv[3]);
        }
        else
        {
            xv_check_help(argv[1]);
        }
    }
    return stat;
}

