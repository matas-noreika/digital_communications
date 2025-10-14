/*
 * Programmer: Matas Noreika 2025-10-08 22:54
 * Purpose: Program tht will generate a .divu file that holds data information for a 256x256 pixel white image
*/

#include "divu.h"//include header for divu extension

//Macros for raw image data
#define ROW_LENGTH 32
#define COL_LENGTH 32

int main(int argc, char** argv){//start of main method
  
  //allocate memory for image data
  //make the image_data pointer point to an array of 32 uint8_t*
  uint8_t **image_data = (uint8_t **) calloc(ROW_LENGTH, sizeof(uint8_t *));

  //loop through all row's
  for(uint8_t i = 0; i < ROW_LENGTH; i++){
    
    //make row pointer point to memory address of 32 uint8_t
    image_data[i] = (uint8_t *) calloc(COL_LENGTH, sizeof(uint8_t));

  }

  //open raw image data file 256x256 pixels or 32x32 bytes
  FILE *raw_f_ptr = fopen("data/raw/whitebox.bin", "rb");
  
  //read image data into ram
  for(uint8_t row = 0; row < ROW_LENGTH; row++){
    //read all column data straight into row
    fread(image_data[row],sizeof(uint8_t),COL_LENGTH,raw_f_ptr);
  }

  //close the raw data file
  fclose(raw_f_ptr);

  #ifdef DEBUG
    //loop through all the data
    for(uint8_t row = 0; row < ROW_LENGTH; row++){
      
      printf("row %02d ",row+1);

      for(uint8_t col = 0; col < COL_LENGTH; col++){

        printf("%x", image_data[row][col]);

      }
      printf("\n");
    }
  #endif

  //generate a divu file header
  divu_header_t header = {
    .width = 256,
    .height = 256
  };
  
  #ifdef DEBUG
    //debugging print content
    printf("size of header: %d\nwidth: %d, height: %d\n", sizeof(header), header.width, header.height);
  #endif
  
  uint8_t *compressed_data = NULL;
  size_t compressed_data_size = 0;

  //call function to compress data
  divu_compress_data(image_data, &compressed_data, ROW_LENGTH, COL_LENGTH, &compressed_data_size);
 
  #ifdef DEBUG
    //debug print to show the size of compressed_data
    printf("Data size: %d\n", compressed_data_size);
#endif

  //create whitebox.divu
  FILE *divu_f_ptr = fopen("data/output/whitebox.divu", "wb");

  //write the header to file
  fwrite(&header, sizeof(header), 1, divu_f_ptr);

  //write compressed_data content to file
  fwrite(compressed_data, sizeof(uint8_t), compressed_data_size, divu_f_ptr);

  //close the whitebox.divu
  fclose(divu_f_ptr);
  
  #ifdef DEBUG
    printf("Freeing memory\n");
  #endif

  //deallocate dynamic memory
  free(compressed_data);
  
  for(uint8_t row = 0; row < ROW_LENGTH; row++){
    free(image_data[row]);
  }

  free(image_data);

  return 0;

}//end of main method
