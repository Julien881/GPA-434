#include "StringImage.h"


void StringImage::initialise(int w, int h, char backGroundChar) // StringImage fais le lien vers le .h
{
	//garde fou
	if (w <= 0 || w > 1000 || h <= 0 || h > 1000)  
	{
		return;
	}
	
 	width = w;
	height = h;
	
	size_t charCount = (width + 1) * height; //grosseur de la chaine de charactere nécéssaire c'est un malloc
	image.resize(charCount); 

	setbackground(backGroundChar);

	for (size_t y = 0; y < 4;y++) {
		image[y * (width +1)+ width] = '\n';
	}	
}
void StringImage::setPixel(int x,int y,char c){

	if (x >= 0 && x < width && y >= 0 && y < height) {

	}
	else {

	}
}
void StringImage::setbackground(char c){
	for (size_t i = 0; i < image.size();i++) {
		image[i] = c;
	}
}

int StringImage::getOffset(int x, int y) {

	return x + y * width;
}

bool IsCharValid(char c) {
	
	return c >= 32;

}