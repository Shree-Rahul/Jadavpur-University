#include<stdio.h>
#include<stdlib.h>

/*--------Structure------------*/
typedef struct linkedlist
{
    int val;
    struct linkedlist *next ;
}node;
/*-----------------------------*/

/*------Create-----------------*/
node* create() {
    int n;
    printf("\nEnter number of nodes : ");
    scanf("%d",&n);
    node *head=NULL,*tail=NULL;
    printf("\n Enter %d elements one by one :",n);
    for(int i=1;i<=n;i++) {
        node* newnode = (node*)malloc(sizeof(node));
        scanf("%d",&(newnode->val));
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}
/*--------------------------------------*/

void display(node* head){
    while(head!= NULL)
    {
        printf("  %d",head->val);
        head = head->next;
    }
    printf("\n");
}
/*-----------Insert a first------------------*/
node* insertAtFirst(node** head){
    printf("\nEnter the element to insert :");
    node *newnode = (node* ) malloc(sizeof(node));
    scanf("%d",&(newnode->val));
    newnode->next = *head;
    return newnode;
}
/*--------------Insert at last-------------------------*/
void insertAtLast(node** head) {

    printf("\n Enter the number to insert : ");
    node *temp = *head, *newnode = (node*) malloc(sizeof(node));
    scanf("%d",&(newnode->val));
    newnode->next = NULL;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newnode;
}
/*-------------------Insert at k+1th node-------------------*/

void insertAtK(node **head) {
    printf("\tEnter the position followed by the Element : ");
    node *temp = *head, *newnode = (node*) malloc(sizeof(node));
    int pos;
    scanf("%d %d",&pos,&(newnode->val));

    for(int i =1 ;i<pos-1;i++) temp = temp->next;

    newnode->next = temp->next;
    temp->next = NULL;
    temp->next = newnode;
}
/*--------------------Sort---------------------*/
void sort(node **head) {
    node *curr = *head;

    while(curr->next != NULL) {
        node *prev  = curr->next;
        while(prev != NULL){
            if(curr->val > prev->val){
                int temp = curr->val;
                curr->val = prev->val;
                prev->val = temp;
            }
            prev = prev->next;
        }
        curr = curr->next;
    }
}

/*----------------Merge two sorted arrays----------------*/
void insert (node **head,int val){

    node  *tail=*head,*newnode  = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
        if(*head == NULL){
            *head = newnode;
        } else {
            while(tail->next) tail =tail->next;
            tail->next = newnode;
        }
}
node* merge(node *first , node *second) {

    node *result = NULL, *temp_f= first , *temp_s = second ,*tail=NULL;


    while(temp_f && temp_s){
        if(temp_f->val < temp_s->val) {
                insert(&result , temp_f->val);
                temp_f = temp_f->next;
            } else {
                insert(&result , temp_s->val);
                temp_s = temp_s->next;
            }
    }
    while(temp_f) {
        insert(&result , temp_f->val);
        temp_f = temp_f->next;
    }
    while(temp_s) {
        insert(&result , temp_s->val);
        temp_s =temp_s->next;
    }
    return result;
}
int main()
{
    node *head= create();
    node *second = create();
    
    display(head);
    display(second);
    // sort(&head);
    display(merge(head,second));
    return 0;
}