#ifndef _linked_list2_h_                   // include file only once
#define _linked_list2_h_
#include <limits.h>
#include <vector>

void 	Init (int M, int b, int t); // initializes the linked list, should be called once from the main
void 	Destroy (); 		 //	destroys the linked list and cleans resources
int 	Insert (int key,char * value_ptr, int value_len); // inserts the key and copies the value to the payload
int 	Delete (int key); 	 // delete the whole block containing that particular key. When multiple entries with the same key, delete only the first one	
char* 	Lookup (int key);	 //	Looks up the first item with the given and returns a pointer to the value portion (the value length and the actual value) 
							//(the user can read or modify after obtaining the pointer)
void 	PrintList ();		// prints the entire list by following the next pointers. Print the keys and the length	of the value



typedef struct Node Node;
typedef struct MemoryPool MemoryPool;

vector<MemoryPool> Tiers;
int tier_size = 0;
int tier_t;//global t given by the main or user


struct Node {		//Each node is 8 bytes max
 	Node *next;
	
	//payload
	int key;     	//4-bytes
	//char* value;    	//variable length
	void* value;
	int value_len;
};

struct MemoryPool{
	
	MemoryPool(): b(128), M(128*4){}
	
	Node* mempool;
	Node* free_pointer;
	Node* head;
	Node* trailer;
	
	void set_b(int B){ b = B; }
	void set_M(int m){ M = m; }
	int get_b(){ return b; }
	int get_M(){ return M; }
	
	private:
	int b;
	int M;
	
	
};



#endif 
