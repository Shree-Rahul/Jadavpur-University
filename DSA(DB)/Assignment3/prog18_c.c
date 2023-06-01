#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORITIES 5
#define MAX_SIZE 100

struct PriorityQueue {
    int queue[MAX_PRIORITIES][MAX_SIZE];
    int front[MAX_PRIORITIES];
    int rear[MAX_PRIORITIES];
};

// Function to initialize the priority queue
void initialize(struct PriorityQueue* pq) {
    int i;
    for (i = 0; i < MAX_PRIORITIES; i++) {
        pq->front[i] = -1;
        pq->rear[i] = -1;
    }
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    int i;
    for (i = 0; i < MAX_PRIORITIES; i++) {
        if (pq->front[i] != -1)
            return 0;
    }
    return 1;
}

// Function to check if the priority queue is full
int isFull(struct PriorityQueue* pq) {
    int i;
    for (i = 0; i < MAX_PRIORITIES; i++) {
        if (pq->rear[i] == MAX_SIZE - 1)
            return 1;
    }
    return 0;
}

// Function to enqueue an element with a given priority into the priority queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full. Enqueue operation failed.\n");
        return;
    }

    int row = priority - 1;
    int nextIndex = pq->rear[row] + 1;
    pq->queue[row][nextIndex] = data;
    pq->rear[row] = nextIndex;

    if (pq->front[row] == -1)
        pq->front[row] = 0;
}

// Function to dequeue the element with the highest priority from the priority queue
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int i;
    for (i = 0; i < MAX_PRIORITIES; i++) {
        if (pq->front[i] != -1) {
            int element = pq->queue[i][pq->front[i]];
            if (pq->front[i] == pq->rear[i]) {
                pq->front[i] = -1;
                pq->rear[i] = -1;
            } else {
                pq->front[i]++;
            }
            return element;
        }
    }
    return -1;
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 2);
    enqueue(&pq, 40, 1);

    printf("Dequeued elements: ");
    while (!isEmpty(&pq)) {
        printf("%d ", dequeue(&pq));
    }
    printf("\n");

    return 0;
}