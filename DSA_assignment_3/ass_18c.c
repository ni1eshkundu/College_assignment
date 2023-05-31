#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element items[MAX_SIZE];
    int front;
    int rear;
} PriorityQueue;

void initPriorityQueue(PriorityQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(PriorityQueue* queue) {
    return (queue->front == -1);
}

int isFull(PriorityQueue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(PriorityQueue* queue, int data, int priority) {
    Element newItem;
    newItem.data = data;
    newItem.priority = priority;

    if (isFull(queue)) {
        printf("Priority Queue is full. Cannot enqueue element.\n");
        return;
    }

    int i;
    for (i = queue->rear; i >= 0; i--) {
        if (queue->items[i].priority > priority) {
            queue->items[i + 1] = queue->items[i];
        } else {
            break;
        }
    }

    queue->items[i + 1] = newItem;
    queue->rear++;
    if (queue->front == -1) {
        queue->front = 0;
    }

    printf("Enqueued element with data %d and priority %d.\n", data, priority);
}

int dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int data = queue->items[queue->front].data;
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    printf("Dequeued element with data %d.\n", data);
    return data;
}

void displayPriorityQueue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("(%d, %d) ", queue->items[i].data, queue->items[i].priority);
    }
    printf("\n");
}

int main() {
    PriorityQueue queue;
    initPriorityQueue(&queue);

    int choice, data, priority;
    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Priority Queue\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                printf("Enter the priority of the element: ");
                scanf("%d", &priority);
                enqueue(&queue, data, priority);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayPriorityQueue(&queue);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

