#include "xlnx_video.h"
#include "_netlink.h"

extern char msg_rx[128];
static char rxval_s[5][16];
static uint8_t rx_cnt = 0;


int xv_default_program(void)
{
    return 0;
}

static int xv_count_rx_params(char *rxstr)
{
    int i = 0;
	int arg_num = 0;
	int msglen = 0;
	int arglen = 0;
	int passed = 0;
	int prevlen = 0;
    msglen = strlen(rxstr);
	memset(&rxval_s[0][0],0x00,16);
	memset(&rxval_s[1][0],0x00,16);
	memset(&rxval_s[2][0],0x00,16);
    memset(&rxval_s[3][0],0x00,16);
    memset(&rxval_s[4][0],0x00,16);
    for(i=0;i<=msglen;i++)
    {
        if(*(rxstr+i)==0x20 || !(*(rxstr+i)) || *(rxstr+i)==0x00)
        {
            if(passed != 1)
			{
				arglen = i - prevlen;
				//printf("RV: RxLen: %d\n", arglen);
				memcpy(&rxval_s[arg_num][0],&rxstr[i-arglen], arglen);
				//printf("RV: RxVal: %s\n", rxval_s[arg_num]);
				prevlen += arglen;
				arg_num += 1;
				passed = 1;
            }
            prevlen += 1;
        }
        else
		{
			passed = 0;
		}
    }
    rx_cnt = arg_num;
    return XV_OK;
}

static void xv_print_help(void)
{
    printf("USAGE:\n");
    printf("   unmap [Addr in HEX]\n");
    printf("   remap [Addr in HEX] [Size in HEX]\n");
    printf("   rd [Addr in HEX]\n");
    printf("   wr [Addr in HEX] [Value in HEX]\n");
}


static void xv_notify_help(void)
{
    printf("XV: Wrong arguments or number of arguments.\n");
    printf("    Type --help for more details\n");
}

/*---------------------------------------------------------*/
int xv_unmap_reg(uint32_t arg1, uint32_t arg2)
{
    int stat = XV_ERR;
    char *args1 = (char*)malloc(sizeof(char)*32);
    char *args2 = (char*)malloc(sizeof(char)*32);
    memset(args1,0x00,32);
    memset(args2,0x00,32);
    sprintf(args1,"0x%x", arg1);
    sprintf(args2,"0x%x", arg2);
    netlink_open_iface();
    stat = netlink_check_command("unmap");
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args1, 1);
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args2, 2);
    if(stat != XV_OK) return stat;
    stat = netlink_send_data();
    netlink_close_iface();
    return stat;
}

/*---------------------------------------------------------*/
int xv_remap_reg(uint32_t arg1, uint32_t arg2)
{
    int stat = XV_ERR;
    char *args1 = (char*)malloc(sizeof(char)*32);
    char *args2 = (char*)malloc(sizeof(char)*32);
    memset(args1,0x00,32);
    memset(args2,0x00,32);
    sprintf(args1,"0x%x", arg1);
    sprintf(args2,"0x%x", arg2);
    netlink_open_iface();
    stat = netlink_check_command("remap");
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args1, 1);
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args2, 2);
    if(stat != XV_OK) return stat;
    stat = netlink_send_data();
    netlink_close_iface();
    return 0;
}

/*---------------------------------------------------------*/
uint32_t xv_read_reg(uint32_t arg1, uint32_t arg2)
{
    int stat = XV_ERR;
    int assign_stat = -1;
    uint32_t rx_value = 0;
    char *args1 = (char*)malloc(sizeof(char)*32);
    char *args2 = (char*)malloc(sizeof(char)*32);
    memset(args1,0x00,32);
    memset(args2,0x00,32);
    sprintf(args1,"0x%x", arg1);
    sprintf(args2,"0x%x", arg2);
    netlink_open_iface();
    stat = netlink_check_command("rd");
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args1, 1);
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args2, 2);
    if(stat != XV_OK) return stat;
    stat = netlink_send_data();
    netlink_close_iface();
    xv_count_rx_params(msg_rx);
    if(rx_cnt == 5)
    {
        assign_stat = sscanf(&rxval_s[4][0], "%x", &rx_value);
    }   
    return rx_value;
}

/*---------------------------------------------------------*/
int xv_write_reg(uint32_t arg1, uint32_t arg2)
{
    int stat = XV_ERR;
    char *args1 = (char*)malloc(sizeof(char)*32);
    char *args2 = (char*)malloc(sizeof(char)*32);
    memset(args1,0x00,32);
    memset(args2,0x00,32);
    sprintf(args1,"0x%x", arg1);
    sprintf(args2,"0x%x", arg2);
    netlink_open_iface();
    stat = netlink_check_command("wr");
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args1, 1);
    if(stat != XV_OK) return stat;
    stat = netlink_check_argument(args2, 2);
    if(stat != XV_OK) return stat;
    stat = netlink_send_data();  
    netlink_close_iface();
    return stat;
}


/*---------------------------------------------------------*/
int main (int argc, char *argv[])
{
    int assign_stat = -1;
    int stat = XV_ERR;
    uint32_t xarg1 = 0;
    uint32_t xarg2 = 0;
    uint32_t result = 0;
    uint32_t i = 0;
    int dclk = 0;
    if(argc == 1)
    {
        xv_remap_reg(0x43C00000,0x100);
        xv_remap_reg(0x43C10000,0x100);
        xv_remap_reg(0x43C20000,0x100);
        //Simply command without arguments. Runs default code
        printf("XV: Running without arguments (default code).\n");
        xv_write_reg(0x43C10008,0x00400041);
        xv_write_reg(0x43C1000c,0x0000069a);
        xv_write_reg(0x43C10010,0x00000000);
        xv_write_reg(0x43C10014,0x000020c4);
        xv_write_reg(0x43C10018,0xcfafa401);
        xv_write_reg(0x43C1001c,0x00a300ff);
        xv_write_reg(0x43C10000,0x00000001);
        do
        {
            dclk = xv_read_reg(0x43C10004,0x00000000);
        } while (!dclk);
        
        xv_write_reg(0x43c00010,0x00000438);
        xv_write_reg(0x43c00018,0x00000780);
        xv_write_reg(0x43c00040,0x00000000);
        xv_write_reg(0x43c00020,0x00000009);
        xv_write_reg(0x43c00028,0x00000000);
        xv_write_reg(0x43c00000,0x00000080);
        xv_write_reg(0x43c00000,0x00000081);

        xv_write_reg(0x43c2006c,0x0000007f);
        xv_write_reg(0x43c20070,0x00000898);
        xv_write_reg(0x43c20074,0x04650465);
        xv_write_reg(0x43c20060,0x04380780);

        xv_write_reg(0x43c20094,0x04380000);
        xv_write_reg(0x43c20078,0x080407d8);
        xv_write_reg(0x43c20080,0x0440043b);
        xv_write_reg(0x43c2008c,0x0440043b);

        xv_write_reg(0x43c20068,0x00000002);
        xv_write_reg(0x43c2007c,0x07800780);
        xv_write_reg(0x43c20084,0x07d807d8);
        xv_write_reg(0x43c20088,0x07800780);
        xv_write_reg(0x43c20090,0x07d807d8);

        xv_write_reg(0x43c20000,0x00000001);
        xv_write_reg(0x43c20000,0x00000005);
        xv_write_reg(0x43c20000,0x00000007);

        for(i=0; i<800; i++)
        {
            sleep(1);
            xv_write_reg(0x43c00020,i);
            if(i == 15) i = 0;
        }
    }
    else
    {
        if(argc == 2)
        {
            stat = netlink_check_command(argv[1]);
            if(stat == XV_OK)
            {
                xv_print_help();
            }
            if(stat == XV_INVARG)
            {
                xv_notify_help();
            }
        }
        else if(argc == 4)
        {
            assign_stat = sscanf(argv[2], "%x", &xarg1);
            assign_stat = sscanf(argv[3], "%x", &xarg2);
            if(!strcmp(argv[1],"unmap"))
            {
                stat = xv_unmap_reg(xarg1, xarg2);
                printf("Reg Unmap: %d\n", stat);
            }
            else if(!strcmp(argv[1],"remap"))
            {
                stat = xv_remap_reg(xarg1, xarg2);
                printf("Reg Remap: %d\n", stat);
            }
            else if(!strcmp(argv[1],"rd"))
            {
                result = xv_read_reg(xarg1, xarg2);
                printf("Reg Read Value: %08x\n", result);
            }
            else if(!strcmp(argv[1],"wr"))
            {
                stat = xv_write_reg(xarg1, xarg2);
                printf("Reg Write: %d\n", stat);
            }
            else
            {
                xv_notify_help();
            }
        }
        else
        {
            xv_notify_help();
        }
    }
    return stat;
}

