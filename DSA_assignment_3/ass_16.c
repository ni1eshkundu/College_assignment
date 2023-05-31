#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int front;
    int rear;
    int arr[MAX_SIZE];
} CircularQueue;

void initialize(CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}

bool isEmpty(CircularQueue* cq) {
    return (cq->front == -1);
}

bool isFull(CircularQueue* cq) {
    return ((cq->front == 0 && cq->rear == MAX_SIZE - 1) || (cq->front == cq->rear + 1));
}

void enqueue(CircularQueue* cq, int data) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(cq)) {
        cq->front = 0;
        cq->rear = 0;
    } else if (cq->rear == MAX_SIZE - 1) {
        cq->rear = 0;
    } else {
        cq->rear++;
    }

    cq->arr[cq->rear] = data;
    printf("Enqueued element: %d\n", data);
}

int dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = cq->arr[cq->front];

    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else if (cq->front == MAX_SIZE - 1) {
        cq->front = 0;
    } else {
        cq->front++;
    }

    return data;
}

int getFront(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }

    return cq->arr[cq->front];
}

int getRear(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. No rear element.\n");
        return -1;
    }

    return cq->arr[cq->rear];
}

void displayQueue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    if (cq->front <= cq->rear) {
        for (int i = cq->front; i <= cq->rear; i++) {
            printf("%d ", cq->arr[i]);
        }
    } else {
        for (int i = cq->front; i < MAX_SIZE; i++) {
            printf("%d ", cq->arr[i]);
        }
        for (int i = 0; i <= cq->rear; i++) {
            printf("%d ", cq->arr[i]);
        }
    }
    printf("\n");
}

int main() {
    CircularQueue cq;
    initialize(&cq);

    int choice, data;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front\n");
        printf("4. Get Rear\n");
        printf("5. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&cq, data);
                break;
            case 2:
                data = dequeue(&cq);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                data = getFront(&cq);
                if (data != -1) {
                    printf("Front element: %d\n", data);
                }
                break;
            case 4:
                data = getRear(&cq);
                if (data != -1) {
                    printf("Rear element: %d\n", data);
                }
                break;
            case 5:
                displayQueue(&cq);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

