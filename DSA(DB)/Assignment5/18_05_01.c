#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // Key found at index i
    }
    return -1;  // Key not found
}

// Function to perform binary search (iterative)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;  // Key found at index mid
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // Key not found
}

int main() {
    int arr[100];
    int n, choice, key, index;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nSearching Techniques Menu\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                index = linearSearch(arr, n, key);
                if (index != -1)
                    printf("Element found at index %d\n", index);
                else
                    printf("Element not found\n");
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                index = binarySearch(arr, n, key);
                if (index != -1)
                    printf("Element found at index %d\n", index);
                else
                    printf("Element not found\n");
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
