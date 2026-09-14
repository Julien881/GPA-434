#pragma once
#ifndef _EZGAME_VECT_2_D_H_
#define _EZGAME_VECT_2_D_H_


// Inclusion des bibliothèques
#include <random>
#include <string>
#include <iostream>


// Déclaration du namespace ezgame
namespace ezgame {

	//! \class Vect2d
	//! 
	//!	\brief Classe modélisant un vecteur bidimensionnel dans un espace 
	//! euclidien.
	//!	
	//!	\details Utilisée au sein de divers modules de la bibliothèque, cette 
	//! classe sert à :
	//!	- exécuter des opérations vectorielles
	//!	- spécifier une position spatiale(un point)
	//!	
	//! Les spécificités de la classe Vect2d sont :
	//!	- représente un vecteur dans un espace bidimensionnel
	//!	- supporte les coordonnées cartésiennes et polaires :
	//!	  - les composantes cartésiennes x et y sont stockées
	//!	  - les composantes polaires sont calculées à la demande
	//!	- inclut des accesseurs et des mutateurs pour une manipulation aisée
	//!	- permet l'emploi d'opérateurs mathématiques :
	//!	  - addition et soustraction vectorielles
	//!	  - multiplication et division par des scalaires
	//!	  - comparaison (avec prise en compte de la précision des nombres 
	//!     flottants)
	//!	- offre diverses fonctions utilitaires :
	//!	  - normalisation du vecteur
	//!	  - calcul de la distance entre deux vecteurs
	//!	  - génération aléatoire de vecteurs
	//!	  - permet la conversion en chaîne de caractères selon le format spécifié
	//! 
	//! Voici un exemple de code utilisant quelques opérateurs :
	//! \code
	//!		Vect2d v0, v1(0.5f, -1.25f), v2(1.0f, 0.0f);	// déclaration et définition des 3 vecteurs v0, v1 et v2
	//!		v0 = v1 + v2 * 10.0f;							// addition, multiplication et assignation
	//!		v0 -= v2;										// soustraction avec assignation
	//!		v0 /= 2.0f;										// division avec assignation
	//!		if (v1 == v2) {									// comparaison
	//!			std::cout << v0 << '\n';					// insertion de v2 dans la sortie standard
	//!		}
	//! \endcode
	//! 
	//! \subsection epsilon_comparison Comparaison avec tolérance
	//! 
	//! Cette classe utilise la technique de comparaison \f$ \epsilon \f$ 
	//! (_epsilon_), ou la technique de comparaison avec tolérance.
	//! 
	//! La comparaison de nombres à virgule flottante (ou point flottant) à 
	//! l'aide d'une valeur epsilon constitue une technique pour gérer les 
	//! imprécisions inhérentes à la représentation en virgule flottante. 
	//! En raison de ces imprécisions, il est souvent déconseillé d'utiliser 
	//! une comparaison stricte (égalité exacte) entre deux nombres à virgule 
	//! flottante.
	//!
	//! Le concept de comparaison \f$ \epsilon \f$ est simple : plutôt que de 
	//! vérifier si deux nombres \f$ a \f$ et \f$ b \f$ sont strictement égaux, 
	//! on vérifie si la valeur absolue de leur différence est suffisamment 
	//! petite. Plus formellement, deux nombres \f$ a \f$ et \f$ b \f$ sont 
	//! considérés comme _égaux_ si : \f$ \left| a - b \right| < \epsilon \f$
	//! 
	//! où \f$ \epsilon \f$ est une petite valeur positive, souvent choisie en 
	//! fonction du contexte de l'application ou du domaine des valeurs à 
	//! comparer.
	//! 
	//! Cette méthode est particulièrement utile pour des calculs qui impliquent 
	//! des approximations numériques ou des erreurs d'arrondi. En utilisant 
	//! une comparaison \f$ \epsilon \f$, on peut donc obtenir des résultats 
	//! _raisonnablement précis_ et éviter des erreurs potentiellement critiques 
	//! dans les calculs.
	//! 
	//! Les fonctions Vect2d::epsilon et Vect2d::setPrecision permettent de 
	//! connaître et déterminer la valeur _epsilon_. Par défaut, la valeur 
	//! _epsilon_ est celle du type `float`. Toutes les fonctions suivantes 
	//! utilisent cette technique :
	//! - Vect2d::isDefined
	//! - Vect2d::isNormalized
	//! - comparaison : `==` et `!=`
	//! 
	class Vect2d
	{
	public:
		//!
		//!
		//! \brief Constructeur par défaut. Initialise un vecteur à l'origine.
		Vect2d();
		//!
		//! \brief Constructeur avec paramètres. Initialise un vecteur avec 
		//! les composantes cartésiennes spécifiées.
		//! 
		//! \param x La composante x du vecteur.
		//! \param y La composante y du vecteur.
		Vect2d(float x, float y);
		//
		//
		//! \cond PRIVATE
		Vect2d(Vect2d const& other) = default;
		Vect2d(Vect2d && other) = default;
		Vect2d& operator=(Vect2d const& other) = default;
		Vect2d& operator=(Vect2d && other) = default;
		//! \endcond
		//! 
		//!
		//! \brief Destructeur par défaut.
		~Vect2d() = default;
		//
		// 
		//!
		//!
		//! \brief Fonction statique créant un vecteur à partir de ses composantes 
		//! polaires.
		//! 
		//! \details Un exemple de code :
		//! \code
		//!		Vect2d myVect;
		//!		myVect = Vect2d::fromPolar(2.5f, 3.14f);
		//! \endcode
		//!
		//! \param length La longueur du vecteur.
		//! \param orientation L'orientation angulaire du vecteur en radians.
		//! \return Un nouveau vecteur Vect2d issu de la représentation polaire 
		//! donnée.
		static Vect2d fromPolar(float length, float orientation);
		//!
		//!
		//! \brief Fonction statique créant un vecteur unitaire à partir d'une 
		//! orientation spécifiée.
		//! 
		//! \details Un exemple de code :
		//! \code
		//!		Vect2d myVect;
		//!		myVect = Vect2d::fromNormalized(3.14f / 2.0f);
		//! \endcode
		//!
		//! \param orientation L'orientation angulaire du vecteur en radians.
		//! \return Un nouveau vecteur Vect2d normalisé.
		static Vect2d fromNormalized(float orientation);
		//!
		//!
		//! \brief Fonction statique créant un vecteur aléatoire.
		//! 
		//! \details Un exemple de code :
		//! \code
		//!		Vect2d myVect;
		//!		myVect = Vect2d::fromNormalized();
		//! \endcode
		//!
		//! \return Un nouveau vecteur unitaire Vect2d avec une direction 
		//! aléatoires.
		static Vect2d fromRandomized();
		//!
		//!
		//! \brief Fonction statique créant un vecteur aléatoire dans les 
		//! limites cartésiennes spécifiées.
		//! 
		//! \details Un exemple de code :
		//! \code
		//!		Vect2d myVect;
		//!		myVect = Vect2d::fromRandomized(-10.0f, 10.0f, -1.0f, 1.0f);
		//! \endcode
		//!
		//! \param xMin La limite inférieure pour la composante x.
		//! \param xMax La limite supérieure pour la composante x.
		//! \param yMin La limite inférieure pour la composante y.
		//! \param yMax La limite supérieure pour la composante y.
		//! \return Un nouveau vecteur Vect2d défini aléatoirement.
		static Vect2d fromRandomized(float xMin, float xMax, float yMin, float yMax);
		//!
		//!
		//! \brief Fonction statique créant un vecteur aléatoire à partir de 
		//! composantes polaires dans des limites spécifiées pour la longueur.
		//! 
		//! \details Un exemple de code :
		//! \code
		//!		Vect2d myVect;
		//!		myVect = Vect2d::fromPolarRandomized(10.0f, 100.0f);
		//! \endcode
		//!
		//! \param lengthMin La longueur minimale du vecteur.
		//! \param lengthMax La longueur maximale du vecteur.
		//! \return Un nouveau vecteur Vect2d avec des composantes polaires 
		//! aléatoires.
		static Vect2d fromPolarRandomized(float lengthMin, float lengthMax);
		//!
		//!
		//! \brief Fonction statique créant un vecteur aléatoire à partir de 
		//! composantes polaires dans des limites spécifiées pour la longueur 
		//! et l'orientation.
		//! 
		//! \details Un exemple de code :
		//! \code
		//!		Vect2d myVect;
		//!		myVect = Vect2d::fromPolarRandomized(10.0f, 100.0f, 0.0f, 3.14f / 2.0f);
		//! \endcode
		//!
		//! \param lengthMin La longueur minimale du vecteur.
		//! \param lengthMax La longueur maximale du vecteur.
		//! \param oriMin L'orientation minimale du vecteur en radians.
		//! \param oriMax L'orientation maximale du vecteur en radians.
		//! \return Un nouveau vecteur Vect2d avec des composantes polaires aléatoires.
		static Vect2d fromPolarRandomized(float lengthMin, float lengthMax, float oriMin, float oriMax);
		//! 
		//!
		//! \brief Vérifie si le vecteur est valide.
		//! 
		//! \details Un vecteur est invalide lorsque l'une de ses composantes 
		//! x ou y sont :
		//! - `NaN` : <b>N</b>ot <b>a</b> <b>N</b>umber
		//! - `INF` : infini
		//! 
		//! \return Vrai si les composantes ne sont pas des `NaN` ou `INF`, sinon 
		//! faux.
		bool isValid() const;
		//! 
		//!
		//! \brief Vérifie si le vecteur est défini.
		//! 
		//! \details Un vecteur défini est un vecteur valide dont la longueur 
		//! n'est pas 0. Un vecteur indéfini n'a aucune orientation.
		//! 
		//! \return Vrai si le vecteur est valide et dont l'orientation est 
		//! définie, sinon faux.
		bool isDefined() const;
		//!
		//!
		//! \brief Vérifie si le vecteur est normalisé.
		//! 
		//! \return Vrai si la longueur du vecteur est 1, sinon faux.
		bool isNormalized() const;
		//!
		//!
		//! \brief Accesseur pour la composante x.
		//! 
		//! \details Représentation cartésienne.
		//!
		//! \return La composante x du vecteur.
		float x() const;
		//!
		//!
		//! \brief Accesseur pour la composante y.
		//! 
		//! \details Représentation cartésienne.
		//!
		//! \return La composante y du vecteur.
		float y() const;
		//!
		//!
		//! \brief Mutateur pour la composante x.
		//! 
		//! \details Représentation cartésienne.
		//!
		//! \param x La nouvelle valeur pour la composante x.
		void setX(float x);
		//!
		//!
		//! \brief Mutateur pour la composante y.
		//! 
		//! \details Représentation cartésienne.
		//!
		//! \param y La nouvelle valeur pour la composante y.
		void setY(float y);
		//!
		//!
		//! \brief Mutateur pour les composantes x et y.
		//! 
		//! \details Représentation cartésienne.
		//!
		//! \param x La nouvelle valeur pour la composante x.
		//! \param y La nouvelle valeur pour la composante y.
		void set(float x, float y);
		//!
		//!
		//! \brief Mutateur réinitialisant les valeurs x et y à 0.0f.
		//! 
		void reset();
		//!
		//!
		//! \brief Calcule la longueur au carré du vecteur.
		//! 
		//! \details Représentation cartésienne.
		//!
		//! \return La longueur au carré du vecteur.
		float squaredLength() const;
		//!
		//!
		//! \brief Calcule la longueur du vecteur.
		//! 
		//! \details Représentation polaire.
		//!
		//! \return La longueur du vecteur.
		float length() const;
		//!
		//!
		//! \brief Calcule l'orientation du vecteur.
		//! 
		//! \details Représentation polaire.
		//!
		//! \return l'orientation du vecteur en radians.
		float orientation() const;
		//!
		//!
		//! \brief Modifie la longueur du vecteur tout en conservant son 
		//! orientation, via son carré.
		//! 
		//! \details Représentation polaire.
		//!
		//! \param squaredLength La nouvelle valeur du carré de la longueur 
		//! du vecteur.
		void setSquaredLength(float squaredLength);
		//!
		//!
		//! \brief Modifie la longueur du vecteur tout en conservant son 
		//! orientation.
		//! 
		//! \details Représentation polaire.
		//!
		//! \param length La nouvelle longueur du vecteur.
		void setLength(float length);
		//!
		//!
		//! \brief Modifie l'orientation du vecteur tout en conservant sa 
		//! longueur.
		//! 
		//! \details Représentation polaire.
		//!
		//! \param orientation La nouvelle orientation du vecteur en radians.
		void setOrientation(float orientation);
		//!
		//! \brief Établit les composantes polaires du vecteur.
		//! 
		//! \details Représentation polaire.
		//!
		//! \param length La longueur du vecteur.
		//! \param orientation L'orientation du vecteur en radians.
		void setPolar(float length, float orientation);
		//!
		//!
		//! \brief Retourne une version normalisée du vecteur actuel.
		//! 
		//! \return Un nouveau vecteur normalisé.
		Vect2d normalized() const;
		//!
		//!
		//! \brief Normalise le vecteur en modifiant ses composantes afin que sa 
		//! longueur soit égale à 1.
		void normalize();
		//!
		//!
		//! \brief Calcule le carré de la distance euclidienne entre le vecteur courant 
		//! et un autre vecteur.
		//!
		//! \param other Le vecteur avec lequel calculer la distance.
		//! \return Le carré de la distance euclidienne.
		float squaredDistance(Vect2d const& other) const;
		//!
		//!
		//! \brief Calcule la distance euclidienne entre le vecteur courant et 
		//! un autre vecteur.
		//!
		//! \param other Le vecteur avec lequel calculer la distance.
		//! \return La distance euclidienne.
		float distance(Vect2d const& other) const;
		//!
		//! \brief Initialise aléatoirement un vecteur unitaire.
		//! 
		//! \details Le vecteur résultant est de longueur 1.
		void randomize();
		//!
		//!
		//! \brief Initialise aléatoirement les composantes du vecteur dans 
		//! les intervalles spécifiés.
		//!
		//! \param xMin La limite inférieure pour la composante x.
		//! \param xMax La limite supérieure pour la composante x.
		//! \param yMin La limite inférieure pour la composante y.
		//! \param yMax La limite supérieure pour la composante y.
		void randomize(float xMin, float xMax, float yMin, float yMax);
		//!
		//!
		//! \brief Initialise aléatoirement les composantes polaires du 
		//! vecteur, en se basant uniquement sur la longueur.
		//! 
		//! \details Le vecteur possède une orientation aléatoire et une 
		//! longueur dans l'intervalle [lengthMin, lengthMax].
		//!
		//! \param lengthMin La limite inférieure pour la longueur du vecteur.
		//! \param lengthMax La limite supérieure pour la longueur du vecteur.
		void randomizePolar(float lengthMin, float lengthMax);
		//!
		//!
		//! \brief Initialise aléatoirement les composantes polaires du 
		//! vecteur dans les intervalles spécifiés.
		//!
		//! \param lengthMin La limite inférieure pour la longueur du vecteur.
		//! \param lengthMax La limite supérieure pour la longueur du vecteur.
		//! \param oriMin La limite inférieure pour l'orientation du vecteur 
		//! en radians.
		//! \param oriMax La limite supérieure pour l'orientation du vecteur 
		//! en radians.
		void randomizePolar(float lengthMin, float lengthMax, float oriMin, float oriMax);
		//!
		//!
		//! \brief Converion du vecteur en chaîne de caractères.
		//! 
		//! \details La conversion utilise quatre éléments de formattage :
		//! - prefixe, par défaut `(`
		//! - séparateur, par défaut `,`
		//! - suffixe, par défaut `)`
		//! - la précision, par défaut 2
		//! 
		//! La converions correspond à ce patron : 
		//!  - \code [prefix][x][separator][y][suffix] \endcode 
		//!  - la conversion des nombres x et y utilisent une notation fixe avec 
		//!    la précision donnée
		//! 
		//! Il est possible de modifier le format avec les mutateurs statiques.
		//! 
		//! Voici un exemple de code :
		//! 
		//! \code
		//!		Vect2d myVector(-2.5f, 3.14159265f); 
		//!		std::cout << myVector.toString() << '\n'; // Affiche : (-2.50, 3.14)
		//! 
		//!		Vect2d::setFormat("[ ", " x ", " ]", 4);
		//!		std::cout << myVector.toString() << '\n'; // Affiche : [ -2.5000 x 3.141596 ]
		//! \endcode 
		//! 
		//! \return La représentation du vecteur sous forme de chaîne de 
		//! caractères.
		std::string toString() const;

		//! \cond PRIVATE
		bool operator==(Vect2d const& other) const;
		bool operator!=(Vect2d const& other) const;

		Vect2d operator+(Vect2d other) const;
		Vect2d operator-(Vect2d other) const;
		Vect2d operator*(float scalar) const;
		Vect2d operator/(float scalar) const;
		friend Vect2d operator*(float scalar, Vect2d const& other);
		friend Vect2d operator/(float scalar, Vect2d const& other);

		Vect2d& operator+=(Vect2d const& other);
		Vect2d& operator-=(Vect2d const& other);
		Vect2d& operator*=(float scalar);
		Vect2d& operator/=(float scalar);

		friend std::ostream& operator<<(std::ostream& stream, Vect2d const& vector);
		//! \endcond

		//!
		//!
		//! \brief Accesseur statique récupérant le préfixe du format 
		//! d'affichage du vecteur.
		//! 
		//! \details Cette méthode statique renvoie la chaîne de caractères 
		//! utilisée comme préfixe lors de l'affichage du vecteur.
		//! 
		//! \return Chaîne de caractères représentant le préfixe actuel.
		static std::string prefix();
		//!
		//!
		//! \brief Accesseur statique récupérant le séparateur du format 
		//! d'affichage du vecteur.
		//! 
		//! \details Cette méthode statique renvoie la chaîne de caractères 
		//! utilisée comme séparateur lors de l'affichage du vecteur.
		//! 
		//! \return Chaîne de caractères représentant le séparateur actuel.
		static std::string separator();
		//!
		//!
		//! \brief Accesseur statique récupérant le suffixe du format 
		//! d'affichage du vecteur.
		//! 
		//! \details Cette méthode statique renvoie la chaîne de caractères 
		//! utilisée comme suffixe lors de l'affichage du vecteur.
		//! 
		//! \return Chaîne de caractères représentant le préfixe actuel.
		static std::string suffix();
		//! 
		//! 
		//! Récupère la précision du format d'affichage du vecteur.
		//! 
		//! \brief Cette méthode statique renvoie le nombre de chiffres après la virgule utilisés lors de l'affichage du vecteur.
		//! \return Nombre entier représentant la précision actuelle.
		static size_t precision();
		
		//!
		//! 
		//! \brief Mutateur statique modifiant le format d'affichage du vecteur.
		//! 
		//! \param prefix Le nouveau préfixe.
		static void setPrefix(std::string const& prefix);
		//!
		//!
		//! \brief Mutateur statique modifiant le format d'affichage du vecteur.
		//! 
		//! \param separator Le nouveau séparateur.
		static void setSeparator(std::string const& separator);
		//!
		//! 
		//! \brief Mutateur statique modifiant le format d'affichage du vecteur.
		//! 
		//! \param suffix Le nouveau suffixe.
		static void setSuffix(std::string const& suffix);
		//!
		//! 
		//! \brief Mutateur statique modifiant le format d'affichage du vecteur.
		//! 
		//! \param precision La nouvelle précision.
		static size_t setPrecision(size_t precision);
		//!
		//! 
		//! \brief Mutateur statique modifiant le format d'affichage du vecteur.
		//! 
		//! \param prefix Le nouveau préfixe.
		//! \param separator Le nouveau séparateur.
		//! \param suffix Le nouveau suffixe.
		static void setFormat(std::string const& prefix, std::string const& separator, std::string const& suffix);
		//!
		//! 
		//! \brief Mutateur statique modifiant le format d'affichage du vecteur.
		//! 
		//! \param prefix Le nouveau préfixe.
		//!	\param separator Le nouveau séparateur.
		//!	\param suffix Le nouveau suffixe.
		//! \param precision La nouvelle précision.
		static void setFormat(std::string const& prefix, std::string const& separator, std::string const& suffix, size_t precision);
		//! 
		//! 
		//! \brief Accessseur statique retournant la valeur epsilon.
		//! 
		//! \details La valeur epsilon est utilisée pour les comparaisons entre 
		//! nombres à virgule flottante. En effet, les nombres à virgule
		//! flottante ne sont pas représentés avec une précision infinie. 
		//! Ainsi, epsilon représente l'erreur maximum acceptable lors d'une
		//! comparaison entre deux nombres à virgule flottante.
		//! \return La valeur epsilon.
		static float epsilon();
		//! 
		//! 
		//! \brief Mutateur statique modifiant la valeur epsilon.
		//! 
		//! \details La valeur epsilon est utilisée pour les comparaisons entre
		//! nombres à virgule flottante. En effet, les nombres à virgule
		//! flottante ne sont pas représentés avec une précision infinie.
		//! Ainsi, epsilon représente l'erreur maximum acceptable lors d'une
		//! comparaison entre deux nombres à virgule flottante.
		//! \param epsilon La nouvelle valeur epsilon.
		static void setEpsilon(float epsilon);

	private:
		static float smEpsilon;
		static size_t smPrecision;
		static std::string smPrefix;
		static std::string smSeparator;
		static std::string smSuffix;

		float mX;
		float mY;

		static bool floatsApproxZero(float a, float epsilon);
		static bool floatsApproxEqual(float a, float b, float epsilon);
	};

} // namespace ezgame

#endif // _EZGAME_VECT_2_D_H_