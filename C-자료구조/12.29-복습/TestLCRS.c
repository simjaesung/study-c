#include "LCRS.h"

int main()
{
	Node* a = LCRS_CreateNode(1);
	Node* b = LCRS_CreateNode(2);
	Node* c = LCRS_CreateNode(3);
	Node* d = LCRS_CreateNode(4);
	Node* e = LCRS_CreateNode(5);
	Node* f = LCRS_CreateNode(6);
	Node* g = LCRS_CreateNode(7);
	Node* h = LCRS_CreateNode(8);
	Node* i = LCRS_CreateNode(9);
	Node* j = LCRS_CreateNode(10);
	Node* k = LCRS_CreateNode(11);

	LCRS_AddChildNode(a, b);
	LCRS_AddChildNode(a, g);
	LCRS_AddChildNode(a, i);
	LCRS_AddChildNode(b, c);
	LCRS_AddChildNode(b, d);
	LCRS_AddChildNode(d, e);
	LCRS_AddChildNode(d, f);
	LCRS_AddChildNode(g, h);
	LCRS_AddChildNode(i, j);
	LCRS_AddChildNode(j, k);

	LCRS_PrintTree(a, 0);

	puts("특정 레벨");
	LCRS_PrintNodesAtLevel(a, 2);


}