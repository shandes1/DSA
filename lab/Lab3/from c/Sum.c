#include <stdio.h>

int sum(int n)
{
    if (n==1)
        return 1;
    else
        return n + sum(n-1);
}

int TailSum(int n,int a)
{
    if (n==1)
        return a;
    else
        return TailSum(n-1,n+a);
}

int main()
{
    int value, s , tail;
    printf("Enter the value:");
    scanf("%d",&value);
    s= sum(value);
    tail= TailSum(value,1);
    printf("%d is the ans of sum \n %d is the ans of Tail Sum",s,tail);
    return 0;
}
