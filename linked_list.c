
#include <stdio.h>
#include "linked_list.h"

typedef struct Node Node;

struct Node {		//Each node is 8 bytes max
 	Node *next;
	//Node *free;
	//payload
	int key;     	//4-bytes
	char* value;    	//variable length
	int value_len;
};

struct MemoryPool{
	
	Node* mempool;
	Node* free_pointer;
	Node* head;
	int b;
	int M;
	//Node* linked_list_head;
	
}MP;		
		

							//m = M/b items in the list
void Init (int M, int b)	//b is node size
{							//M is memory pool
	MP.mempool = (Node*) malloc(M);
	MP.head = MP.mempool;
	MP.free_pointer = MP.head;//nothing is in the first node
	MP.b=b;
	MP.M=M;
	// Node *head = malloc(M);
	// head->next = NULL;
} 

void Destroy ()		//searches linked list for value and destroys that node
{// 9/15 11:09pm
	Node *temp2 = MP.head->next->next;
	while (MP.head->next != NULL)
	{
		Node *temp;
		temp = MP.head->next;
		MP.head->next = temp2;
		free(temp);
	}
	free(MP.head);
} 	
	 
int Insert (int key,char * value_ptr, int value_len){
	//take those values make a Node
	//new?
	//put at free pointer
	//move free pointer
	
	//Node* newnode;
	if(value_len<=MP.b){
		char temp[MP.b-16];
	
		MP.free_pointer->key = key;
		MP.free_pointer->value_len = value_len;
	
		//printf("head: %u \nfree pointer: %u \n",MP.head,MP.free_pointer);
		MP.free_pointer->value = temp;
		//printf("value: %s",MP.free_pointer->value);
		memcpy(MP.free_pointer->value,value_ptr, value_len);//copy value_len elements from value_ptr to MP.value
		//printf("size of b: %u \n \n",MP.b);
		MP.free_pointer->next += MP.b;
		MP.free_pointer += MP.b;//MP.b;
		
	}else{
		printf("Too Large\n");
		
	}
	
	
	
	
}

int Delete (int x){//modified 9/15 11:08pm
	printf("meh");
	char* addr = Lookup (x);
	Node* pointer;
	Node* start=MP.head;
	Node* end=MP.head+MP.M-MP.b;
	
		
	
	pointer =(Node*)((char*)addr);
	
	//if its the first one
	if(pointer==start){
		pointer->next=NULL;
	}//end
	else if(pointer==end){
		pointer->next=NULL;
	}//if its in the middle 
	else if((start<pointer)&&(pointer<end)){
			pointer->next=NULL;
			//take previous and have it point 2 ahead
			pointer -=MP.b;
			pointer->next= pointer+(2*MP.b);
	}else{
		
		printf("Not found");
		return 0;
	}
	return 0;
}
	
	


char* Lookup (int key){
	//search through looking for key

	 Node *Current=MP.head;
	//what if head is null
	int i=1;
	
	while(i<(MP.M/MP.b)){
		
		
		if((Current->key==key)&&(Current->next!=NULL)){

			
			return (char*)(Current);
		}
		
		Current+=MP.b;
	}
	

	return NULL;

}

void PrintList (){
	Node *Current=MP.head;
	
	int i=1;
	int counter=1;
	//what if head is null
	while(i<(MP.M/MP.b)){
		if(Current->next!=NULL){
			printf("%i. ",counter);
			printf("Key: %i \n",Current->key);
			printf("Value: %i \n",Current->value_len);
			counter++;
		}
		i++;
		Current+=MP.b;
			
		
	}
	printf("\n");
	
}
