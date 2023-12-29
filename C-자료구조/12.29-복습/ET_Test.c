#include "ExpressionTree.h"


int main()
{
	char Postfix[100] = { 0 };
	
	scanf_s("%[^\n]s", Postfix, sizeof(Postfix));


	Node* Root;
	BT_MakeExpressionTree(Postfix, &Root);

	BT_Inorder(Root);
	 
	printf("\n계산 결과: %.2f\n", ET_Evaluate(Root));
	
	//스페이스바로 분류된 postfix 식을 받았음
	//이는 두자리 숫자도 같이 입력되게하기 위함
	// 
	//문자열을 거꾸로 읽으면서 읽은 문자 개수만큼 수를 반환시키고
	//읽은 부분은 다시 접근하지않기위해 읽은 부분 앞에 문자 '\0'처리
	//이는 재귀함수를 사용하는데 있어도 유용한 것 같다
	// 
	//스페이스바로 끊지 못하는 부분은 GetNextToken함수를 호출시킬때마다 문자열 길이를 받아
	//0보다 작으면 더이상 읽지 못하게 했음

	// &(*Node)->right 재귀 시 사용 유의
	return 0;
}