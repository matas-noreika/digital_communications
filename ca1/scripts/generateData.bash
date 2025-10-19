# Programmer: Matas Noreika 2025-10-17 09:08
# Purpose: Bash script to generate two text files -> random sequence of characters and repetitive sequence of characters.
# Each file will contain a maximum file size of 65,536 bytes -> 256 x 256 characters.

# Function to replace/create random.txt
RandomTextFile() {
  rm -f data/raw/random.txt 2>/dev/null || true
  touch data/raw/random.txt
  for i in $(seq 1 65536); do
    num=$(($RANDOM % (122 - 97 + 1) + 97))
    printf -v hex '%x' "$num"
    echo -ne "\x$hex" >>data/raw/random.txt
  done
}

#Function to replace/create repetitive.txt
repetitiveTextFile() {
  rm -f data/raw/repetitive.txt 2>/dev/null || true
  touch data/raw/repetitive.txt
  for i in $(seq 1 65536); do
    echo -n "a" >>data/raw/repetitive.txt
  done
}

#call functions on execution
RandomTextFile
repetitiveTextFile
