#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main()
{
	int aLength = 0, cLength = 0;

	printf("문자열 배열 길이 입력: ");
	scanf_s("%d", &aLength);

	printf("최대 문자열 길이 입력: ");
	scanf_s("%d", &cLength);

	char** sListBuffer = (char**)malloc(sizeof(char*) * aLength);
	char* pszBuffer = (char*)malloc(sizeof(char) * cLength * aLength);

	memset(sListBuffer, 0,sizeof(sListBuffer));
	memset(pszBuffer, 0, sizeof(pszBuffer));

	for (int i = 0; i < aLength; i++)
	{
		scanf_s("%s", pszBuffer + cLength * i, cLength);
		sListBuffer[i] = pszBuffer + cLength * i;
	}

	for (int i = 0; i < aLength; i++)
	{
		puts(sListBuffer[i]);
	}

	free(sListBuffer);
	free(pszBuffer);
	
	
	return 0;
}