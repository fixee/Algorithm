#include<stdio.h>


void bubble_sort( int *arr, int len )
{
	int i = 0, j = 0;
	int temp;

	for( i = len; i > 1; i-- )
	{
		for( j = 0; j < i - 1; ++j )
		{
			if( arr[j] > arr[j+1] )
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		
	}
}

int main()
{
	const char * path = "data";
	int arr[100000] = {0};

	read_arr(arr, 100000, path );
	bubble_sort( arr, 100000 );
	print_arr( arr, 100000 );

	return 0;
}
