#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main()
{
	int BufferSize, StrSize;

	printf("������ char* ����:");
	scanf_s("%d", &BufferSize);

	printf("�ִ� ���ڿ� ����:");
	scanf_s("%d", &StrSize);
	char** strBuffer = (char**)malloc(sizeof(char*) * BufferSize);
	memset(strBuffer, 0, _msize(strBuffer));

	for (int i = 0; i < BufferSize; i++)
	{
		char* charBuffer = (char*)malloc(sizeof(char) * StrSize);
		memset(charBuffer, 0, _msize(charBuffer));
		//gets_s(charBuffer, _msize(charBuffer));
		scanf_s("%s", charBuffer);

		strBuffer[i] = charBuffer;
	}

	for (int i = 0; i < BufferSize; i++)
	{
		puts(strBuffer[i]);
		free(strBuffer[i]);
	}

	free(strBuffer);

	return 0;
}