#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

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

void initializeStack(Stack* stack) {
    stack->top = -1;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isStackFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }

    stack->data[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack->data[stack->top--];
}

void reverseQueue(Queue* queue) {
    Stack stack;
    initializeStack(&stack);

    while (!isEmpty(queue)) {
        int item = dequeue(queue);
        push(&stack, item);
    }

    while (!isStackEmpty(&stack)) {
        int item = pop(&stack);
        enqueue(queue, item);
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printf("Queue before reversing: ");
    display(&queue);

    reverseQueue(&queue);

    printf("Queue after reversing: ");
    display(&queue);

    return 0;
}
