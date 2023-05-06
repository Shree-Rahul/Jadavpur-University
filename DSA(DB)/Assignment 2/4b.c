#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the circular linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list with n nodes
Node* createCircularLinkedList(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=1; i<=n; i++) {
        Node* newNode = createNode(i);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; // Make the list circular
    return head;
}

// Function to print the circular linked list
void printCircularLinkedList(Node* head) {
    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

// Function to find the person to be freed using circular linked list
void findPersonToBeFreed(int start, int skip, int n) {
    Node* head = createCircularLinkedList(n);
    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    // Move curr and prev pointers to start position
    while(count != start) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // Loop through the linked list until only one person remains
    while(curr->next != curr) {
        // Move curr and prev pointers to the next person to be executed
        for(int i=1; i<skip; i++) {
            prev = curr;
            curr = curr->next;
        }
        // Execute the person and remove from the list
        prev->next = curr->next;
        printf("Person %d is executed\n", curr->data);
        free(curr);
        curr = prev->next; // Move curr pointer to the next person in the list
    }
    // The only person remaining is freed
    printf("Person %d is freed\n", curr->data);
    free(curr);
}

int main() {
    int start, skip, n;
    printf("Enter the starting position: ");
    scanf("%d", &start);
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &skip);
    printf("Enter the total number of persons: ");
    scanf("%d", &n);
    findPersonToBeFreed(start, skip, n);
    return 0;
}