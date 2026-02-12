#include <stdio.h>
#include <stdlib.h>

typedef struct dynamicStack
{
    int data;
    struct dynamicStack *next;

} dynamicStack;

dynamicStack *top = NULL;

void push(int element)
{
    // allocate
    dynamicStack *newnode;
    newnode = (dynamicStack *)malloc(sizeof(dynamicStack));

    newnode->data = element;
    newnode->next = NULL;

    if (top == NULL)
    {
        top = newnode;
        printf("%d is pushed into stack\n", newnode->data);
    }
    else
    {
        newnode->next = top;
        top = newnode;
        printf("%d is pushed into stack\n", newnode->data);
    }
}

void pop()
{
    dynamicStack *temp;
    if (top == NULL)
        printf("Stack is empty");
    else if (top->next == NULL)
    {
        temp = top;
        top = NULL;
        printf("%d is removed from the stack", temp->data);
        free(temp);
    }
    else
    {
        temp = top;
        top = top->next;
        printf("%d is removed from the stack", temp->data);
        free(temp);
    }
}

int main()
{
    int choice, value;
    do
    {

        printf("Welcome to stack");
        printf("\n1.Push\n2.POP\n3.EXIT \n->");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element:");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
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