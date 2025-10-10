/*
 * Programmer: Matas Noreika 2025-10-08 22:54
 * Purpose: Program tht will generate a .divu file that holds data information for a 256x256 pixel white image
*/

#include "divu.h"//include header for divu extension

int main(int argc, char** argv){//start of main method
  
  //generate a divu file header
  divu_header_t header = {
    .width = 256,
    .height = 256
  };
  
  //image data for column (will be repeated for 256 lines)
  uint16_t col_data = 0x2000; // 0x20 -> number of repetitions 0x00 -> colour associated with repetition
  
  //debugging print content
  printf("size of header: %d\nwidth: %d, height: %d\ncolumn data: %x\n", sizeof(header), header.width, header.height, col_data);
  
  //create whitebox.divu
  FILE *divu_f_ptr = fopen("whitebox.divu", "w");
  
  //write the header to file
  fwrite(&header, sizeof(header), 1, divu_f_ptr);

  //write ( 0x20 0x00 ) 256 times
  for(uint16_t i = 0; i <= 255; i++){
    fwrite(&col_data, sizeof(col_data), 1, divu_f_ptr);
  }

  //close the whitebox.divu
  fclose(divu_f_ptr);
  
  return 0;

}//end of main method
