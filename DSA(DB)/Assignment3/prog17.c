#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Structure for the deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the deque
void initialize(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Delete operation failed.\n");
        return;
    }

    struct Node* temp = deque->front;
    deque->front = deque->front->next;

    if (deque->front == NULL)
        deque->rear = NULL;
    else
        deque->front->prev = NULL;

    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Delete operation failed.\n");
        return;
    }

    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;

    if (deque->rear == NULL)
        deque->front = NULL;
    else
        deque->rear->next = NULL;

    free(temp);
}

// Function to get the front element of the deque without removing it
int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->front->data;
}

// Function to get the rear element of the deque without removing it
int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->rear->data;
}

int main() {
    struct Deque deque;
    initialize(&deque);

    insertFront(&deque, 2);
    insertFront(&deque, 1);
    insertRear(&deque, 3);
    insertRear(&deque, 4);

    printf("Front element: %d\n", getFront(&deque));
    printf("Rear element: %d\n", getRear(&deque));

    printf("Deleted elements from front: ");
    while (!isEmpty(&deque)) {
        printf("%d ", getFront(&deque));
        deleteFront(&deque);
    }
    printf("\n");

    return 0;
}
