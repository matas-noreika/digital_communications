# Programmer: Matas Noreika 2025-10-17 09:08
# Purpose: Bash script to generate two text files -> random sequence of characters and repetitive sequence of characters. 
# Each file will contain a maximum file size of 65,536 bytes -> 256 x 256 characters.

# Function to replace/create random.txt
RandomTextFile(){
  for i in $(seq 1 65536); do
    rm -f 
    echo -ne $((97 + $RANDOM % 122)) 
}

#Function to replace/create repetitive.txt
repetitiveTextFile(){

}

#call functions on execution
RandomTextFile
repetitiveTextFile
