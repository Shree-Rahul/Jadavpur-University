#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }

    stack->data[++(stack->top)] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }

    return stack->data[(stack->top)--];
}

bool isBalanced(char* expression) {
    Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&stack)) {
                return false;
            }

            char top = pop(&stack);

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter the expression: ");
    fgets(expression, MAX_SIZE, stdin);

    // Remove newline character if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    bool balanced = isBalanced(expression);

    if (balanced) {
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }

    return 0;
}
