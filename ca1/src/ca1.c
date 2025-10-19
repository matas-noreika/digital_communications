/*
 * Programmer: Matas Noreika 2025-10-19 14:01
 * Purpose: Application to take input in the format of text via (file, stdin, command line arguments) and output RLE encoded format .rle file
*/

#include <stdio.h>

void rle_encode_file(char *filename,char *rle_filename);

int main(int argc, char** argv){//start of main method
  
  //the output directory of rle files
  char fileout_dir[] = "data/output";

  //the description of how to use application
  char description[] = "The program accepts the following argument flags:\n"
                       "-f -> read from file, argument followed by path/filename output_path/filename,\n"
                       "-s -> Read from stdin";

  //check if no arguments were supplied
  if (argc -1 <= 0){
    //print the description
    printf("%s\n", description);
    return 0;
  }
  
  char *flag = argv[1];
  
  //check if flag format is correct
  if(flag[0] != '-'){
    printf("Invalid flag format!\n");
    printf("%s\n", description);
    return 1;
  }

  //switch case for read input operation
  switch (flag[1]){
    case 'f': //reading from file
      
      //invariant check on filename
      if(argc-1 < 2){
        printf("filename not provided!\n");
        printf("%s\n", description);
        return 1;
      }else if (argc-1 < 3) {
        printf("output_path not provided\n");
        printf("%s\n", description);
        return 1;
      }
      
      //encode the file
      rle_encode_file(argv[2], argv[3]);
      break;

    case 's': // reading from stdin (stream)
      
      break;
    
    default: //invalid flag format or flag
      printf("Invalid flag format!\n");
      printf("%s\n", description);
  }

  return 0;
}//end of main method

//function to encode a text file into rle encoded .rle file
//will use relative path to the directory of execution to store file
void rle_encode_file(char *filename, char *rle_filename){
  FILE *txtfile_ptr = fopen(filename, "r+");

  //failed to open file
  if(txtfile_ptr == NULL){
    fprintf(stderr,"Failed to open text file!\n");
    return;
  }
  
  #ifdef DEBUG
    printf("rle filename: %s\n", rle_filename);
  #endif

  //open file or create
  FILE *rlefile_ptr = fopen(rle_filename, "w+");
  
  //failed to open file
  if(rlefile_ptr == NULL){
    fprintf(stderr,"Failed to open rle file!\n");
    fclose(txtfile_ptr);
    return;
  }

  //the current character we are counting repetitions for
  char current_char;
  //the next character we are comparing
  char next_char;
  //count variable to store the repetitions of a character
  unsigned int count = 1;
  //read first byte in to set current_char
  fread(&current_char, sizeof(char), 1, txtfile_ptr);
  
  #ifdef DEBUG
    printf("Current char: %c\n", current_char);
  #endif

  while(fread(&next_char, sizeof(char), 1, txtfile_ptr)){//start of read loop

    //character changed write [char, count], then reset
    if(current_char != next_char){
      
      //write the character
      fwrite(&current_char, sizeof(char), 1, rlefile_ptr);
      //write the count
      fwrite(&count, sizeof(int), 1, rlefile_ptr);

      #ifdef DEBUG
        printf("Writing: %c %u\n",current_char, count);
      #endif

      //reset the counter and current character
      current_char = next_char;
      count = 1;
      continue;
    }
    
    //overflow happended
    if (!(count + 1)){
      //write the character
      fwrite(&current_char, sizeof(char), 1, rlefile_ptr);
      //write the count
      fwrite(&count, sizeof(int), 1, rlefile_ptr);

      #ifdef DEBUG
        printf("Writing: %c %u\n",current_char, count);
      #endif

      count = 1;
      continue;
    }

    //incrament count
    count++;

  }//end of read loop
  
  //write the character
  fwrite(&current_char, sizeof(char), 1, rlefile_ptr);
  //write the count
  fwrite(&count, sizeof(int), 1, rlefile_ptr);

  #ifdef DEBUG
    printf("Writing: %c %u\n",current_char, count);
  #endif
 

  //close files
  fclose(txtfile_ptr);
  fclose(rlefile_ptr);

  #ifdef DEBUG
    printf("Successfully added data to rle file\n");
  #endif

}
