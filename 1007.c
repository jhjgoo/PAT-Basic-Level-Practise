/***
1007. �����Բ��� (20)

�����Ƕ��� dn Ϊ��dn = pn+1 - pn������ pi �ǵ�i����������Ȼ�� d1=1 �Ҷ���n>1�� dn ��ż�����������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

�ָ�������������N (< 105)������㲻����N���������������Եĸ�����

�����ʽ��ÿ�������������1����������������������N��

�����ʽ��ÿ���������������ռһ�У�������N���������������Եĸ�����

����������
20
���������
4
***/

#include <stdio.h>
#include <math.h>

int isprime(int n)
{
    int i;
    if(n == 2)
        return 1;
    for(i = 2; i <= sqrt(n); i ++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int i,n;
    int index = 0;
    scanf("%d",&n);
    for(i = 2; i <= n; i ++)
    {
        if(isprime(i) && i+2 <= n && isprime(i+2))
            index ++;

    }
    printf("%d",index);

    return 0;
}
