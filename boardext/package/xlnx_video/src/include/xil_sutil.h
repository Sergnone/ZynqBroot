/******************************************************************************/
/**
* Copyright (C) 2024 - 2025 Advanced Micro Devices, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/****************************************************************************/
/**
* @file xil_sutil.h
* @addtogroup common_utilities Common Utility APIs
* @{
* @details
*
* xil_sutil.h file contains xil utility functions declarations
* Except few functions, most of these functions are wrappers to standard functions.
* The standard string functions do not validate the input and that results into
* buffer overflows. To avoid it, the wrapper function validates the input and
* then passed to standard function. There are few constant time functions
* ( xxx_CT() ) which are used to compare the data in constant time.
* The constant time functions should be used while comparing secure data
* like password, keys which prevent disclosing of the data using
* timing analysis.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who      Date     Changes
* ----- -------- -------- -----------------------------------------------
* 9.2   kpt      04/21/19 First release.
* 9.3   ml       02/19/25 Fix Type Mismatch in Xil_UtilRMW32
* 9.4   ml       07/24/25 Fixed GCC warnings
*       har      10/10/25 Updated datatype of Len in Xil_ConvertStringToHex
*
* </pre>
*
*****************************************************************************/

#ifndef XIL_SUTIL_H_
#define XIL_SUTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************* Include Files ********************************/
#include "xil_types.h"
#include "xil_io.h"
#include "xstatus.h"

/*************************** Constant Definitions *****************************/

/****************** Macros (Inline Functions) Definitions *********************/

/******************************************************************************/
/**
 *
 * Builds version number by concatenates 16-bit Major version and Minor version.
 *
 * @param   Major is the 16-bit major version number
 * @param   Minor is the 16-bit minor version number
 *
 * @return	32-bit version number
 *
 ******************************************************************************/
#define XIL_BUILD_VERSION(Major, Minor)		((((uint32_t)Major) << 16U) | (Minor))

#ifdef __GNUC__
/******************************************************************************/
/**
 *
 * Updates the return value of the called function into Var and VarTmp variables
 * for redundancy. This is to avoid glitches from altering the return values of
 * security critical functions.
 *
 * @param   Var is the variable which holds the return value of function
 *          executed
 * @param   VarTmp is the variable which holds the value stored in Var
 * @param	Function is the function to be executed
 * @param	Other params are arguments to the called function
 *
 * @return	None
 *
 ******************************************************************************/
#define XSECURE_TEMPORAL_IMPL(Var, VarTmp, Function, ...) \
	{ \
		Var = XST_FAILURE; \
		VarTmp = XST_FAILURE; \
		Var = Function(__VA_ARGS__); \
		VarTmp = Var; \
	}

/******************************************************************************/
/**
 *
 * Adds redundancy while checking the status of the called function.
 * This is to avoid glitches from altering the return values of security
 * critical functions. The macro requires a label to be passed to "go to"
 * in case of error.
 *
 * @param   Label is the label defined in function and the control
 *          will jump to the label in case of XST_FAILURE
 * @param   Status is the variable which holds the return value of
 *          function executed
 * @param	Function is the function to be executed
 * @param	Other params are arguments to the called function
 *
 * @return	None
 *
 ******************************************************************************/
#define XSECURE_TEMPORAL_CHECK(Label, Status, Function, ...)   \
	{ \
		volatile int StatusTmpVal; \
		XSECURE_TEMPORAL_IMPL(Status, StatusTmpVal, Function, __VA_ARGS__); \
		if ((Status != XST_SUCCESS) || \
		    (StatusTmpVal != XST_SUCCESS)) { \
			if (((Status) != (StatusTmpVal)) || \
			    (Status == XST_SUCCESS)) { \
				Status = XST_GLITCH_ERROR; \
			}\
			goto Label; \
		} \
	}

/******************************************************************************/
/**
 *
 * Adds redundancy to the function call. This is to avoid glitches which can skip
 * a function call and cause altering of the code flow in security critical
 * functions.
 *
 * @param	Status is the variable which holds the return value of
 *		function executed
 * @param	StatusTmp is the variable which holds the return value of
 *		redundant function call executed
 * @param	Function is the function to be executed
 * @param	Other params are arguments to the called function
 *
 * @return	None
 *
 ******************************************************************************/
#define XSECURE_REDUNDANT_CALL(Status, StatusTmp, Function, ...)   \
	{ \
		Status = Function(__VA_ARGS__); \
		StatusTmp = Function(__VA_ARGS__); \
	}

/******************************************************************************/
/**
 *
 * Adds redundancy to the function call. This is to avoid glitches which can skip
 * a function call and cause altering of the code flow in security critical
 * functions.
 *
 * @param	Function is the function to be executed
 * @param	Other params are arguments to the called function
 *
 * @return	None
 *
 ******************************************************************************/
#define XSECURE_REDUNDANT_IMPL(Function, ...)   \
	{ \
		Function(__VA_ARGS__); \
		Function(__VA_ARGS__); \
	}

/******************************************************************************/
/**
 *
 * This Macro helps to detect glitches skipping the Status check
 * in case of error.
 *
 * @param 	None
 *
 * @return	None
 *
 ******************************************************************************/
#define XSECURE_STATUS_CHK_GLITCH_DETECT(Status)   \
	{ \
		if (Status == XST_SUCCESS) { \
			Status = (int)XST_GLITCH_ERROR; \
		} \
	}

#endif
/*************************** Function Prototypes ******************************/

/**< Converts input character to nibble */
uint32_t Xil_ConvertCharToNibble(uint8_t InChar, uint8_t *Num);

/**< Convert input hex string to array of 32-bits integers */
uint32_t Xil_ConvertStringToHex(const char *Str, uint32_t *buf, uint32_t Len);

#ifdef VERSAL_PLM
/**< Register PLM handler */
void Xil_RegisterPlmHandler(void (*PlmAlive) (void));

/**< Call PLM handler */
void Xil_PlmStubHandler(void);
#endif

/**< Waits for specified event */
uint32_t Xil_WaitForEvent(uint32_t RegAddr, uint32_t EventMask, uint32_t Event, uint32_t Timeout);

/**< Waits for specified events */
uint32_t Xil_WaitForEvents(uint32_t EventsRegAddr, uint32_t EventsMask, uint32_t WaitEvents,
		      uint32_t Timeout, uint32_t *Events);

/**< Read, Modify and Write to an address*/
void Xil_UtilRMW32(uint32_t Addr, uint32_t Mask, uint32_t Value);

/**< Copies Len bytes from source memory to destination memory */
uint32_t Xil_SecureMemCpy(void *DestPtr, uint32_t DestPtrLen, const void *SrcPtr, uint32_t Len);

/**< Zeroizes the memory of given length */
uint32_t Xil_SecureZeroize(uint8_t *DataPtr, const uint32_t Length);

/**< Copies Len bytes from source memory to destination memory */
uint32_t Xil_SMemCpy (void *Dest, const uint32_t DestSize,
		 const void *Src, const uint32_t SrcSize, const uint32_t CopyLen);

/**< Copies Len bytes from source memory to destination memory, allows
   overlapped memory between source and destination */
uint32_t Xil_SMemMove(void *Dest, const uint32_t DestSize,
		 const void *Src, const uint32_t SrcSize, const uint32_t CopyLen);

/**< Compares Len bytes between source and destination memory */
uint32_t Xil_SMemCmp (const void *Src1, const uint32_t Src1Size,
		 const void *Src2, const uint32_t Src2Size, const uint32_t CmpLen);

/**< Compares Len bytes between source and destination memory with constant time */
uint32_t Xil_SMemCmp_CT (const void *Src1, const uint32_t Src1Size,
		    const void *Src2, const uint32_t Src2Size, const uint32_t CmpLen);

/**< Sets the destination memory of given length with given data */
uint32_t Xil_SMemSet (void *Dest, const uint32_t DestSize,
		 const uint8_t Data, const uint32_t Len);

/**< Copies source string to destination string */
uint32_t Xil_SStrCpy (uint8_t *DestStr, const uint32_t DestSize,
		 const uint8_t *SrcStr, const uint32_t SrcSize);

/**< Compares source string with destination string */
uint32_t Xil_SStrCmp (const uint8_t *Str1, const uint32_t Str1Size,
		 const uint8_t *Str2, const uint32_t Str2Size);

/**< Compares source string with destination string with constant time */
uint32_t Xil_SStrCmp_CT (const uint8_t *Str1, const uint32_t Str1Size,
		    const uint8_t *Str2, const uint32_t Str2Size);

/**< Concatenates source string to destination string */
uint32_t Xil_SStrCat (uint8_t *DestStr, const uint32_t DestSize,
		 const uint8_t *SrcStr, const uint32_t SrcSize);

/**< Waits for event timeout */
uint32_t Xil_WaitForEventSet(uint32_t Timeout, uint32_t NumOfEvents, volatile uint32_t *EventAddr, ...);

/**< Implements Read Modify Writes securely */
uint32_t Xil_SecureRMW32(uint32_t Addr, uint32_t Mask, uint32_t Value);

/**< Changes byte endianness of source buffer and copies it into destination */
uint32_t Xil_SChangeEndiannessAndCpy(void *Dest, const uint32_t DestSize,
		const void *Src, const uint32_t SrcSize, const uint32_t CopyLen);

/**< Changes byte endianness of buffer and copies it into the same buffer */
uint32_t Xil_SReverseData(void *Buf, uint32_t Size);

/**< Copies data from 64 bit address Src to 64 bit address Dst */
void Xil_MemCpy64(uint64_t DstAddr, uint64_t SrcAddr, uint32_t Cnt);

#ifdef __cplusplus
}
#endif

#endif	/* XIL_SUTIL_H_ */
/**
* @} End of "addtogroup common_utilities".
*/
