#include <stdio.h>
#include <time.h>

void TOH(int n,char  src,char dsc,char tem)
{
    if (n==1)
        printf("Move disk %d from %c to %c\n",n,src,dsc);
    else
    {
        TOH(n-1,src,tem,dsc);
        printf("Move disk %d from %c to %c\n",n,src,dsc);

        TOH(n-1,tem, dsc,src);
    }
}


int main()
{
    int value;
    time_t start,end;
    double diff;
    printf("Enter the value:");
    scanf("%d",&value);

    start= time(NULL);
    TOH(value,'A','B','C');
    end= time(NULL);
    diff= difftime(end,start);
    printf("The time taken is %lf second",diff);
    
    return 0;
}