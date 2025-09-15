#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

struct QueueNode
{
    struct Node *data;
    struct QueueNode *next;
};

struct Queue
{

    struct QueueNode *front, *rear;
};


struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q-> rear= NULL;
    return q;
}

void enqueue(struct Queue *q, struct Node *node)
{
    struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode)); // Allocate queue node
    temp->data = node;                                                             // Store tree node pointer
    temp->next = NULL;                                                             // New node goes at rear, so next is NULL

    if (q->rear == NULL)
    {                              
        q->front = q->rear = temp; 
        return;
    }
    q->rear->next = temp; 
    q->rear = temp;       
}


struct Node *dequeue(struct Queue *q)
{
    if (q->front == NULL) 
        return NULL;

    struct QueueNode *temp = q->front; 
    struct Node *node = temp->data;    

    q->front = q->front->next; 

    if (q->front == NULL) 
        q->rear = NULL;   

    free(temp); 
    return node; 
}

int isEmpty(struct Queue *q)
{
    return q->front == NULL; 
}

struct Node *insert(struct Node *root, int value)
{
    struct Node *newNode = createNode(value); 

    if (root == NULL) 
        return newNode;

    struct Queue *q = createQueue(); 
    enqueue(q, root);               

    while (!isEmpty(q))
    {
        struct Node *temp = dequeue(q); 
        if (temp->left == NULL)
        { 
            temp->left = newNode;
            break;
        }
        else
        {
            enqueue(q, temp->left); 
        }

        if (temp->right == NULL)
        { 
            temp->right = newNode;
            break;
        }
        else
        {
            enqueue(q, temp->right); 
        }
    }

    free(q);    
    return root; 
}


void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);        
    printf("%d ", root->data);  
    inorder(root->right);   
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);  
    preorder(root->left);       
    preorder(root->right);      
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);      
    postorder(root->right);     
    printf("%d ", root->data);  
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n=== Binary Tree Menu ===\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            exit(0); 

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
