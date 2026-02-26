#include "regwriter.h"

#define NETLINK_REGWRITER 	31
#define MAX_PAYLOAD 		1024 // maximum payload size

struct sock *nl_sk = NULL;

static void __iomem *io_mem_base;


static int table_pointer = 0;
static uint32_t table_args[REGW_NODES_COUNT][6];
static char argval_s[3][REGW_ARG_MAXLEN];
static uint32_t	argval_n[3];
static uint32_t rxdata = 0;

int Status = 0;


/*------------------------------------------------------------------*/
/*
static void regwriter_print(char *strarg, uint8_t len)
{
	int i = 0;
	for(i=0;i<len;i++)
	{
		printk(KERN_CONT "%c", *(strarg+i));
	}
	printk(KERN_INFO "\n");
}
*/


/*------------------------------------------------------------------*/
static int regwriter_unmap(void)
{
	int i = 0;
	for(i=0;i<REGW_NODES_COUNT;i++)
	{
		if(table_args[i][REGW_ARG_HW_ADDR] == argval_n[REGW_ARG_HW_ADDR])
		{
			iounmap((volatile void *)table_args[i][REGW_ARG_VT_ADDR]);
			table_pointer = i;
			table_args[i][REGW_ARG_ID] = i;
			table_args[i][REGW_ARG_HW_ADDR] = 0x00000000;
			table_args[i][REGW_ARG_VAL] = 0x00000000;
			table_args[i][REGW_ARG_VT_ADDR] = 0x00000000;
			return REGW_CMPT;
		}
	}
	return REGW_OK;
}

/*------------------------------------------------------------------*/
static int regwriter_map(uint32_t defsz_flag)
{
	int i = 0;
	uint32_t rmap_size = 0;
	uint32_t addroffset = 0;
	for(i=0;i<REGW_NODES_COUNT;i++)
	{
		if((argval_n[REGW_ARG_HW_ADDR] >= (table_args[i][REGW_ARG_HW_ADDR])) &&
			(argval_n[REGW_ARG_HW_ADDR] <= (table_args[i][REGW_ARG_HW_ADDR_END])))
		//if((table_args[i][REGW_ARG_HW_ADDR] & 0xfffff000) == 
		//				(argval_n[REGW_ARG_HW_ADDR] & 0xfffff000))
		{
			printk(KERN_INFO "REGWRITER: Reg already mapped to %08x\n",
								table_args[i][REGW_ARG_VT_ADDR]);
			//printk(KERN_INFO "REGWRITER: END %08x\n", table_args[i][REGW_ARG_HW_ADDR_END]);
			//printk(KERN_INFO "REGWRITER: PREV %08x\n", argval_n[REGW_ARG_HW_ADDR]);
			addroffset = argval_n[REGW_ARG_HW_ADDR]-table_args[i][REGW_ARG_HW_ADDR];
			//printk(KERN_INFO "REGWRITER: Offset %08x\n", addroffset);
			//printk(KERN_INFO "REGWRITER: Vt %08x\n", table_args[i][REGW_ARG_VT_ADDR]);
			table_args[i][REGW_ARG_VT_ADDR_ACTIVE] = table_args[i][REGW_ARG_VT_ADDR] + addroffset;
			table_pointer = i;
			return REGW_USED;
		}
	}
	for(i=0;i<REGW_NODES_COUNT;i++)
	{
		if(table_args[i][REGW_ARG_HW_ADDR] == 0x00000000)
		{
			printk(KERN_INFO "REGWRITER: MAP: %x - %x\n",
					argval_n[REGW_ARG_HW_ADDR], argval_n[REGW_ARG_VAL]);
			rmap_size = argval_n[REGW_ARG_VAL];
			if(defsz_flag > 0) rmap_size = REGW_RMAP_SIZE;
			io_mem_base = ioremap_cache((resource_size_t)argval_n[REGW_ARG_HW_ADDR],
									(size_t)rmap_size);
			if(io_mem_base)
			{	
				table_pointer = i;
				table_args[i][REGW_ARG_ID] = i;
				table_args[i][REGW_ARG_HW_ADDR] = argval_n[REGW_ARG_HW_ADDR];
				table_args[i][REGW_ARG_VAL] = argval_n[REGW_ARG_VAL];
				table_args[i][REGW_ARG_VT_ADDR] = (uint32_t)io_mem_base;
				table_args[i][REGW_ARG_HW_ADDR_END] = argval_n[REGW_ARG_HW_ADDR] + REGW_RMAP_SIZE;
				table_args[i][REGW_ARG_VT_ADDR_ACTIVE] = table_args[i][REGW_ARG_VT_ADDR];
				printk(KERN_INFO "REGWRITER: Reg remapped OK! %08x\n", 
								table_args[i][REGW_ARG_VT_ADDR]);
				return REGW_CMPT;
			}
			else
			{
				printk(KERN_INFO "REGWRITER: --Resource is busy\n");
				return REGW_ERR;
			}
		}
	}
	return REGW_OK;
}

/*------------------------------------------------------------------*/
static int regwriter_read(void)
{
	int stat = REGW_ERR;
	uint32_t rValue = 0;
	stat = regwriter_map(1);
	if(stat == REGW_USED || stat == REGW_CMPT)
	{
		printk(KERN_INFO "REGWRITER: RD %08x\n", 
								table_args[table_pointer][REGW_ARG_VT_ADDR_ACTIVE]);
		rValue = ioread32((volatile void *)table_args[table_pointer][REGW_ARG_VT_ADDR_ACTIVE]);
		rxdata = rValue;
		return REGW_CMPT;
	}
	return stat;
}

/*------------------------------------------------------------------*/
static int regwriter_write(void)
{
	int stat = REGW_ERR;
	stat = regwriter_map(1);
	if(stat == REGW_USED || stat == REGW_CMPT)
	{
		printk(KERN_INFO "REGWRITER: WR %08x\n", 
								table_args[table_pointer][REGW_ARG_VT_ADDR_ACTIVE]);
		iowrite32(argval_n[2],
						(volatile void *)table_args[table_pointer][REGW_ARG_VT_ADDR_ACTIVE]);
		return REGW_CMPT;
	}
	return stat;
}

/*------------------------------------------------------------------*/
static int regwriter_invoke_cmd(void)
{
	int stat = REGW_ERR;
	switch(argval_n[0])
	{
		case REGW_OP_UNMAP:
		{
			stat = regwriter_unmap();
		}
		break;
		case REGW_OP_MAP:
		{
			stat = regwriter_map(0);
		}
		break;
		case REGW_OP_RD:
		{
			stat = regwriter_read();
		}
		break;
		case REGW_OP_WR:
		{
			stat = regwriter_write();
		}
		break;
		default:
			stat = REGW_ERR;
		break;
	}
	return stat;
}


/*------------------------------------------------------------------*/
static int regwriter_parse_arguments(void)
{
	int assign_stat = -1;
	int i = 0;
	uint32_t rValue = 0;
	for(i=0;i<3;i++)
	{
		assign_stat = sscanf(argval_s[i], "%x", &rValue);
		if (assign_stat == 1)
		{
			argval_n[i] = rValue;
		}
		else
		{
			return -1;
		}
	}
	return REGW_OK;
}

/*------------------------------------------------------------------*/
static int regwriter_get_arguments(char *msg)
{
	int i = 0;
	int arg_num = 0;
	int msglen = 0;
	int arglen = 0;
	int passed = 0;
	int prevlen = 0;
	msglen = strlen(msg);
	memset(&argval_s[0][0],0x00,REGW_ARG_MAXLEN);
	memset(&argval_s[1][0],0x00,REGW_ARG_MAXLEN);
	memset(&argval_s[2][0],0x00,REGW_ARG_MAXLEN);
	//printk(KERN_INFO "REGWRITER: Full string Len: %d\n", msglen);
	if(msglen == 0)
	{
		return -1;
	}
	for(i=0;i<=msglen;i++)
	{
		if(*(msg+i)==0x20 || !(*(msg+i)) || *(msg+i)==0x00)
		{
			if(passed != 1)
			{
				arglen = i - prevlen;
				memcpy(&argval_s[arg_num][0],&msg[i-arglen], arglen);
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
	if(arg_num != 3)
	{
		return REGW_ERR;
	}
	return REGW_OK;
}




/*------------------------------------------------------------------*/
static void regwriter_nl_recv_msg(struct sk_buff *skb)
{
	int stat = REGW_ERR;
    struct nlmsghdr *nlh;
    int pid;
    struct sk_buff *skb_out;
    int msg_size;
    char msg[MAX_PAYLOAD];
    int res;
	char cvalue[16];
	char msg_back[128];
	rxdata = 0;
    // Parse the message
    nlh = nlmsg_hdr(skb);
    pid = nlh->nlmsg_pid;
    //printk(KERN_INFO "Netlink received msg from user space process %d\n", pid);
    strcpy(msg, (char *)nlmsg_data(nlh));
    //printk(KERN_INFO "Message: %s\n", msg);

	stat = regwriter_get_arguments(msg);
	if(stat == REGW_OK)
	{
		stat = regwriter_parse_arguments();
		if(stat == REGW_OK)
		{
			stat = regwriter_invoke_cmd();
		}
	}
	//if(stat != REGW_OK) return;
	memset(cvalue, 0x00, 16);
	memset(msg_back, 0x00, 128);
	sprintf(cvalue,"0x%02x ",stat);
	strcat(msg_back, cvalue);
	strcat(msg_back, msg);
	if(argval_n[0] == REGW_OP_RD)
	{
		memset(cvalue, 0x00, 16);
		sprintf(cvalue," 0x%08x",rxdata);
		strcat(msg_back, cvalue);
	}
	//printk(KERN_INFO "Back Message: %s\n", msg_back);
    // Prepare reply
    //msg_size = strlen("Hello from kernel space!");
	msg_size = strlen(msg_back);
    skb_out = nlmsg_new(msg_size, 0);
    if (!skb_out)
	{
        printk(KERN_ERR "Failed to allocate new skb\n");
        return;
    }

    nlh = nlmsg_put(skb_out, 0, 0, NLMSG_DONE, msg_size, 0);
    NETLINK_CB(skb_out).dst_group = 0; // Unicast
    strncpy(nlmsg_data(nlh), msg_back, msg_size);

    // Send the message back to the user space process
    res = nlmsg_unicast(nl_sk, skb_out, pid);
    if (res < 0) Status = -1;
        //printk(KERN_INFO "Error while sending back to user\n");
    else Status = 0;
        //printk(KERN_INFO "Message sent back to user\n");
}

/*------------------------------------------------------------------*/
static int __init regwriter_init(void)
{
    printk(KERN_INFO "Initializing Netlink example module\n");
    
    // Configuration for netlink socket
    struct netlink_kernel_cfg cfg = {
        .input = regwriter_nl_recv_msg, // Callback function for received messages
    };

    nl_sk = netlink_kernel_create(&init_net, NETLINK_REGWRITER, &cfg);
    if (!nl_sk) {
        printk(KERN_ALERT "Error creating netlink socket\n");
        return -ENOMEM;
    }

    printk(KERN_INFO "Netlink socket created\n");
    return 0;
}

/*------------------------------------------------------------------*/
static void __exit regwriter_exit(void)
{
    printk(KERN_INFO "Exiting Netlink example module\n");
    netlink_kernel_release(nl_sk); // Release the socket
}

module_init(regwriter_init);
module_exit(regwriter_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Frolov");
MODULE_DESCRIPTION("A simple Netlink kernel module example");
MODULE_INFO(intree, "Y");
/*------------------------------------------------------------------*/
