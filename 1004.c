/***
1004. �ɼ����� (20)

����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��ÿ�������������1��������������ʽΪ

  ��1�У�������n
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ�������� ѧ�� �ɼ�
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112
***/
#include <stdio.h>
#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b

struct student{
    char* name[10];
    char* id[10];
    unsigned int score;
}class[100];

int main()
{
    int i,n,max,min;
    scanf("%d",&n);
    max = 0, min = 0;
    for(i = 0; i < n; i ++)
    {
        scanf("%s %s %d",&class[i].name,&class[i].id,&class[i].score);
    }
    for(i = 1; i < n; i ++)
    {
        if(class[max].score < class[i].score)
            max = i;
        else if(class[min].score > class[i].score)
            min = i;
    }
    printf("%s %s\n",class[max].name,class[max].id);
    printf("%s %s\n",class[min].name,class[min].id);
}
