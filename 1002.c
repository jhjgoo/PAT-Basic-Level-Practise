/***
1002. 写出这个数 (20)

读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
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
    return 0;
}

