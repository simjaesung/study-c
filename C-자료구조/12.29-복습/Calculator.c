#include "Calculator.h"

char Num[] = { '0','1','2','3','4','5','6','7','8','9','.' };



int IsNum(char token)
{
	for (int i = 0; i < sizeof(Num); i++)
	{
		if (Num[i] == token)
			return 1;
	}

	return 0;
}

int GetPirioirty(char token)
{
	int priority = -1;

	switch (token)
	{
	case LEFT:
		priority = 1;
		break;

	case PLUS:
	case MINUS:
		priority = 2;
		break;

	case MULTIPLT:
	case DIVIDE:
		priority = 3;
		break;

	case RIGHT:
		priority = 4;
		break;
	}

	return priority;
}


int GetNextToken(char* Infix, char* Token, int* Type)
{
	int i = 0;
	while (*Infix != '\0')
	{
		Token[i++] = *Infix;

		if (IsNum(*Infix))
		{
			*Type = OPERAND;
			if (IsNum(*(Infix + 1)))
			{
				Infix++;
				continue;
			}
			else
				break;
		}
		else
		{
			*Type = *Infix;
			break;
		}
	}
	Token[i] = '\0';
	return i;
}

void InfixToPostfix(char* Infix, char* Postfix)
{
	LLS* Stack = NULL;
	LLS_CreateStack(&Stack);

	char Token[32];
	int Type = -1;
	int Tmp = 0;


	while (Tmp < strlen(Infix))
	{
		Tmp += GetNextToken(&Infix[Tmp], Token, &Type);

		if (Type == OPERAND)
		{
			strcat_s(Postfix, sizeof(char) * 100, Token);
			strcat_s(Postfix, sizeof(char) * 100, " ");
		}
		else
		{
			if (LLS_GetSize(&Stack) == 0)
				LLS_PushStack(&Stack, LLS_CreateNode(Token));

			else if (Type == RIGHT)
			{
				while (LLS_GetSize(&Stack) != 0)
				{
					if (LLS_GetTop(&Stack)[0] != LEFT)
					{
						strcat_s(Postfix, sizeof(char) * 100, LLS_PopStack(&Stack));
						strcat_s(Postfix, sizeof(char) * 100, " ");
					}
					else
					{
						LLS_PopStack(&Stack);
						break;
					}
				}
			}
			else
			{ 
				int TokenPriority = GetPirioirty(Token[0]);

				while (TokenPriority <= GetPirioirty(LLS_GetTop(&Stack)[0]))
				{
					strcat_s(Postfix, sizeof(char) * 100, LLS_PopStack(&Stack));
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
		strcat_s(Postfix, sizeof(char) * 100, LLS_PopStack(&Stack));
		strcat_s(Postfix, sizeof(char) * 100, " ");
	}
}


double Calculator(char* Postfix)
{
	LLS* Stack = NULL;
	LLS_CreateStack(&Stack);

	char Token[32];
	int Type = -1;
	int Tmp = 0;

	while (Tmp < strlen(Postfix))
	{
		Tmp += GetNextToken(&Postfix[Tmp], Token, &Type);

		if (Type == SPACE)
			continue;

		if (Type == OPERAND)
			LLS_PushStack(&Stack, LLS_CreateNode(Token));
		else
		{
			double result;
			double a = atof(LLS_PopStack(&Stack));
			double b = atof(LLS_PopStack(&Stack));

			switch (Type)
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