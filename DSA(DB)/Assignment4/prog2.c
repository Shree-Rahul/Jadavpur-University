#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Array to store the binary tree
int tree[MAX_SIZE];
int currentIndex = 0;

// Function to insert a node into the binary tree
void insertNode(int data) {
    if (currentIndex < MAX_SIZE) {
        tree[currentIndex] = data;
        currentIndex++;
    } else {
        printf("Binary tree is full. Insert operation failed.\n");
    }
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(int index) {
    if (index >= currentIndex)
        return;

    printf("%d ", tree[index]);
    preorderTraversal(2 * index + 1);
    preorderTraversal(2 * index + 2);
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(int index) {
    if (index >= currentIndex)
        return;

    inorderTraversal(2 * index + 1);
    printf("%d ", tree[index]);
    inorderTraversal(2 * index + 2);
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(int index) {
    if (index >= currentIndex)
        return;

    postorderTraversal(2 * index + 1);
    postorderTraversal(2 * index + 2);
    printf("%d ", tree[index]);
}

int main() {
    int choice, data;

    do {
        printf("Binary Tree Menu\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertNode(data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(0);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(0);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(0);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
