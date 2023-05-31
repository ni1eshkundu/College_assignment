#include <stdbool.h>
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

bool is_queue_equal(Queue q1, Queue q2) {
    Node* currNode1 = q1.front;
    Node* currNode2 = q2.front;

    while (currNode1 != NULL && currNode2 != NULL) {
        if (currNode1->data != currNode2->data) {
            return false;
        }
        currNode1 = currNode1->next;
        currNode2 = currNode2->next;
    }

    if (currNode1 == NULL && currNode2 == NULL) {
        return true;
    }

    return false;
}

int main() {
    Queue q1, q2;
    q1.front = NULL;
    q1.rear = NULL;
    q2.front = NULL;
    q2.rear = NULL;

    int numElements, element;

    printf("Enter the number of elements for Queue 1: ");
    scanf("%d", &numElements);

    printf("Enter the elements for Queue 1:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        enqueue(&q1, element);
    }

    printf("Enter the number of elements for Queue 2: ");
    scanf("%d", &numElements);

    printf("Enter the elements for Queue 2:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        enqueue(&q2, element);
    }

    bool equal = is_queue_equal(q1, q2);

    if (equal) {
        printf("q1 and q2 are equal.\n");
    } else {
        printf("q1 and q2 are not equal.\n");
    }

    return 0;
}

