#include<stdio.h>

int main()
{
	int num = 55; //������ ������ ���� num�� 55�� ����
	int user_num = 0; //������ ���ߴ� ����ڿ��� �Է¹ޱ����� ���� user_num
	int count = 0; //����Ƚ���� �������� ���� count �ʱ�ȭ

	printf("�ϳ��� ���� �Է��Ͻÿ�:");

	while (num != user_num) //����� �ٸ� ���� �Է¹޾��� �� �ݺ�
	{
		scanf_s("%d", &user_num); //������ ���߱� ���� ���� �Է�
		if (user_num < num) //���亸�� �Է¹��� ���� ������
			printf("�� ū ���� �Է��Ͻÿ�:");
		else if (user_num > num) //���亸�� �Է¹��� ���� ũ��
			printf("�� ���� ���� �Է��Ͻÿ�:");
		count++; //����Ƚ�� 1ȸ�� �ø���
	}
	printf("�½��ϴ�. ����Ƚ���� %d�� �Դϴ�.", count); //����� ����Ƚ�� ���


	return 0;
}