#include <stdio.h>

#define MAX_SIZE 5

struct CircularQueue {
    int queue[MAX_SIZE];
    int front;
    int rear;
    int size;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
    cq->size = 0;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* cq) {
    return cq->size == 0;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* cq) {
    return cq->size == MAX_SIZE;
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Circular Queue is full. Enqueue operation failed.\n");
        return;
    }

    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->queue[cq->rear] = value;
    cq->size++;

    if (cq->front == -1)
        cq->front = cq->rear;
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int element = cq->queue[cq->front];
    cq->front = (cq->front + 1) % MAX_SIZE;
    cq->size--;

    if (cq->size == 0) {
        cq->front = -1;
        cq->rear = -1;
    }

    return element;
}

// Function to get the front element of the circular queue without removing it
int front(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular Queue is empty.\n");
        return -1;
    }

    return cq->queue[cq->front];
}

// Function to get the rear element of the circular queue without removing it
int rear(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular Queue is empty.\n");
        return -1;
    }

    return cq->queue[cq->rear];
}

int main() {
    struct CircularQueue cq;
    initialize(&cq);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    enqueue(&cq, 4);

    printf("Front element: %d\n", front(&cq));
    printf("Rear element: %d\n", rear(&cq));

    printf("Dequeued elements: ");
    while (!isEmpty(&cq)) {
        printf("%d ", dequeue(&cq));
    }
    printf("\n");

    return 0;
}