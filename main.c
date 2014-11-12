#include "BMP.h"
#include "HASH.h"

void printBinary( unsigned char data ){
	int j;
	
	for( j = 0; j < 8; j++ ){
		printf( "%i", data & ( 128 >> j ) ? 1 : 0 );
	}
}

int getCharLength( char* data ){
	int x = 0;
	char m = data[ 0 ];
	while( m != '\0' ){
		x++;
		m = data[ x ];
	}
	return x;
} 

int main( int argc, char** argv ){
	char* fileName = argv[ 1 ];
	char* text = argv[ 2 ]; 
	char* key = argv[ 3 ];
	int hash, i, j, k = 0, l, m = 0;
	int value = 1;
	int textData[ 100000 ] = { 0 };
	unsigned char bit_fld = 21;
	FILE* img;
	INFOHEADER info;
	PIXEL** bmpData;

	img = fopen( fileName, "r" );
	info = readImgInfo( img );
	bmpData = createMatrix( info.height, info.width );
	bmpData = loadImage( img, bmpData, info.height, info.width );
	
	
	//hash = getHashedKey( key );
	//printf( "%i %li\n", hash, sizeof( fileName ) );
	//bit_fld |= (1 << n)
	//printBinary( bit_fld );
	//bit_fld |= (0 << 7);
	l = getCharLength( text );
	for( i = 0; i < l; i++ ){
		printBinary( text[ i ] );
		for( j = 0; j < 8; j++ ){
			textData[ k ] = ( ( text[ i ] & ( 128 >> j ) ) ? 1 : 0 );
			k++;
		}
		
	}
	
	for( i = 0; i < info.height; i++ ){
		for( j = 0; j < info.width; j++ ){
			bmpData[ i ][ j ].rgb[ 0 ] |= ( 1 << 7 ) & textData[ m++ ];
			bmpData[ i ][ j ].rgb[ 1 ] |= ( 1 << 7 ) & textData[ m++ ];
			bmpData[ i ][ j ].rgb[ 2 ] |= ( 1 << 7 ) & textData[ m++ ];
			if( m > l ){
				saveImage( bmpData, &info, info.height, info.width );
				return 0;
			}
		}
	}
	
	saveImage( bmpData, &info, info.height, info.width );
	
	return 0;
}




