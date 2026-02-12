#include <stdio.h>
#include <stdlib.h>

typedef struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
}dll;

dll *first,*last=NULL;

//insertion
void At_the_beginning(int element)
{
    dll *newnode;
    newnode=(dll *)malloc(sizeof(dll));

    newnode->data=element;
    newnode->next=newnode->prev=NULL;

    if (first==NULL)
        first=last=newnode;
    else
    {
        newnode->next=first;
        first->prev=newnode;
        first=newnode;
    }    
}

void At_the_end(int element)
{
    dll*newnode;
    newnode= (dll *)malloc(sizeof(dll));

    newnode->data=element;
    newnode->next=newnode->prev=NULL;

    if (first=NULL)
        first=last=newnode;
    else
    {
        last->next=newnode;
        last=newnode;
    }
}

void At_specific_position(int element, int pos)
{
    dll *newnode;
    newnode=(dll*)malloc(sizeof(dll));

    newnode->data=element;
    newnode->next=newnode->prev=NULL;

    if (pos<=0)
        printf("Invalid Position");
    else
    if (pos ==1)
        At_the_beginning(element);
    else
    {
        dll*temp=first;
        for(int i=1;(i<pos-1)&&(temp->next!=last);i++)
        {
            temp=temp->next;
        }
        if (temp==last)
            At_the_end(element);
        else
        {
            dll *tempp;
            tempp=temp->next;
            temp->next=newnode;
            newnode->next=tempp;
            tempp->prev=newnode;
            newnode->prev=temp;
        }
    }
}

//deletion
void Fron_the_beginning()
{
    dll *temp;
    if (first=NULL)
        printf("Invalid");
    else
    if (first==last)
    {
        temp=first;
        first=last=NULL;
        free(temp);
    }
    else
    {
        temp=first;
        first=temp->next;
        first->prev=NULL;
        free(temp);  
    }
}

void From_the_end()
{
    dll *temp;
    if (first=NULL)
        printf("INvalid");
    else
    if (first==last)
    {
        temp=first;
        first=last=NULL;
        free(temp);
    }
    else
    {
        temp=last;
        last=last->prev;
        last->next=NULL;
        free(temp);
    }
}

void From_specific_position(int pos)
{
    dll *temp;
    if (pos<=0 || first==NULL)
        printf("INvalid");
    else
    if (pos==1)
        Fron_the_beginning();
    else
    {
        temp=first;
        for(int i=0;(i<pos-1)&&(temp->next!=NULL);i++)
        {
            temp=temp->next;
        }
        if (temp==last)
            From_the_end();
        else
        {
            dll *tempp;
            tempp=temp->next;
            temp->next=tempp->next;
            (tempp->next)->prev=temp;
            free(tempp);
        }
    }
}

void display()
{
    if (first==NULL)
        printf("List is empty");
    else
    {
        dll *temp;
        while(temp!=NULL)
        {
             printf("%d ->",temp->data);
            temp=temp->next;
        }
         printf("NULL\n");
    }
}