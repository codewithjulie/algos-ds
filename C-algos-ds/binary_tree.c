#include <stdio.h>
#include <stdlib.h>

// Dynamic data structure consisting of nodes
// Binary trees have at most 2 children

//HOMEWORK
//Determine the hight of a tree. 
//Draw tree

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void init_tree(struct node **root);
struct node ** search_date(struct node**node, int num);
void fill_tree(struct node**node, int num);
struct node ** search_data(struct node**node, int num);
void print_tree_data(struct node *node);
void print_tree(struct node *node);
void is_in_tree(struct node**node);
void free_tree(struct node**node);

int main(void) {
  int num;
  struct node *root;
  struct node **node_ptr;
  init_tree(&root); // = root = NULL;
  
  while(scanf("%d", &num) == 1) {
    node_ptr = search_data(&root, num);  // Function to find where to put node
    fill_tree(node_ptr, num);  // Function to place the node
  }

  print_tree(root);

  while(scanf("%d", &num) == 1) {
    node_ptr = search_data(&root, num);  // Function to find where to put node
    is_in_tree(node_ptr);  // Function to place the node
  }

  free_tree(&root);
  print_tree(root);
}

void init_tree(struct node **root) {
  *root = NULL;
}

struct node ** search_data(struct node**node, int num) {
  if (!(*node) || (*node)->data == num) {
    return node;
  }
  else if ((*node)->data < num) {
    return search_data(&(*node)->left, num);
  }
  else {
    return search_data(&(*node)->right, num);
  }
}

void fill_tree(struct node**node, int num) {
  if (!(*node)) {
    (*node) = malloc(sizeof(struct node));
    (*node)->data = num;
    (*node)->left = NULL;
    (*node)->right = NULL;
  }
  else {
    printf("fill_tree error: data already in a tree!\n");
  }
}

void print_tree(struct node *node) {
  if (!node)
    return;
  print_tree_data(node);
  printf("\n");
}

void print_tree_data(struct node *node) {
  if (!node) {
    return;
  }
  else {
    print_tree_data(node->left);
    printf("%d ", node->data);
    print_tree_data(node->right);
  }
}

void is_in_tree(struct node**node) {
  if (*node)
    printf("Yes!\n");
  else
    printf("Nope!\n");
}

void free_tree(struct node**node) {
  if (!(*node)) {
    return;
  }
  else {
    free_tree(&(*node)->left);
    free_tree(&(*node)->right);
    free(*node);
    (*node) = NULL;
  }
}