/*******************************************************************************
*
* Program: Queue Data Structure & Operations (Linked List Based)
*
* Description: An implementation of the queue data structure in C using a 
* linked list as the underlying data structure.  To learn more about queues see:
* https://en.wikipedia.org/wiki/Queue_(abstract_data_type).
*
* YouTube Lesson: https://www.youtube.com/watch?v=YjxKYxpf51E 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// We use a linked list as the underlying data structure to implement the queue,
// where the queue will maintain a pointer to the head of the linked list and
// the tail.
//
//      head         tail
//         |         |
//         4 -> 5 -> 6 -> null
//
// Each node in the linked list will point to the next in the chain except the
// tail which will point to NULL to indicate that it is the tail.  New elements
// will be enqueued by inserting a node at the tail (making this node the new
// tail), and elements will be dequeued be removing the head node and returning 
// the value stored at that node (making the next node the head node).  
//
// Inserting a new value onto the queue is called enqueuing, and removing a 
// value from the queue is called dequeuing.  Queues often allow for a peek 
// operation that allows us to view the value stored at the head of the 
// queue without dequeuing the value.  Because the values are removed from the 
// queue in the same order they are inserted we say the queue is a first in 
// first out (FIFO) data structure.  It works like a grocery store line in 
// this sense, where the customers to first enter the line are the first to 
// leave the line.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Declare Node struct that defines the individual nodes of the linked list 
// underlying our queue.  Each node will store an integer and a pointer to the
// next node.
typedef struct Node
{
  int value;
  struct Node *next;
} Node;

// Declare Queue struct that defines the Queue, it will maintain pointers to the
// head and tail nodes, and keep track of the size of the queue (i.e. the number
// of elements in the queue).
typedef struct
{
  Node *head;
  Node *tail;
  int size;
} Queue;


// We implement the below library of functions for working with queues.
Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);


// Test out the library of queue functions
int main(void)
{
  // Create a queue
  Queue *queue = create_queue();
  
  // The queue should initially be empty
  if (is_empty(queue)) printf("Queue is empty.\n");
  
  // Try to enqueue the value 4 onto the queue
  enqueue(queue, 4);
  
  // The queue should not be empty now
  if (!is_empty(queue)) printf("Queue is not empty.\n");
  
  // Enqueue the values 5 and 6 onto the queue
  enqueue(queue, 5);
  enqueue(queue, 6);
  
  // The queue size should now be 3
  printf("Queue size: %d\n", size(queue));
  
  
  // We'll try using the peek and dequeue operations.  We'll declare a bool 
  // variable to store the status returned via "pass-by-pointer", and a variable
  // value to store the value peek'ed or dequeued.
  bool status = false;
  int value = 0;
  
  // Peek at the value stored at the head of the queue, which should be 4
  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  // Now dequeue the value
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  

  // Peek and dequeue the next two values 5 and 6
  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  
  value = peek(queue, &status);
  if (status) printf("Peek successful: %d\n", value);
  
  value = dequeue(queue, &status);
  if (status) printf("Dequeue succesful: %d\n", value);
  
  
  // Now the queue should be empty, so both peek and dequeue should fail with
  // the variable status being set to false as a result.
  value = peek(queue, &status);
  if (!status) printf("Peek unsuccessful.\n");
  
  value = dequeue(queue, &status);
  if (!status) printf("Dequeue unsuccesful.\n");
  

  // destroy/delete the queue 
  destroy_queue(queue);
  
  return 0;
}


// Returns a pointer to a new empty queue on the heap
Queue *create_queue()
{
  // Use malloc() to allocate space for a Queue struct, store the pointer to
  // the Queue struct
  Queue *queue = malloc(sizeof(Queue));
  
  // Initially the queue is empty so set head and tail to point to NULL and size
  // to zero
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  
  // Return the pointer to the Queue struct
  return queue;
}


// Returns the size of the queue.  We could just directly use the size member
// of the Queue struct, but we could also say that our goal is to give the 
// user a library of functions which does not require them to access the 
// Queue struct members directly in which case implementing a size function
// would make sense.
int size(Queue *queue)
{
  return queue->size;
}


// Returns true if the queue is empty and false if it is not
bool is_empty(Queue *queue)
{
  return (queue->size == 0);
}


// Returns the value stored at the head of the queue.  Sets the bool variable
// pointed to by status to false if the queue is empty to indicate that the 
// peek operation was unsuccessful (we cannot peek at the head of an empty
// queue...), otherwise it is set to true to indicate the operation was 
// successful.  We call this approach "pass-by-pointer" or "pass-by-reference".
int peek(Queue *queue, bool *status)
{
  // If the queue is empty, we set the bool variable pointed to by status to
  // false and return NULL.  We can't just return NULL to indicate that the 
  // peek was unsuccessful as NULL will evaluate to '0' and the user of this
  // function would not know whether 0 was the value peek'ed or if the 
  // operation failed.  So instead we rely on the second special status 
  // parameter to indicate this.
  if (is_empty(queue))
  {
    *status = false;
    return NULL;
  }
  
  // If the queue isn't empty, set the bool variable pointed to by status to 
  // true to indicate the peek operation was successful and return the value 
  // stored at the head node of the list/queue.
  *status = true;
  return queue->head->value;
}


// Enqueues the value onto the queue (inserts the value onto the queue).  
void enqueue(Queue *queue, int value)
{
  // Create a new Node struct to store the value by first allocating space for 
  // new Node and having newNode store the pointer to this new Node.
  Node *newNode = malloc(sizeof(Node));
  
  // Store the value in this new node, and because it will be the new tail have
  // it point to NULL as the next node.
  newNode->value = value;
  newNode->next = NULL;
  
  // If the queue is empty then this is the only node, and we can set both head
  // and tail to point to this new node.
  if (is_empty(queue))
  {
    queue->head = newNode;
    queue->tail = newNode;
  }
  // Otherwise set the current tail node to point to this new node (instead of 
  // NULL) and update the Queue struct's tail pointer to point to this new Node.
  else
  {
    queue->tail->next = newNode;
    queue->tail = newNode;
  }
  
  // Increment size to acknowledge the Queue now stores another element
  queue->size++;
}


// Performs a dequeue operation for the queue returning the value that was 
// stored at the head of queue (deleting the queue node and making the next
// node the new head node).  If the queue is empty than the bool variable 
// pointed to by status is set to false to indicate the dequeue operation 
// was unsuccessful (as we cannot dequeue a value from an empty queue), 
// otherwise it is set to true to indicate the operation was successful.
int dequeue(Queue *queue, bool *status)
{
  // If the queue is empty set the bool variable pointed to by status to false
  // and return NULL.
  if (is_empty(queue))
  {
    *status = false;
    return NULL;
  }
  
  // Otherwise we set the bool variable pointed to by status to true to indicate
  // that the operation will be successful.
  *status = true;
  
  // We'll need to delete the head node.  At the same time we need to return the
  // value stored at the head node, and we need to use the head node to set the 
  // head pointer of the Queue struct to point to the NEXT node in the list by 
  // using the current head node's next member.
  //
  // If we delete the node first, we can't do these things.  But if say we 
  // update the head pointer of the queue to point to the next node, we'll lose
  // our pointer to this old head. 
  //
  // So we'll keep the value of the current head node in a temporary variable,
  // and we'll also store a pointer to the old head in a temporary variable, so 
  // we can later return the value and delete the old head node (by free-ing the
  // space associated with it on the heap).
  //

  // Store the value at the head so we can return it later
  int value = queue->head->value;
  
  // Store a pointer to the old head node
  Node *oldHead = queue->head;
    
  // If the queue size is 1 we are deleting the last node in the list and the
  // queue is going to be empty again.  So we set both the head and tail 
  // pointers to NULL in this case.
  if (queue->size == 1)
  {
    queue->head = NULL;
    queue->tail = NULL;
  }
  // Otherwise set the head pointer to point to the next node in list as this
  // as the new head of the queue.
  else
  {
    queue->head = queue->head->next;
  }
  
  // Use the pointer to the old head that we saved to delete the head
  free(oldHead);
  
  // Decrement the queue size to acknowledge we have removed an element from
  // the queue.
  queue->size--;
  
  // Return the value of the old head node that we saved into the value variable
  return value;
}


// Destroys the entire queue by freeing the memory allocated to store all Node 
// structs in the linked list and the Queue struct itself.
void destroy_queue(Queue *queue)
{
  // We'll traverse the list using currentNode, starting it off at the head 
  // node.  As we visit each node we'll free the memory associated with it.
  Node *currentNode = queue->head;
  
  // The loop will stop when we reach the tail of the list with currentNode.
  while (currentNode != NULL)
  {
    // Keep a pointer to the current node visited during this loop iteration.
    // We'll set currentNode to the NEXT node using currentNode's next member,
    // which means we'll lose our pointer to "this loop iteration's" current 
    // node.  We keep it stored in this temp variable so we can free it after
    // we've used the current node's next member.
    Node *temp = currentNode;

    // Set currentNode to point to the next node in the list using the next
    // member.
    currentNode = currentNode->next;

    // Now free the "current node of this loop iteration" that we kept a 
    // temporary pointer to.
    free(temp);
  }

  // After free'ing all Node structs in the list, free the Queue struct. 
  free(queue);
}