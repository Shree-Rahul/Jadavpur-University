#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}node;

typedef struct Queue
{
    node *rear;
    node *front;
}queue;

void Initialize(queue *Q){
    Q->front = NULL;
    Q->rear = NULL;
}
void enqueue(queue *Q,int val){
    node *new = (node*) malloc(sizeof(node));
    new->val=val;
    new->next = NULL;
    if(!(Q->front && Q->rear)){
        Q->front = new;
        Q->rear = new;
    }else{
        Q->rear->next = new;
        Q->rear = new;
    }
    
}
int dequeue(queue *Q){
    node *temp = Q->front;
    int data = temp->val;
    if(!Q->front){
        printf("Queue is empty.\n");
        return -1;
    }
    if(Q->front == Q->rear){
        Q->front = NULL;
        Q->rear = NULL;
    }
    Q->front = Q->front->next;
    temp->next = NULL;
    free(temp);
    return data;
}

void display(queue *Q){
    node *temp = Q->front;
    while(temp){
        printf("%d-->",temp->val);
        temp =temp->next;
    }
    printf("NULL\n");
}

int main(){
    queue Q ;
    Initialize(&Q);
    enqueue(&Q,1);
    enqueue(&Q,2);
    enqueue(&Q,3);
    enqueue(&Q,4);
    enqueue(&Q,5);
    enqueue(&Q,6);
    display(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    display(&Q);
    return 0;
}