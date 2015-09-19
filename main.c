#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.c"
// g++-4.7 -std=c++11 *.cpp
//gcc -o main main.c
//http://faculty.cs.tamu.edu/welch/teaching/211.s03/lnotes2.pdf
//http://c.learncodethehardway.org/book/ex16.html
//http://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
int main(int argc, char ** argv) 
{
	int b = 128;
	int M = b * 11;  // so we have space for 11 items
	
	char buf [1024];
	memset (buf, 1, 1024);		// set each byte to 1
	
	char * msg = "a sample message";
	
	Init (M,b); // initialize
	// test operations
	int testnums [] = {100, 5, 200, 7, 39, 25, 400, 50, 200, 300};
	int i = 0;
	// some sample insertions
	for (i=0; i< 10; i ++)
	{
		Insert (testnums [i], buf, 50);   // insert 50 bytes from the buffer as value for each of the insertions
	}
	Insert (150, buf, 200); // this Insert should fail
	PrintList ();
	Delete (7);
	Insert (13, msg, strlen(msg)+1);		// insertion of strings, copies the null byte at the end
	PrintList ();

	Delete (55);
	/*Insert (15, "test msg", 8);
	Delete (3);
	PrintList ();
	
	// a sample lookup operations that should return null, because it is looking up a non-existent number
	char* kv = Lookup (3);
	if (kv)
		printf ("Key = %d, Value Len = %d\n", *(int *) kv, *(int *) (kv+4));
	
	
	// this look up  should succeed and print the string "a sample message"
	kv = Lookup (13);
	if (kv)
		printf ("Key = %d, Value Len = %d, Value = %s\n", *(int *) kv, *(int *) (kv+4), kv + 8);
	
	
	// end test operations	
	Destroy ();
	

	//testlist
	printf ("Enter basic block size: ");
    scanf ("%i",&b);
	printf ("Enter memory size(in bytes): ");
    scanf ("%i",&M);
	Init (M,b); // initialize

	int repeat =1;
	int key;
	char * value_ptr;
	int value_len;
	int length;
	while(repeat ==1){
		printf ("Enter key: ");
		scanf ("%i",&key); 
		//char?
		printf ("Enter value length: ");
		scanf ("%i",&length); 
		Insert (key, value_ptr, length); 
		printf ("Would you like to enter in another? 1-Yes   0-No \n");
		scanf ("%i",&repeat);
	}
	repeat =1;
	printf ("Would you like to delete? 1-Yes   0-No \n");
	scanf ("%i",&repeat); 
	
	while(repeat==1){
		printf ("Enter key: ");
		scanf ("%i",&key); 
		Delete(key);
		printf ("Would you like to delete? 1-Yes   0-No \n");
		scanf ("%i",&repeat); 
	}
	PrintList ();
	Destroy ();*/
	printf("Finish");
	
}
