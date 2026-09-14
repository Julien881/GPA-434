#pragma once
#ifndef _EZGAME_SCREEN_H_
#define _EZGAME_SCREEN_H_


// Inclusion des bibliothèques
#include <memory>
#include "Color.h"
#include "Circle.h"
#include "Text.h"


// Déclaration du namespace ezgame
namespace ezgame {
    
    class Application;

    //! \class Screen
    //! 
    //! \brief Classe permettant de dessiner à l'écran.
    //! 
    //! \details La classe Screen permet de dessiner sur la surface graphique 
    //! les primitives disponibles avec la librairie `EzGame`.
    //! 
    //! Il est possible de :
    //!  - connaître la taille de la surface graphique :
    //!    - Screen::width
    //!    - Screen::height
    //!  - remplir la surface graphique d'une couleur uniforme :
    //!    - Screen::clear
    //!  - dessiner un objet Circle ou Text :
    //!    - Screen::draw
    class Screen
    {
    public:
        // Accesseurs
        //!
        //!
        //! \brief Accesseur retournant la largeur de la surface graphique.
        //! 
        //! \return La largeur de la surface graphique.
        size_t width() const;
        //!
        //!
        //! \brief Accesseur retournant la hauteur de la surface graphique.
        //! 
        //! \return La hauteur de la surface graphique.
        size_t height() const;

        // Mutateurs
        //!
        //!
        //! \brief Rempli l'écran de la couleur noire. 
        //! 
        //! \details La couleur étant opaque, cette fonction a pour effet 
        //! d'effacer tous les éléments présents.
        void clear();
        //!
        //!
        //! \brief Rempli l'écran de la couleur donnée. 
        //! 
        //! \details Puisque la transparence de la couleur est utilisée :
        //! - une couleur opaque a pour effet d'effacer tout ce qui se trouve 
        //!   sur la surface graphique
        //! - une couleur semi transparente permet un effet intéressant
        void clear(Color const& color);
        //!
        //!
        //! \brief Dessine le cercle donné.
        //! 
        //! \details Le cercle est dessiné en considérant :
        //! - taille et positionnement selon :
        //!   - le rayon
        //!   - la position
        //!   - l'alignement
        //! - l'apparence selon :
        //!   - la couleur de remplissage
        //!   - la couleur et l'épaisseur du contour 
        //! 
        //! Voir la classe Circle pour plus de détails.
        void draw(Circle const& circle);
        //!
        //!
        //! \brief Dessine le texte donné.
        //! 
        //! \details Le texte est dessiné en considérant :
        //! - taille et positionnement selon :
        //!   - la taille de la police de caractère
        //!   - le texte lui-même
        //!   - la position
        //!   - l'alignement
        //! - l'apparence selon :
        //!   - la couleur de remplissage
        //!   - la couleur et l'épaisseur du contour 
        //! 
        //! Voir la classe Text pour plus de détails.
        void draw(Text const& text);

    private:
        Screen(Application & app);
        Screen(Screen const &) = delete;
        Screen(Screen &&) = delete;
        Screen& operator=(Screen const &) = delete;
        Screen& operator=(Screen &&) = delete;
        ~Screen();

        class Impl;
        std::unique_ptr<Impl> mImpl;

        friend class Application;
    };

} // namespace ezgame

#endif // _EZGAME_SCREEN_H_