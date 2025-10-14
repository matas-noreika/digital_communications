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
### `uint8_t* divu_compress_data(uint8_t *image_data, uint16_t width, uint16_t height, size_t *arraySize)`
Function that will compress passed image data using Run length encoding. The Function assumes the image_data is a uint8_t** casted to uint8_t.
The pointer returned is dynamically allocated so a call to free is required once data is no longer required.
### `uint8_t* divu_decompress_data(uint8_t *compressed_data, uint16_t width, uint16_t height)`
Function to return image data from compressed Run length encoded data. Returns a pointer to pointers.
