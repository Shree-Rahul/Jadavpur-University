#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the threaded binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isThreaded; // Flag to indicate if the right pointer is a thread
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Function to find the leftmost node in the subtree rooted at a given node
struct Node* leftmostNode(struct Node* node) {
    if (node == NULL)
        return NULL;

    while (node->left != NULL)
        node = node->left;

    return node;
}

// Function to perform an inorder traversal of the threaded binary tree
void inorderTraversal(struct Node* root) {
    struct Node* current = leftmostNode(root);

    while (current != NULL) {
        printf("%d ", current->data);

        if (current->isThreaded)
            current = current->right;
        else
            current = leftmostNode(current->right);
    }
}

// Function to insert a node into the threaded binary tree
struct Node* insertNode(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    if (root == NULL) {
        root = newNode;
    } else {
        struct Node* current = root;
        struct Node* parent = NULL;

        while (1) {
            parent = current;

            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    newNode->right = current;
                    newNode->isThreaded = 1;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->isThreaded == 1) {
                    newNode->right = current->right;
                    current->right = newNode;
                    current->isThreaded = 0;
                    newNode->isThreaded = 1;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("Threaded Binary Tree Menu\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

/*A threaded binary tree is a variation of a binary tree where some of the null pointers are replaced with threads. These threads link nodes together to facilitate efficient traversal of the tree without using recursion or a stack.

In a threaded binary tree, each node contains two additional pointers, known as threaded pointers, along with the regular left and right pointers. These threaded pointers can be used to navigate through the tree in a specific order without explicitly traversing all the left and right sub-trees.

There are two types of threads in a threaded binary tree:

1. Inorder predecessor thread: It connects a node to its inorder predecessor, i.e., the node that comes before it in an inorder traversal.
2. Inorder successor thread: It connects a node to its inorder successor, i.e., the node that comes after it in an inorder traversal.

The purpose of using threads is to eliminate the need for explicit stack-based or recursive traversal methods. By following the threaded pointers, we can move directly to the inorder predecessor or inorder successor of a node without traversing the entire left or right sub-tree.

Threads can be helpful in various scenarios, such as finding the next or previous node in an inorder traversal, performing efficient inorder traversals without using recursion or a stack, and reducing the memory overhead required for traversal.

It's important to note that maintaining and updating threads during insertions and deletions can add complexity to the tree operations, and care must be taken to ensure the threads are correctly maintained to preserve the integrity of the threaded binary tree.*/