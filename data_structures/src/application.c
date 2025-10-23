/*
 * Programmer: Matas Noreika 2025-10-23 17:27
 * Purpose: Application that showcases the use of data structures
*/

#include "linked_list.h"

int main(int argc, char** argv){ //start of main method

  ll_node_t *node_head = ll_create(10);
  ll_end_insert(node_head, 12);
  ll_end_insert(node_head, 24);
  ll_end_insert(node_head, 56);
  ll_end_insert(node_head, 180);
  node_head = ll_start_insert(node_head, 250);

  //print out our current list
  ll_print_list(node_head);
  
  //free up memory in heap used by linked list
  ll_delete(node_head);
  
  printf("Successfully freed linked list memory\n");

  return 0;
} //end of main method

