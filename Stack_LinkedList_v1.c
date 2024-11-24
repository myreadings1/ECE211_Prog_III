// C program to implement a stack using singly linked list
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Struct representing a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//////////////////////////////////////////
Node* createNode(int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
//////////////////////////////////////////
// Struct to implement stack using a singly linked list

//Node * head;

typedef struct Stack {
    Node* head;
} Stack;

//////////////////////////////////////////
// Constructor to initialize the stack
void initializeStack(Stack* stack) 
{ stack->head = NULL; }
//////////////////////////////////////////
// Function to check if the stack is empty
int isEmpty(Stack* stack) {
  
    // If head is NULL, the stack is empty
    return stack->head == NULL;
}
//////////////////////////////////////////
// Function to push an element onto the stack
void push(Stack* stack, int new_data) 
{
  
    // Create a new node with given data
    Node* new_node = createNode(new_data);

    // Check if memory allocation for the new node failed
    if (new_node == NULL) {
        printf("\nStack Overflow");
        return;
    }

    // Link the new node to the current top node
    new_node->next = stack->head;

    // Update the top to the new node
    stack->head = new_node;
}
//////////////////////////////////////////
// Function to remove the top element from the stack
void pop(Stack* stack) {
  
    // Check for stack underflow
    if (isEmpty(stack)) {
        printf("\nStack Underflow\n");
        return;
    }
    else {
      
        // Assign the current top to a temporary variable
        Node* temp = stack->head;

        // Update the top to the next node
        stack->head = stack->head->next;

        // Deallocate the memory of the old top node
        free(temp);
    }
}

// Function to return the top element of the stack
int peek(Stack* stack) {
  
    // If stack is not empty, return the top element
    if (!isEmpty(stack))
        return stack->head->data;
    else {
        printf("\nStack is empty");
        return INT_MIN;
    }
}

// Driver program to test the stack implementation
int main() {
  
    // Creating a stack
    Stack stack;
    //stack.head = NULL;

    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);

    // Print top element of the stack
    printf("Top element is %d\n", peek(&stack));

  
      // removing two elemements from the top
      printf("Removing two elements...\n");
    pop(&stack);
    pop(&stack);

    // Print top element of the stack
    printf("Top element is %d\n", peek(&stack));

    return 0;
}
