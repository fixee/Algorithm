#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	struct Node * pre;
};

struct Node *head = NULL;

void push( int value )
{
	struct Node *node = (struct Node *)malloc( sizeof( struct Node ) );
	node->value = value;
	node->pre = head;
	head = node;
}

int pop()
{
	if( head == NULL )
		return -1;

	struct Node *cur = head;
	int value = cur->value;
	head = cur->pre;
	free( cur );

	return value;
}


int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

int main()
{
	struct Node *head = NULL;
	int i;
	for( i = 0; i < 10; i++ )
		push( a[i] );

	int top;
	while( ( top = pop() ) != -1 )
	{
		printf( "%d\n", top );
	}
	return 0;
}
