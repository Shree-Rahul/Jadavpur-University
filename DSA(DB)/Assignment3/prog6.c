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

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }

    return stack->data[stack->top];
}

int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool isLeftParenthesis(char ch) {
    return ch == '(';
}

bool isRightParenthesis(char ch) {
    return ch == ')';
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initializeStack(&stack);

    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix[postfixIndex++] = ch;
        } else if (isOperator(ch)) {
            while (!isEmpty(&stack) && !isLeftParenthesis(peek(&stack)) &&
                   getPrecedence(ch) <= getPrecedence(peek(&stack))) {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        } else if (isLeftParenthesis(ch)) {
            push(&stack, ch);
        } else if (isRightParenthesis(ch)) {
            while (!isEmpty(&stack) && !isLeftParenthesis(peek(&stack))) {
                postfix[postfixIndex++] = pop(&stack);
            }
            if (!isEmpty(&stack) && isLeftParenthesis(peek(&stack))) {
                pop(&stack);
            }
        }
    }

    while (!isEmpty(&stack)) {
        if (isLeftParenthesis(peek(&stack)) || isRightParenthesis(peek(&stack))) {
            pop(&stack);
        } else {
            postfix[postfixIndex++] = pop(&stack);
        }
    }

    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
