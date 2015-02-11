#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define TEST

#ifndef TEST
#define ARRAY_LENGH 100000
#else
#define ARRAY_LENGH 10
#endif

#define MAX_NUM 1000000

void bucket_sort( int *arr, int length )
{
	if( NULL == arr || 0 == length )
		return;

	int *bucket = (int *)malloc( sizeof( int ) * MAX_NUM );
	if( NULL == bucket )
	{
		perror( "malloc bucket error" );
		exit(1);
	}

	memset( bucket, 0, sizeof( int ) * MAX_NUM );

	int i, j;
	for( i = 0; i < length; ++i )
		bucket[arr[i]]++;
	for( i = 1; i < MAX_NUM; ++i )
		bucket[i] += bucket[i-1];

	i = 0; 
	j = 0;
	while( i < length && j < MAX_NUM )
	{
		if( bucket[j] > i )
			arr[i++] = j;
		else
			j++;
	}
}

int main()
{
	const char * path = "data";
	int arr[ARRAY_LENGH] = {0};

	read_arr(arr, ARRAY_LENGH, path );
	bucket_sort( arr, ARRAY_LENGH );
	print_arr( arr, ARRAY_LENGH );

	return 0;
}
