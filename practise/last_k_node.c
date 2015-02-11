#include<stdio.h>

struct Node {
	int value;
	struct Node *next;
};

Node *find_last_k_node( Node *head, unsigned int k )
{
	if( NULL == head )
		return NULL;

	struct Node *first = head;
	struct Node *second = head;
	first = head
	while( --k > 0 && first != NULL )
		first = first->next;

	if( k > 0 )
		return NULL;

	while( first != NULL )
	{
		second = second->next;
		first = first->next;
	}

	return second;
}


int main()
{
	
}
