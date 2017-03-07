/***
1005. 继续(3n+1)猜想 (25)

卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

输入样例：
6
3 5 6 7 8 11
输出样例：
7 6
***/

#include <stdio.h>

int covered[100] = {0};
int flag[100] = {0};
int input[100] = {0};
int insert_flag = 0;

void sort(int* a, int left, int right)
{
    if(left >= right)
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];

    while(i < j)
    {
        while(i < j && key >= a[j])
        {
            j--;
        }
        a[i] = a[j];

        while(i < j && key <= a[i])
        {
            i++;
        }

        a[j] = a[i];
    }

    a[i] = key;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}

int inarray(int *a, int n)
{
    int i = 0;
    while(a[i] > 0)
    {
        if(n == a[i])
            return ++i;
         i ++;
    }
    return 0;
}

int callatz(int n)
{
    while( n != 1 && !inarray( covered, n))
    {
        covered[insert_flag] = n;
        insert_flag ++;
        if(n % 2 == 0)
            n /= 2;
        else
            n = (3 * n + 1) / 2;
    }
    int index = inarray( input, n);
    if(index != 0)
    {
        flag[index-1] = 2;
    }
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", input+i);
    }
    sort(input,0,n-1);
    for(i = 0; i < n; i ++)
    {
        if(flag[i] == 2)
        {
            continue;
        }
        else
        {
            flag[i] = 1;
            callatz(input[i]);
        }
    }
    for(i=0;i < n; i ++)
    {
        if(flag[i] == 1)
        {
            printf("%d",input[i]);
            i ++;
            break;
        }
    }
    while( i < n)
    {
        if(flag[i] == 1)
            printf(" %d",input[i]);
        i ++;
    }
}



