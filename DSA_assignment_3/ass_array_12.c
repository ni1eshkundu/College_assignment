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

bool isEqual(Queue* q1, Queue* q2) {
    if ((q1->rear - q1->front) != (q2->rear - q2->front))
        return false;

    for (int i = q1->front, j = q2->front; i <= q1->rear && j <= q2->rear; i++, j++) {
        if (q1->arr[i] != q2->arr[j])
            return false;
    }

    return true;
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
    Queue queue1, queue2;
    initialize(&queue1);
    initialize(&queue2);

    int n, data;

    printf("Enter the number of elements in Queue 1: ");
    scanf("%d", &n);

    printf("Enter the elements of Queue 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(&queue1, data);
    }

    printf("Enter the number of elements in Queue 2: ");
    scanf("%d", &n);

    printf("Enter the elements of Queue 2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(&queue2, data);
    }

    printf("Queue 1: ");
    displayQueue(&queue1);

    printf("Queue 2: ");
    displayQueue(&queue2);

    if (isEqual(&queue1, &queue2))
        printf("Queue 1 and Queue 2 are equal.\n");
    else
        printf("Queue 1 and Queue 2 are not equal.\n");

    return 0;
}

