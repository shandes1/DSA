#include <stdio.h>
#define true 1
#define false 0
#define MAX 5

typedef struct stack
{
    int TOS;
    int data[MAX];

}stack;

// function for full stack
int IsFull(stack *s)
{
    // if (s->TOS== MAX-1)
    //     return true;
    // else
    //     return false;

    return s-> TOS == MAX -1 ? true:false;

}

// function for empty stack
int IsEmpty(stack *s)
{
    // if (s->TOS==-1)
    //     return true;
    // else
    //     return false;

    return s-> TOS ==-1 ? true:false;
}

// push operator
void push(stack *s,int elements)
{
    // s->TOS +=1;
    // s->data[s->TOS ]= elements;
     s-> data[++s->TOS]=elements;
}

// pop operator
int pop(stack *s)
{
    // int element;
    // element= s->data[s->TOS]
    // TOS -=1;
    return s->data[s->TOS--];
}

//peek operator 
int peek(stack *s)
{
    return s->data[s->TOS];
}

int main()
{
    int choice,value;
    stack s={-1};
    do 
    {
        printf("welcome to the STACK:");
        printf("\n1.Push\n2.POP\n3.PEEK\n4.EXIT \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            if(IsFull(&s))
                printf("Stack overrflow\n");
            else
            {
                printf("Enter element:");
                scanf("%d",&value);
                push(&s,value);
                printf("%d is pushed in the stack \n",value);
            }
            break;

            case 2:
            if(IsEmpty(&s))
                printf("Stack empty\n");
            else
            {
                value= pop(&s);
                printf("The element is %d\n", value);
            }
            break;

            case 3:
            if(IsEmpty(&s))
                printf("Stack Empty\n");
            else
            {
                value= peek(&s);
                printf("The element at the top of stack is %d\n", value);
            }
            break;
            case 4:
                printf("This is the end");
                break;
            default:
                printf("Invalid value");
                break;
        }
    }while(choice!= 4);
   printf("\n");
   return 0;
}