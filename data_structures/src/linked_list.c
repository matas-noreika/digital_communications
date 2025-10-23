/*
 * Programmer: Matas Noreika 2025-10-23 14:57
 * Purpose: Implementation of linked list data structure
 * All functions and data types are prefixed with ll_
*/

#include "linked_list.h"

void ll_print_list(ll_node_t *head){
  ll_node_t *current_node = head;
  int index = 0;
  printf("Start\nIndex:\tdata\tnext\n");
  do{
    printf("%5d:\t%4d\t%4p\n", index, current_node->data, current_node->next);
    current_node = current_node->next;
    index++;
  } while(current_node != NULL);
  printf("End\n");
}

ll_node_t *ll_create(int data){
  ll_node_t *node_ptr = (ll_node_t *) malloc(sizeof(ll_node_t));
  node_ptr->data = data;
  node_ptr->next = NULL;
  return node_ptr;
}

/*void ll_index_insert(int data, int index){
  
}*/

int ll_end_insert(ll_node_t *head, int data){

  printf("head node: %p\n", head);

  ll_node_t *last_node = head;
  ll_node_t *next_node = head->next;
  
  //traverse to the end node
  while(next_node != NULL){
    last_node = next_node;
    next_node = next_node->next;
  }
  
  printf("last node: %p\n", last_node);

  last_node->next = ll_create(data);
  
  //failed to add new node
  if (last_node->next == NULL){
    return 1;
  }

  return 0;

}

ll_node_t *ll_start_insert(ll_node_t *head, int data){
  ll_node_t *new_head = ll_create(data);
  
  //if we sucessful created a new node
  if(new_head != NULL){
    new_head->next = head;
  }

  return new_head;
}

void ll_delete(ll_node_t *head){
  ll_node_t *current_node = head;
  ll_node_t *next_node;
  do {
    next_node = current_node->next; //assign our next node
    free(current_node);// free current_node memory
    current_node = next_node; //set our current_node to next node
  }while(current_node != NULL); //repeat while the node is not a null referance
}

