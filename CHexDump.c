/******************************************************************************
* \file      CHexDump.c
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

#include "CHexDump.h"


#define BYTES_PER_LINE 16


#if defined(__clang__)
#pragma clang unsafe_buffer_usage begin
#endif /* defined(__clang__) */


/******************************************************************************
**  Prints a hex + ASCII dump of a memory buffer.
*/
void HEXDUMP_Memory(const unsigned char* buffer, size_t length, size_t start_offset)
{
    size_t offset;
    size_t line_len;
    size_t i;
    unsigned char c;

    for (offset = 0; offset < length; offset += BYTES_PER_LINE)
    {
        line_len = (length - offset > BYTES_PER_LINE) ? BYTES_PER_LINE : (length - offset);

        /* Print offset */
        printf("%08zx  ", start_offset + offset);

        /* Print hex values */
        for (i = 0; i < BYTES_PER_LINE; i++)
        {
            if (i < line_len)
                printf("%02x ", buffer[offset + i]);
            else
                printf("   ");
            if (i == 7) printf(" ");
        }

        /* Print ASCII representation */
        printf(" |");
        for (i = 0; i < line_len; i++)
        {
            c = buffer[offset + i];
            printf("%c", isprint(c) ? c : '.');
        }
        printf("|\n");
    }

    return;
}


/******************************************************************************
**  Reads from file and prints a hexdump.
*/
int HEXDUMP_File(const char* file_name)
{
    FILE* fp;
    unsigned char buffer[BYTES_PER_LINE];
    size_t bytesRead;
    size_t offset;

    offset = 0;

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif /* _MSC_VER */

    fp = fopen(file_name, "rb");

#ifdef _MSC_VER
#pragma warning(default:4996)
#endif /* _MSC_VER */

    if (!fp) 
    {
        printf("Error opening file\n");
        return(-1);
    }

    while ((bytesRead = fread(buffer, 1, BYTES_PER_LINE, fp)) > 0)
    {
        HEXDUMP_Memory(buffer, bytesRead, offset);
        offset += bytesRead;
    }

    fclose(fp);

    return(0);
}


#if defined(__clang__)
#pragma clang unsafe_buffer_usage end
#endif /* defined(__clang__) */
