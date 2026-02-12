#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicQueue
{
    int data;
    struct DynamicQueue *next;
} DynamicQueue;

DynamicQueue *front = NULL, *rear = NULL;

void enqueue(int element)
{
    DynamicQueue *newnode;
    newnode = (DynamicQueue *)malloc(sizeof(DynamicQueue));

    newnode->data = element;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
        printf("%d is pushed into queue\n", newnode->data);
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        printf("%d is pushed into queue\n", newnode->data);
    }
}

void dequeue()
{
    if (front == NULL)
        printf("INvalid");
    else if (front->next == NULL)
    {
        DynamicQueue *temp = front;
        front = rear = NULL;
        printf("%d is removed from the queue", temp->data);
        free(temp);
    }
    else
    {
        DynamicQueue *temp = front;
        front = front->next;
        printf("%d is removed from the queue", temp->data);
        free(temp);
    }
}

int main()
{
    int choice, value;
    do
    {

        printf("Welcome to queue");
        printf("\n1.Enqueue\n2.Dequeue\n3.EXIT \n->");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element:");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            printf("This is the end.\n");
            break;

        default:
            printf("Invalid");
            break;
        }
    } while (choice != 3);
}