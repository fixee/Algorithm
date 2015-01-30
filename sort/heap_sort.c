#include<stdio.h>

//#define TEST

#ifndef TEST
#define ARRAY_LENGH 100000
#else
#define ARRAY_LENGH 10
#endif

#define LCHILD(x) 2*(x)+1
#define RCHILD(x) 2*(x)+2

void adjust_heap( int *arr, int len, int node )
{
	int i=node, tmp;

	if( LCHILD(node) < len && arr[LCHILD(node)] > arr[i] )
		i = LCHILD(node);

	if( RCHILD(node) < len && arr[RCHILD(node)] > arr[i] )
		i = RCHILD(node);

	if( i != node )
	{
		tmp = arr[i];
		arr[i] = arr[node];
		arr[node] = tmp;
		adjust_heap( arr, len, i );
	}
}

void build_heap( int *arr, int len )
{
	int i = len / 2;
	for( ; i >= 0; i--)
		adjust_heap( arr, len, i );
}

void heap_sort( int *arr, int len )
{
	build_heap( arr, len );

	int tmp;
	while( --len > 0 )
	{
		tmp = arr[0];
		arr[0] = arr[len];
		arr[len] = tmp;
		adjust_heap( arr, len, 0 );
	}
}

int main()
{
	const char * path = "data";
	int arr[ARRAY_LENGH] = {0};

	read_arr(arr, ARRAY_LENGH, path );
	heap_sort( arr, ARRAY_LENGH );
	print_arr( arr, ARRAY_LENGH );

	return 0;
}
