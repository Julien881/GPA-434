#pragma once
#ifndef _EZGAME_CIRCLE_H_
#define _EZGAME_CIRCLE_H_


// Inclusion des bibliothèques
#include "Vect2d.h"
#include "Alignment.h"
#include "Color.h"


// Déclaration du namespace ezgame
namespace ezgame {

    //! \class Circle
    //! 
    //! \brief Classe représentant un cercle.
    //! 
    //! \details Cette classe est l'un des deux objets pouvant être affiché à 
    //! l'écran par la bibliothèque `EzGame`. 
    //! 
    //! Un cercle est défini par :
    //! - le rayon
    //! - la position (représentée par un Vect2d)
    //! - l'alignement
    //! - la couleur de remplissage
    //! - la couleur et l'épaisseur du contour
    class Circle
    {
    public:
        //!
        //!
        //! \brief Constructeur par défaut.
        //!
        //! \details Initialise un objet cercle avec des valeurs par défaut.
        //! Délègue la construction avec les paramètres par défaut suivants :
        //! - rayon : 1.0f
        //! - position : `(0.0f, 0.0f)`
        //! - alignement : `CenterCenter`
        //! - remplissage : blanc
        //! - bordure : aucune
        Circle();
        //!
        //!
        //! \brief Constructeur initialisant les attributs d'un objet cercle 
        //! sans bordure.
        //! 
        //! \details Ce constructeur délègue la construction à un autre 
        //! constructeur en mettant la bordure invisible et de taille 0. 
        //! 
        //! \param radius Le rayon du cercle.
        //! \param position La position du cercle, représentée par un vecteur 
        //! Vect2d.
        //! \param color La couleur de remplissage du cercle, spécifiée en 
        //! tant qu'objet Color.
        //! \param alignment L'alignement du cercle. Par défaut, l'alignement 
        //! est centré horizontalement et verticalement.
        Circle(float radius, Vect2d const& position, Color const color = Color::White, Alignment alignment = Alignment::CenterCenter);
        //!
        //!
        //! \brief Constructeur initialisant les attributs d'un objet cercle.
        //! 
        //! \details Ce constructeur permet de créer un objet de la classe 
        //! Circle.
        //! 
        //! \param radius Le rayon du cercle.
        //! \param position La position du cercle, représentée par un vecteur 
        //! Vect2d.
        //! \param fillColor La couleur de remplissage du cercle, spécifiée en 
        //! tant qu'objet Color.
        //! \param edgeColor La couleur de la bordure du cercle, spécifiée en 
        //! tant qu'objet Color.
        //! \param edgeSize La taille de la bordure en pixels.
        //! \param alignment L'alignement du cercle. Par défaut, l'alignement 
        //! est centré horizontalement et verticalement.
        Circle(float radius, Vect2d const& position, Color const fillColor, Color const edgeColor, float edgeSize = 1.0f, Alignment alignment = Alignment::CenterCenter);
        
        //! \cond PRIVATE
        Circle(Circle const& other) = default;
        Circle(Circle && other) = default;
        Circle& operator=(Circle const& other) = default;
        Circle& operator=(Circle && other) = default;
        ~Circle() = default;
        //! \endcond

        //!
        //!
        //! \brief Accesseur retournant le rayon.
        //! 
        //! \return Le rayon.
        float radius() const;
        //!
        //!
        //! \brief Accesseur retournant la position.
        //! 
        //! \details Un Vect2d est utilisé pour représenter la position.
        //!
        //! \return La position.
        Vect2d position() const;
        //!
        //!
        //! \brief Accesseur retournant l'alignement.
        //! 
        //! \return L'alignement..
        Alignment alignment() const;
        //!
        //!
        //! \brief Accesseur retournant la couleur de remplissage.
        //! 
        //! \return La couleur de remplissage.
        Color fillColor() const;
        //!
        //!
        //! \brief Accesseur retournant la couleur de la bordure.
        //! 
        //! \return La couleur de la bordure.
        Color edgeColor() const;
        //!
        //!
        //! \brief Accesseur retournant la taille de la bordure.
        //! 
        //! \return La taille de la bordure.
        float edgeSize() const;
        //!
        //!
        //! \brief Fonction utilitaire retournant si ce cercle entre en 
        //! collision avec au autre cercle.
        //! 
        //! \details La collision est déterminé par le rayon et non pas par 
        //! l'apparence du cercle. Ceci implique que si la bordure est 
        //! épaisse, la collision ne sera affective que lorsque les deux 
        //! cercles se touchent au niveau de leur rayon respectif sans 
        //! considération pour la bordure apparente. Cette situation peut 
        //! rendre l'application confuse selon l'intention.
        //! 
        //! De plus, si deux cercles ne font que s'effleurer sur leur rayon,
        //! il est considéré que la collision est effective.
        //! 
        //! \code
        //!     Circle myCircle(25.0f, Vect2d(0.0f, 25.0f); 
        //!     Circle yourCircle(50.0f, Vect2d(0.0f, -50.0f);
        //!     
        //!     std::cout << myCircle.isColliding(yourCircle); 
        //! \endcode
        //! 
        //! \param otherCircle Le cercle à considérer pour la collision.
        //! 
        //! \return Vrai s'il y a une collision, faux sinon.
        bool isColliding(Circle const& otherCircle) const;
        //!
        //!
        //! \brief Mutateur du rayon.
        //! 
        //! \details Le rayon est contraint à un minimum de 1.0f.
        //!
        //! \param radius Le nouveau rayon.
        void setRadius(float radius);
        //!
        //!
        //! \brief Mutateur de la position du texte.
        //!
        //! \param position Le nouveau vecteur position dans un espace 2D.
        void setPosition(Vect2d const& position);
        //!
        //!
        //! \brief Mutateur de l'alignement du texte.
        //!
        //! \param alignment Le nouvel alignement du texte.
        void setAlignment(Alignment alignment);
        //!
        //!
        //! \brief Mutateur de la couleur de remplissage du texte.
        //!
        //! \param color La nouvelle couleur de remplissage.
        void setFill(Color const& color);
        //!
        //!
        //! \brief Supprime la couleur de remplissage du texte.
        //! 
        //! \details Assigne la couleur transparente au remplissage du texte.
        void setNoFill();
        //!
        //!
        //! \brief Mutateur de la couleur de la bordure du texte.
        //!
        //! \param color La nouvelle couleur de la bordure.
        void setEdge(Color const& color);
        //!
        //!
        //! \brief Mutateur de la taille de la bordure du texte.
        //!
        //! \param size La nouvelle taille de la bordure en pixel.
        void setEdge(float size);
        //!
        //!
        //! \brief Mutateur de la couleur et de la taille de la bordure du 
        //! texte.
        //!
        //! \param color La nouvelle couleur de la bordure.
        //! \param size La nouvelle taille de la bordure en unités.
        void setEdge(Color const& color, float size);
        //!
        //!
        //! \brief Supprime la bordure du texte.
        //! 
        //! \details Assigne la couleur transparente et la taille 0 à la 
        //! bordure.
        void setNoEdge();
        //!
        //!
        //! \brief Mutateur des couleurs de remplissage et de la bordure du 
        //! texte.
        //!
        //! \param fillColor La nouvelle couleur de remplissage.
        //! \param edgeColor La nouvelle couleur de la bordure.
        void setColors(Color const& fillColor, Color const& edgeColor);
        //!
        //!
        //! \brief Mutateur des couleurs de remplissage et de bordure, ainsi 
        //! que la taille de la bordure du texte.
        //!
        //! \param fillColor La nouvelle couleur de remplissage.
        //! \param edgeColor La nouvelle couleur de la bordure.
        //! \param edgeSize La nouvelle taille de la bordure en unités.
        void setColors(Color const& fillColor, Color const& edgeColor, float edgeSize);
        //!
        //!
        //! \brief Mutateur relatif du rayon.
        //! 
        //! \details Le rayon mininum est 1.0f. L'impact sur la taille est :
        //! - si `relativeSize` < 1.0, réduction du rayon
        //! - si `relativeSize` = 1.0, aucun changement
        //! - si `relativeSize` > 1.0, augmentation du rayon
        //! 
        //! \param relativeSize La proportion relative à appliquer au rayon.
        void adjustSize(float relativeSize);
        //!
        //!
        //! \brief Déplace du cercle.
        //! 
        //! \details Cette fonction applique une translation sur le cercle. 
        //! 
        //! Si le déplacement est (0.0, 0.0), la position reste inchangée.
        //! 
        //! \param displacement La translation à appliquer.
        void move(Vect2d const& displacement);

    private:
        static float const smMinimumRadius;
        float mRadius;
        Vect2d mPosition;
        Alignment mAlignment;
        Color mFillColor;
        Color mEdgeColor;
        float mEdgeSize;
    };


} // namespace ezgame


#endif // _EZGAME_CIRCLE_H_