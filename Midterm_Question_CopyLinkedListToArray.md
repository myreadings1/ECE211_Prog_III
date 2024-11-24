
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void copyLinkedListToArray(struct Node* head, int arr[]) {
    int i = 0;
    while (head != NULL) {
        arr[i] = head->data;
        head = head->next;
        i++;
    }
}

int main() {
    // Create a sample linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Count the number of nodes in the linked list
    int n = countNodes(head);

    // Create an array to store the copied elements
    int arr[n];

    // Copy the linked list to the array
    copyLinkedListToArray(head, arr);

    // Print the array elements
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```

**Explanation:**

1. **Node Structure:** Defines a structure `Node` to represent a node in the linked list with `data` and `next` pointer.
2. **`countNodes` Function:** Iterates through the linked list to count the number of nodes.
3. **`copyLinkedListToArray` Function:** Iterates through the linked list, copying the `data` of each node to the corresponding index in the array.
4. **`main` Function:**
   - Creates a sample linked list.
   - Counts the number of nodes.
   - Creates an array of the same size as the number of nodes.
   - Calls the `copyLinkedListToArray` function to copy the linked list to the array.
   - Prints the array elements.

This code effectively copies the linked list to an array, demonstrating a clear and efficient approach.
