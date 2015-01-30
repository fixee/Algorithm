#include<stdio.h>

#define TEST

#ifndef TEST
#define ARRAY_LENGH 100000
#else
#define ARRAY_LENGH 10
#endif

int tmp_arr[ARRAY_LENGH] = {0};

void combine_sort( int *arr, int begin, int end )
{
	if( end - begin < 1 )
		return;

	int mid = ( begin + end ) / 2;
	combine_sort( arr, begin, mid );
	combine_sort( arr, mid + 1, end );

	int i = begin, j = mid + 1, k = 0;
	while( i <= mid && j <= end )
	{
		if( arr[i] < arr[j] )
			tmp_arr[k++] = arr[i++];
		else
			tmp_arr[k++] = arr[j++];
	}

	if( i > mid )
	{
		while( j <= end )
			tmp_arr[k++] = arr[j++];
	}
	else
	{
		while( j <= end )
			tmp_arr[k++] = arr[i++];
	}

	i = begin;
	j = 0;
	while( i <= end )
		arr[i++] = tmp_arr[j++];
}

int main()
{
	const char * path = "data";
	int arr[ARRAY_LENGH] = {0};

	read_arr(arr, ARRAY_LENGH, path );
	combine_sort( arr, 0, ARRAY_LENGH - 1 );
	print_arr( arr, ARRAY_LENGH );

	return 0;
}
