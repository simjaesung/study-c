#include "Union.h"


void DS_UnionSet(Set* Set1, Set* Set2)
{
	Set2 = DS_FindSet(Set2);
	Set2->Parent = Set1;
}

Set* DS_FindSet(Set* Set)
{
	while (Set->Parent != NULL)
		Set = Set->Parent;
	
	return Set;
}


Set* DS_MakeSet(int Data)
{
	Set* NewSet = (Set*)malloc(sizeof(Set));
	NewSet->Data = Data;
	NewSet->Parent = NULL;

	return NewSet;
}

void DS_DeleteSet(Set* Set)
{
	free(Set);
}