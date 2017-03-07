#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    char c;
    int count = 10;
    int *input = (int*)malloc(10*sizeof(int));
    int n;

    while(scanf("%d",&n))
    {
        input[i] = n;
        i ++;
        if((c = getchar()) == '\n')
            break;
        if(i >= count)
        {
            input = (int *)realloc(input,(i+10)*sizeof(int));
            count += 10;
        }
    }
    count = i;
    for(i = 0; i < count; i += 2)
    {
        if(input[i+1] == 0)
            count -= 2;
        else
        {
            input[i] = input[i] * input[i+1];
            input[i+1] -= 1;
        }

    }
    if(count > 0)
    {
        for(i = 0; i < count - 1; i ++)
        {
            printf("%d ",input[i]);
        }
        printf("%d",input[i]);
    }
    else
    {
        printf("0 0");
    }

}
