#include "ExpressionTree.h"


int main()
{
	char Postfix[100] = { 0 };
	
	scanf_s("%[^\n]s", Postfix, sizeof(Postfix));


	Node* Root;
	BT_MakeExpressionTree(Postfix, &Root);

	BT_Inorder(Root);
	 
	printf("\n��� ���: %.2f\n", ET_Evaluate(Root));
	
	//�����̽��ٷ� �з��� postfix ���� �޾���
	//�̴� ���ڸ� ���ڵ� ���� �Էµǰ��ϱ� ����
	// 
	//���ڿ��� �Ųٷ� �����鼭 ���� ���� ������ŭ ���� ��ȯ��Ű��
	//���� �κ��� �ٽ� ���������ʱ����� ���� �κ� �տ� ���� '\0'ó��
	//�̴� ����Լ��� ����ϴµ� �־ ������ �� ����
	// 
	//�����̽��ٷ� ���� ���ϴ� �κ��� GetNextToken�Լ��� ȣ���ų������ ���ڿ� ���̸� �޾�
	//0���� ������ ���̻� ���� ���ϰ� ����

	// &(*Node)->right ��� �� ��� ����
	return 0;
}