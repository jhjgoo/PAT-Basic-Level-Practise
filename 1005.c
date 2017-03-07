/***
1005. ����(3n+1)���� (25)

������(Callatz)�����Ѿ���1001�и������������������Ŀ������΢��Щ���ӡ�

��������֤�����Ȳ����ʱ��Ϊ�˱����ظ����㣬���Լ�¼�µ��ƹ�����������ÿһ�����������n=3������֤��ʱ��������Ҫ����3��5��8��4��2��1�������Ƕ�n=5��8��4��2������֤��ʱ�򣬾Ϳ���ֱ���ж������Ȳ������α��������Ҫ�ظ����㣬��Ϊ��4�����Ѿ�����֤3��ʱ���������ˣ����ǳ�5��8��4��2�Ǳ�3�����ǡ����������ǳ�һ�������е�ĳ����nΪ���ؼ����������n���ܱ������е��������������ǡ�
���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡������������ҳ���Щ�ؼ����֣������Ӵ�С��˳��������ǡ�

�����ʽ��ÿ�������������1��������������1�и���һ��������K(<100)����2�и���K��������ͬ�Ĵ���֤��������n(1<n<=100)��ֵ�����ּ��ÿո������

�����ʽ��ÿ���������������ռһ�У����Ӵ�С��˳������ؼ����֡����ּ���1���ո��������һ�������һ�����ֺ�û�пո�

����������
6
3 5 6 7 8 11
���������
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



