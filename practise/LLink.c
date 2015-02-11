#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value;
	struct Node * next;
};

LNode *head = NULL;
LNode *tail = NULL;

struct Node * init_node( int value )
{
	struct Node *node = (struct Node *)malloc( sizeof( Node ) );
	node->value = value;
	node->next = NULL;

	return node;
}

void destroy_node( struct Node *node )
{
	if( node != NULL )
		free( node );
}

bool search( int value )
{
	struct Node * p = head;
	while( p != tail )
	{
		if( p->value == value )
			return true;
	}

	return false;
}

void insert( int value )
{
	struct Node *node = init_node( value );

	if( tail == NULL )
		tail = node;

	if( head != NULL )
		node->next = head;

	head = node;
}

void append( int value )
{
	struct Node *node = init_node( value );

	if( head == NULL )
		head = node;

	if( tail != NULL )
		tail->next = node;
	tail = node;
}

void inverse_list()
{
	if( head == NULL )
		return;

	struct Node *p;
	tail = head;

	p = head;
	head = NULLr
	while( p != NULL )
	{
		p->next = head;
		head = p;
	}
}

void delete_list()
{
}

void print_list()
{
	struct Node *p = head;
	while( p != tail )
	{
		printf( "%d ", p->value );
	}
	printf( "\n" );
}

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
}
