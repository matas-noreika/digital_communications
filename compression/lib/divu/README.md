# divu library
The following library exposes an API for handling and manipulating files with the .divu file extension.
# Documentation
## Types
### `divu_header_t`
Definition of divu header struct with the following data members:
|byte offset|name|size|
|-----------|----|----|
|0|width|2|
|2|height|2|
|4|reserved|124 |
### `divu_header_ptr`
Definition of pointer to divu_header_t variable.
## Functions
### `void divu_get_header(char *filename, divu_header_ptr)`
Function that will read from divu file with provided filename. The contents of the header will be stored in the divu_header_ptr reference passed.
### `char* divu_compress_data(char **image_data)`
Function that will compress passed image data using Run length encoding.
### `char** divu_decompress_data(char *compressed_data)`
Function to return image data from compressed Run length encoded data.
