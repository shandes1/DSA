#include <stdio.h>
#include <stdlib.h>

typedef struct SLL 
{
    int data;
    struct SLL * next;

}sll ;

sll *first, *last=NULL;

void insert_at_beginning(int element)
{
    
    sll *newnode;
    newnode= (sll*)malloc(sizeof(sll));
    
    newnode->data = element;
    newnode->next= NULL;
    if (first== NULL)
    {
        first=last=newnode;
        
    }
    else
    {
        newnode->next= first;
        first = newnode;
    }
    printf("%d is inserted at the beginning. \n",first->data);
}

void insert_at_end(int element)
{
    sll *newnode;
    newnode= (sll*)malloc(sizeof(sll));

    newnode->data = element;
    newnode->next= NULL;

    if (first== NULL)
    {
        first=last=newnode;
    }
    else
    {
        last->next= newnode;
        last= newnode;
    }
    printf("%d is inserted at the end.\n",last-> data);
}

void insert_at_specific_position(int element, int pos)
{
    sll *newnode;
    newnode= (sll *)malloc(sizeof(sll));

    newnode->data= element;
    newnode->next = NULL;

    if (pos <=0)
    {
        printf("Invalid position\n");
    }
    else
    {
        if (pos== 1)
        {
            insert_at_beginning(newnode->data);
        }
        else
        {
            sll * temp;
            temp= first;
            for(int i= 1; (i< pos-1) && (temp->next != NULL);i++)
            {
                temp= temp-> next;
            }
            if (temp== last)
            {
                insert_at_end(newnode->data);
            }
            else
            {
                newnode->next= temp-> next;
                temp->next=newnode;
                printf("%d is inserted at the %d position.\n",newnode->data,pos);
            }
        }
    }
}


void deletion_from_the_beginning()
{
      sll *temp;
    if (first== NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if (first->next== NULL)
        {
            temp= first;
            first=last=NULL;
            free(temp);
        }
        else
        {
            temp= first;
            first=first->next;
            free(temp);
        }
    }
    printf(" A element is deleted from the beginning\n");
}

void deletion_from_the_end()
{
      sll *temp;
    if (first== NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if (first->next== NULL)
        {
            temp= first;
            first=last=NULL;
            free(temp);
        }
        else
        {
            temp= first;
            while(temp->next != last)
            {
                temp = temp->next;
            }
            last = temp;
            temp = temp-> next;
            last->next = NULL;
            free(temp);
        }
    }
    printf(" A element is deleted from the end\n");
}



void deletion_from_specific_position(int pos)
{

    if (pos <=0 || first==NULL)
    {
        printf("Invalid deletion\n");
    }
    else
    {
        if (pos== 1)
        {
            deletion_from_the_beginning();
        }
        else
        {   
            sll * temp;
            temp= first;
            for(int i= 1; (i< pos-1) && (temp->next != last);i++)
            {
                temp= temp-> next;
            }
            if (temp->next== last)
            {
                deletion_from_the_end();
            }
            else
            {
                sll *temppp;
                temppp= temp->next;
                temp->next=temppp->next;
                free(temppp);
                printf("An element is deleted from the %d position.\n",pos);
            }
        }
    }
}


void display()
{
    sll* temp;
    if(first == NULL)
     printf("list is empty\n");
    else
    { 
        temp= first;
        while( temp!= NULL)
        {
            printf(" %d ->",temp->data);
            temp= temp-> next;
        }
        printf("NULL \n");
    }
}

int main()
{
    insert_at_beginning(5);
    display();
    insert_at_beginning(11);
    display();  
    insert_at_beginning(12);
    display();
    insert_at_beginning(6);
    display();
    insert_at_end(7);
    display();
    insert_at_specific_position(8,100);
    display();
    deletion_from_the_beginning();
    display();
    deletion_from_the_end();
    display();
    deletion_from_specific_position(2);
    display();
    return 0;
}
    
