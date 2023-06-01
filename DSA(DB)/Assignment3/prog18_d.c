#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the priority queue
struct PriorityQueue {
    struct Node* queues[5]; // Assuming 5 priority levels
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the priority queue
void initialize(struct PriorityQueue* pq) {
    int i;
    for (i = 0; i < 5; i++) {
        pq->queues[i] = NULL;
    }
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    int i;
    for (i = 0; i < 5; i++) {
        if (pq->queues[i] != NULL)
            return 0;
    }
    return 1;
}

// Function to enqueue an element with a given priority into the priority queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    if (priority < 0 || priority >= 5) {
        printf("Invalid priority. Enqueue operation failed.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    if (pq->queues[priority] == NULL) {
        pq->queues[priority] = newNode;
    } else {
        struct Node* temp = pq->queues[priority];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to dequeue the element with the highest priority from the priority queue
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int i;
    for (i = 0; i < 5; i++) {
        if (pq->queues[i] != NULL) {
            struct Node* temp = pq->queues[i];
            int element = temp->data;
            pq->queues[i] = pq->queues[i]->next;
            free(temp);
            return element;
        }
    }
    return -1;
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 2);
    enqueue(&pq, 40, 0);
    enqueue(&pq, 50, 3);

    printf("Dequeued elements: ");
    while (!isEmpty(&pq)) {
        printf("%d ", dequeue(&pq));
    }
    printf("\n");

    return 0;
}