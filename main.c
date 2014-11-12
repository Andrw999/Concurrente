#include "BMP.h"
#include "HASH.h"

int main( int argc, char** argv ){
	char* fileName = argv[ 1 ];
	char* text = argv[ 2 ]; 
	char* key = argv[ 3 ];
	int hash;
	FILE* img;
	INFOHEADER info;
	PIXEL** bmpData;

	img = fopen( fileName, "r" );
	info = readImgInfo( img );
	bmpData = createMatrix( info.height, info.width );
	bmpData = loadImage( img, bmpData, info.height, info.width );
	saveImage( bmpData, &info, info.height, info.width );
	
	hash = getHashedKey( key );
	printf( "%i %li\n", hash, sizeof( fileName ) );
	return 0;
}


