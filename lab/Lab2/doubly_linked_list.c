#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *next, *prev;
};

struct DLL *first, *last = NULL;

void display()
{
    if (first == NULL)
        printf("Empty List.\n");
    else
    {
        struct DLL *temp = first;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insert_at_beginning(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));

    NewNode->data = element;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if (first == NULL)
        first = last = NewNode;
    else
    {
        NewNode->next = first;
        first->prev = NewNode;
        first = NewNode;
    }
    printf("%d WAS INSERTED at beginning.\n", first->data);
}

void insert_at_end(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));

    NewNode->data = element;
    NewNode->next = NULL;

    if (first == NULL)
        first = last = NewNode;
    else
    {
        NewNode->prev = last;
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d WAS INSERTED at end.\n", last->data);
}

void insert_at_specificPostion(int element, int POS)
{
    struct DLL *NewNode, *temp;
    int i;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));

    NewNode->data = element;
    NewNode->next = NULL;

    if (POS <= 0)
    {
        printf("Invalid Position.\n");
    }
    else if (POS == 1 || first == NULL)
    {
        insert_at_beginning(element);
    }
    else
    {
        struct DLL *temp = first;

        for (i = 1; (i < POS - 1) && (temp->next != NULL); i++)
        {
            temp = temp->next;
        }

        if (temp == last)
            insert_at_end(element);
        else
        {
            NewNode->next = temp->next;
            NewNode->prev = temp;
            (NewNode->next)->prev = NewNode;
            temp->next = NewNode;
            printf("%d WAS INSERTED at %d.\n", NewNode->data, POS);
        }
    }
}

void delete_from_beginning()
{
    struct DLL *temp;

    if (first == NULL)
        printf("ERROR: List is empty.\n");
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        free(temp);
        first->prev = NULL;
    }
    printf("Data was deleted from beginning.\n");
}

void delete_from_end()
{
    struct DLL *temp;

    if (first == NULL)
        printf("ERROR: List is empty.\n");
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = last->prev;
        last = temp;
        free(temp->next);
        last->next = NULL;
    }
    printf("Data was deleted from end.\n");
}

void delete_from_specific_position(int POS)
{
    struct DLL *temp, *tempp;
    int i;
    if (first == NULL)
        printf("List is empty\n");
    else if (POS <= 0)
        printf("Invalid position.");
    else if (POS == 1)
        delete_from_beginning();
    else
    {
        temp = first;
        for (i = 1; (i < POS - 1) && (temp->next != last); i++)
            temp = temp->next;

        if (temp->next == last)
            delete_from_end();
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            (tempp->next)->prev = temp;
            free(tempp);
        }

        printf("Data was deleted from %d\n", POS);
    }
}

int main()
{
    insert_at_end(20);
    display();
    insert_at_end(10);
    display();
    insert_at_end(25);
    display();
    insert_at_specificPostion(30, 1);
    display();
    insert_at_specificPostion(11, 4);
    display();
    insert_at_specificPostion(200, 6);
    display();
    insert_at_specificPostion(500, 20);
    display();

    delete_from_beginning();
    display();
    delete_from_end();
    display();
    delete_from_specific_position(3);
    display();
}