#include <stdio.h>       // Include standard input-output library for printf and scanf

#define MAX 10           // Define maximum number of elements in the universal set

// Function to display a set from its bit string representation
void displaySet(int set[], int n, char universal[]) {
    printf("{ ");                       // Print opening brace for set
    for (int i = 0; i < n; i++) {       // Loop through each element in the universal set
        if (set[i] == 1) {              // If bit is 1, that element is in the set
            printf("%c ", universal[i]); // Print the corresponding element
        }
    }
    printf("}\n");                       // Print closing brace and new line
}

// Function to compute Union (A ∪ B) and store in C
void unionSet(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) {       // Loop through all elements
        C[i] = A[i] | B[i];             // Bitwise OR: if element in A or B → C=1
    }
}

// Function to compute Intersection (A ∩ B) and store in C
void intersectionSet(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) {       // Loop through all elements
        C[i] = A[i] & B[i];             // Bitwise AND: if element in both A and B → C=1
    }
}

// Function to compute Difference (A - B) and store in C
void differenceSet(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) {       // Loop through all elements
        C[i] = A[i] & (!B[i]);          // Bitwise AND with NOT: element in A but not in B → C=1
    }
}

int main() {
    int n;
    printf("Enter size of universal set: ");  
    scanf("%d", &n);                     // Input size of universal set

    char universal[MAX];                 // Array to store universal set elements
    printf("Enter elements of universal set:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &universal[i]);    // Input each element of universal set
        // Note the space before %c to skip whitespace/newlines
    }

    int A[MAX] = {0}, B[MAX] = {0}, C[MAX] = {0}; // Initialize bit string arrays to 0
    int sizeA, sizeB;

    printf("Enter size of set A: ");
    scanf("%d", &sizeA);                 // Input number of elements in Set A
    printf("Enter elements of set A:\n");
    for (int i = 0; i < sizeA; i++) {
        char x;
        scanf(" %c", &x);               // Input each element of Set A
        for (int j = 0; j < n; j++) {   // Find the element in universal set
            if (universal[j] == x) {    // If element matches
                A[j] = 1;               // Set bit to 1 in bit string
            }
        }
    }

    printf("Enter size of set B: ");
    scanf("%d", &sizeB);                 // Input number of elements in Set B
    printf("Enter elements of set B:\n");
    for (int i = 0; i < sizeB; i++) {
        char x;
        scanf(" %c", &x);               // Input each element of Set B
        for (int j = 0; j < n; j++) {   // Find the element in universal set
            if (universal[j] == x) {    // If element matches
                B[j] = 1;               // Set bit to 1 in bit string
            }
        }
    }

    printf("\nSet A: ");
    displaySet(A, n, universal);         // Display Set A
    printf("Set B: ");
    displaySet(B, n, universal);         // Display Set B

    // Union
    unionSet(A, B, C, n);                // Compute A ∪ B
    printf("\nA ∪ B = ");
    displaySet(C, n, universal);         // Display union

    // Intersection
    intersectionSet(A, B, C, n);         // Compute A ∩ B
    printf("A ∩ B = ");
    displaySet(C, n, universal);         // Display intersection

    // Difference
    differenceSet(A, B, C, n);           // Compute A - B
    printf("A - B = ");
    displaySet(C, n, universal);         // Display difference

    return 0;                             // End of program
}
