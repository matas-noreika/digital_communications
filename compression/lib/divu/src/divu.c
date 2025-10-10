/*
 * Programmer: Matas Noreika 2025-10-09 00:26
 * Purpose: Implementation file of divu API
*/

#include "divu.h"

//Function to read from divu file the contents of the header
void divu_get_header(char *filename, divu_header_ptr header){
  //open file
  //read first 128 bytes into header pointer
  //close file
}

//Function to compress data using RLE
char* divu_compress_data(char **image_data){
  //loop through all bytes in row's & columns
  //set initial color to first byte
  //set count of color to 1
  //if color changes -> reset count and change color to new color
  //repeat till the end of the image data
}

//Function to decompress data from RLE compression
char** divu_decompress_data(char *compressed_data){
  
}
