#ifndef DATA_H
#define DATA_H

/*****
	PIXEL
*****/
typedef struct {
	unsigned char rgb[3];
} PIXEL;

/*****
	BMP IMAGE HEADER
*****/
typedef struct {
	char b;
	char m;
	unsigned int size;
	unsigned int reserved;
	unsigned int offset;
	unsigned int info;
	int width;
	int height;
	unsigned short int planes;
	unsigned short int bpp;
	unsigned int compression;
	unsigned int imagesize;
	int xresolution;
	int yresolution;
	unsigned int colours;
	unsigned int impcolours;
} INFOHEADER;

#endif
