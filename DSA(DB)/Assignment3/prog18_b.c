#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the singly linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Structure for the priority queue
struct PriorityQueue {
    struct Node* front;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the priority queue
void initialize(struct PriorityQueue* pq) {
    pq->front = NULL;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return pq->front == NULL;
}

// Function to enqueue an element into the priority queue based on its priority
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (isEmpty(pq) || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to dequeue the element with the highest priority from the priority queue
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    struct Node* temp = pq->front;
    int data = temp->data;
    pq->front = pq->front->next;
    free(temp);

    return data;
}

// Function to get the front element of the priority queue without removing it
int peek(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    return pq->front->data;
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 5, 2);
    enqueue(&pq, 10, 1);
    enqueue(&pq, 7, 3);
    enqueue(&pq, 3, 2);

    printf("Front element: %d\n", peek(&pq));

    printf("Dequeued elements: ");
    while (!isEmpty(&pq)) {
        printf("%d ", dequeue(&pq));
    }
    printf("\n");

    return 0;
}