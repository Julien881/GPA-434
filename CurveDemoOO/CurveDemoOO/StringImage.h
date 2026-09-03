#pragma once

#include <string> 

class StringImage
{
public:
	//Mutateur
	void initialise(int width, int height, char backGroundChar);
	
	void setPixel(int x,int y,char c);
	void SetWidth(int w);
	
	//Devoir
	void fill();
	void clear();
	void drawLHine();
	void drawVLine();
	void drawHText();
	void drawVText();

	//Acceseur
	char getPixel();
	int GetWidth();
	int GetHeight();
	int GetSize();


	//utilitaire
	//im.toString();

private:
	char backgroundChar;
	int width;
	int height;
	std::string image;
	
	//Accesseur
	int getOffset(int x, int y);
	bool IsCharValid(char c);
	bool IsPosValid(int x, int y);
	
	//Mutateur
	void setbackground(char c);

};

