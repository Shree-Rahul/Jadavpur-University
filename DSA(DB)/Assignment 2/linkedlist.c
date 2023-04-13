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
    printf("\nEnter %d elements one by one :",n);
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
/*--------------Display--------------------*/

void display(node *head){
    if(head==NULL){
        printf("\nEmpty list");
        return;
    }
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

/*----Insert a node after the node (first from the start) containing a given value.------*/

void insertAfterVal(node **head){
    printf("\nAfter what val you want to insert : ");
    int val ,flag =0;
    scanf("%d",&val);
    printf("\nEnter the element you want to insert :");
    node *temp = *head, *newnode = (node*) malloc(sizeof(node));
    scanf("%d",&(newnode->val));
    newnode->next =NULL;
    while(temp){
        if(temp->val == val ) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag){
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else {
        printf("\n%d is not present in the list.",val);
    }
}
/*------------Delete first node-------------------*/

void delHead(node **head){
    node *temp = *head ;

    if(!temp) printf("\nlist is empty");
    *head = temp->next;
    temp->next = NULL;
    free(temp);
}
/*---------------Delete last node---------------*/
void delTail(node **head){
    node *temp = *head;
    if(!(*head)->next){
        free(*head);
        *head=NULL;
        return;
    }
    while(temp->next->next) {
        temp = temp->next;
    }
    free(temp->next->next);
    temp->next = NULL;
    printf("\nLast element deleted");
}

/*---------------Delete after kth node--------------*/
void delKth(node **head){
    printf("\nEnter the position : ");
    node *curr= *head,*prev=NULL;
    int pos;
    scanf("%d",&pos);
    if(pos==1){
        delHead(head);
        return;
    }
    for(int i =1 ;i<pos;i++) {
        if(!curr){
            printf("\nInvalid position ,try another.");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if(!(*head)->next){
        free(*head);
        *head=NULL;
        return;
    }
    prev->next = curr->next;
    curr->next= NULL;
    free(curr);
}
/*---------------Delete before kth node--------------*/
void delBeforeKth(node **head){
    printf("\nEnter the position : ");
    node *curr= *head,*prev=NULL;
    int pos;
    scanf("%d",&pos);
    if(pos<2){
        printf("\n there is no element before this position.");
        return;
    }
    for(int i =1 ;i<pos-1&& curr != NULL;i++) {
        if(!curr){
            printf("\nInvalid position ,try another.");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if(!(*head)->next){
        free(*head);
        *head=NULL;
        return;
    }
    prev->next = curr->next;
    curr->next= NULL;
    free(curr);
}

/*---------------Delete kth node--------------*/
void delAfterKth(node **head){
    printf("\nEnter the position : ");
    node *curr= (*head)->next,*prev=*head;
    int pos;
    scanf("%d",&pos);
    if(pos<1){
        printf("\nPosition starts from 1.");
        return;
    }
    for(int i =1 ;i<pos;i++) {
        if(curr->next==NULL){
            printf("\nInvalid position ,try another.");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if(!(*head)->next){
        free(*head);
        *head=NULL;
        return;
    }
    prev->next = curr->next;
    curr->next= NULL;
    free(curr);
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
/*------------------Search----------------------*/
void search(node *head){
    printf("\nEnter the element you want to search : ");
    int val ,flag =0,pos=1;
    scanf("%d",&val);
    node *temp = head;
        while(temp){
            
            if(temp->val == val ) {
                flag = 1;
                break;
            }
            temp = temp->next;
            pos++;
    }
    if(flag){
        printf("\n%d is found at %d position.",val,pos);
    }
    else {
        printf("\n%d is not present in the list.",val);
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
    // node *second = create();
    
    display(head);
    // display(second);
    // sort(&head);
    // display(merge(head,second));
    search(head);
    // insertAfterVal(&head);
    // delAfterKth(&head);
    // display(head);
    return 0;
}