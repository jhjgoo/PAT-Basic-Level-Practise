/***
1009. ˵���� (20)

����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������

�����ʽ�������������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�

�����ʽ��ÿ���������������ռһ�У���������ľ��ӡ�

����������
Hello World Here I Come
���������
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
���ϴ���Ľⷨ��
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
