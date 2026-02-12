#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial
{
    int power;
    float coefficient;
    struct polynomial *next;
} polynomial;

void insert(polynomial **first, int power, float coeff)
{
    polynomial *newnode;
    newnode = (polynomial *)malloc(sizeof(polynomial));

    newnode->coefficient = coeff;
    newnode->power = power;
    newnode->next = NULL;

    if ((*first) == NULL || power > (*first)->power)
    {
        newnode->next = *first;
        *first = newnode;
    }
    else
    {
        polynomial *temp;
        temp = *first;
        while (temp->next != NULL && temp->next->power > power)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

polynomial *create()
{
    int n, power;
    float coeff;
    polynomial *first = NULL;
    printf("Enter the polynomial eqn:\n");
    printf("Enter the no of terms:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coeffient for term %d:", i + 1);
        scanf("%f", &coeff);

        printf("Enter the power for term %d:", i + 1);
        scanf("%d", &power);

        insert(&first, power, coeff);
    }
    return first;
}

void print(polynomial *first)
{
    if (first == NULL)
        printf("NO polynomial\n");
    else
    {
        polynomial *temp = first;
        printf("The Polynomial is:\n");
        while (temp != NULL)
        {
            printf("(%.2f)x^%d", temp->coefficient, temp->power);
            temp = temp->next;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

void add(polynomial *p1, polynomial *p2)
{
    polynomial *temp1 = p1;
    polynomial *temp2 = p2;
    polynomial *result = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->power == temp2->power)
        {
            float coeff = temp1->coefficient + temp2->coefficient;
            int power = temp1->power;
            insert(&result,power,coeff);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power)
        {
            insert(&result, temp1->power,temp1->coefficient);
            temp1 = temp1->next;
        }
        else
        {
            insert(&result, temp2->power,temp2->coefficient);
            temp2 = temp2->next;
        }
    }
    //remaining
    while (temp1 != NULL)
    {
        insert(&result, temp1->coefficient, temp1->power);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        insert(&result, temp2->coefficient, temp2->power);
        temp2 = temp2->next;
    }
    printf("The result polynomial is :\n");
    print(result);
}

int main()
{
    polynomial *p1 = create();
    polynomial *p2 = create();
    print(p1);
    print(p2);
    add(p1,p2);

    return 0;
}