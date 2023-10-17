//문자열을 뒤집는 함수 만들기.

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

	printf("뒤집을 문자: ");
	scanf_s("%s", pszData,12);

	printf("결과: %s\n", MyStrrev(pszData));


	
	return 0;
}