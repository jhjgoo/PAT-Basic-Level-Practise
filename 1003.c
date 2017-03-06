/***
1003. ��Ҫͨ����(20)

������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�
1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
YES
YES
YES
YES
NO
NO
NO
NO
***/
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,n;
    int p_flag,t_flag;
    int head_a,middle_a,end_a;
    char pat[100];
    scanf("%d\n",&n);
    for(j=0; j < n; j ++)
    {
        p_flag = 0,t_flag = 0;
        head_a = 0,middle_a = 0,end_a = 0;
        gets(pat);
        for(i=0;i < strlen(pat); i ++)
        {
            if(!p_flag && pat[i] == 'P')
                p_flag = 1;
            else if(p_flag && pat[i] == 'P')
            {
                printf("NO\n");
                break;
            }
            else if(!t_flag && pat[i] == 'T')
                t_flag = 1;
            else if(t_flag && pat[i] == 'T')
            {
                printf("NO\n");
                break;
            }
            else if(!p_flag && !t_flag && pat[i] == 'A')
                head_a ++;
            else if(p_flag && !t_flag && pat[i] == 'A')
                middle_a ++;
            else if(p_flag && t_flag && pat[i] == 'A')
                end_a ++;
            else
            {
                printf("NO\n");
                break;
            }
        }
        if(i == strlen(pat))
        {
            if( p_flag && t_flag && middle_a && end_a == middle_a * head_a )
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
}
