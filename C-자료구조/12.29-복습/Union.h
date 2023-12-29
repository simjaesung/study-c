#pragma once


#include<stdio.h>
#include<stdlib.h>


typedef struct Set
{
	struct Set* Parent;
	int Data;
}Set;


void DS_UnionSet(Set* Set1, Set* Set2);
Set* DS_FindSet(Set* Set);
Set* DS_MakeSet(int Data);
void DS_DeleteSet(Set* Set);