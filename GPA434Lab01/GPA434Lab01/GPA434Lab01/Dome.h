#pragma once
#include <EzGame>
#include "Arena.h"

class Dome
{
	public:
		Dome(Arena const &gameArena )
			: mShape(gameArena.smallerSize()/4, gameArena.Center(), ezgame::Color::Cyan, ezgame::Color::Blue,mEdgeSize)
		{
		}
		//Accèsseur	
		float radius()const;
		ezgame::Vect2d position()const;
		ezgame::Circle circle()const;
		ezgame::Color color()const;

		//Mutateur
		void setColors(const ezgame::Color &fillColor);

		//Utilitaire
		void tic(float elapsedTime) const;
		void draw(ezgame::Screen& screen)const;
		
	private:
		const float mEdgeColorLighterRatio{0.75};
		const float mEdgeSize{ 1.5 };
		ezgame::Circle mShape;
		
};

