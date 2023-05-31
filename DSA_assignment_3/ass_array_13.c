#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct queue {
    int front;
    int rear;
    int arr[MAX_SIZE];
} Queue;

void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

int isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    
    if (isEmpty(q))
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    
    int data = q->arr[q->front];
    
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    
    return data;
}

void reverseQueue(Queue* q) {
    if (isEmpty(q))
        return;

    int stack[MAX_SIZE];
    int top = -1;

    while (!isEmpty(q)) {
        stack[++top] = dequeue(q);
    }

    while (top >= 0) {
        enqueue(q, stack[top--]);
    }
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initialize(&queue);

    int n, data;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter the elements of the queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(&queue, data);
    }

    printf("Original Queue: ");
    displayQueue(&queue);

    reverseQueue(&queue);

    printf("Reversed Queue: ");
    displayQueue(&queue);

    return 0;
}

