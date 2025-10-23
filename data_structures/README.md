# Introduction
This sub directory is a fun experiment to try out data structure implementation in c. This would be very easy using OOP languages like c++ but I want to challenge myself to have a deeper understanding of the process that is required for implementing these behind the scenes.

# Data Structures
The data Structures that I am going to implement are as follows:
* [ ] Linked lists
* [ ] Binary Search Tree (or sorted Binary tree)
* [ ] Queue (FIFO -> First In Last Out)
* [ ] Stack (LIFO -> Last In First Out)

## Linked list
A linked list is the most fundamental data type that is the basis for implementing the later structures. There are three different types of linked lists:
* Single
* Double
* Circular
In each implementation an idea of a node that at minimum contains two data members:

|data|next|
|----|----|
|any type|pointer to next node|

If the next pointer is NULL we can determine that the current node is the end node. In C issues arise as well in relation to the type of data. If we want to expand support for more linked lists it would require more definitions or more complex functions in relation the `ll_create()` method. For my specific implementation I just used a int for the data type. 
## Linked list Documentation
### Functions
#### `ll_node_t *ll_create(int data)`
Function to create a node with data value. Upon success this will return a pointer to the node or `NULL` in the event of an error.
#### `void ll_delete(ll_node_t *head)`
Function that removes linked list and deallocates memory from heap.
#### `void ll_print_list(ll_node_t *head)`
Function to print out the contents of linked list to stdout stream.
#### `ll_node_t *ll_start_insert(ll_node_t *head, int data)`
Function to create a new node with data and set its next pointer to previous head. Upon success this will return a pointer to the new head node otherwise will return `NULL`
#### `int ll_end_insert(ll_node_t *head, int data)`
Function to insert new node with data at the end of the linked list.
### Data Types
#### `ll_node_t`
<center>Data Members</center>

|type|name|description|
|----|----|-----------|
|int|data|Data stored at node|
|ll_node_t *|next|Pointer to next node|

