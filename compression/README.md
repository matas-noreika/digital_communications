# Introduction
The following application is to showcase the topic of file compression. The following project holds many programs to generate multiple types files in a custom .divu extension and one application to de-compression the files into an image that will be rendered to the standard output stream.
# Run length encoding
Run length encoding (RLE) is a type of compression scheme that is best suited for long runs of identical information. Take the example of an image which is completely white with dimensions 256x256 pixels. If no RLE is used the image data would require 1024 bytes. If RLE is used we can read the image row by row and byte per byte keeping count of the number of similar colour pixels read. In the example all pixels are white therefore the final data would only require 3 bytes: 2 bytes for the value of repeating bytes in this case decimal 1024 and 1 byte for color information 0x00 (assuming white is 0).
# .divu file standard specifications
* The .divu file will consist of two sections header and data.
* The header section is a 128 byte block that holds relevant information for the file such as width, height used to know when to cut the stream of bytes into relevant rows.
* The data section is to immediately follow the header section at byte offset 128. The data presented will be in a long row.The first byte relates to the first byte of the image (top left corner).

_row breaks can be determined using the width variable in the header by dividing the width by 8 and adding a newline feed or similar inside the decompressed data_

# Testing methods
The divu file outputs are tested using command line tools like hexdump to view binary raw information and ls -l to view byte size of file.

# applications
## divu.h
Header API for handling files with divu extension. The API provides functions for compression and decompression. The header also provides type definitions for header information to be easily parsed.

## whitebox.exe
The whitebox program generates a file called whitebox.divu that holds the RLE compressed data of a 256x256 whitebox image.
