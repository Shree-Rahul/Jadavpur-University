#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUES 10
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

typedef struct {
    Queue queues[MAX_QUEUES];
    int numQueues;
} QueueSystem;

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

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue->data[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue->data[queue->rear];
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

void initializeQueueSystem(QueueSystem* queueSystem) {
    queueSystem->numQueues = 0;
}

bool isQueueSystemFull(QueueSystem* queueSystem) {
    return queueSystem->numQueues == MAX_QUEUES;
}

void addQueue(QueueSystem* queueSystem) {
    if (isQueueSystemFull(queueSystem)) {
        printf("Cannot add more queues\n");
        return;
    }

    initializeQueue(&(queueSystem->queues[queueSystem->numQueues]));
    queueSystem->numQueues++;
}

Queue* selectQueue(QueueSystem* queueSystem, int queueIndex) {
    if (queueIndex < 0 || queueIndex >= queueSystem->numQueues) {
        printf("Invalid queue index\n");
        return NULL;
    }

    return &(queueSystem->queues[queueIndex]);
}

int main() {
    QueueSystem queueSystem;
    initializeQueueSystem(&queueSystem);

    int choice, queueIndex, item;
    char input[10];

    do {
        printf("1. Add Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Front\n");
        printf("5. Rear\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQueue(&queueSystem);
                break;
            case 2:
                printf("Enter the queue index: ");
                scanf("%d", &queueIndex);
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                if (selectQueue(&queueSystem, queueIndex) != NULL) {
                    enqueue(selectQueue(&queueSystem, queueIndex), item);
                }
                break;
            case 3:
                printf("Enter the queue index: ");
                scanf("%d", &queueIndex);
                if (selectQueue(&queueSystem, queueIndex) != NULL) {
                    item = dequeue(selectQueue(&queueSystem, queueIndex));
                    if (item != -1) {
                        printf("Dequeued item: %d\n", item);
                    }
                }
                break;
            case 4:
                printf("Enter the queue index: ");
                scanf("%d", &queueIndex);
                if (selectQueue(&queueSystem, queueIndex) != NULL) {
                    item = front(selectQueue(&queueSystem, queueIndex));
                    if (item != -1) {
                        printf("Front item: %d\n", item);
                    }
                }
                break;
            case 5:
                printf("Enter the queue index: ");
                scanf("%d", &queueIndex);
                if (selectQueue(&queueSystem, queueIndex) != NULL) {
                    item = rear(selectQueue(&queueSystem, queueIndex));
                    if (item != -1) {
                        printf("Rear item: %d\n", item);
                    }
                }
                break;
            case 6:
                printf("Enter the queue index: ");
                scanf("%d", &queueIndex);
                if (selectQueue(&queueSystem, queueIndex) != NULL) {
                    display(selectQueue(&queueSystem, queueIndex));
                }
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    } while (choice != 7);

    return 0;
}
