#include "ArrayStack.h"


int main()
{
	ArrayStack* stack = NULL;
	AS_CreateStack(&stack,10);

	puts("1~10 push");
	AS_PushStack(stack, 1);
	AS_PushStack(stack, 2);
	AS_PushStack(stack, 3);
	AS_PushStack(stack, 4);
	AS_PushStack(stack, 5);
	AS_PushStack(stack, 6);
	AS_PushStack(stack, 7);
	AS_PushStack(stack, 8);
	AS_PushStack(stack, 9);
	AS_PushStack(stack, 10);

	printf("남은 Size: %d\n", AS_GetSize(stack));
	printf("Top: %d\n", AS_GetTop(stack));

	puts("\n4개 pop");
	printf("POP: %d\n",AS_PopStack(stack));
	printf("POP: %d\n", AS_PopStack(stack));
	printf("POP: %d\n", AS_PopStack(stack));
	printf("POP: %d\n", AS_PopStack(stack));

	printf("남은 Size: %d\n", AS_GetSize(stack));
	printf("Top: %d\n", AS_GetTop(stack));

	return 0;
}