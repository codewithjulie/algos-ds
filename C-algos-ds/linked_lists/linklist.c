#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node
{
    int num;
    struct node *next;
} node;





int main(void)
{
    // Create head
    node *head = NULL;

    // Create a node
    node *n;  // pointer to a node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->num = 2;  // value for node
    n->next = NULL;
    head = n;  // head points to 2

    // Add a node (head)
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> num = 1;
    n -> next = head;  // n points to 2
    head = n;  // head points to 1

    // Insert a node (middle/tail)

    node *cursor = malloc(sizeof(node));
    cursor = head;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->num = 3;
    n->next = NULL;

    while (cursor->next != NULL)
    {
        cursor = cursor->next;
    }
    
    cursor->next = n; // does not link 2 to 3
    //head->next->next = n; // links 2 to 3

    // printf("%i\n", cursor->num);


    // Delete a node
    cursor = head; // cursor points to 1
    node *cursor_2 = malloc(sizeof(node));
    cursor_2 = head;

    cursor_2 = cursor->next->next; // cursor_2 points to 3
    free(cursor->next);
    cursor->next = cursor_2;
    
    // int i = 0;
    // while (i < 3)
    // {
    //     cursor_2 = cursor->next;
    // }

    // free(cursor->next);

    // cursor->next = cursor_2;



    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        {
            // Within the node, we'll just print the number stored:
            printf("%i\n", tmp->num);
        }

}




