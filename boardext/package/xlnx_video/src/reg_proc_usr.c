#include "reg_proc_usr.h"

int fd = 0;
size_t map_size = 0;


uintptr_t dclk_ptr;
uintptr_t vtc_ptr;
uintptr_t tpg0_ptr;
uintptr_t tpg1_ptr;
uintptr_t fbrd_ptr;
uintptr_t fbwr_ptr;
uintptr_t vmix_ptr;
uintptr_t gpio_ptr;


/*---------------------------------------------------------------------*/
int reg_proc_usr_init(void)
{
    /*
    uint32_t dclk = 0;
	Xil_Out32(dclk_ptr+0x08, 0x00400041);
	Xil_Out32(dclk_ptr+0x0c, 0x0000069a);
	Xil_Out32(dclk_ptr+0x10, 0x00000000);
	Xil_Out32(dclk_ptr+0x14, 0x000020c4);
	Xil_Out32(dclk_ptr+0x18, 0xcfafa401);
	Xil_Out32(dclk_ptr+0x1c, 0x00a300ff);
	Xil_Out32(dclk_ptr+0x00, 0x00000001);
    do
    {
        dclk = Xil_In32(dclk_ptr+0x04)&(0x1);
    } while (!dclk);
    Xil_Out32(tpg_ptr+0x10, 0x00000438);
	Xil_Out32(tpg_ptr+0x18, 0x00000780);
	Xil_Out32(tpg_ptr+0x40, 0x00000000);
	Xil_Out32(tpg_ptr+0x20, 0x00000009);
	Xil_Out32(tpg_ptr+0x28, 0x00000000);
	Xil_Out32(tpg_ptr+0x00, 0x00000080);
	Xil_Out32(tpg_ptr+0x00, 0x00000081);

    Xil_Out32(vtc_ptr+0x00, 0x00000000);
    Xil_Out32(vtc_ptr+0x6c, 0x0000007f);
    Xil_Out32(vtc_ptr+0x70, 0x00000898);
    Xil_Out32(vtc_ptr+0x74, 0x04650465);
    Xil_Out32(vtc_ptr+0x60, 0x04380780);
    Xil_Out32(vtc_ptr+0x94, 0x04380000);
    Xil_Out32(vtc_ptr+0x78, 0x080407d8);
    Xil_Out32(vtc_ptr+0x80, 0x0440043b);
    Xil_Out32(vtc_ptr+0x8c, 0x0440043b);
    Xil_Out32(vtc_ptr+0x68, 0x00000002);
    Xil_Out32(vtc_ptr+0x7c, 0x07800780);
    Xil_Out32(vtc_ptr+0x84, 0x07d807d8);
    Xil_Out32(vtc_ptr+0x88, 0x07800780);
    Xil_Out32(vtc_ptr+0x90, 0x07d807d8);
    Xil_Out32(vtc_ptr+0x00, 0x00000001);
    Xil_Out32(vtc_ptr+0x00, 0x00000005);
    Xil_Out32(vtc_ptr+0x00, 0x00000007);
    */
    return RGP_USR_OK;
}
/*---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
volatile uintptr_t *reg_proc_usr_remap(uint32_t ph_addr)
{
    void *map_base;
    void *virt_addr;
    uintptr_t paddr = ph_addr;
    uintptr_t reg_offset = 0;
    reg_offset = paddr & (~(map_size - 1));
    map_base = mmap(NULL, map_size, 
                    PROT_READ | PROT_WRITE, 
                    MAP_SHARED, fd, 
                    reg_offset);
    if (map_base == MAP_FAILED)
    {
        close(fd);
        fprintf(stderr, "mmap failed: %s\n", strerror(errno));
        return NULL;
    }
    printf("Addr %08x mapped to %p.\n", paddr, map_base);
    virt_addr = map_base;
    return (volatile uintptr_t *)virt_addr;
}
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
int reg_proc_usr_close(void)
{
    close(fd);
    return RGP_USR_OK;
}
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
int reg_proc_usr_open(void)
{
    int stat =  RGP_USR_ERR;
    map_size = getpagesize();
    printf("Map size: %08x\n", map_size);
    if ((fd = open("/dev/mem", O_RDWR | O_SYNC)) == -1) {
        fprintf(stderr, "Error opening /dev/mem: %s\n", strerror(errno));
        fprintf(stderr, "Ensure you run with sudo/root privileges.\n");
        return stat;
    }
    printf("/dev/mem opened successfully.\n");
    return RGP_USR_OK;
}
/*---------------------------------------------------------------------*/



/*---------------------------------------------------------------------*/
int reg_proc_usr_default(void)
{
    int stat = RGP_USR_ERR;
    stat = reg_proc_usr_open();
    if(stat != RGP_USR_OK) return stat;
    dclk_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_DCLK_BASEADDR);
    vtc_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_VTC_BASEADDR);
    tpg0_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_TPG_0_BASEADDR);
    tpg1_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_TPG_1_BASEADDR);
    fbrd_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_FBRD_BASEADDR);
    fbwr_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_FBWR_BASEADDR);
    vmix_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_VMIX_BASEADDR);
    gpio_ptr = (uintptr_t)reg_proc_usr_remap(RGP_USR_GPIO_BASEADDR);
    return stat;
}
/*---------------------------------------------------------------------*/
/***********************************************************************/