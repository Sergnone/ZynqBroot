#ifndef __XLNX_VIDEO_H_
#define __XLNX_VIDEO_H_

#include "_commons/_xl_vtc.h"
#include "_commons/_xl_tpg.h"
#include "_commons/_xl_dynclk.h"
#include "_commons/_xl_vmix.h"
#include "_commons/_xl_fb_rd.h"
#include "_commons/_xl_fb_wr.h"
#include "_commons/_xl_gpio.h"
#include <stdio.h>

enum {
    XV_ERR = -1,
    XV_OK = 0,
    XV_BUSY = 1,
    XV_CMPT = 2,
    XV_INVARG = 3,
};

#endif