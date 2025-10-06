#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



struct Node* insert(struct Node* root, int value){
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}


struct Node* search(struct Node* root, int value){

    if(root == NULL || root->data==value)
    {
        return root;
    }

    if(value <root->data){
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}



struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;  // Move to the leftmost node
    }
    return root;
}



struct Node* deleteNode(struct Node* root ,int  value){

    if(root == NULL){
        return root;
    }


    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if (value >root->data){
        root->right = deleteNode(root->right, value);  
    }
    else{

        if(root ->left== NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root ->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data); 
    }
}



void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void postorder(struct Node* root)
{
    if(root !=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


void preorder(struct Node* root){
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}




int main()
{
    int ch,value;
    struct node *root = NULL;
    while (1)
    {
        printf("\n\n---Binary Search Tree Menu---\n");
        printf("\n1.Insertion \n2.Deletion\n3.Search\n4.Inorder traversal\n5.Preorder Traversal\n6.Postorder Traversal \n7.Exit\n");
        printf("Enter Your Choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Element to Insert :");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the Element To Delete :");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            printf("Enter the Element to Search :");
            scanf("%d", &value);
            struct Node *found = search(root, value);
            if(found != NULL)
            {
                printf("%d is Found in the Tree\n", value);
            }
            else{
                printf("The Element %d is not Found in the Tree\n", value);
            }
        case 4:
            printf("Inorder Traversal : \n");
            inorder(root);
            break;
        case 5:
            printf("Preorder Traversal :\n");
            preorder(root);
            break;
        case 6:
            printf("Postorder Traversal :\n");
            postorder(root);
            break;
        case 7:
            printf("Exiting the Program...\n");
            exit(0);
        default:
            printf("Invalid Choice , Try Again...!\n");
            break;
        }
    }
    return 0;
}