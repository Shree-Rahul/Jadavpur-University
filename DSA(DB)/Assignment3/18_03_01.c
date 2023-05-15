//-------------------------------------------------------------------------------------------|
//                               Create and Handle A Stack                                   |
//___________________________________________________________________________________________|

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 20

int top = -1;

int stack[MAX_SIZE];

bool isEmpty(){
    if(top ==-1){
        printf("\nStack is empty.");
        return true;
    }
    printf("\nStack is not empty.");
    return false;
}

bool isFull(){
    if(top == MAX_SIZE-1){
        printf("\nStack is full.");
        return true;
    }
    float p = ((top+1)/MAX_SIZE)*100;
    printf("\nStack is %.2f%% full",p);
    return false;
}
void push(int data){
    if(top==MAX_SIZE-1){
        printf("\nStack is full.");
        return;
    }
    top +=1;
    stack[top]=data;
    printf("\nData pushed into the Stack.");
}

int pop(){
    if(top==-1){
        printf("\nStack is empty.");
        return -1;
    }
    int val = stack[top];
    top--;
    printf("\n%d popped out of the Stack .",val);
    return val;
}

int peek(){
    if(top==-1){
        printf("\nStack is empty.");
        return -1;
    }
    printf("\nCurrent top of the Stack : %d",stack[top]);
    return stack[top];
}
int main(){
    printf("\nMaximum storing capacity of the Stack is %d",MAX_SIZE);

    int ch;
    while(1){
        printf("\nChoose any of the following options:\n");
        printf(" 0: Exit            1: Push            2: Pop            3: Peek\n");
        printf(" 4: Check if the stack is empty     5: Check if the stack is full\n\n");
        scanf("%d", &ch);

        switch(ch){
            case 0: exit(0);
            case 1:
                int x;
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &x);
                push(x); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            default: printf("Please choose a correct option!");
        }
    }
    return 0;
}