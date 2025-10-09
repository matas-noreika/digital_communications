/*
 * Programmer: Matas Noreika 2025-10-08 22:56
 * Purpose: API header for functionality realted to files of the .divu extension
*/

//start of header guard
#ifndef __DIVU_H__
#define __DIVU_H__

#include <stdio.h>//libc i/o header
#include <stdint.h>//libc integer type header

//#pragma pack(1)
//type definition of divu header
typedef struct{
  uint16_t width; //the width of the current image
  uint16_t height; //the height of the current image
  char padding[124]; //padding to extent header to size of 128 bytes
}divu_header_t;

//type definition of pointer to divu_header
typedef divu_header_t *divu_header_ptr;

//Function to read from divu file the contents of the header
void divu_get_header(char*, divu_header_ptr);

//Function to compress data using RLE
char* divu_compress_data(char **);

//Function to decompress data from RLE compression
char** divu_decompress_data(char*);

#endif
//end of header guard
