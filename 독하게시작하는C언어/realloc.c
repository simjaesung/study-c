#include<stdio.h>
#include <string.h>
#include<malloc.h>

//���� �Ҵ���� �޸��� ũ�⸦ �ø��� ���

//1try
//int main()
//{
//	int size = 2;
//
//	char* pszData = (char*)malloc(sizeof(char)*20);
//	printf("ó�� ���� �޸�: %d\n", _msize(pszData));
//
//	scanf_s("%s", pszData, _msize(pszData));
//	int nlength = strlen(pszData);
//
//	while (1)
//	{
//		puts(pszData);
//
//		char NewpszData[10];
//		scanf_s("%s", NewpszData,10);
//
//
//		if (strcmp("quit", NewpszData) == 0)
//		{
//			free(pszData);
//			break;
//		}
//			
//
//		nlength += strlen(NewpszData);
//		printf("�� ����: %d\n", nlength);
//
//		if (nlength+1 >= _msize(pszData))
//		{
//			printf("�޸� ũ�� ���� �Ϸ�\n");
//			pszData = realloc(pszData, _msize(pszData) * size);
//
//			if (pszData == NULL)
//			{
//				printf("�޸� ũ�� ���� ����");
//				break;
//				//���Ҵ� �� ��� �ڷ� �ʿ�
//			}
//
//			size++;
//		}
//
//		//strcat_s(pszData, _msize(pszData), NewpszData);
//		strncat_s(pszData, _msize(pszData), NewpszData,strlen(NewpszData)+1);
//	}
//
//	return 0;
//}


//2 �ٽ� �ۼ��غ� �Լ�


int main()
{
	int init_size = 20, up_size = 1;

	char* pszBuffer = (char*)malloc(init_size * up_size);

	puts("����: quit");

	scanf_s("%s", pszBuffer, 20);
	int nLength = strlen(pszBuffer);


	while (1)
	{
		puts(pszBuffer);
		char pszNewBuffer[20];
		scanf_s("%s", pszNewBuffer, 20);

		if (strcmp("quit", pszNewBuffer) == 0)
			{
				free(pszBuffer);
				break;
			}

		nLength += strlen(pszNewBuffer);

		if (nLength + 1 >= init_size)
		{
			up_size++;
			pszBuffer = realloc(pszBuffer, init_size * up_size);
			puts("�޸� size Ȯ�� �Ϸ�");
			printf("����: %d / Ȯ�� �� : %d\n", init_size, init_size * up_size);
			init_size *= up_size;
		}

		strncat_s(pszBuffer, _msize(pszBuffer), pszNewBuffer, strlen(pszNewBuffer) + 1);
		//strncat_s(pszBuffer, sizeof(pszBuffer), pszNewBuffer, strlen(pszNewBuffer) + 1);
	}
	
	
	
	return 0;
}