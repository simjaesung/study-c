#include<stdio.h>


typedef struct NODE
{
	int nData;
	struct NODE* pnext;
} NODE;


int main2(void)
{
	//	struct NODE node[8] = { 0 };
	NODE list[5] = { 0 };


	//list[0].pnext = list[1];

	list[0].pnext = &list[2];
	list[1].pnext = NULL;
	list[2].pnext = &list[3];
	list[3].pnext = &list[4];
	list[4].pnext = &list[1];


	list[0].nData = 100;
	list[1].nData = 200;
	list[2].nData = 300;
	list[3].nData = 350;
	list[4].nData = 400;

	for (int i = 0; i < 5; i++)
		printf("list[%d].nData = %d\n", i, list[i].nData);


	NODE* node = NULL;
	
	node = &list[0];

	while (node != NULL)
	{
		printf("list[%p].nData = %d\n", node, node->nData);
		node = node->pnext;
	}




	return 0;
}