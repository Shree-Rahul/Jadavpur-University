#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }

    stack->data[++(stack->top)] = item;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack->data[(stack->top)--];
}

bool areEqual(Stack *stack1, Stack *stack2) {
    if (stack1->top != stack2->top) {
        return false;
    }

    for (int i = 0; i <= stack1->top; i++) {
        if (stack1->data[i] != stack2->data[i]) {
            return false;
        }
    }

    return true;
}

void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);

    int choice, item;

    do {
        printf("\nStack Menu\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Compare Stacks\n");
        printf("4. Display Stack 1\n");
        printf("5. Display Stack 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push to Stack 1: ");
                scanf("%d", &item);
                push(&stack1, item);
                break;
            case 2:
                printf("Enter the element to push to Stack 2: ");
                scanf("%d", &item);
                push(&stack2, item);
                break;
            case 3:
                if (areEqual(&stack1, &stack2)) {
                    printf("Stacks are equal\n");
                } else {
                    printf("Stacks are not equal\n");
                }
                break;
            case 4:
                display(&stack1);
                break;
            case 5:
                display(&stack2);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
