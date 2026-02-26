/******************************************************************************
* Copyright (c) 2009 - 2021 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xil_testio.h
*
* @addtogroup common_test_utils Test Utilities for Memory and Caches
* <h2>I/O test </h2>
* The xil_testio.h file contains utility functions to test endian related memory
* IO functions.
*
* A subset of the memory tests can be selected or all of the tests can be run
* in order. If there is an error detected by a subtest, the test stops and the
* failure code is returned. Further tests are not run even if all of the tests
* are selected.
*
* @{
* <pre>
* MODIFICATION HISTORY:
*
* Ver    Who    Date    Changes
* ----- ---- -------- -----------------------------------------------
* 1.00 hbm  08/05/09 First release
* </pre>
*
******************************************************************************/

/**
 *@cond nocomments
 */

#ifndef XIL_TESTIO_H	/* prevent circular inclusions */
#define XIL_TESTIO_H	/* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xil_types.h"

/************************** Constant Definitions *****************************/


#define XIL_TESTIO_DEFAULT 	0
#define XIL_TESTIO_LE		1
#define XIL_TESTIO_BE		2

/**
 *@endcond
 */

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/


/************************** Function Prototypes ******************************/

extern uint32_t Xil_TestIO8(uint8_t *Addr, uint32_t Length, uint8_t Value);
extern uint32_t Xil_TestIO16(uint16_t *Addr, uint32_t Length, uint16_t Value, uint32_t Kind, uint32_t Swap);
extern uint32_t Xil_TestIO32(uint32_t *Addr, uint32_t Length, uint32_t Value, uint32_t Kind, uint32_t Swap);

#ifdef __cplusplus
}
#endif

#endif /* end of protection macro */
/**
* @} End of "addtogroup common_test_utils".
*/
