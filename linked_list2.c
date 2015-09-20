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
int Insert(int key, char * value_ptr, int value_len){
	
	unsigned int max_size = INT_MAX;//maximum size of a signed integer
	printf("max size: %u\n",max_size);
	
	
	printf("key: %u\n",key);
	
	unsigned int tier_range = max_size/tier_t;//specifies the key range for each tier. tier t is the amt of tiers
	
	printf("tier range: %u\n",tier_range);
	
	unsigned int tier_placement = ((unsigned int)key)/tier_range;//tier where node will be place
	
	printf("tier placement: %u\n",tier_placement);
	
	if(tier_placement >= 0) printf("TRUE1\n");
	if(tier_placement < tier_t) printf("TRUE2\n");
	if(tier_placement >= 0 &&  tier_placement < tier_t){//needs to check for available space within tier
	
		MemoryPool* current = Tiers;//point to the first tier
		printf("\nb: %d\n",current->b);
		current += tier_placement;//current now points to the tier where we will insert the node
		printf("tier: %d\n",tier_placement);
		printf("b: %d\n",current->b);
		
		if(value_len<=current->b){
			char temp[current->b-16];
			printf("before key assignment\n\n");
			//if(current->free_pointer) printf("free pointer not NULL!\n\n");
			
			
			current->free_pointer->key = key;//segfault
			current->free_pointer->value_len = value_len;
			printf("done deed\n");
			
			current->free_pointer->value = temp;
			
			memcpy(current->free_pointer->value,value_ptr, value_len);//copy value_len elements from value_ptr to MP.value
			
			current->free_pointer->next += current->b;
			current->free_pointer += current->b;//MP.b;
			printf("b: %d\n",current->b);
		}
		else{
			printf("Value Length Too Large\n");
			
		}
		if(current->free_pointer)printf("free_pointer not NULL\n\n");
		// printf("inserted: %d\n",*value_ptr);
		// printf("inserted: %s\n",value_ptr);
		
	}
	else{
		printf("key is too large or key is negative\n");
	}
	
}
int Delete(int key){}
char* Lookup(int key)
{
	
}
void PrintList(){}
