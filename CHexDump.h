/******************************************************************************
* \file      CHexDump.h
* \version   2025.03.18
* \author    Peter Potrok ( @ignackocom )
*            ignacko.com@outlook.com
*            https://github.com/ignackocom
* \copyright Copyright (c) 1994 - 2025
*            MIT License (see License.txt file)
* \brief     C Hex Dump library
*            C89, C99 and >C99 compatible, CPP compatible, Embedded C compatible
* \details
*
* \see       https://github.com/ignackocom
*            and other resources
******************************************************************************/

#ifndef CHEXDUMP_H
#define CHEXDUMP_H      20250318L


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#ifdef __cplusplus
extern "C" {
#endif

    /******************************************************************************
     * \brief
     *	Prints a hex + ASCII dump of a memory buffer.
     *
     * \param
     *	buffer - Data to print.
     * \param
     *	length - Data length.
     * \param
     *	start_offset - Start offset.
     *
     * \return
     *	Nothing (void).
     *
     */
    void HEXDUMP_Memory(const unsigned char* buffer, size_t length, size_t start_offset);


    /******************************************************************************
     * \brief
     *	Reads from file and prints a hexdump.
     *
     * \param
     *	file_name - File name with path to print.
     *
     * \return
     *	0 success, <0 error
     *
     */
    int HEXDUMP_File(const char* file_name);

#ifdef __cplusplus
}
#endif


#endif /* CHEXDUMP_H */
