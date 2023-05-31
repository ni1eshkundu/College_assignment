#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

void initPriorityQueue(PriorityQueue* queue) {
    queue->size = 0;
}

int isEmpty(PriorityQueue* queue) {
    return (queue->size == 0);
}

int isFull(PriorityQueue* queue) {
    return (queue->size == MAX_SIZE);
}

void enqueue(PriorityQueue* queue, int data, int priority) {
    if (isFull(queue)) {
        printf("Priority Queue is full. Cannot enqueue element.\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = queue->size - 1;
    while (i >= 0 && queue->elements[i].priority > priority) {
        queue->elements[i + 1] = queue->elements[i];
        i--;
    }

    queue->elements[i + 1] = newElement;
    queue->size++;

    printf("Enqueued element with data %d and priority %d.\n", data, priority);
}

int dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int data = queue->elements[0].data;
    int i;

    for (i = 0; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }

    queue->size--;

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
    for (i = 0; i < queue->size; i++) {
        printf("(%d, %d) ", queue->elements[i].data, queue->elements[i].priority);
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

