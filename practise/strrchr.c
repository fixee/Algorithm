#include<stdio.h>

const char * strchr( const char *str, char c )
{
	if( NULL == str )
		return NULL;

	while( *str != c && *++str != '\0' );
	
	return *str == '\0' ? NULL : str;
}

const char *strrchr( const char *str, char c )
{
	if( NULL == str )
		return NULL;

	const char *tmp = NULL;
	while( *str != '\0' )
	{
		if( *str == c )
			tmp = str;
		str++;
	}

	return tmp;
}

int strpos( const char *str, char c )
{
}

int strrpos( const char *str, char c )
{
}

int stripos( const char *str, char c )
{
}

int main()
{
	const char *str = "hello world";
	printf( "%s\n", strrchr( str, 'w' ) );
}
