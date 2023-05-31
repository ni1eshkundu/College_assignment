#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

void initPriorityQueue(PriorityQueue* queue) {
    queue->front = NULL;
}

int isEmpty(PriorityQueue* queue) {
    return (queue->front == NULL);
}

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(PriorityQueue* queue, int data, int priority) {
    Node* newNode = createNode(data, priority);

    if (isEmpty(queue) || priority < queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        Node* current = queue->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued element with data %d and priority %d.\n", data, priority);
}

int dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    printf("Dequeued element with data %d.\n", data);
    return data;
}

void displayPriorityQueue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
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

