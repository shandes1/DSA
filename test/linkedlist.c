#include <stdio.h>
#include <stdlib.h>


struct SLL
{
    int data;
    struct SLL *next; //address of next
};

struct SLL *FIRST, *LAST= NULL;

// insertion 
void At_the_beginning(int element)
{
    //newnode create
    struct SLL *newnode;
    newnode=(struct SLL *)malloc(sizeof(struct SLL));

    //value put garne
    newnode->data= element;
    newnode->next=NULL;

    //check 
    if (FIRST==NULL)
        FIRST=LAST=newnode;
    else
        newnode->next=FIRST;
        FIRST=newnode;
    
}

void At_the_end(int element)
{
    //newnode create
    struct SLL *newnode;
    newnode=(struct SLL*)malloc(sizeof(struct SLL));

    //value halne
    newnode->data=element;
    newnode->next=NULL;

    //CHECK
    if (FIRST==NULL)
        FIRST=LAST=newnode;
    else
    {
        LAST->next =newnode;
        LAST=newnode;
    }
    
}

void At_specific_position(int element,int pos)
{
    //create 
    struct SLL *newnode;
    newnode=(struct SLL*)malloc(sizeof(struct SLL));

    newnode->data=element;
    newnode->next=NULL;

    if (pos<=0)
        printf("invalid");
    else
    if (pos==1)
        At_the_beginning(element);
    else
    {
        struct SLL* temp=FIRST;
        for (int i=1;(i<pos-1)&&(temp->next!=NULL);i++)
        {
            temp=temp->next;
        }
        if (temp==LAST)
            At_the_end(element);
        else
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}

//deletion
void from_the_beginning()
{
    if (FIRST==NULL)
        printf("List is empty\n");
    else
    if (FIRST==LAST)
        {
            struct SLL * temp=FIRST;
            FIRST=LAST=NULL;
            free(temp);
        }
    else
    {
        struct SLL * temp=FIRST;
        FIRST=FIRST->next;
        free(temp);
    }

}

void from_the_end()
{
    if (FIRST==NULL)
        printf("List is empty\n");
    else
    if (FIRST==LAST)
    {
        struct SLL *temp=FIRST;
        FIRST=LAST=NULL;
        free(temp);
    }
    else
    {
        struct SLL*temp=FIRST;
        while(temp->next!=LAST)
        {
            temp=temp->next;
        }
        LAST=temp;
        temp=temp->next;
        free(temp);
        LAST->next=NULL;
    }
}

void from_the_specific_position(int pos)
{
    if (pos<=0 || FIRST==NULL)
        printf("Invalid deletion");
    else
    if (pos==1)
        from_the_beginning();
    else
    {
        struct SLL *temp=FIRST;
        for(int i=1;(i<pos-1)&&(temp->next!=LAST);i++)
        {
            temp=temp->next;
        }
        if (temp==LAST)
            from_the_end();
        else
        {
            struct SLL *tempp =temp->next;
            temp->next=tempp->next;
            free(tempp);
        }
    }
}


void display()
{
    if (FIRST==NULL)
        printf("LIST IS EMPTY\n");
    else
    {
        struct SLL *temp=FIRST;
        while(temp!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    At_the_beginning(5);
    display();
    At_the_beginning(11);
    display();  
    At_the_beginning(12);
    display();
    At_the_beginning(6);
    display();
    At_the_end(7);
    display();
    At_specific_position(8,100);
    display();
    from_the_beginning();
    display();
    from_the_end();
    display();
    from_the_specific_position(2);
    display();
    return 0;
}