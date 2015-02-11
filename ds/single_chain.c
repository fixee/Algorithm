#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ds_basic.h"

int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };

SLNode *head = NULL;
SLNode *tail = NULL;

SLNode *init_node( int value )
{
	SLNode *p = ( SLNode * )malloc( sizeof( SLNode ) );
	if( NULL == p )
	{
		perror("malloc error");
		exit(1);
	}

	p->value = value;
	p->next = NULL;

	return p;
}

void insert_node( int value )
{
	SLNode *node = init_node( value );
	if( tail == NULL )
		tail = node;

	node->next = head;
	head = node;
}

void append_node( int value )
{
	SLNode *node = init_node( value );
	if( head == NULL )
		head = node;

	if( tail != NULL )
		tail->next = node;
	tail = node;
}

SLNode *search_node( int value )
{
	SLNode *p = head;
	while( p != NULL )
	{
		if( p->value == value )
			return p;

		p = p->next;
	}

	return NULL;
}

void inverse_chain()
{
	SLNode *p = NULL;
	while( head != NULL )
	{
		head->next = (SLNode *)((long)head->next ^ (long)p);
		p = (SLNode *)((long)head->next ^ (long)p);
		head->next = (SLNode *)((long)head->next ^ (long)p);

		head = (SLNode *)((long)p ^ (long)head);
		p = (SLNode *)((long)head ^ (long)p);
		head = (SLNode *)((long)head ^ (long)p);
	}

	head = p;
}

void delete_chain()
{
	if( NULL == head )
		return;

	SLNode *p = head;
	while( p != NULL )
	{
		head = p->next;
		free(p);
		p = head;
	}
}

void print_chain()
{
	SLNode *p = head;
	while( p != NULL )
	{
		printf( "%d ", p->value );
		p = p->next;
	}
	printf( "\n" );
}

int main()
{
	int i;
	for( i = 0; i < 10; ++i )
	{
		append_node( arr[i] );
		//insert_node( arr[i] );
	}

	print_chain();
	inverse_chain();
	print_chain();

	delete_chain();

	return 0;
}
