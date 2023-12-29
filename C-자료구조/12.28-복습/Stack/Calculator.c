#include "Calculator.h"

char Num[] = { '0','1','2','3','4','5','6','7','8','9','.'};

int IsNumber(char Token)
{
	for (int i = 0; i < sizeof(Num); i++)
	{
		if (Token == Num[i])
			return 1;
	}
	return 0;
}

int GetNextToken(char* Expression, char* Token, int* Type)
{
	int i = 0;
	while (*Expression != '\0')
	{
		Token[i++] = *Expression;
		if (IsNumber(*Expression))
		{
			*Type = OPERAND;
			if (IsNumber(*(Expression + 1)))
				Expression++;
			else
				break;
		}
		else
		{
			*Type = *Expression;
			break;
		}
	}
	Token[i] = '\0';
	return i;
}

int GetPriority(char Operator)
{
	int prior = -1;

	switch (Operator)
	{
	case LEFT:
		prior = 1;
		break;

	case RIGHT:
		prior = 4;
		break;

	case PLUS:
	case MINUS:
		prior = 2;
		break;

	case MULTIPLT:
	case DIVIDE:
		prior = 3;
	}
	return prior;
}

void GetPostfix(char* Infix, char* Postfix)
{
	LLS* Stack = NULL;
	LLS_CreateStack(&Stack);
	int type = -1;
	char Token[32];

	int tmp = 0;
	while (tmp < strlen(Infix))
	{
		tmp += GetNextToken(&Infix[tmp],Token,&type);

		if (type == OPERAND)
		{
			strcat_s(Postfix, sizeof(char) * 100, Token);
			strcat_s(Postfix, sizeof(char) * 100, " ");
		}
		else
		{
			if (LLS_GetSize(&Stack) == 0)
			{
				LLS_PushStack(&Stack,LLS_CreateNode(Token));
			}
			else if (type == RIGHT)
			{
				while (LLS_GetSize(&Stack) != 0)
				{
					char* Operator = LLS_PopStack(&Stack);
					if (*Operator != LEFT)
					{
						strcat_s(Postfix, sizeof(char) * 100, Operator);
						strcat_s(Postfix, sizeof(char) * 100, " ");
					}
					else
						break;
				}
			}
			else
			{
				int Token_Priority = GetPriority(Token[0]);
				while (GetPriority(LLS_GetTop(&Stack)[0]) >= Token_Priority)
				{
					if (GetPriority(LLS_GetTop(&Stack)[0]) == 1)
						break;

					char* Operator = LLS_PopStack(&Stack);
					strcat_s(Postfix, sizeof(char) * 100, Operator);
					strcat_s(Postfix, sizeof(char) * 100, " ");

					if (LLS_GetSize(&Stack) == 0)
						break;
				}
				LLS_PushStack(&Stack, LLS_CreateNode(Token));
			}

		}
	}

	while (LLS_GetSize(&Stack) != 0)
	{
		char* Operator = LLS_PopStack(&Stack);
		strcat_s(Postfix, sizeof(char) * 100, Operator);
		strcat_s(Postfix, sizeof(char) * 100, " ");
	}
}

double Calculate(char* Postfix)
{
	LLS* Stack = NULL;
	LLS_CreateStack(&Stack);

	int tmp = 0;
	char Token[32];
	int type = -1;
		
	while (tmp < strlen(Postfix))
	{
		tmp += GetNextToken(&Postfix[tmp], Token, &type);

		if (type == SPACE)
			continue;

		if (type == OPERAND)
		{
			LLS_PushStack(&Stack, LLS_CreateNode(Token));
		}
		else
		{
			double result;
			double a = atof(LLS_PopStack(&Stack));
			double b = atof(LLS_PopStack(&Stack));

			switch (type)
			{
			case PLUS: result = b + a; break;
			case MINUS: result = b - a; break;
			case MULTIPLT: result = b * a; break;
			case DIVIDE: result = b / a; break;
			}

			_gcvt(result, 10, Token);
			LLS_PushStack(&Stack, LLS_CreateNode(Token));
		}
	}
	double result = atof(LLS_PopStack(&Stack));

	free(Stack);

	return result;
}