/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    // FILL THIS IN!
    Node* first = *list;
    if(first->next == NULL){
      return -1;
    }
    int save = first->val;
    *list = first -> next;
    free(first);
    return save;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    // initialize new head node, point to dereferenced head pointer of current list
    Node *head = make_node(val, *list);
    *list = head;
}

int swap(Node** list) {
  Node* first = *list;
  if(first->next == NULL){
    return -1;
  }
  Node* second = first->next;
  if(second->next == NULL){
    return -1;
  }
  Node* third = second->next;
  Node* fourth = third->next;

  first->next = third;
  third->next = second;
  second->next = fourth;

  return 1;
}

/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    // FILL THIS IN!
    Node *this = *list;
    // make sure the first node isn't the match
    if(this->val == val){
      pop(&this);
      return 1;
    }
    while(this->next != NULL){
      if(this->next->val == val){
        Node *temp = this->next;
        this->next = this->next->next;
        // temp->next = NULL;
        free(temp);
        return 1;
      }
      this = this->next;
    }
    return 0;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    // FIX THIS! -Emma

    Node* prev = *list;
    Node* curr = prev->next;
    Node* after = curr->next;

    prev->next = NULL;

    while(after != NULL){
      curr->next = prev;

      prev = curr;
      curr = after;
      after = curr->next;
    }
    curr->next = prev;
    *list = curr;
}

int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL); // pointer to NULL is 0

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    int val = swap(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
