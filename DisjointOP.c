#include <stdio.h>

#define MAX 20 // Maximum number of elements

int parent[MAX];   // Parent array
int elements[MAX]; // Store actual user elements
int n;

// Function to create disjoint sets
void createSet()
{
    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elements[i]);
        parent[i] = i; // initially each element is its own parent
    }
    printf("Disjoint sets created.\n");
}

// Find index of element in elements[]
int getIndex(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (elements[i] == x)
            return i;
    }
    return -1; // not found
}

// Find operation with path compression
int findSet(int i)
{
    if (parent[i] != i)
        parent[i] = findSet(parent[i]);
    return parent[i];
}

// Union operation
void unionSet(int x, int y)
{
    int i = getIndex(x);
    int j = getIndex(y);

    if (i == -1 || j == -1)
    {
        printf("One or both elements not found!\n");
        return;
    }

    int rootI = findSet(i);
    int rootJ = findSet(j);

    if (rootI != rootJ)
    {
        parent[rootJ] = rootI;
        printf("Union done: %d and %d are now in the same set.\n", x, y);
    }
    else
    {
        printf("%d and %d are already in the same set.\n", x, y);
    }
}

// Display parent mapping
void display()
{
    printf("Element: ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements[i]);
    printf("\nParent : ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements[parent[i]]);
    printf("\n");
}

int main()
{
    int choice, x, y;

    createSet();

    do
    {
        printf("\n--- Disjoint Set Operations ---\n");
        printf("1. Union\n");
        printf("2. Find\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter two elements to union: ");
            scanf("%d %d", &x, &y);
            unionSet(x, y);
            break;

        case 2:
            printf("Enter element to find its set representative: ");
            scanf("%d", &x);
            {
                int idx = getIndex(x);
                if (idx == -1)
                    printf("Element not found!\n");
                else
                    printf("Representative of %d is: %d\n", x, elements[findSet(idx)]);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}