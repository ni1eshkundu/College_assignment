#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

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

void append_queue(Queue* y, Queue* x) {
    if (x->front == NULL) {
        printf("Queue x is empty. Cannot append.\n");
        return;
    }

    if (y->rear == NULL) {
        y->front = x->front;
        y->rear = x->rear;
    } else {
        y->rear->next = x->front;
        y->rear = x->rear;
    }

    // Reset queue x
    x->front = NULL;
    x->rear = NULL;
}

void display_queue(Queue q) {
    if (q.front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* currNode = q.front;
    printf("Queue: ");
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    Queue y, x;
    y.front = NULL;
    y.rear = NULL;
    x.front = NULL;
    x.rear = NULL;

    int data;
    char choice;

    printf("Enqueue elements into Queue y:\n");
    do {
        printf("Enter element: ");
        scanf("%d", &data);
        enqueue(&y, data);

        printf("Do you want to enqueue more elements into Queue y? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    printf("\nEnqueue elements into Queue x:\n");
    do {
        printf("Enter element: ");
        scanf("%d", &data);
        enqueue(&x, data);

        printf("Do you want to enqueue more elements into Queue x? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    printf("\nBefore appending:\n");
    printf("Queue y: ");
    display_queue(y);
    printf("Queue x: ");
    display_queue(x);

    append_queue(&y, &x);

    printf("\nAfter appending:\n");
    printf("Queue y: ");
    display_queue(y);
    printf("Queue x: ");
    display_queue(x);

    return 0;
}

