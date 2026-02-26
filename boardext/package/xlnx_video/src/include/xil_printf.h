/******************************************************************************
* Copyright (C) 1995 - 2021 Xilinx, Inc.  All rights reserved.
* Copyright (C) 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
*******************************************************************************/
 #ifndef printf_H
 #define printf_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "xil_types.h"
#include "bspconfig.h"
#include <stdio.h>

#if defined (__aarch64__) && HYP_GUEST && EL1_NONSECURE && XEN_USE_PV_CONSOLE
#include "xen_console.h"
#endif

/*----------------------------------------------------*/
/* Use the following parameter passing structure to   */
/* make printf re-entrant.                        */
/*----------------------------------------------------*/

struct params_s;


/*---------------------------------------------------*/
/* The purpose of this routine is to output data the */
/* same as the standard printf function without the  */
/* overhead most run-time libraries involve. Usually */
/* the printf brings in many kilobytes of code and   */
/* that is unacceptable in most embedded systems.    */
/*---------------------------------------------------*/

typedef char* charptr;
typedef int32_t (*func_ptr)(int c);

/************************** Function Prototypes ******************************/
/**< prints the statement */
void printf( const char *ctrl1, ...);
/**< This routine is equivalent to vprintf routine */
void xil_vprintf(const char *ctrl1, va_list argp);
void print( const char *ptr);
extern void outbyte (char c); /**< To send byte */
extern char inbyte(void); /**< To receive byte */

#ifdef __cplusplus
}
#endif

#endif	/* end of protection macro */
