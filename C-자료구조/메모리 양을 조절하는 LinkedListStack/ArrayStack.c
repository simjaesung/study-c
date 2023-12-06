#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** stack, int size)
{
	*stack = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*stack)->Top = -1;
	(*stack)->Capacity = size;
	(*stack)->Nodes = (Node*)malloc(sizeof(Node) * size);
}

int PercentSize(int a, int b)
{
	float remain;

	float A = (float)a;
	float B = (float)b;

	remain = A / B * 100;
	return (int)remain;
}

void AS_PushStack(ArrayStack* stack, int Data)
{
	//stack->Top++;
	int Position = ++stack->Top;

	if (PercentSize(Position + 1, stack->Capacity) == 100) //스택의 사용 용량이 없을 시
	{
		stack->Capacity = (int)(stack->Capacity * 1.3); // 용량을 1.3배 증가하고 realloc을 통한 메모리 재할당
		stack->Nodes = (Node*)realloc(stack->Nodes,sizeof(Node) * stack->Capacity);
	}

	stack->Nodes[Position].Data = Data;
}

int AS_PopStack(ArrayStack* stack)
{
	int Position = stack->Top--;

	if (PercentSize(Position, stack->Capacity) < 50) //스택의 사용 용량이 절반 이상일 시 
	{
		stack->Capacity = (int)(stack->Capacity * 0.8); // 용량을 0.8배 감소시키고 realloc을 통한 메모리 재할당
		stack->Nodes = (Node*)realloc(stack->Nodes, sizeof(Node) * stack->Capacity);
	}
	return stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* stack)
{
	return stack->Capacity - 1 - stack->Top;
}

int AS_GetTop(ArrayStack* stack)
{
	int Position = stack->Top;
	return stack->Nodes[Position].Data;
}