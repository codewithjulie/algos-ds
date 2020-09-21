#include <stdio.h>
#include <stdlib.h>

// stack (last in first out) ex. stack of trays
// queue (first in first out) ex. line at CVS

// Define structure for a "node" calling it Stack
struct Stack { //do i need to use typedef in structs? - homework
  int data; // stores the value
  struct Stack *next; // points to the location of next item
};

void push(struct Stack **stack, int n);
void print_stack(struct Stack *stack);


int main(void) {
  int n; //data to push
  struct Stack *stack; // 

  stack = NULL; //for now we don`t have a stack, it is empty;
  while (scanf("%d", &n) != EOF) {
    push(&stack, n); //put in queue
  }
  print_stack(stack);
/*
  pop();  //get in queue
  free_stack();
*/
//some brilliant code

}

//node_new
//stack -> node_new -> node -> node -> node

// Adding a node into a linked list
void push(struct Stack **stack, int n) {
   struct Stack *tmp;  // create Stack structure called tmp
   tmp = malloc(sizeof(struct Stack));
   tmp->data = n;       // go into tmp and update data to n
   tmp->next = *stack;  // go into tmp and update next to 
   *stack = tmp;
   printf("ENTRY: %d\n", (*stack)->data);
}

void print_stack(struct Stack *stack) {
  struct Stack *tmp = stack;
  while (tmp) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}