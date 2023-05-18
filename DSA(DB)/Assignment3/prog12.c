#include <stdio.h>
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

bool isEqual(Queue* q1, Queue* q2) {
    if (q1->front == -1 && q2->front == -1) {
        return true;
    }

    if ((q1->front == -1 && q2->front != -1) || (q1->front != -1 && q2->front == -1)) {
        return false;
    }

    if ((q1->rear - q1->front) != (q2->rear - q2->front)) {
        return false;
    }

    int i = q1->front;
    int j = q2->front;

    while (i != q1->rear && j != q2->rear) {
        if (q1->data[i] != q2->data[j]) {
            return false;
        }

        i = (i + 1) % MAX_SIZE;
        j = (j + 1) % MAX_SIZE;
    }

    if (q1->data[i] != q2->data[j]) {
        return false;
    }

    return true;
}

int main() {
    Queue q1, q2;
    initializeQueue(&q1);
    initializeQueue(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 3);

    bool result = isEqual(&q1, &q2);

    if (result) {
        printf("The queues are equal\n");
    } else {
        printf("The queues are not equal\n");
    }

    return 0;
}
