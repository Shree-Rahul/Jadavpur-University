#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to perform bubble sort by interchanging data
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                // Swap the data of the current and next nodes
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Function to perform insertion sort by interchanging data
void insertionSort(struct Node* head) {
    struct Node* sorted = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* next = current->next;

        struct Node* temp = sorted;
        struct Node* prev = NULL;

        while (temp != NULL && temp->data < current->data) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {
            current->next = sorted;
            sorted = current;
        } else {
            prev->next = current;
            current->next = temp;
        }

        current = next;
    }

    head = sorted;
}

// Function to perform selection sort by interchanging data
void selectionSort(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        struct Node* min = current;
        struct Node* temp = current->next;

        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }

        // Swap the data of the current and minimum nodes
        int tempData = current->data;
        current->data = min->data;
        min->data = tempData;

        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nSorting Techniques Menu\n");
        printf("1. Insert an element\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                bubbleSort(head);
                printf("List sorted using Bubble Sort.\n");
                break;
            case 3:
                insertionSort(head);
                printf("List sorted using Insertion Sort.\n");
                break;
            case 4:
                selectionSort(head);
                printf("List sorted using Selection Sort.\n");
                break;
            case 5:
                printf("Current List: ");
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
