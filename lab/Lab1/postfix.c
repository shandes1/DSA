#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX  100

typedef struct Stack
{
    int tos;
    float data[MAX];
}stack;

void push(stack *s, float element)
{
    if (s->tos==MAX-1)
    { 
        printf("Stack Overflow\n");
        exit(1);
    }
        s->data[++s->tos]=element;
    
}

 float pop(stack *s)
{
    if (s->tos == -1)
       { 
        printf("Stack empty\n");
        exit(1);
       }
        return s->data[s->tos--];
       
}


int main()
{
    stack s={-1};
    char element[MAX];
    float op1,op2,result;

    printf("Enter the postfix expression:");
      fgets(element, sizeof(element), stdin);
    

    char *item= strtok(element, " ");

    while( item!= NULL)
    {
        if(isdigit(item[0]) || item[0]=='-' && isdigit(item[1]))
        {
            push(&s,atof(item));
        }
        else
        {
            op1=pop(&s);
            op2=pop(&s);

            if (item[0]== '+')
                 result = op2 +op1;
            else
            if (item[0]== '-')
                result = op2 - op1;
            else
            if (item[0]=='*')
                result = op2 *op1;
            else
            if (item[0]=='/')
                result = op2 /op1;
            else
            if ( item[0] =='^')
            result = pow(op2,op1);
            else
            { 
             printf("INVALID ");
             return 1;
            }

            push(&s, result);
        }
       item = strtok(NULL," ");
    }
    if(s.tos==0)
    printf("The result is %f",result);
    else
    printf("Invalid postfix expression.");
    return 0;  
}