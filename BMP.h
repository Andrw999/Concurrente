#ifndef BMP_H
#define BMP_H
#include "DATA.h"
#include "FILE.h"
#include "MEMORY.h"

PIXEL** loadImage( FILE* filePointer, PIXEL** bmpData, int height, int width ){
	int i,j;
	PIXEL tmp;
	long pos = 54;
	
	//Restart file position
	fseek( filePointer, 0, 0 );
	
	for( i = 0; i < height; i++ ){
		for( j = 0; j < width; j++ ){
			fseek( filePointer, pos, 0 );
			fread( &tmp, ( sizeof( PIXEL ) ), 1, filePointer );
			bmpData[ i ][ j ] = tmp;
			pos+= 3;
		}
	}
	return( bmpData );
}

INFOHEADER readImgInfo( FILE* filePointer ){
	INFOHEADER info;
	
	fseek( filePointer, 0, 0 );
	
	fread( &info.b, sizeof( char ), 1, filePointer );
	fread( &info.m, sizeof( char ), 1, filePointer );
	fread( &info.size, sizeof( unsigned int ), 1, filePointer );
	fread( &info.reserved, sizeof( unsigned int ), 1, filePointer );
	fread( &info.offset, sizeof( unsigned int ), 1, filePointer );
	fread( &info.info, sizeof( unsigned int ), 1, filePointer );
	fread( &info.width, sizeof( unsigned int ), 1,  filePointer );
	fread( &info.height, sizeof( unsigned int ), 1, filePointer );
	fread( &info.planes, sizeof( unsigned short int ), 1, filePointer );
	fread( &info.bpp, sizeof( unsigned short int ), 1, filePointer );
	fread( &info.compression, sizeof( unsigned int ), 1, filePointer );
	fread( &info.imagesize, sizeof( unsigned int ), 1, filePointer );
	fread( &info.xresolution, sizeof( int ), 1, filePointer );
	fread( &info.yresolution, sizeof( int ), 1, filePointer );
	fread( &info.colours, sizeof( unsigned int ), 1, filePointer );
	fread( &info.impcolours, sizeof( unsigned int ), 1, filePointer );
	
	return( info );
}

void saveImage( PIXEL** bmpData, INFOHEADER* info, int height, int width ){
	FILE* filePointer;
	int i,j;
	PIXEL tmp;
	
	filePointer = fopen( "crypto.bmp", "w" );
	fwrite( &info -> b, sizeof( char ), 1, filePointer );
	fwrite( &info -> m, sizeof( char ), 1, filePointer );
	fwrite( &info -> size, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> reserved, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> offset, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> info, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> width, sizeof( unsigned int ), 1,  filePointer );
	fwrite( &info -> height, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> planes, sizeof( unsigned short int ), 1, filePointer );
	fwrite( &info -> bpp, sizeof( unsigned short int ), 1, filePointer );
	fwrite( &info -> compression, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> imagesize, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> xresolution, sizeof( int ), 1, filePointer );
	fwrite( &info -> yresolution, sizeof( int ), 1, filePointer );
	fwrite( &info -> colours, sizeof( unsigned int ), 1, filePointer );
	fwrite( &info -> impcolours, sizeof( unsigned int ), 1, filePointer );

	for( i = 0; i < height; i++ ){
		for ( j = 0; j < width; j++ ){
			fwrite( &bmpData[ i ][ j ], ( sizeof( PIXEL ) ), 1, filePointer );
        }
    }
}

#endif
