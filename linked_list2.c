#include "linked_list2.h"
#include <stdio.h>
#include <stdlib.h>

void 	Init (int M, int b, int t){
	Tiers = (MemoryPool*) malloc(t);
	
	MemoryPool* current = Tiers;//start at the beginning
	
	int i = 0;
	for(i = 0; i<t;++i){
		current->mempool = (Node*) malloc(M);
		current->head = current->mempool;
		current->free_pointer = current->head;//nothing is in the first node
		current->b=b;
		current->M=M;
		current->trailer = current->head + M;
		
		current++;
		
	}
	
	


} 
void 	Destroy (){} 		 
int 	Insert (int key,char * value_ptr, int value_len){}
int 	Delete (int key){}
char* 	Lookup (int key){}
void 	PrintList (){}

