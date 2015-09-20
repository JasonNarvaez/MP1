#include "linked_list2.h"
#include <stdio.h>
#include <stdlib.h>

void Init(int M, int b, int t){
	Tiers = (MemoryPool*)malloc(t);
	tier_t = t;//global variable for t
	MemoryPool* current = Tiers;//start at the beginning

	int i = 0;
	for (i = 0; i<t; ++i){
		current->mempool = (Node*)malloc(M);
		current->head = current->mempool;
		current->free_pointer = current->head;//nothing is in the first node
		current->b = b;
		current->M = M;
		current->trailer = current->head + M;

		current++;
		tier_size++;

	}
}
void Destroy()	
{
	for (int i = 0; i < tiersize; i++)
	{	//array of memory pools
		MemoryPool* t = Tiers[i]
		Node *temp2 = t.head->next->next;
		while (t.head->next != NULL)
		{
			Node *temp;
			temp = t.head->next;
			t.head->next = temp2;
			free(temp);
		}
		free(t.head);
		free(t);
	}
}
int Insert(int key, char * value_ptr, int value_len){}
int Delete(int key){}
char* Lookup(int key)
{
	
}
void PrintList(){}
