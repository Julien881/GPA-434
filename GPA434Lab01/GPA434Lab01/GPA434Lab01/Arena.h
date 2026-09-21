#pragma once
#include <EzGame>
#include <algorithm>

class Arena
{
	public:
		Arena(float vWidth, float vHeight)
			: mWidth{ vWidth }
			, mHeight{ vHeight }
		{}
		
		//Accesseur
		float width() const;
		float height() const;
		ezgame::Vect2d Center()const;
		float smallerSize()const;
		float largerSize()const;

		//Utilitaire
		ezgame::Vect2d restrictedPosition(ezgame::Vect2d position)const;
		ezgame::Vect2d warpedPosition(ezgame::Vect2d position)const;
		void tic(float elapsedTime) const;
		void draw(ezgame::Screen &screen)const;

private:
		const float mMinimumSize{ 50 };
		const float mMaximumSize{ 2000 };
		float mWidth{};
		float mHeight{};
};

