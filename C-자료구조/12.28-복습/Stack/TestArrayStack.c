#include "ArrayStack.h"


int main()
{
	ArrayStack* Stack = NULL;
	AS_CreateStack(&Stack, 10);
	AS_Push(&Stack, 1);
	AS_Push(&Stack, 2);
	AS_Push(&Stack, 3);
	AS_Push(&Stack, 4);

	printf("���� ���� Stack�� ũ��: %d\n", AS_GetSize(&Stack));

	printf("POP: %d\n", AS_Pop(&Stack));
	printf("POP: %d\n", AS_Pop(&Stack));
	printf("POP: %d\n", AS_Pop(&Stack));

	printf("���� ���� Stack�� ũ��: %d\n", AS_GetSize(&Stack));
	
	
	
	
	return 0;
}