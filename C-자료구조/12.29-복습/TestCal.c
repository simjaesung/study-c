#include "Calculator.h"

int main()
{
	char Infix[100] = { 0 };
	char Postfix[100] = { 0 };

	scanf_s("%s", Infix, sizeof(Infix));

	printf("Infix: %s\n", Infix);

	InfixToPostfix(Infix, Postfix);

	printf("Postfix: %s\n", Postfix);

	printf("계산결과: %.2f\n", Calculator(Postfix));
}