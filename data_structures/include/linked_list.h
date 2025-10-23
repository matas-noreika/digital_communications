/*
 * Programmer: Matas Noreika 2025-10-23 17:22
 * Purpose: Header API for linked list data structure
 * All functions and data types are prefixed with ll_
*/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h> //libc printf
#include <stdlib.h> //libc malloc, calloc, free

//type defintions
//type definition of node type for linked list
typedef struct ll_node{
  int data; //data information of node
  struct ll_node *next; //pointer to next node
}ll_node_t;

//function prototypes
//creates a linked list
ll_node_t *ll_create(int data);
//deletes a linked list
void ll_delete(ll_node_t *head);
//prints a linked list's content to stdout
void ll_print_list(ll_node_t *head);
//inserts new node with data to end of linked list
//returns 0 if sucessful or 1 if failed
int ll_end_insert(ll_node_t *head, int data);
//insert new node with data to start of linked list
//returns new head pointer or Null if unsucessful
ll_node_t *ll_start_insert(ll_node_t *head, int data);

#endif
