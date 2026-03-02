#ifndef __REG_PROC_USR_H_
#define __REG_PROC_USR_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include "include/xil_io.h"

#define RGP_USR_DCLK_BASEADDR           0x43C10000
#define RGP_USR_VTC_BASEADDR            0x43C20000
#define RGP_USR_TPG_0_BASEADDR          0x43c00000
#define RGP_USR_TPG_1_BASEADDR          0x43c60000
#define RGP_USR_FBRD_BASEADDR           0x43c30000
#define RGP_USR_FBWR_BASEADDR           0x43c40000
#define RGP_USR_VMIX_BASEADDR           0x43C50000

#define RGP_USR_GPIO_BASEADDR           0xe000a000

#define MAP_SIZE                4096UL 
#define MAP_MASK                (MAP_SIZE - 1)
#define PAGE_MASK               (~(MAP_SIZE - 1))

enum {
    RGP_USR_ERR = -1,
    RGP_USR_OK = 0,
    RGP_USR_BUSY = 1,
    RGP_USR_CMPT = 2,
    RGP_USR_INVARG = 3,
};


int reg_proc_usr_init(void);
int reg_proc_user_test(void);
int reg_proc_usr_default(void);
int reg_proc_usr_close(void);
int reg_proc_usr_open(void);
int reg_proc_usr(int cid, uint32_t arg1, uint32_t arg2);


#endif
