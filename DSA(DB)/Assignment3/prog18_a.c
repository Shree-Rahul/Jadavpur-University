#include <stdio.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int heap[MAX_SIZE];
    int size;
};

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min heap property
void heapify(struct PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->heap[left] < pq->heap[smallest])
        smallest = left;

    if (right < pq->size && pq->heap[right] < pq->heap[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&pq->heap[idx], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

// Function to initialize the priority queue
void initialize(struct PriorityQueue* pq) {
    pq->size = 0;
}

// Function to enqueue an element into the priority queue
void enqueue(struct PriorityQueue* pq, int value) {
    if (pq->size == MAX_SIZE) {
        printf("Priority Queue is full. Enqueue operation failed.\n");
        return;
    }

    int i = pq->size;
    pq->heap[i] = value;
    pq->size++;

    while (i != 0 && pq->heap[(i - 1) / 2] > pq->heap[i]) {
        swap(&pq->heap[(i - 1) / 2], &pq->heap[i]);
        i = (i - 1) / 2;
    }
}

// Function to dequeue the element with the highest priority
int dequeue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    heapify(pq, 0);

    return root;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

// Function to check the element with the highest priority
int peek(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    return pq->heap[0];
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 4);
    enqueue(&pq, 2);
    enqueue(&pq, 7);
    enqueue(&pq, 1);
    enqueue(&pq, 5);

    printf("Priority Queue: ");
    while (!isEmpty(&pq)) {
        printf("%d ", dequeue(&pq));
    }
    printf("\n");

    return 0;
}