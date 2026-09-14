#pragma once
#ifndef _EZGAME_TEXT_H_
#define _EZGAME_TEXT_H_


//#include "Graphical.h"
#include <string>
#include "Vect2d.h"
#include "Alignment.h"
#include "Color.h"


// Déclaration du namespace ezgame
namespace ezgame {

    //! \class Text
    //! 
    //! \brief Classe représentant un texte.
    //! 
    //! \details Cette classe est l'un des deux objets pouvant être affiché à 
    //! l'écran par la bibliothèque `EzGame`. 
    //! 
    //! Un texte est défini par :
    //! - la chaîne de caractères
    //! - la taille de la police de caractère
    //! - la position (représentée par un Vect2d)
    //! - l'alignement
    //! - la couleur de remplissage
    //! - la couleur et l'épaisseur du contour
    class Text
    {
    public:
        //!
        //!
        //! \brief Constructeur par défaut.
        //!
        //! \details Initialise un objet texte avec des valeurs par défaut.
        //! Délègue la construction avec les paramètres par défaut suivants :
        //! - texte : `"EzGame"`
        //! - taille de la police : `24.0f`
        //! - position : `(0.0f, 0.0f)`
        //! - alignement : `BaseLeft`
        //! - remplissage : noir
        //! - bordure : aucune
        Text();
        //!
        //!
        //! \brief Constructeur initialisant les attributs d'un objet texte 
        //! sans bordure.
        //! 
        //! \details Ce constructeur délègue la construction à un autre 
        //! constructeur en mettant la bordure invisible et de taille 0. 
        //! 
        //! \param text Le texte à afficher.
        //! \param textSize La taille du texte en pixels.
        //! \param position La position du texte, représentée par un vecteur 
        //! Vect2d.
        //! \param color La couleur de remplissage du texte, spécifiée en 
        //! tant qu'objet Color.
        //! \param alignment L'alignement du texte. Par défaut, l'alignement 
        //! est à la base gauche.
        Text(std::string const & text, float textSize, Vect2d const& position, Color const color = Color::Black, Alignment alignment = Alignment::BaseLeft);
        //!
        //!
        //! \brief Constructeur initialisant les attributs d'un objet texte.
        //! 
        //! \details Ce constructeur permet de créer un objet Text avec une 
        //! bordure autour du texte. La bordure et le texte peuvent avoir 
        //! des couleurs différentes.
        //! 
        //! \param text Le texte à afficher.
        //! \param textSize La taille du texte en pixels.
        //! \param position La position du texte, représentée par un vecteur 
        //! Vect2d.
        //! \param fillColor La couleur de remplissage du texte, spécifiée en 
        //! tant qu'objet Color.
        //! \param edgeColor La couleur de la bordure du texte, spécifiée en 
        //! tant qu'objet Color.
        //! \param edgeSize La taille de la bordure en pixels.
        //! \param alignment L'alignement du texte. Par défaut, l'alignement 
        //! est à la base gauche.
        Text(std::string const & text, float textSize, Vect2d const& position, Color const fillColor, Color const edgeColor, float edgeSize, Alignment alignment = Alignment::BaseLeft);
        
        //! \cond PRIVATE
        Text(Text const& other) = default;
        Text(Text && other) = default;
        Text& operator=(Text const& other) = default;
        Text& operator=(Text && other) = default;
        ~Text() = default;
        //! \endcond

        //!
        //!
        //! \brief Accesseur de la chaîne de caractères.
        //! 
        //! \return Le texte.
        std::string text() const;
        //!
        //!
        //! \brief Accesseur retournant la taille de la chaîne de caractères.
        //! 
        //! \return La taille de l'objet texte.
        float textSize() const;
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

        // to do : textWidth
        // to do : textHeight

        //!
        //!
        //! \brief Mutateur du texte à afficher.
        //!
        //! \param text La nouvelle chaîne de caractères à afficher.
        void setText(std::string const& text);
        //!
        //!
        //! \brief Mutateur du texte à afficher en tant que nombre entier 
        //! non signé.
        //!
        //! \param number Le nombre à convertir en texte et à afficher.
        void setText(size_t number);
        //!
        //!
        //! \brief Mutateur du texte à afficher en tant que nombre entier signé.
        //!
        //! \param number Le nombre à convertir en texte et à afficher.
        void setText(int number);
        //!
        //!
        //! \brief Mutateur du texte à afficher en tant que nombre réel.
        //!
        //! \param number Le nombre à convertir en texte.
        //! \param precision Le nombre de décimales à conserver.
        void setText(float number, size_t precision = 3);
        //!
        //!
        //! \brief Mutateur du texte et sa taille.
        //!
        //! \param text La nouvelle chaîne de caractères à afficher.
        //! \param textSize La nouvelle taille du texte en unités.
        void setText(std::string const& text, float textSize);
        //!
        //!
        //! \brief Mutateur de la taille du texte.
        //!
        //! \param textSize La nouvelle taille du texte en unités.
        void setTextSize(float textSize);
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

    private:
        static float const smMinimumTextSize;
        std::string mText;
        float mTextSize;
        Vect2d mPosition;
        Alignment mAlignment;
        Color mFillColor;
        Color mEdgeColor;
        float mEdgeSize;
    };

} // namespace ezgame


#endif // _EZGAME_TEXT_H_