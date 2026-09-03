#include "Voiture.h"
#include <stdlib>

class Voiture
{
	double x;
	double y;

	void innit() {
		printf("innitialision complêté");
	}

	//fonction accesseur permet de récupérer des attribut privé
	double GetX() {

		return x;
	}

	//fonction mutateur permet de modifier l'objet de façon controlé 
	//Contrôle signifie par exemple qu'on peut mettre des bornes exemple du résevoir d'essence a -5%
	void SetX(double NewX) {
	
		x = NewX;

	}
};

