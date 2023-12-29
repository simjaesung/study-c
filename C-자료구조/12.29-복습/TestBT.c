#include "BiniaryTree.h"


int main()
{
	Node* A = BT_CreateNode('A');
	Node* B = BT_CreateNode('B');
	Node* C = BT_CreateNode('C');
	Node* D = BT_CreateNode('D');
	Node* E = BT_CreateNode('E');
	Node* F = BT_CreateNode('F');
	Node* G = BT_CreateNode('G');


	A->left = B;
	A->right = E;
	B->left = C;
	B->right = D;
	E->left = F;
	E->right = G;


	
	puts("\nPreorder");
	BT_Preorder(A);

	puts("\nInorder");
	BT_Inorder(A);

	puts("\nPostorder");
	BT_Postorder(A);
	
	
	
	BT_DeleteTree(A);
	
	return 0;
}