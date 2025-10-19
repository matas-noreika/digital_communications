# Introduction
The following directory holds an application to encode data using Run Length Encoding(RLE). The application depends on a library called data_analysis to analyse particular aspects of the data. The source code and additional information regarding data_analysis can be found in the data_analysis directory under the same github repository.
# RLE specification
* Input data is to be provided in text format only using alpha characters \[a-Z\]
* The format of the output file will include a sequence of entries with a unsigned char referring to which character is repeated, followed by a unsigned integer value indication the count of repetitions. Example:

|uchar|uint|
|-----|-----|
|0x61|0x00000020|
|a|32|
# application specifications
The application to encode the text data *.txt into (RLE) *.rle file format may accept one or more of the following input options:
* File input
* Stream (stdin)
* Command line arguments (argv)
* Hard-coded static variable #define char\[256\]

The application must perform some data analysis on the input data. Examples:
* most frequent character
* least frequent character
* compression ratio

The final output will be stored within `data/output` directory.

# ca1.exe
ca1.exe is an implementation using the [application specifications](#application-specifications). ca1.exe allows for two options for taking in input data. They are the following:
* -f \[path/filename.txt\] \[output_path/filename.rle\], reads from text file into rle file
* -s \[output_path/filename.rle\], reads from stdin stream into rle file

The project directory provides bash scripts to generate two text files into `data/raw`, one in a repetitive nature named repetitive.txt another in a random nature named random.txt . Both files are 256x256 or 65536 bytes in size.

To run the bash scripts use the following command:
```
chmod +x scripts/generateData.bash # gives execution permissions
./scripts/generateData.bash # runs the script
```

Now if you list the data/raw directory you should see:
```

data/
  |
  |--raw/
  |   |
  |   |--random.txt
  |   |
  |   |--repetitive.txt
  |
  |--output/
  |   |
  |   
```
## How to compile executable
To compile `ca1.c` into `bin/ca1.exe` ensure you are in ca1 directory and ensure you have gnu make installed on your system. Just call make and the makefile will handle all the process. To generate a specific file ensure you append the `bin/%.exe` where % is the target source c filename you wish to compile.
## file input example
Assuming the scripts were used to generate text files into `data/raw` use the following example to generate a rle encoded version of repetitive.txt:
```
bin/ca1.exe -f ./data/raw/repetitive.txt ./data/output/repetitive.rle
```
## stream input example
The stream option allows for piping of commands into the ca1.exe process. Use the following example to generate `data/output/commandLine.rle`:
```
for i in $seq(97 122); do echo -n $i; done | ./bin/ca1.exe -s ./data/output/commandline.rle
```
# additional notes
The method RLE used within ca1 is ideal for repetitive data. The stream input example the commandLine.rle file size is 290 bytes when the input size is 75 bytes. This shows a negative compression ratio which is not ideal. 
