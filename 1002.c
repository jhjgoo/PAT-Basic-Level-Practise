/***
1002. д������� (20)

����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10100��

�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������
1234567890987654321123456789
���������
yi san wu
***/

#include <stdio.h>
#include <math.h>

const char* pinyin[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{
    int i,sum,digit;
    char x;
    sum = 0;
    for(i=1;i <= 100; i++)
    {
        scanf("%c",&x);
        if(x-'0'>= 0 && x-'0' <= 9)
        {
            sum += x-'0';
        }
        else
        {
            break;
        }
    }
    digit = 1;
    while(sum / pow(10,digit) > 1)
        digit ++;
    for(i = digit-1; i > 0; i --)
    {
        printf("%s ",pinyin[(int)(sum/pow(10,i))]);
        sum %= (int)pow(10,i);
    }
    printf("%s",pinyin[sum]);

}

