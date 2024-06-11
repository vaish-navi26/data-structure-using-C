#include<stdio.h>
#include<stdlib.h>

char stack[100];
int top= -1;

void main()
{
    int len,i,j=0,count=0;

    printf("Enter the string :");
    
    if (top == 100-1)
    {
        printf("stack overflow\n\n");
    }
    else
    {
        ++top;
        gets(stack);

        for(i=top;stack[i]!='\0';i++)
        {
            ++top;
        }
    }

    j = top-1;
    len = top;

    for(i=0;i<top;i++)
    {
        if (stack[i] == stack[j])
        {
            count++;
            j--;
        }
    }

    if (count == len)
    {
        printf("Palindrome\n\n");
    }
    else
    {
        printf("Not Palindrome\n\n");
    }


}