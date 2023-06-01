#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the AVL tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to get the height of a node
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to update the height of a node
void updateHeight(struct Node* node) {
    if (node == NULL)
        return;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to perform a left rotation
struct Node* leftRotate(struct Node* node) {
    struct Node* rightChild = node->right;
    struct Node* leftGrandchild = rightChild->left;

    rightChild->left = node;
    node->right = leftGrandchild;

    updateHeight(node);
    updateHeight(rightChild);

    return rightChild;
}

// Function to perform a right rotation
struct Node* rightRotate(struct Node* node) {
    struct Node* leftChild = node->left;
    struct Node* rightGrandchild = leftChild->right;

    leftChild->right = node;
    node->left = rightGrandchild;

    updateHeight(node);
    updateHeight(leftChild);

    return leftChild;
}

// Function to get the balance factor of a node
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform insertion in the AVL tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else // Duplicate keys are not allowed in AVL tree
        return root;

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if (balanceFactor > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balanceFactor < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balanceFactor > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for an element in the AVL tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

// Function to find the node with minimum value in the AVL tree
struct Node* findMinimum(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Function to perform deletion in the AVL tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted is found

        // Case 1: Node with no child or only one child
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp);
        }
        // Case 2: Node with two children
        else {
            struct Node* successor = findMinimum(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }

    if (root == NULL)
        return root;

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform inorder traversal of the AVL tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("AVL Tree Menu\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Element deleted\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
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