#include <stdio.h>

int main()
{
	char str[100];
	int len = 0;
	char *p;

	printf("���ڿ��� �Է��Ͻÿ�:");
	gets(str);
	p = str;

	for (int i = 0; *(p + i); i++) {
		len++;
	}

	printf("�Է��� ���ڿ��� ���� : %d\n", len);
}