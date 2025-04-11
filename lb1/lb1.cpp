#include <stdio.h>
#include <string.h>
// определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]);
using namespace std;
int main(void)
{
	char line[MAXLINE];
	gets_s(line);
	process_line(line);
	printf("\nresult: ");
	puts(line);
	return 0;
}
void process_line(char buffer[])
{
	int prev_c2[] = { 29,109,91,123,21,101,96,128,82,114,19,99,17,97,88,120,18,98 };
	char c; // текущий символ
	int flag = 1; // признак слова
	char* in_ptr; // указатель на текущий символ
	// входной строки
	char* out_ptr; // указатель на текущий символ
	// выходной строки
	int i = 0, i2 = 0;
	in_ptr = buffer;
	out_ptr = buffer;

	do
	{
		c = *in_ptr; // взять текущий символ из буфера
		//ищет гласную букву в начале слова
		for (i = 0;i < 18;i++)
			if ((int)c * -1 == (prev_c2[i]) && flag == 1)//проверка на гласную в начале слова
			{
				flag = 2;
				goto copy;
				break;
			}

		i2 = 0;
		for (i = 0;i < 18;i++)
			if ((int)c != prev_c2[i] * -1 && flag == 1)//проверка что в начале слова не гласная
				i2++;
		if (i2 == 18)
			flag = 0;

		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' && flag == 0)
			flag = 1;
		else
			goto contin;
		//ищет гласную букву в начале слова//

	copy:
		if (flag == 2)
			while (c != ' ') {
				in_ptr++;
				c = *in_ptr;
				if (c == '\n' || c == '\0' || c == ' ' || c == '.' || c == ',' || c == '!' || c == '?') //выход в конце строки
				{
					flag = 1;
					break;
				}
			}

	contin:
		*out_ptr++ = *in_ptr++;
	} while (c != '\0');
}
