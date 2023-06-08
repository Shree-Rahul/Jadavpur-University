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

// Function to perform bubble sort by interchanging links
void bubbleSort(struct Node* head) {
    if (head == NULL)
        return;

    struct Node *current, *prev;
    int swapped;

    do {
        swapped = 0;
        current = head;
        prev = NULL;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                if (prev == NULL) {
                    // Swap the first two nodes
                    struct Node* nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->next = current;
                    head = nextNode;
                } else {
                    // Swap the current and next nodes
                    struct Node* nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->next = current;
                    prev->next = nextNode;
                }
                swapped = 1;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);
}

// Function to perform insertion sort by interchanging links
void insertionSort(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* sorted = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            // Insert current node at the beginning
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            // Insert current node after temp
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
}

// Function to perform selection sort by interchanging links
void selectionSort(struct Node* head) {
    if (head == NULL)
        return;

    struct Node *current, *prev, *min, *minPrev;

    current = head;
    while (current->next != NULL) {
        min = current;
        minPrev = prev = current;
        while (prev->next != NULL) {
            if (prev->next->data < min->data) {
                minPrev = prev;
                min = prev->next;
            }
            prev = prev->next;
        }

        if (min != current) {
            if (current == head) {
                // Update head
                head = min;
            } else {
                // Interchange links
                minPrev->next = current;
            }
            struct Node* temp = min->next;
            min->next = current->next;
            current->next = temp;
        } else {
            current = current->next;
        }
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



// or this 

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

// Function to swap two nodes in a linked list
void swapNodes(struct Node** head_ref, struct Node* prev1, struct Node* node1, struct Node* prev2, struct Node* node2) {
    if (prev1 == NULL) {
        *head_ref = node2;
    } else {
        prev1->next = node2;
    }

    if (prev2 == node1) {
        node1->next = node2->next;
        node2->next = node1;
    } else {
        struct Node* temp = node2->next;
        node2->next = node1->next;
        node1->next = temp;
        prev2->next = node1;
    }
}

// Function to perform bubble sort by interchanging nodes
void bubbleSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    struct Node* prev;
    struct Node* current = NULL;

    do {
        swapped = 0;
        prev = NULL;
        current = head;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                struct Node* nextNode = current->next;
                struct Node* prevNode = prev;

                swapNodes(&head, prevNode, current, current, nextNode);
                swapped = 1;
            }

            prev = current;
            current = current->next;
        }
    } while (swapped);
}

// Function to perform insertion sort by interchanging nodes
void insertionSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    struct Node* sorted = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            // Insert current node at the beginning
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            // Insert current node after temp
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
}

// Function to find the minimum node in a linked list
struct Node* findMinNode(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* minNode = head;
    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }

    return minNode;
}

// Function to perform selection sort by interchanging nodes
void selectionSort(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* sorted = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* minNode = findMinNode(current);
        struct Node* prevMinNode = NULL;

        if (minNode != current) {
            struct Node* temp = minNode->next;

            swapNodes(&head, prevMinNode, minNode, current, minNode);

            current = minNode;
        }

        if (sorted == NULL) {
            sorted = current;
        }

        current = current->next;
    }

    head = sorted;
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
