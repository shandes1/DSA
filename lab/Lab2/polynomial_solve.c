#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynomial
{
    int power;
    float coefficient;
    struct polynomial *next;
}polynomial;

polynomial *first=NULL;

void insert(int power,float coeff)
{
    polynomial *newnode;
    newnode= (polynomial*)malloc(sizeof(polynomial));

    newnode->coefficient=coeff;
    newnode->power=power;
    newnode->next=NULL;

    if (first==NULL || power > first->power )
    {
        newnode->next=first;
        first=newnode;
    }      
    else
    {
        polynomial *temp;
        temp=first;
        while (temp->next!=NULL && temp->next->power>power)
        {
            temp = temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}



void create()
{
    int n,power;
    float coeff;
    printf("Enter the polynomial eqn:\n");
    printf("Enter the no of terms:");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the coeffient for term %d:",i+1);
        scanf("%f", &coeff);
        
        printf("Enter the power for term %d:",i+1);
        scanf("%d", &power);
       
        insert(power,coeff);
    }

}

void print()
{
    if (first==NULL)
        printf("NO polynomial\n");
    else
    {
        polynomial*temp=first;
        while(temp!=NULL)
        {
            printf("The Polynomial is:\n");
            printf("(%.2f)x^%d",temp->coefficient,temp->power);
            temp=temp->next;
            if (temp!=NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

void solve()
{
    int n;
    printf("Please enter the value of x:");
    scanf("%d",&n);

    polynomial *temp=first;
    float coeff, sum=0;
    int power;
    while(temp!=NULL)
    {
        coeff=temp->coefficient;
        power=temp->power;
        sum += coeff*pow(n,power);
        temp=temp->next;
    }
    printf("The value of the polynomial is %f",sum);
}



int main()
{
    create();
    print();
    solve();
    return 0;
}