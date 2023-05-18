#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Element pushed to stack\n");
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    Node* temp = stack->top;
    int item = temp->data;
    stack->top = temp->next;
    free(temp);

    return item;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->top->data;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int numStacks;
    printf("Enter the number of stacks: ");
    scanf("%d", &numStacks);

    Stack* stacks = (Stack*)malloc(numStacks * sizeof(Stack));
    if (stacks == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < numStacks; i++) {
        initializeStack(&stacks[i]);
    }

    int choice, stackIndex, item;

    do {
        printf("\nStack Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the stack index (1-%d): ", numStacks);
                scanf("%d", &stackIndex);
                if (stackIndex < 1 || stackIndex > numStacks) {
                    printf("Invalid stack index\n");
                    break;
                }
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(&stacks[stackIndex - 1], item);
                break;
            case 2:
                printf("Enter the stack index (1-%d): ", numStacks);
                scanf("%d", &stackIndex);
                if (stackIndex < 1 || stackIndex > numStacks) {
                    printf("Invalid stack index\n");
                    break;
                }
                item = pop(&stacks[stackIndex - 1]);
                if (item != -1) {
                    printf("Popped element from stack %d: %d\n", stackIndex, item);
                }
                break;
            case 3:
                printf("Enter the stack index (1-%d): ", numStacks);
                scanf("%d", &stackIndex);
                if (stackIndex < 1 || stackIndex > numStacks) {
                    printf("Invalid stack index\n");
                    break;
                }
                item = peek(&stacks[stackIndex - 1]);
                if (item != -1) {
                    printf("Top element of stack %d: %d\n", stackIndex, item);
                }
                break;
            case 4:
                printf("Enter the stack index (1-%d): ", numStacks);
                scanf("%d", &stackIndex);
                if (stackIndex < 1 || stackIndex > numStacks) {
                    printf("Invalid stack index\n");
                    break;
                }
                display(&stacks[stackIndex - 1]);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    free(stacks);

    return 0;
}
