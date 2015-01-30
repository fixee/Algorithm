#include<stdio.h>

//#define TEST

#ifndef TEST
#define ARRAY_LENGH 100000
#else
#define ARRAY_LENGH 10
#endif

void insert_sort( int *arr, int len )
{
	int i, j, tmp;
	for( i = 1; i < len; ++i )
	{
		tmp = arr[i];
		j = i;
		while( j > 0 && tmp < arr[j-1] )
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = tmp;
	}

	return ;
}

int main()
{
	const char * path = "data";
	int arr[ARRAY_LENGH] = {0};

	read_arr(arr, ARRAY_LENGH, path );
	insert_sort( arr, ARRAY_LENGH );
	print_arr( arr, ARRAY_LENGH );

	return 0;
}
