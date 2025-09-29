#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of Circular Queue

int queue[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Insert an element into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full! Cannot insert %d\n", value);
    } else {
        if (front == -1) // First element
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

// Delete an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty! Cannot delete.\n");
    } else {
        int data = queue[front];
        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("%d deleted from queue.\n", data);
    }
}

// Display elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

// Count elements in the circular queue
void countElements() {
    if (isEmpty()) {
        printf("Queue is Empty! Count = 0\n");
    } else {
        int count = (rear - front + SIZE) % SIZE + 1;
        printf("Total elements in queue: %d\n", count);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                countElements();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 //allocating the size as 5

int queue[SIZE];
int front = -1, rear = -1; //initilizing the front and rear = -1 as intial value

int isFull()//function to check wheaher the queue is full or not
{
    if ((rear + 1) % SIZE == front)
    {
        return 1;
    }
    return 0;
}

int isEmpty()//funcation to check wheather the queue if empty
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int value)//insert funcation
{
    if (isFull())//checking overflow
    {
        printf("The Queue if Full !, Delete Some Elements !\n");
        return;
    }
    if (isEmpty())// if the queue is empty, we are changeing the intial value as 0 
    {
        front = rear = 0;
    }
    else//increASING THE rear to insert value
    {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;// assiging the value to the rear
    printf("%d Is Inserted Into the Queue !\n", value);
}

void dequeue()//delete function
{
    if (isEmpty())//checking the queue is empty or not
    {
        printf("The Queue Is Empty !");
        return;
    }

    printf("The Element %d is Deleted from the Queue \n", queue[front]);//displaying the front element before it is deleted

    if (front == rear)//if it was the last element in the queue then we are updating the front and rear =-1
    {
        front = rear = -1;//
    }
    else// IF THERE ARE MORE THAN 1 ELEMNT PRESNT THIS else part works ..... jst moving the front of the queue froward
    {
        front = (front + 1) % SIZE;
    }
}

void count()//count Function
{

    if (isEmpty())//checking wheather the queue is Empty
    {
        printf("The Queue Is Empty ! , 0 Number of Elements\n");
        return;
    }
    int count = 0;
    int i = front;// i vasrible is used since the font is a global varible ,(changes in front affect the global value)
    while (1)
    {
        count++;
        if (i == rear)//to exit once the last element is counted
            break;
        i = (i + 1) % SIZE;//updating the value of i to move forward through the queue
    }
    printf("The Total Number of Elements in the Queue are : %d\n\n", count);
}

void display()
{
    int i = front;//i vasrible is used since the font is a global varible ,(changes in front affect the global value)
    if (isEmpty())
    {
        printf("The Queue Is Empty \n");//checking wheather the queue is Empty
        return;
    }
    printf("The Elements of the Queue are :");
    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)//to exit once the last element is printed
        {
            break;
        }
        i = (i + 1) % SIZE;
    }
}

int main()
{
    int ch, val;
    while (1)
    {
        printf("\n\n===Circular Queue===\n");
        printf("\n1.Enqueue(Insert)\n");
        printf("\n2.Dequeue (Delete)\n");
        printf("\n3.Display The Queue Elements\n");
        printf("\n4.Count OF the Elements\n");
        printf("\n5.Exit\n\n");
        printf("Enter the Choice :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the Elementss To Insert :");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            count();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Choice , try Again !");
            break;
        }
    }
}