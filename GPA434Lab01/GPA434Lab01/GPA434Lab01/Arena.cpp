#include "Arena.h"

//Accèsseur
float Arena::width()const{ return mWidth; }
float Arena::height()const { return mHeight; }

ezgame::Vect2d Arena::Center()const{ 
	ezgame::Vect2d gameArenaC(mWidth / 2, mHeight / 2); //comment je devrais nommer des variables comme ça ? 
	return gameArenaC;
}

float Arena::smallerSize()const { return std::min(mWidth, mHeight); }
float Arena::largerSize()const { return std::max(mWidth, mHeight); }

//Utilitaire
ezgame::Vect2d Arena::restrictedPosition(ezgame::Vect2d position)const {
	//clamp contraint les valeurs dans l'intervalle donné
	return {
		std::clamp(position.x(), 0.0f, mWidth),
		std::clamp(position.y(), 0.0f, mHeight)
	};
}
ezgame::Vect2d Arena::warpedPosition(ezgame::Vect2d position)const {
	if (position.x() < 0.0f) {
		position.setX(mWidth);
	}
	if (position.x() > mWidth) {
		position.setX(0.0f);
	}
	if (position.y() < 0.0f) {
		position.setY(mHeight);
	}
	if (position.y() > mHeight) {
		position.setY(0.0f);
	}
	return position;
}
void Arena::tic(float elapsedTime) const {}
void Arena::draw(ezgame::Screen& screen)const { screen.clear(); }//la j'ai fais ça mais je suis pas sur c'est quoi 
