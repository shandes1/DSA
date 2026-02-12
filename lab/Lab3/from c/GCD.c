#include <stdio.h>

int GCD(int a,int b)
{
    if (b==0)
        return a;
    else
        return GCD(b,a%b);
}


int main()
{
    int a,b,result;
    printf("Enter the value of a and b:");
    scanf("%d%d",&a,&b);

    result= GCD(a,b);
    printf("The result is %d",result);
    return 0;
}