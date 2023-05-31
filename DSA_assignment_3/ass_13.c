#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Structure for the queue
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

// Function to reverse the queue
void reverseQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot reverse.\n");
        return;
    }

    // Create a stack
    Node* stack = NULL;

    // Dequeue all elements from the queue and push them onto the stack
    while (!isEmpty(q)) {
        int data = dequeue(q);

        // Push the dequeued element onto the stack
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = stack;
        stack = newNode;
    }

    // Enqueue all elements from the stack back into the queue
    while (stack != NULL) {
        int data = stack->data;

        // Deallocate the memory of the node in the stack
        Node* temp = stack;
        stack = stack->next;
        free(temp);

        // Enqueue the element back into the queue
        enqueue(q, data);
    }
}

// Function to display the elements of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = q->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue* q = createQueue();

    int n, data;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(q, data);
    }

    printf("Original queue: ");
    displayQueue(q);

    // Reverse the queue
    reverseQueue(q);

    printf("Reversed queue: ");
    displayQueue(q);

    return 0;
}

