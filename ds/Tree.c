#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ds_basic.h"

TNode *init_node( int value )
{
	TNode *node = (TNode *)malloc( sizeof( TNode ) );
	if( NULL == node )
	{
		perror( "malloc error" );
		exit(1);
	}

	node->value = value;
	node->rchild = NULL;
	node->lchild = NULL;

	return node;
}

void insert_node_recurse( TNode **tree, TNode *node )
{
	if( NULL == *tree )
	{
		*tree = node;
		return;
	}

	if( node->value < (*tree)->value )
	{
		if( NULL == (*tree)->lchild )
			(*tree)->lchild = node;
		else
			insert_node_recurse( &( (*tree)->lchild ), node );

		return;
	}

	if( NULL == (*tree)->rchild )
		(*tree)->rchild = node;
	else
		insert_node_recurse( &( (*tree)->rchild ), node );
}

void insert_node( TNode **tree, int value )
{
	TNode *node = init_node( value );
	if( *tree == NULL )
	{
		*tree = node;
		return;
	}

	TNode *p = *tree;
	while( NULL != p )
	{
		if( value < p->value )
		{
			if( p->lchild == NULL )
			{
				p->lchild = node;
				break;
			}
			else
				p = p->lchild;
		}
		else
		{
			if( p->rchild == NULL )
			{
				p->rchild = node;
				break;
			}
			else
				p = p->rchild;
		}
	}

	return;
}

TNode *build_tree( int *arr, int length )
{
	int i;
	TNode *tree = NULL;
	//for(i = 0; i < length; i++)
	//{
	//	TNode * node = init_node( arr[i] );
	//	insert_node_recurse( &tree, node );
	//}
	
	for( i = 0; i < length; i++ )
	{
		insert_node( &tree, arr[i] );
	}

	return tree;
}

void mid_travell( TNode *tree )
{
	if( NULL == tree )
		return;
	mid_travell( tree->lchild );
	printf( "%d\n", tree->value );
	mid_travell( tree->rchild );
}

void pre_travell( TNode *tree )
{
	if( NULL == tree )
		return;
	printf( "%d\n", tree->value );
	pre_travell( tree->lchild );
	pre_travell( tree->rchild );
}

void last_travell( TNode *tree )
{
	if( NULL == tree )
		return;
	last_travell( tree->lchild );
	last_travell( tree->rchild );
	printf( "%d\n", tree->value );
}

void pre( TNode *tree )
{
}

void mid( TNode *tree )
{
	if( NULL == tree )
		return;

	TNode *p = tree;
	STNode *stack = NULL;
	while( NULL != p && !stack_empty( stack ) )
	{
		if( NULL == p )
		{
		}
	}
}

void last( TNode *tree )
{
}


int main()
{
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };

	TNode *tree = build_tree( arr, 10 );
	mid_travell( tree );
	//pre_travell( tree );
	//last_travell( tree );

	return 0;
}
