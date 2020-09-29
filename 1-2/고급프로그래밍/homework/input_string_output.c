#include <stdio.h>

int main()
{
	char str[100];
	int len = 0;
	char *p;

	printf("문자열을 입력하시오:");
	gets(str);
	p = str;

	for (int i = 0; *(p + i); i++) {
		len++;
	}

	printf("입력한 문자열의 길이 : %d\n", len);
}