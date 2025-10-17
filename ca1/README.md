# Introduction
The following directory holds an application to encode data using Run Length Encoding(RLE). The application depends on a library called data_analysis to analyse particular aspects of the data. The source code and additional information regarding data_analysis can be found in the data_analysis directory under the same github repository.
# RLE specification
* Input data is to be provided in text format only using alpha characters \[a-Z\]
* The format of the output file will include a sequence of entries with a unsigned char referring to which character is repeated, followed by a unsigned integer value indication the count of repetitions. Example:

|uchar|uint|
|-----|-----|
|0x61|0x0020|
|a|32|
# application specifications
The application to encode the text data *.txt into (RLE) *.rle file format may accept one or more of the following input options:
* File input
* Stream (stdin)
* Command line arguments (argv)
* Hardcoded static variable #define char\[256\]

The application must perform some data analysis on the input data. Examples:
* most frequent character
* least frequent character
* compression ratio

