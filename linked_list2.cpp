#include "linked_list2.h"
#include <stdio.h>
#include <stdlib.h>

void 	Init (int M, int b, int t){
	
	//Tiers = (MemoryPool*) malloc(t);
	tier_t = t;//global variable for t
	
	MemoryPool temp;
	for(int i=0;i<t;++i){
		Tiers.push_back(temp);
		
	}
	
	
	int i = 0;
	for(i = 0; i<t;++i){
		Tiers[i].mempool = (Node*) malloc(M);
		Tiers[i].head = Tiers[i].mempool;
		Tiers[i].free_pointer = Tiers[i].head;//nothing is in the first node
		Tiers[i].set_b(b);
		Tiers[i].set_M(M);
		Tiers[i].trailer = Tiers[i].head + Tiers[i].get_M();
		
		/* current->mempool = (Node*) malloc(M);
		current->head = current->mempool;
		current->free_pointer = current->head;//nothing is in the first node
		current->set_b(b);
		current->set_M(M);
		current->trailer = current->head + current->get_M();
		 */
		//current->free_pointer->next = current->free_pointer + b;
		
		//if(i<t-1)current++;
		tier_size++;
		
	}
	//current = Tiers;
	for(i = 0; i<t;++i){
		//printf("current: %d\n",current);
		printf("current free pointer: %d\n",Tiers[i].free_pointer);
		printf("current free pointer next: %d\n",Tiers[i].free_pointer->next);
		//if(i<t-1)current++;
		
	}
	
	
} 
void 	Destroy (){} 		 
int 	Insert (int key,char * value_ptr, int value_len){
	
	
	int max_size = INT_MAX;//maximum size of a signed integer
	//printf("max size: %u\n",max_size);
	
	
	printf("key: %u\n",key);
	
	int tier_range = max_size/tier_t;//specifies the key range for each tier. tier t is the amt of tiers
	
	//printf("tier range: %u\n",tier_range);
	
	int tier_placement = ((unsigned int)key)/tier_range;//tier where node will be place
	
	printf("tier placement: %u\n",tier_placement);
	
	//if(tier_placement >= 0) printf("TRUE1\n");
	//if(tier_placement < tier_t) printf("TRUE2\n");
	if(tier_placement >= 0 &&  tier_placement < tier_t){//needs to check for available space within tier
	
		//MemoryPool current = Tiers[0];//point to the first tier
		
		//printf("\nb: %d\n",current->b);
		//printf("current free pointer: %d\n",current.free_pointer);
		//printf("current free pointer next: %d\n",current.free_pointer->next);
		
		MemoryPool &current = Tiers[tier_placement];//current now points to the tier where we will insert the node
		//printf("tier: %d\n",tier_placement);
		//printf("b: %d\n",current->b);
		
		if(value_len<=current.get_b()){
			Node* tempNode = current.free_pointer;
			
			char temp[current.get_b()-16];
			//printf("before key assignment\n\n");
			//if(current->free_pointer) printf("free pointer not NULL!\n\n");
			
			
			tempNode->key = key;//segfault
			tempNode->value_len = value_len;
			//printf("done deed\n");
			
			tempNode->value = temp;
			
			memcpy(tempNode->value,value_ptr, value_len);//copy value_len elements from value_ptr to MP.value
			//printf("b: %d\n",current.get_b());
			
			// printf("current free pointer: %d\n",current.free_pointer);
			// printf("current free pointer next: %d\n",current.free_pointer->next);
			
			tempNode->next = current.free_pointer + current.get_b();
			 
			// printf("b: %d\n",current.get_b());
			// printf("current free pointer: %d\n",current.free_pointer);
			// printf("current free pointer next: %d\n",current.free_pointer->next);
			
			current.free_pointer = current.free_pointer + current.get_b();//current->b;//MP.b;
			
			// printf("b: %d\n",current.get_b());
			// printf("current free pointer: %d\n",current.free_pointer);
			// printf("current free pointer next: %d\n",current.free_pointer->next);
		}
		else{
			printf("Value Length Too Large\n");
			
		}
		//if(current.free_pointer)printf("free_pointer not NULL\n\n");
		// printf("inserted: %d\n",*value_ptr);
		// printf("inserted: %s\n",value_ptr);
		
	}
	else{
		printf("key is too large or key is negative\n");
	}

}
int 	Delete (int key){}
char* 	Lookup (int key){}
void 	PrintList (){
	
	//MemoryPool* current = Tiers;//start at the beginning
	
	//int i = 0;
	
	for(int i = 0;i<tier_size;++i){
		cout<<"tier: "<<i<<endl;
		Node* current = Tiers[i].mempool;//start at the beginning
		while(current != Tiers[i].trailer){
			cout<<"key: "<<current->key<<endl;
			cout<<"Value: "<<current->value<<endl;
			current += Tiers[i].get_b();
		
		cout<<endl;
		/* cout<<"tier:"<<i<<"\n";
		Node* current = Tiers[i].mempool;//start at the beginning
		int j=0;
		while(j<((Tiers[i].get_M()/Tiers[i].get_b()))){
			if(current->next != NULL){
				
				//cout<<"i: "<<i<<endl;
				cout<<"key: "<<current->key<<endl;
				cout<<"Value: "<<current->value<<endl;
				
				
			}

		current+=Tiers[i].get_b();
		j++; */
		}
	}
	//int t = sizeof(Tiers);
	printf("size of tiers: %d",tier_size);



}

