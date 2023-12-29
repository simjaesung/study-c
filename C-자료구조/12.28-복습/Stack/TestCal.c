#include "Calculator.h"


int main()
{
	char Infix[100] = { 0 };
	char Postfix[100] = { 0 };

	scanf_s("%s",Infix,sizeof(Infix));
	

	GetPostfix(Infix, Postfix);
	printf("%s\n", Postfix);

	puts("계산결과");
	printf("%f\n", Calculate(Postfix));

}