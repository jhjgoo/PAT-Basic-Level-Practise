/***
1009. 说反话 (20)

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
***/

#include <stdio.h>

int main()
{
    char str_input[81];
    char str_output[40][81];
    gets(str_input);
    int i = 0;
    int j = 0;
    int k = 0;
    while(str_input[i] != '\0')
    {
        if(str_input[i] != ' ')
        {
            str_output[j][k] = str_input[i];
            k ++;
        }
        else
        {
            str_output[j][k] = '\0';
            k = 0;
            j ++;
        }
        i ++;
    }
    str_output[j][k] = '\0';
    for(i = j; i > 0; i --){
        printf("%s ",str_output[i]);
    }
    printf("%s\n",str_output[0]);

}

/***
网上大神的解法：
#include <stdio.h>
#include <string.h>
void output(char *str)
{
  char* tail = strchr(str,' ');
  if (tail == NULL)
    printf("%s",str);
  else
    {
      output(tail + 1);
      *tail = '\0';
      printf(" %s",str);
    }
}
int main()
{
  char str[81];
  gets(str);
  output(str);
  putchar('\n');
  return 0;
}
***/
