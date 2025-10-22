#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
void Push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Stack OverFlow Condition!!!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("THe Value %d has been Inserted \n", value);
}

void pop()
{
    if (top == NULL)
    {
        printf("The Stack Is Empty\n");
        return;
    }
    struct Node *temp = top;
    printf("%d is poped from the stack\n", temp->data);
    top = top->next;
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("The Stack Is Empty...\n");
        return;
    }

    struct Node *temp = top;
    printf("THe elements of the Stack are :\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void count()
{
    if (top == NULL)
    {
        printf("The stack Is Empty , Count = 0\n");
        return;
    }

    struct Node *temp = top;
    int count=0;
    while (temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("The Number OF elements are : %d",count);
}
int main()
{
    int val, ch;
    while (1)
    {
        printf("\n++++++Singly Link List Using Stack +++++++++++\n\n");
        printf("1.Insert(push)\n");
        printf("2.Delete(pop)\n");
        printf("3.Display\n");
        printf("4.Count\n");
        printf("5.Exit\n");
        printf("Enter Your Choice!\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Value TO Insert Into The Stack :\n");
            scanf("%d", &val);
            Push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            count();
            break;
        case 5:
            printf("exiting...");
            exit(0);
        default:
            pritnf("Invalid CHoice, Try Again!!!");
        }
    }
}