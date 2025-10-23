/*
 * Programmer: Matas Noreika 2025-10-23 14:57
 * Purpose: Implementation of linked list abstract data type
 * All functions and data types are prefixed with ll_
*/

#include <stdio.h>
#include <stdlib.h>

//type defintions
//type definition of node type for linked list
typedef struct ll_node{
  int data; //data information of node
  struct ll_node *next; //pointer to next node
}ll_node_t;

//function prototypes
ll_node_t *ll_create(int data);
void ll_delete(ll_node_t *head);
void ll_print_list(ll_node_t *head);
int ll_end_insert(ll_node_t *head, int data);

int main(int argc, char** argv){ //start of main method

  ll_node_t *node_head = ll_create(10);
  ll_end_insert(node_head, 12);
  ll_end_insert(node_head, 24);
  ll_end_insert(node_head, 56);
  ll_end_insert(node_head, 180);

  //print out our current list
  ll_print_list(node_head);
  
  //free up memory in heap used by linked list
  ll_delete(node_head);
  
  printf("Successfully freed linked list memory\n");

  return 0;
} //end of main method

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

//function defintions
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

void ll_delete(ll_node_t *head){
  ll_node_t *current_node = head;
  ll_node_t *next_node;
  do {
    next_node = current_node->next; //assign our next node
    free(current_node);// free current_node memory
    current_node = next_node; //set our current_node to next node
  }while(current_node != NULL); //repeat while the node is not a null referance
}

