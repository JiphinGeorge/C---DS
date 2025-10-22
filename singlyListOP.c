#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Initially the list is empty

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insertNode()
{
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted successfully!\n");
}

// Function to delete a node by value
void deleteNode()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct Node *temp = head, *prev = NULL;

    // If head node holds the value
    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully!\n");
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL)
    {
        printf("Value not found in list!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully!\n");
}

// Function to traverse (display) the linked list
void displayList()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to count nodes
void countNodes()
{
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes: %d\n", count);
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Count Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            displayList();
            break;
        case 4:
            countNodes();
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
