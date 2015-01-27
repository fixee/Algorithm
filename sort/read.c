#include<stdio.h>

int read_arr( int *arr, int len, const char * filepath )
{
	FILE *fp = fopen( filepath, "r" );
	if( fp == NULL )
		return 1;

	char buffer[1024] = {0};
	int index = -1;
	while( fgets( buffer, 1024, fp ) != NULL && ++index < len )
	{
		arr[index] = atoi( buffer );
	}

	fclose( fp );

	return 0;
}

int print_arr( int * arr, int len )
{
	if( NULL == arr || 0 == len )
		return 1;

	int i;
	for( i = 0; i < len ; ++i )
		printf( "%d\n", arr[i] );

	return 0;
}

