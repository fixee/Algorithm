#include<stdio.h>

#define ARRAY_LENGH 100000

void quick_sort( int *arr, int begin, int end )
{
	if( begin >= end )
		return;

	int i, j, tmp;
	i = begin - 1;
	for( j = begin; j < end ; ++j )
	{
		if( arr[j] < arr[end] )
		{
			i++;
			if( i != j )
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	i++;
	tmp = arr[end];
	arr[end] = arr[i];
	arr[i] = tmp;

	quick_sort( arr, begin, i - 1 );
	quick_sort( arr, i + 1, end );
}

int main()
{
	const char * path = "data";
	int arr[ARRAY_LENGH] = {0};

	read_arr(arr, ARRAY_LENGH, path );
	quick_sort( arr, 0, ARRAY_LENGH - 1 );
	print_arr( arr, ARRAY_LENGH );

	return 0;
}
