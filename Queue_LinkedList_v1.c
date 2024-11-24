// C program to implement the queue data structure using
// linked list
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure representing a single node in the linked
// list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Node * head;
//struct Node * head;
// Function to create a new node
///////////////////////////////////////////////////
Node* createNode(int new_data)
{
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
///////////////////////////////////////////////////
// Structure to implement queue operations using a linked
// list
typedef struct Queue {

    // Pointer to the front and the rear of the linked list
//    Node *front, *rear;
    Node *head, *tail;
} Queue;
/////////////////////////////////////////////////

// Function to create a queue
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}
//////////////////////////////////////////////////////////////
// Function to check if the queue is empty
int isEmpty(Queue* q1)
{

    // If the front and rear are null, then the queue is
    // empty, otherwise it's not
    if (q1->head == NULL && q1->tail == NULL) {
        return 1;
    }
    return 0;
}
////////////////////////////////////////////////////////////////
// Function to add an element to the queue
void enqueue(Queue * que, int new_data)
{

    // Create a new linked list node
    Node * new_node = createNode(new_data);

    // If queue is empty, the new node is both the front
    // and rear
    if (que->tail == NULL) 
    {
        que->head = new_node;
        que->tail = new_node;
        return;
    }

    // Add the new node at the end of the queue and
    // change rear
    que->tail->next = new_node;
    que->tail = new_node;
}
////////////////////////////////////////////////////////////////

// Function to remove an element from the queue
void dequeue(Queue* q1)
{

    // If queue is empty, return
    
    if (isEmpty(q1) == 1) 
    {
        printf("Queue is Empty\n");
        return;
    }

    // Store previous front and move front one node
    // ahead
    Node * temp = q1->head;
    q1->head = q1->head->next;

    // If front becomes null, then change rear also
    // to null
    if (q1->head == NULL)
        q1->tail = NULL;
    
    printf("Dequeued elem %d: \n", temp->data);
    // Deallocate memory of the old front node
    free(temp);
}
/////////////////////////////////////////////////////////
///////////////////////////////////////////////
void print_queue (Queue* q1)
{
    // If queue is empty, return
    
    if (isEmpty(q1) == 1) {
        printf("Queue is Empty\n");
        return;
    }

    Node * temp = q1->head;

    //while ( temp->next != NULL )
    while ( temp  != NULL )
    {
        printf (" %d : ", temp->data);

        temp = temp->next;

    }

printf ("\n");
}


////////////////////////////////////////////////////////////////
// Function to get the front element of the queue
/*int getFront(Queue* q)
{

    // Checking if the queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->front->data;
}
///////////////////////////////////////////////
// Function to get the rear element of the queue
int getRear(Queue* q)
{

    // Checking if the queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->rear->data;
}
*/
///////////////////////////////////////////////////
// Driver code
int main()
{
    Queue* q = createQueue();

    // Enqueue elements into the queue
//    enqueue(q, 10);
//    enqueue(q, 20);

//    enqueue(q, 25);


  //  printf("Queue Front: %d\n", getFront(q));
  //  printf("Queue Rear: %d\n", getRear(q));
//    print_queue( q);
    // Dequeue elements from the queue
//    dequeue(q);

//    print_queue( q);

int elem;
int StopLoop = 0;
int UserChoice = 0;

while ( StopLoop == 0 )
{


    printf ("1- Enqueue element. \n" );
    printf ("2- Dequeue element. \n" );
    printf ("3- Print Queue. \n" );
    printf ("4- Exit. \n" );
    printf ("Select a choice:\n");
    
    //scanf (" %d ", &UserChoice);
    scanf("%d", &UserChoice);

    switch ( UserChoice )
    {

        case 1:

            printf ("Enter Elem:");
            scanf ("%d", &elem );
            enqueue(q, elem);

        break;

        case 2:
            dequeue(q);
        //    printf ("");
        break;    

        case 3:
            print_queue(q);
        break;     

        case 4:
            StopLoop = 1; 
            //exit(0);
        break;

        default:
        printf("Invalid Choice..! \n");

    // end switch
    }
// End while loop
}

    return 0;

// end main
}

