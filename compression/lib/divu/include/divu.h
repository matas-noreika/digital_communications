/*
 * Programmer: Matas Noreika 2025-10-08 22:56
 * Purpose: API header for functionality realted to files of the .divu extension
*/

//start of header guard
#ifndef __DIVU_H__
#define __DIVU_H__

#include <stdio.h>//libc i/o header
#include <stdlib.h>
#include <stdint.h>//libc integer type header

//type definition of divu header
typedef struct{
  uint16_t width; //the width of the current image
  uint16_t height; //the height of the current image
  char padding[124]; //padding to extent header to size of 128 bytes
}divu_header_t;

//type definition of pointer to divu_header
typedef divu_header_t *divu_header_ptr;

//Helper function to print image data 2D matrix
void divu_print_image_data(uint8_t **image_data, uint16_t width, uint16_t height);

//Function to read from divu file the contents of the header
void divu_get_header(uint8_t *filename, divu_header_ptr header);

//Function to compress data using RLE
void divu_compress_data(uint8_t **image_data, uint8_t **compressed_data,uint16_t width, uint16_t height, size_t *arraySize);

//Function to decompress data from RLE compression
void divu_decompress_data(uint8_t *compressed_data, uint8_t *image_data,uint16_t width, uint16_t height);

#endif
//end of header guard
