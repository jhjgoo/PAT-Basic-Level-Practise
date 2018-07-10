/***
1003. 我要通过！(20)

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
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
