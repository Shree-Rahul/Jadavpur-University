#include<stdio.h>
#include<stdlib.h>

/*--------Structure------------*/
typedef struct linkedlist
{
    int val;
    struct linkedlist *prev;
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
        // node* newnode = (node*)malloc(sizeof(node));
        int val;
        scanf("%d",&(val));
        // newnode->next = NULL;
        // newnode->prev = NULL;
        // if(head == NULL){
        //     head = newnode;
        //     tail = head;
        // } else {
        //     newnode->prev = tail;
        //     tail->next = newnode;
        //     tail = newnode;
        // }
        insert(&head,val);
    }
    return head;
}
void insert (node **head,int val){

    node  *tail=*head,*newnode  = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(*head == NULL){
        *head = newnode;
    } else {
        while(tail->next) tail =tail->next;
        tail->next = newnode;
        newnode->prev = tail;
    }
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
    (*head)->prev = newnode;
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
    newnode->prev = temp;
}
/*-------------------Insert at kth node-------------------*/

void insertAtK(node **head) {
    printf("\tEnter the position followed by the Element : ");
    node *temp = *head, *newnode = (node*) malloc(sizeof(node));
    int pos;
    scanf("%d %d",&pos,&(newnode->val));

    for(int i =1 ;i<pos-1;i++) temp = temp->next;

    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void insertBeforeKth(node **head) {
    int val,k;
    printf("Enter the position : ");
    scanf("%d", &k);
    printf("Enter the value of the new node: ");
    scanf("%d", &val);

    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->prev = NULL;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        printf("%d inserted as the first node in the list.\n", val);
        return;
    }

    node *temp = *head;
    int pos = 1;

    while (temp != NULL && pos < k) {
        temp = temp->next;
        pos++;
    }

    if (temp == NULL) {
        printf("Cannot insert node before the kth node as list has less than k nodes.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
        newNode->prev = temp->prev;
    }

    newNode->next = temp;
    temp->prev = newNode;

    printf("%d inserted before the kth node in the list.\n", val);
}

void insertAfterKth(node **head) {
    int pos, val, count = 0;
    printf("\nEnter the position after which you want to insert a node: ");
    scanf("%d", &pos);

    node *temp = *head;

    while(temp != NULL) {
        count++;
        if(count == pos) {
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &val);

            node *new_node = (node*) malloc(sizeof(node));
            new_node->val = val;
            new_node->next = temp->next;
            new_node->prev = temp;

            if(temp->next != NULL) {
                temp->next->prev = new_node;
            }
            temp->next = new_node;
            printf("\nElement %d inserted successfully after position %d.", val, pos);
            return;
        }
        temp = temp->next;
    }
    printf("\nInvalid position. List has only %d nodes.", count);
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
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
    else {
        printf("\n%d is not present in the list.",val);
    }
}

void insertBeforeValue(node **head, int val, int newVal) {
    printf("\nAfter what val you want to insert : ");
    int val ,flag =0;
    scanf("%d",&val);
    printf("\nEnter the element you want to insert :");
    node *temp = *head, *newnode = (node*) malloc(sizeof(node));
    scanf("%d",&(newnode->val));
    newnode->next =NULL;
    newnode->prev =NULL;
    while(temp) {
        if(temp->val == val) {
            newnode->prev = temp->prev;
            newnode->next = temp;
            temp->prev = newnode;
            if(temp == *head) {
                *head = newnode;
            }
            else {
                newnode->prev->next = newnode;
            }
            printf("\nElement inserted succesfully.");
            return;
        }
        temp = temp->next;
    }
    printf("\n%d not found in the list.", val);
}

/*------------Delete first node-------------------*/

void delHead(node **head){
    node *temp = *head ;

    if(!temp) printf("\nlist is empty");
    *head = temp->next;
    temp->next = NULL;
    temp->next->prev = NULL;
    free(temp);
    printf("\nHead deleted succesfully.");
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
void delKth(node **head) {
    printf("\nEnter the position: ");
    node *curr = *head, *prevNode = NULL;
    int pos;
    scanf("%d", &pos);
    if (pos == 1) {
        delHead(head);
        return;
    }
    for (int i = 1; i < pos; i++) {
        if (!curr) {
            printf("\nInvalid position, try another.");
            return;
        }
        prevNode = curr;
        curr = curr->next;
    }
    if (!(*head)->next) {
        free(*head);
        *head = NULL;
        printf("\nElement deleted successfully.");
        return;
    }
    prevNode->next = curr->next;
    if (curr->next) {
        curr->next->prev = prevNode;
    }
    curr->next = NULL;
    curr->prev = NULL;
    free(curr);
    printf("\nElement deleted successfully.");
}
/*---------------Delete before kth node--------------*/
void delBeforeKth(node **head) {
    printf("\nEnter the position: ");
    node *curr = *head, *prevNode = NULL;
    int pos;
    scanf("%d", &pos);
    if (pos < 2) {
        printf("\nThere is no element before this position.");
        return;
    }
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        if (!curr) {
            printf("\nInvalid position, try another.");
            return;
        }
        prevNode = curr;
        curr = curr->next;
    }
    if (!prevNode) {
        printf("\nThere is no element before this position.");
        return;
    }
    if (!(*head)->next) {
        free(*head);
        *head = NULL;
        printf("\nElement deleted successfully.");
        return;
    }
    prevNode->next = curr->next;
    if (curr->next) {
        curr->next->prev = prevNode;
    }
    curr->next = NULL;
    curr->prev = NULL;
    free(curr);
    printf("\nElement deleted successfully.");
}

/*---------------Delete kth node--------------*/
void delAfterKth(node **head) {
    printf("\nEnter the position: ");
    node *curr = (*head)->next, *prevNode = *head;
    int pos;
    scanf("%d", &pos);
    if (pos < 1) {
        printf("\nPosition starts from 1.");
        return;
    }
    for (int i = 1; i <= pos && curr != NULL; i++) {
        if (curr->next == NULL) {
            printf("\nInvalid position, try another.");
            return;
        }
        prevNode = curr;
        curr = curr->next;
    }
    if (!prevNode->next) {
        printf("\nThere is no element after this position.");
        return;
    }
    prevNode->next = curr->next;
    if (curr->next) {
        curr->next->prev = prevNode;
    }
    curr->next = NULL;
    curr->prev = NULL;
    free(curr);
    printf("\nElement deleted successfully.");
}

/*---------------------Delete  after specified node -----------*/

void delAfterSpecified(node **head){
    printf("\nAfter what val you want to delete: ");
    int val ,flag =0;
    scanf("%d",&val);
    
    node *curr = *head;
    while(curr){
        if(curr->val == val ) {
            flag = 1;
            break;
        }
        curr = curr->next;
    }
    if(flag && curr->next){
        node *temp = curr->next;
        curr->next = temp->next;
        if(temp->next){
            temp->next->prev = curr;
        }
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
        printf("\nElement deleted successfully.");
    }
    else {
        if(flag){
            printf("\nThere is no element after given value.");
            return;
        }
        printf("\n%d is not present in the list.",val);
    }
}

void reverse(node **head) {
    node *temp = NULL;
    node *current = *head;

    // Swap prev and next pointers of each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // If list is not empty, update head
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main()
{
    node *head= create();
    node *second = create();
    // node *second = create();
    
    display(head);
    // display(second);
    // sort(&head);
    // display(merge(head,second));
    // search(head);
    // insertAfterVal(&head);
    // delAfterKth(&head);
    // display(concat(head,head));
    // delAfterSpecified(&head);
    display(second);
    if(checkEqual(&head,&second)) printf("\nThey are equal.");
    else printf("\nThey are not the same brooo.");
    return 0;
}