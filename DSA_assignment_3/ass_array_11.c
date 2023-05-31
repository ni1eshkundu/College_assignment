#include <stdio.h>
#include <stdlib.h>
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

void appendQueue(Queue* x, Queue* y) {
    if (isEmpty(x)) {
        printf("Queue X is empty. Nothing to append.\n");
        return;
    }

    while (!isEmpty(x)) {
        int data = dequeue(x);
        enqueue(y, data);
    }

    printf("Queue X appended to Queue Y.\n");
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
    Queue queueX, queueY;
    initialize(&queueX);
    initialize(&queueY);

    int n, data;

    printf("Enter the number of elements in Queue X: ");
    scanf("%d", &n);

    printf("Enter the elements of Queue X:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(&queueX, data);
    }

    printf("Enter the number of elements in Queue Y: ");
    scanf("%d", &n);

    printf("Enter the elements of Queue Y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(&queueY, data);
    }

    printf("Queue X: ");
    displayQueue(&queueX);

    printf("Queue Y: ");
    displayQueue(&queueY);

    appendQueue(&queueX, &queueY);

    printf("Modified Queue Y: ");
    displayQueue(&queueY);

    return 0;
}

