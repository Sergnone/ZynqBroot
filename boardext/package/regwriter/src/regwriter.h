#ifndef _REGWRITER_H
#define _REGWRITER_H

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/netlink.h>
#include <net/sock.h>
#include <linux/skbuff.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/types.h>


#define REGW_NODES_COUNT        16
#define REGW_CMD_REMAP          1
#define REGW_CMD_READ           2
#define REGW_CMD_WRITE          3

#define REGW_ARG_MAXLEN         16

#define REGW_RMAP_SIZE          0x100


enum {
    REGW_OP_UNMAP,
    REGW_OP_MAP,
    REGW_OP_RD,
    REGW_OP_WR
};

enum {
    REGW_ARG_ID,
    REGW_ARG_HW_ADDR,
    REGW_ARG_VAL,
    REGW_ARG_VT_ADDR,
    REGW_ARG_HW_ADDR_END,
    REGW_ARG_VT_ADDR_ACTIVE,
};

enum {
    REGW_ERR = -1,
    REGW_OK = 0,
    REGW_USED = 1,
    REGW_CMPT = 2,
};



#endif