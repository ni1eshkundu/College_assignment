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

void replace(Queue* q, int e, int x) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot replace.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        if (q->arr[i] == e) {
            q->arr[i] = x;
        }
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

    int e, x;
    printf("Enter the element to be replaced: ");
    scanf("%d", &e);
    printf("Enter the new value: ");
    scanf("%d", &x);

    printf("Original Queue: ");
    displayQueue(&queue);

    replace(&queue, e, x);

    printf("Queue after replacement: ");
    displayQueue(&queue);

    return 0;
}

