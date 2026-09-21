#include "Dome.h"

float Dome::radius()const {return mShape.radius();}
ezgame::Vect2d Dome::position()const { return mShape.position();}
ezgame::Circle Dome::circle()const { return mShape;}
ezgame::Color Dome::color()const { return mShape.fillColor(); }
void Dome::setColors(const ezgame::Color &fillColor) {
	mShape.setColors(fillColor, fillColor.lighter(mEdgeColorLighterRatio),mEdgeSize); 
}
void Dome::tic(float elapsedTime)const {}
void Dome::draw(ezgame::Screen& screen)const {screen.draw(mShape);}