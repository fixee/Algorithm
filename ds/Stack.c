#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "ds_basic.h"

unsigned int g_stack_error = 0;

STNode *stack_init_node( int value )
{
	STNode *node = (STNode *)malloc( sizeof( STNode ) );
	if( NULL == node )
	{
		perror( "malloc error");
		exit(1);
	}

	node->value = value;
	node->pre = NULL;

	return node;
}

void stack_insert( STNode ** stack, int value )
{
	STNode *node = stack_init_node( value );
	node->pre = (*stack);
	*stack = node;
}

void stack_pop( STNode **stack )
{
	if( NULL == *stack )
		return;

	STNode *p = *stack;
	*stack = p->pre;
	free(p);
}

int stack_top( STNode * stack )
{
	if( NULL != stack )
		return stack->value;

	g_stack_error = 1;
	return -1;
}

bool stack_empty( STNode *stack )
{
	return NULL == stack;
}
