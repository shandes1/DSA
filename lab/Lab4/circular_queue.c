#include <stdio.h>
#define MAX 5

typedef struct CircularQUEUE
{
    int Front;
    int Rear;
    int SIZE;
    int data[MAX];
}queue;



void Enqueue(queue *Q,int element)
{
    if(Q->SIZE==MAX)
    {
        printf("Queue is full\n");
    }
    else
    {
        Q->Rear=(Q->Rear+1)%MAX;
        Q->data[Q->Rear]=element;
        Q->SIZE +=1;


    }
}

int Dequeue(queue *Q)
{
    if (Q->SIZE==0)
    {
        printf("Queue is empty\n");
        return -9999;
    }
    else
    {
        int element=Q->data[Q->Front];
        Q->Front=(Q->Front+1)%MAX;
        Q->SIZE-=1;
        return element;
    }
}

int isFull(queue *Q)
{
   return Q->SIZE==MAX?1:0;
}

int isEmpty(queue *Q)
{
    return Q->SIZE==0?1:0;   
}

int main()
{
    queue Q={0,-1,0};
    int choice,value;
    do
    {
        printf("welcome to the Queue:");
        printf("\n1.Insert\n2.Remove\n3.Check\n4.EXIT \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
       
            printf("Enter the value:");
            scanf("%d",&value);
            Enqueue(&Q,value);
            break;
        
        case 2:
            
            value=Dequeue(&Q);
            if (value!=-9999)
                printf("%d is removed from the queue\n",value);
            break;
        
        case 3:
            if (isFull(&Q))
                printf("Queue is full\n");
            else 
                if (isEmpty(&Q))
                    printf("Queue is Empty\n");
                else
                    printf("Queue is neither empty nor full\n");
            break;
        
        case 4:
            printf("This is the end");
            break;

        default:
            printf("Invalid");
            break;
        }


    } while (choice !=4);
    
}