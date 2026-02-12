#include <stdio.h>

long int table[100] = {0};

long int FiboM(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        if (table[n] == 0)
        {
            table[n] = FiboM(n - 1) + FiboM(n - 2);
        }
        return table[n];
    }
}

int main()
{
    int value, fibo;
    printf("Enter the value:");
    scanf("%d",&value);
    fibo=FiboM(value);
    printf("%d is the ans",fibo);
    return 0;
}
