#ifndef __N_NETLINK_H_
#define __N_NETLINK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>

#define NL_ARG_MAXLEN           128
#define NL_REGWRITER 	        31  // A custom netlink family ID
#define NL_MAX_PAYLOAD 		    1024 // maximum payload size


enum {
    NL_OP_UNMAP,
    NL_OP_MAP,
    NL_OP_RD,
    NL_OP_WR
};

enum {
    NL_APP_ERR = -1,
    NL_APP_OK = 0,
    NL_APP_USED = 1,
    NL_APP_CMPT = 2,
    NL_APP_INVARG = 3,
};

int netlink_open_iface(void);
void netlink_close_iface(void);

void netlink_init_space(void);
int netlink_check_command(char *strv);
int netlink_check_argument(char *strv, int arg_id);
int netlink_send_data(void);

#endif