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

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

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

void replace(Queue* q, int e, int x) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot replace.\n");
        return;
    }

    Node* current = q->front;

    while (current != NULL) {
        if (current->data == e) {
            current->data = x;
        }
        current = current->next;
    }
}

int main() {
    Queue* q = createQueue();

    int n, data;
    int e, x;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(q, data);
    }

    printf("Enter the element to replace: ");
    scanf("%d", &e);

    printf("Enter the new value: ");
    scanf("%d", &x);

    printf("Original queue: ");
    displayQueue(q);

    // Replace the element
    replace(q, e, x);

    printf("Updated queue: ");
    displayQueue(q);

    return 0;
}

