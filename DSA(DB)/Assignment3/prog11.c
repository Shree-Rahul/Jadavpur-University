#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

bool isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = item;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int item = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return item;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[i]);
}

void appendQueue(Queue* y, Queue* x) {
    while (!isEmpty(x)) {
        int item = dequeue(x);
        enqueue(y, item);
    }
}

int main() {
    Queue y, x;
    initializeQueue(&y);
    initializeQueue(&x);

    // Enqueue elements into queue x
    enqueue(&x, 1);
    enqueue(&x, 2);
    enqueue(&x, 3);

    // Enqueue elements into queue y
    enqueue(&y, 4);
    enqueue(&y, 5);

    printf("Queue y before appending: ");
    display(&y);

    printf("Queue x: ");
    display(&x);

    appendQueue(&y, &x);

    printf("Queue y after appending: ");
    display(&y);

    return 0;
}
