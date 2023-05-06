#include <stdio.h>

int main() {
    int n, k, p, direction, count = 0, i;
    printf("Enter the total number of people: ");
    scanf("%d", &n);
    int circle[n][2];
    for (i = 0; i < n; i++) {
        circle[i][0] = i + 1; // Initialize the first column with the values 1 to n
        circle[i][1] = 0; // Initialize the second column with the value 0
    }
    printf("Enter the starting point of counting: ");
    scanf("%d", &p);
    printf("Enter the direction of counting (0 for clockwise, 1 for anticlockwise): ");
    scanf("%d", &direction);
    printf("Enter the number of people to skip: ");
    scanf("%d", &k);
    while (count < n - 1) { // Repeat until only one person remains
        int next = (p - 1 + k) % n; // Find the next person to be executed
        while (circle[next][1] == 1) { // Skip the executed people
            next = (next + 1) % n;
        }
        circle[next][1] = 1; // Execute the next person
        count++;
        p = next; // Set the next starting point
    }
    for (i = 0; i < n; i++) {
        if (circle[i][1] == 0) { // Find the person to be freed
            printf("The person to be freed is: %d\n", circle[i][0]);
            break;
        }
    }
    return 0;
}