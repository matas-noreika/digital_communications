/*
 * Programmer: Matas Noreika 2025-10-09 00:26
 * Purpose: Implementation file of divu API
*/

#include "divu.h"

//Function to read from divu file the contents of the header
void divu_get_header(uint8_t *filename, divu_header_ptr header){
  //open file
  //read first 128 bytes into header pointer
  //close file
}

void divu_print_image_data(uint8_t **image_data, uint16_t width, uint16_t height){

  for(uint16_t row = 0; row < width; row++){
    for(uint16_t col = 0; col < height; col++){
      printf("data[%d][%d] = %d", row, col, image_data[row][col]);
    }
  }

}

//Function to compress data using RLE(Run Length Encoding)
//Translates width x height image data matrix into RLE compressed data
void divu_compress_data(uint8_t **image_data, uint8_t **compressed_data, uint16_t width, uint16_t height, size_t *arraySize){
  
  //variable to keep track of which index of the compressed data we are at
  uint16_t pos = 0;

  //allocate memory for compressed data (100 bytes)
  *compressed_data = (uint8_t *) calloc(100, sizeof(uint8_t));
  
  //initialise count variable to count the repetitions of colors (will use bits per pixel from header)
  //currently assumes image data is 1 bpp
  uint16_t count = 0;
  
  //value to store current color
  uint8_t color = 0;
  
  //loop through all bytes in row's & columns
  for(uint16_t row = 0; row < width; row++){
    for(uint16_t col = 0; col < height; col++){
      
      //current byte we are operating on
      uint8_t byte = image_data[row][col];
      
      //loop through each bit
      for(uint8_t i = 8; i >= 1; i--){
        
        //set the bit mask to the current bit position
        uint8_t mask = (1<<(i-1));
        //set the color to the bit value 1 or 0
        uint8_t newColor = ((byte & mask) >> (i-1));
         
        //check if color changed
        if(color != newColor){
          //if its first byte and first bit
          if (!row && !col && i == 8){
            //set the color
            color = newColor;
            //incrament the count
            count++;
            //move to next bit
            continue;
          }

          #ifdef DEBUG
            printf("Color changed\n");
            printf("Writing Pos: %d, Count: %d, color: %d\n", pos, count, color);
          #endif 

          //write count byte followed by color byte
          *compressed_data[pos] = (uint8_t) count;
          *compressed_data[pos++] = (uint8_t) (count >> 8);
          *compressed_data[pos++] = color;
           
          //reset all variables
          pos++;
          color = newColor;
          count = 1;
          continue;

        }

        //count overflow saftey check
        if (count == 0xFFFF){

          #ifdef DEBUG
            printf("overflow value\n");
            printf("Writing Pos: %d, Count: %d, color: %d\n", pos, count, color);
          #endif

          //write count byte followed by color byte
          *compressed_data[pos] = (uint8_t) count;
          *compressed_data[pos++] = (uint8_t) (count >> 8);
          *compressed_data[pos++] = color;
 
          //reset variables
          pos++;
          count = 1;
          continue;
        } 
        
        //incrament count
        count++;
      }
    }
  }

  #ifdef DEBUG
    printf("Writing Pos: %d, Count: %d, color: %d\n", pos, count, color);
    //printf("Pointer address: %X\n", *compressed_data[0]);
  #endif

  //write count byte's followed by color byte
  *(*compressed_data + pos++) = (uint8_t) count;
  *(*compressed_data + pos++) = (uint8_t) (count >> 8);
  *(*compressed_data + pos++) = (uint8_t) color;
  
  *compressed_data = realloc(*compressed_data, sizeof(uint8_t) * pos);
  *arraySize = pos;//set the final size of array

}

//Function to decompress data from RLE compression
//The function function that decompresses 1D compressed_data into 2D image_data
void divu_decompress_data(uint8_t *compressed_data, uint8_t *image_data,uint16_t width, uint16_t height){
  
  
}
