#include <stdio.h>
#define MAX_SIZE 100

int stacks[MAX_SIZE][MAX_SIZE];
int tops[MAX_SIZE];
int numStacks;

void initializeStacks() {
    printf("Enter the number of stacks: ");
    scanf("%d", &numStacks);

    for (int i = 0; i < numStacks; i++) {
        tops[i] = -1;
    }

    printf("Stacks initialized\n");
}

void push(int stackIndex, int item) {
    if (tops[stackIndex] >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stacks[stackIndex][++tops[stackIndex]] = item;
        printf("Element pushed to stack %d\n", stackIndex + 1);
    }
}

int pop(int stackIndex) {
    if (tops[stackIndex] < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stacks[stackIndex][tops[stackIndex]--];
    }
}

int peek(int stackIndex) {
    if (tops[stackIndex] < 0) {
        printf("Stack %d is empty\n", stackIndex + 1);
        return -1;
    } else {
        return stacks[stackIndex][tops[stackIndex]];
    }
}

void display(int stackIndex) {
    if (tops[stackIndex] < 0) {
        printf("Stack %d is empty\n", stackIndex + 1);
    } else {
        printf("Stack %d elements: ", stackIndex + 1);
        for (int i = 0; i <= tops[stackIndex]; i++) {
            printf("%d ", stacks[stackIndex][i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, stackIndex, item;
    
    initializeStacks();

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
                push(stackIndex - 1, item);
                break;
            case 2:
                printf("Enter the stack index (1-%d): ", numStacks);
                scanf("%d", &stackIndex);
                if (stackIndex < 1 || stackIndex > numStacks) {
                    printf("Invalid stack index\n");
                    break;
                }
                item = pop(stackIndex - 1);
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
                item = peek(stackIndex - 1);
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
                display(stackIndex - 1);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}