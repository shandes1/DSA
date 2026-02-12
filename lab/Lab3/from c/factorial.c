#include <stdio.h>
#include <time.h>

int Fact(int n)
{
    if(n == 1)
        return 1;
    else
        return n*Fact(n-1);
}

int TailFact(int n,int  a)
{
    if (n==1)
        return a;
    else
        return TailFact(n-1,a*n);
}


int main()
{
    int fact, tail;
    time_t start1,start2 ,end1,end2;

    double diff1,diff2;
    start1=time(NULL);
    fact=Fact(4);
    end1=time(NULL);

    diff1= difftime(end1,start1);

    start2=time(NULL);
    tail= TailFact(4,1);
    end2=time(NULL);

    diff2= difftime(end2,start2);

    printf("%d is the ans of factorial\n %d is the ans by tail factorial",fact,tail);
    printf("\nNormal factorial take %lf and Tail Factorial take %lf",diff1,diff2);
    return 0;
}