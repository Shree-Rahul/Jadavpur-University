#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coefficient;
    int exponent;
    struct node *next;
}Node;

/*------------Create------------------*/
void insert(Node **head , int coef,int exp){
    
        Node *temp=*head,*newnode = (Node*)malloc(sizeof(Node));
        newnode->coefficient = coef;
        newnode->exponent =exp;
        newnode->next;
        if(!(*head)){
            *head = newnode;
            return;
        }
        while(temp->next){
            temp =temp->next ;
        }
        temp->next = newnode;
}
Node* create(){
    Node *head =NULL;
    printf("\nHow many variables are there in the polynomial:");
    int num;
    scanf("%d",&num);
    while(num--){
        int coef,exp;
        printf("\nEnter the co-efficient of %d variable: ",num+1);
        scanf("%d",&(coef));
        printf("\nEnter the power of %d variable: ",num+1);
        scanf("%d",&exp);
        insert(&head,coef,exp);
    }
    return head;
}
void display(Node *head){

    Node *temp=head;

    if(!temp){
        printf("\nPolynomial is empty.");
        return;
    }
    while(temp){
        if(temp->exponent==0){
            printf("%d",temp->coefficient);
        }
        else if(temp->exponent==1){
            printf("%dx",temp->coefficient);
        }else
        printf("%dx^%d",temp->coefficient,temp->exponent);
        if(temp->next != NULL) printf(" + ");
        temp=temp->next;
    }
    printf("\n");
}
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent > p2->exponent) {
            insert(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p2->exponent > p1->exponent) {
            insert(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            insert(&result, p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}
Node* subPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent > p2->exponent) {
            insert(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p2->exponent > p1->exponent) {
            insert(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            insert(&result, p1->coefficient - p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}
int main()
{
    Node *first = create();
    Node *second = create();
    display(first);
    display(second);

    Node *result = subPolynomials(first,second);
    display(result);

    return 0;
}