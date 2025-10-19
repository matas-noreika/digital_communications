/*
 * Programmer: Matas Noreika 2025-10-19 16:49
 * Purpose: Header api for ca1 RLE application
*/

//start of header guard
#ifndef __CA1_H__
#define __CA1_H__

#include <stdio.h> //libc header for i/o
#include <unistd.h> //POSIX c header for general uitilies

//declerations of function prototypes
void rle_encode_stream(char *rle_filename);
void rle_encode_file(char *filename,char *rle_filename);

#endif
//end of header guard
