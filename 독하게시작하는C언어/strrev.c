//���ڿ��� ������ �Լ� �����.

#include<stdio.h>
#include<string.h>

char* MyStrrev(char* pszData)
{
	int len = strlen(pszData);

	for (int i = 0; i < len / 2; i++)
	{
		char tmp = pszData[i];
		pszData[i] = pszData[len - 1-i];
		pszData[len -1-i] = tmp;
	}

	return pszData;
}



int main2()
{
	char pszData[12] = {0};

	printf("������ ����: ");
	scanf_s("%s", pszData,12);

	printf("���: %s\n", MyStrrev(pszData));


	
	return 0;
}