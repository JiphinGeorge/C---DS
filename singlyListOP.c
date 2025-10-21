// Single Linked List operations- Creation, Insertion, Deletion, Traversal, Count.

#include <stdio.h>  // For input-output functions like printf, scanf
#include <stdlib.h> // For malloc() and free() functions

// Define structure for a node in the linked list
struct Node
{
    int data;          // To store data value
    struct Node *next; // Pointer to the next node
};

// Declare head pointer globally (points to the first node)
struct Node *head = NULL;

// Function to create a new node and return its address
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
    newNode->data = value;                                             // Store the value
    newNode->next = NULL;                                              // Set next pointer as NULL (end of list)
    return newNode;                                                    // Return the created node
}

// Function to insert a node at the end of the list
void insertNode(int value)
{
    struct Node *newNode = createNode(value); // Create a new node using the given value

    if (head == NULL)
    { // If list is empty, make newNode the first node
        head = newNode;
        return;
    }

    struct Node *temp = head;  // Start from the head node
    while (temp->next != NULL) // Traverse till the last node
        temp = temp->next;

    temp->next = newNode; // Link the last node to the new node
}

// Function to delete a node by its value
void deleteNode(int value)
{
    struct Node *temp = head; // Temporary pointer to traverse
    struct Node *prev = NULL; // Pointer to store previous node

    // Case 1: If list is empty
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // Case 2: If the head node itself has the value
    if (temp != NULL && temp->data == value)
    {
        head = temp->next; // Move head to the next node
        free(temp);        // Delete the old head node
        printf("Node with value %d deleted.\n", value);
        return;
    }

    // Case 3: Search for the node to be deleted
    while (temp != NULL && temp->data != value)
    {
        prev = temp;       // Store the previous node
        temp = temp->next; // Move to next node
    }

    // Case 4: If the value is not found in the list
    if (temp == NULL)
    {
        printf("Value %d not found.\n", value);
        return;
    }

    // Case 5: Unlink the node from the list
    prev->next = temp->next;
    free(temp); // Free the memory of deleted node
    printf("Node with value %d deleted.\n", value);
}

// Function to display all nodes in the linked list
void displayList()
{
    struct Node *temp = head; // Temporary pointer to traverse
    if (temp == NULL)
    { // If list is empty
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL)
    {                                 // Traverse until the end of the list
        printf("%d -> ", temp->data); // Print data of each node
        temp = temp->next;            // Move to next node
    }
    printf("NULL\n"); // End of list
}

// Function to count total number of nodes in the list
void countNodes()
{
    int count = 0;            // Initialize counter
    struct Node *temp = head; // Temporary pointer

    while (temp != NULL)
    {                      // Traverse through the list
        count++;           // Increment counter
        temp = temp->next; // Move to next node
    }

    printf("Total nodes = %d\n", count); // Print total count
}

// Main function: Provides a menu to perform operations
int main()
{
    int choice, value;

    while (1)
    { // Infinite loop for menu-driven program
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Count Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user choice

        switch (choice)
        { // Perform action based on choice
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertNode(value); // Call insert function
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value); // Call delete function
            break;

        case 3:
            displayList(); // Display current list
            break;

        case 4:
            countNodes(); // Count total nodes
            break;

        case 5:
            exit(0); // Exit the program

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
