#ifndef MEMORY_H
#define MEMORY_H
#include <stdlib.h>
#include "DATA.h"

PIXEL** createMatrix( int height, int width ){
	PIXEL** matrix;
	int i;
	
	matrix = ( PIXEL** )malloc( sizeof ( PIXEL* ) * height );	
	for( i = 0; i < height; i++ ){
		matrix[ i ] = ( PIXEL* )malloc( sizeof( PIXEL ) * width );
	}
	return( matrix );
}

#endif
