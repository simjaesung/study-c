#include "ExpressionTree.h"

char Num[] = { '0','1','2','3','4','5','6','7','8','9','.' };

int IsNumber(char Token)
{
	for (int i = 0; i < sizeof(Num); i++)
	{
		if (Token == Num[i])
			return 1;
	}
	return 0;
}


Node* BT_CreateNode(char* Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc((sizeof(char) * strlen(Data)) + 1);
	memset(NewNode->Data, 0, _msize(NewNode->Data));
	strcpy_s(NewNode->Data, _msize(NewNode->Data), Data);

	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

int GetNextToken(char* Postfix, char* Token, int* Type, int len)
{
	int i = 0;
	while (*Postfix != SPACE && len > 0)
	{
		Token[i++] = *Postfix;
		
		if (IsNumber(*Postfix))
		{
			*Type = OPERAND;
			*Postfix--;
			len--;
		}
		else
		{
			*Type = *Postfix;
			break;
		}
	}
	Token[i] = '\0';

	//거꾸로 읽었기에 뒤집어줬음
	for (int i = 0; i < strlen(Token) / 2; i++)
	{
		char s = Token[i];
		Token[i] = Token[strlen(Token) - 1 - i];
		Token[strlen(Token) - 1 - i] = s;
	}

	return i;
}

void BT_MakeExpressionTree(char* Postfix, Node** Node)
{
	char Token[32];
	int type = -1;

	int len = strlen(Postfix);
	len -= GetNextToken(&Postfix[len - 1], Token, &type, len);
	
	if (len > 0)
		Postfix[len - 1] = '\0';

	if (type == OPERAND)
	{
		*Node = BT_CreateNode(Token);
		return NULL; 
	}
	else
	{
		*Node = BT_CreateNode(Token);
		BT_MakeExpressionTree(Postfix, &(*Node)->right);
		BT_MakeExpressionTree(Postfix, &(*Node)->left);
	}
}

double ET_Evaluate(Node* ExTreeRoot)
{
	char* Token = ExTreeRoot->Data;
	double left, right;

	switch (*Token)
	{
	case '+':
		left = ET_Evaluate(ExTreeRoot->left);
		right = ET_Evaluate(ExTreeRoot->right);
		return left + right;

	case '-':
		left = ET_Evaluate(ExTreeRoot->left);
		right = ET_Evaluate(ExTreeRoot->right);
		return left - right;

	case '*':
		right = ET_Evaluate(ExTreeRoot->right);
		left = ET_Evaluate(ExTreeRoot->left);
		return left * right;

	case '/':
		right = ET_Evaluate(ExTreeRoot->right);
		left = ET_Evaluate(ExTreeRoot->left);
		return left / right;

	default:
		return atof(Token);
	}

}

void BT_Preorder(Node* Root)
{
	if (Root == NULL)
		return;

	printf("%s\n", Root->Data);
	BT_Preorder(Root->left);
	BT_Preorder(Root->right);

}

void BT_Inorder(Node* Root)
{
	if (Root == NULL)
		return;

	BT_Inorder(Root->left);
	printf("%s ", Root->Data);
	BT_Inorder(Root->right);
}

void BT_Postorder(Node* Root)
{

	if (Root == NULL)
		return;

	BT_Postorder(Root->left);
	BT_Postorder(Root->right);
	printf("%s\n", Root->Data);

}