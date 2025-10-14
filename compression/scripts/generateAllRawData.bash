# Programmer:  Matas Noreika 2025-10-10 12:18
# Purpose: Script that will generate all binary data into data/raw required for the applications

# function that will generate whitebox.bin
whitebox() {
  #remove existing whitebox.bin
  rm -f data/raw/whitebox.bin 2>/dev/null

  for row in $(seq 0 31); do

    for col in $(seq 0 31); do

      echo -e -n '\x00' >>data/raw/whitebox.bin

    done

  done
}

#call functions
whitebox
