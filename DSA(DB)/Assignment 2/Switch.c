#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* createList(node* head);
void printList(node* head);
node* insertFront(node* head, int data);
node* insertEnd(node* head, int data);
node* insertAfterK(node* head, int data, int k);
node* insertAfterValue(node* head, int data, int value);
node* insertBeforeK(node* head, int data, int k);
node* insertBeforeValue(node* head, int data, int value);
node* deleteFirst(node* head);
node* deleteLast(node* head);
node* deleteAfterK(node* head, int k);
node* deleteBeforeK(node* head, int k);
node* deleteK(node* head, int k);
node* deleteValue(node* head, int value);
node* reverseList(node* head);
node* sortList(node* head);
int searchList(node* head, int data);
node* mergeLists(node* head1, node* head2);
node* concatenateLists(node* head1, node* head2);
int areListsEqual(node* head1, node* head2);

int main() {
    int choice, data, k, value;
    node* head = NULL;
    node* head1 = NULL;
    node* head2 = NULL;

    do {
        printf("\nMenu\n");
        printf("1. Create a linked list.\n");
        printf("2. Print the content of the list.\n");
        printf("3. Insert an element at the front of the list.\n");
        printf("4. Insert an element at the end of the list.\n");
        printf("5. Insert a node after the kth node.\n");
        printf("6. Insert a node after the node (first from the start) containing a given value.\n");
        printf("7. Insert a node before the kth node.\n");
        printf("8. Insert a node before the node (first from the start) containing a given value.\n");
        printf("9. Delete the first node.\n");
        printf("10. Delete the last node.\n");
        printf("11. Delete a node after the kth node.\n");
        printf("12. Delete a node before the kth node.\n");
        printf("13. Delete the kth node.\n");
        printf("14. Delete the node (first from the start) containing a specified value.\n");
        printf("15. Find the reverse of a list.\n");
        printf("16. Sort the list.\n");
        printf("17. Search a given element.\n");
        printf("18. Merge two lists; those are in ascending order.\n");
        printf("19. Concatenate two lists.\n");
        printf("20. Find if two lists are equal.\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                head = createList(head);
                printf("List created.\n");
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                printf("%d inserted at the front.\n", data);
               
            break;
        case 4:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            head = insertEnd(head, data);
            printf("%d inserted at the end.\n", data);
            break;
        case 5:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the value of k: ");
            scanf("%d", &k);
            head = insertAfterK(head, data, k);
            printf("%d inserted after the %dth node.\n", data, k);
            break;
        case 6:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the value to search: ");
            scanf("%d", &value);
            head = insertAfterValue(head, data, value);
            printf("%d inserted after the first node with value %d.\n", data, value);
            break;
        case 7:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the value of k: ");
            scanf("%d", &k);
            head = insertBeforeK(head, data, k);
            printf("%d inserted before the %dth node.\n", data, k);
            break;
        case 8:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the value to search: ");
            scanf("%d", &value);
            head = insertBeforeValue(head, data, value);
            printf("%d inserted before the first node with value %d.\n", data, value);
            break;
        case 9:
            head = deleteFirst(head);
            printf("First node deleted.\n");
            break;
        case 10:
            head = deleteLast(head);
            printf("Last node deleted.\n");
            break;
        case 11:
            printf("Enter the value of k: ");
            scanf("%d", &k);
            head = deleteAfterK(head, k);
            printf("Node after the %dth node deleted.\n", k);
            break;
        case 12:
            printf("Enter the value of k: ");
            scanf("%d", &k);
            head = deleteBeforeK(head, k);
            printf("Node before the %dth node deleted.\n", k);
            break;
        case 13:
            printf("Enter the value of k: ");
            scanf("%d", &k);
            head = deleteK(head, k);
            printf("%dth node deleted.\n", k);
            break;
        case 14:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            head = deleteValue(head, value);
            printf("First node with value %d deleted.\n", value);
            break;
        case 15:
            head = reverseList(head);
            printf("List reversed.\n");
            break;
        case 16:
            head = sortList(head);
            printf("List sorted.\n");
            break;
        case 17:
            printf("Enter the element to search: ");
            scanf("%d", &data);
            if (searchList(head, data)) {
                printf("%d found in the list.\n", data);
            } else {
                printf("%d not found in the list.\n", data);
            }
            break;
        case 18:
            printf("Creating list 1.\n");
            head1 = createList(head1);
            printf("Creating list 2.\n");
            head2 = createList(head2);
            head = mergeLists(head1, head
            break;
        case 19:
            printf("Creating list 1.\n");
            head1 = createList(head1);
            printf("Creating list 2.\n");
            head2 = createList(head2);
            head = concatenateLists(head1, head2);
            printf("Lists concatenated.\n");
            break;
        case 20:
            printf("Creating list 1.\n");
            head1 = createList(head1);
            printf("Creating list 2.\n");
            head2 = createList(head2);
            if (areListsEqual(head1, head2)) {
                printf("Lists are equal.\n");
            } else {
                printf("Lists are not equal.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
} while (choice != 0);

return 0;
