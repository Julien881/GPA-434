#pragma once
#ifndef _EZGAME_COLOR_H_
#define _EZGAME_COLOR_H_


// Déclaration du namespace ezgame
namespace ezgame {

    //! \class Color
    //! 
    //! \brief Classe représentant une couleur.
    //! 
    //! \details La représentation d'une couleur est :
    //!  - dans l'espace `RGBA`
    //!     - `R -> red ->` rouge
    //!     - `G -> green ->` vert
    //!     - `B -> blue ->` bleu
    //!     - `A -> alpha ->` opacité
    //!  - chacune des bandes est :
    //!     - représentée par un réel de type `float`
    //!     - normalisée (dans l'intervalle [0.0, 1.0])
    //!     - où `0.0f` implique aucun et `1.0f` veut dire tout, par exemple :
    //!       <br> `(1, 0.5, 0)` indique tout le rouge, la moitié du vert et aucun bleu 
    //!       <br> ce qui donne la couleur orange
    //! 
    //! Cette classe fournit des méthodes pour :
    //!  - manipuler les couleurs dans les espaces colorimétriques RGB, HSV et HSL 
    //!  - mélanger des couleurs
    //!  - assombrir et éclaircir
    //!  - définir aléatoirement (selon une distribution uniforme)
    //! 
    //! Quelques couleurs sont prédéfénies :
    //!  - <span style = "background-color: #00000000; border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Transparent _transparent_
    //!  - <span style = "background-color: #00000000; border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::NoColor _synonyme de transparent_
    //!  - <span style = "background-color: #000000;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Black _noir_
    //!  - <span style = "background-color: #FF0000;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Red _rouge_
    //!  - <span style = "background-color: #00FF00;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Green _vert_
    //!  - <span style = "background-color: #0000FF;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Blue _bleu_
    //!  - <span style = "background-color: #FFFF00;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Yellow _jaune_
    //!  - <span style = "background-color: #00FFFF;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Cyan _cyan_
    //!  - <span style = "background-color: #FF00FF;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Magenta _magenta_
    //!  - <span style = "background-color: #FFFFFF;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::White _blanc_
    //!  - <span style = "background-color: #FF8000;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Orange _orange_
    //!  - <span style = "background-color: #80FF00;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Lime _lime_
    //!  - <span style = "background-color: #FF0080;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Fuchsia _fuchsia_
    //!  - <span style = "background-color: #8000FF;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Violet _violet_
    //!  - <span style = "background-color: #00FF80;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Aqua _aqua_
    //!  - <span style = "background-color: #0080FF;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Sky _ciel_
    //!  - <span style = "background-color: #404040;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::DarkGray _gris foncé_
    //!  - <span style = "background-color: #808080;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::Gray _gris moyen_
    //!  - <span style = "background-color: #C0C0C0;   border: 2px solid #444444; height: 1.2em; width: 1em; display: inline-block; vertical-align: top;"></span> Color::LightGray _gris clair_
    //! 
    //! 
    //! 
    //! Cette classe est organisée de façon à contenir et maintenir 
    //! exclusivement les valeurs rouge, vert, bleu et alpha de l'espace 
    //! colorimétrique RGB. Les valeurs des autres espaces colorimétriques 
    //! sont calculées au besoin. 
    //! 
    //! L'alignement en mémoire est :
    //!  - 4 réels représentés par des `float`
    //!  - 4 x 32 bits ou 4 x 4 octets
    //!  - pour un total de 128 bits ou 16 octets <br>
    //! \code 
    //!     [    Color     ]
    //!     ----------------
    //!     [R ][G ][B ][A ]
    //!     [32][32][32][32]
    //!     [<----128----->]
    //! \endcode
    //! 
    class Color
    {
    public:
        //! \brief Constructeur par défaut. 
        //! 
        //! \details Initialise un objet Color en noir avec une opacité 
        //! complète.
        Color();
        //! 
        //! \brief Constructeur avec initialisation. 
        //! 
        //! \details Initialise un objet Color avec les valeurs RGBA spécifiées.
        //! 
        //! \param red Composante rouge [0.0, 1.0]
        //! \param green Composante verte [0.0, 1.0]
        //! \param blue Composante bleue [0.0, 1.0]
        //! \param alpha Composante alpha [0.0, 1.0], par défaut à 1.0 (opaque)
        Color(float red, float green, float blue, float alpha = 1.0);
        //! 
        //! \brief Destructeur.
        ~Color() = default;

        //! \cond PRIVATE
        Color(Color const& color) = default;
        Color(Color && color) = default;
        Color& operator=(Color const& color) = default;
        Color& operator=(Color && color) = default;
        //! \endcond

        //! 
        //! 
        //! \brief Accesseur retournant la composante rouge.
        //! 
        //! \return Le niveau de rouge [0.0, 1.0].
        float red() const;
        //!
        //!
        //! \brief Accesseur retournant la composante verte.
        //! 
        //! \return Le niveau de vert [0.0, 1.0].
        float green() const;
        //!
        //!
        //! \brief Accesseur retournant la composante bleue.
        //! 
        //! \return Le niveau de vert [0.0, 1.0].
        float blue() const;
        //!
        //!
        //! \brief Accesseur retournant la composante alpha.
        //! 
        //! \return Le niveau d'alpha [0.0, 1.0].
        float alpha() const;
        //! 
        //! 
        //! \brief Accesseur retournant la composante de teinte dans l'espace 
        //! colorimétrique HSL.
        //! 
        //! \return La composante de teinte en HSL [0.0, 1.0].
        float hslHue() const;
        //! 
        //! 
        //! \brief Accesseur retournant la composante de saturation dans 
        //! l'espace colorimétrique HSL.
        //! 
        //! \return La composante de saturation en HSL [0.0, 1.0].
        float hslSaturation() const;
        //! 
        //! 
        //! \brief Accesseur retournant la composante de luminosité dans 
        //! l'espace colorimétrique HSL.
        //! 
        //! \return La composante de luminosité en HSL [0.0, 1.0].
        float hslLightness() const;
        //! 
        //! 
        //! \brief Obtient les composantes de teinte, de saturation et de 
        //! luminosité de l'espace colorimétrique HSL.
        //! 
        //! \details Cette fonction rempli les valeurs des paramètres avec 
        //! les composantes de teinte, de saturation et de luminosité de la 
        //! couleur.
        //! 
        //! \param hue Référence à une variable `float` pour stocker la teinte 
        //! [0.0, 1.0].
        //! \param saturation Référence à une variable `float` pour stocker la 
        //! saturation [0.0, 1.0].
        //! \param lightness Référence à une variable `float` pour stocker la 
        //! luminosité [0.0, 1.0].
        //! 
        //! \code 
        //!     Color myColor(1.0f, 0.5f, 0.25f);
        //!     float hue, saturation, lightness;
        //!     myColor.getHsl(hue, saturation, lightness)
        //!     std::cout << "Teinte     : " << hue << "\n";
        //!     std::cout << "Saturation : " << saturation << "\n";
        //!     std::cout << "Luminosité : " << lightness << "\n";
        //! \endcode
        void getHsl(float& hue, float& saturation, float& lightness) const;
        //! 
        //! 
        //! \brief Accesseur retournant la composante de teinte dans l'espace 
        //! colorimétrique HSV.
        //! 
        //! \return La composante de teinte en HSV [0.0, 1.0].
        float hsvHue() const;
        //! 
        //! 
        //! \brief Accesseur retournant la composante de saturation dans 
        //! l'espace colorimétrique HSV.
        //! 
        //! \return La composante de saturation en HSV [0.0, 1.0].
        float hsvSaturation() const;
        //! 
        //! 
        //! \brief Accesseur retournant la composante de valeur dans l'espace 
        //! colorimétrique HSV.
        //! 
        //! \return La composante de valeur en HSV [0.0, 1.0].
        float hsvValue() const;
        //! 
        //! 
        //! \brief Obtient les composantes de teinte, de saturation et de 
        //! valeur de l'espace colorimétrique HSV.
        //! 
        //! \details Cette fonction rempli les valeurs des paramètres avec 
        //! les composantes de teinte, de saturation et de valeur de la 
        //! couleur.
        //! 
        //! \param hue Référence à une variable `float` pour stocker la teinte 
        //! [0.0, 1.0].
        //! \param saturation Référence à une variable `float` pour stocker la 
        //! saturation [0.0, 1.0].
        //! \param value Référence à une variable `float` pour stocker la 
        //! valeur [0.0, 1.0].
        //! 
        //! \code 
        //!     Color myColor(1.0f, 0.5f, 0.25f);
        //!     float hue, saturation, value;
        //!     myColor.getHsv(hue, saturation, value)
        //!     std::cout << "Teinte     : " << hue << "\n";
        //!     std::cout << "Saturation : " << saturation << "\n";
        //!     std::cout << "Valeur     : " << value << "\n";
        //! \endcode
        void getHsv(float& hue, float& saturation, float& value) const;
        //!
        //!
        //! \brief Retourne une nouvelle couleur issue du mélange de la 
        //! couleur actuelle et d'une autre couleur.
        //! 
        //! \details Le mélange ce fait avec une proportion de la couleur 
        //! courante et de la couleur spécifiée.
        //! 
        //! \param otherColor La couleur à mélanger à celle-ci.
        //! \param blendFactor Le pourcentage de couleur à préserver. Le 
        //! pourcentage est défini entre 0 et 1 et sera limité à cet 
        //! intervalle. Par exemple, la valeur 0.25 garde 25% de la présente 
        //! couleur et 75% de la couleur donnée.
        //! \param blendAlpha La valeur indiquant si le canal alpha 
        //! doit être mélangé. Si oui, mélange l'opacité. Sinon, la 
        //! valeur alpha reste la même que la couleur courante.
        //! \return La couleur mélangée.
        Color blended(Color const& otherColor, float blendFactor = 0.5, bool blendAlpha = false) const;
        //! 
        //! 
        //! \brief Fonction utilitaire retournant une nouvelle couleur 
        //! correspondant à la couleur courante assombri d'un certain 
        //! facteur.
        //! 
        //! \details L'assombrissement est réalisé en modifiant exclusivement 
        //! la luminosité dans l'espace colorimétrique `HSL`.
        //! 
        //! Le facteur correspond donc au pourcentage pour :
        //! - ne rien changer : 0%
        //! - mettre complètement noir : 100%
        //! 
        //! \param factor Correspond au pourcentage d'assombrissement. Cette 
        //! valeur est limitée dans l'intervalle [0, 1]. 
        //! 
        //! \return La nouvelle couleur assombrie.
        Color darker(float factor = 0.5) const;
        //! 
        //! 
        //! \brief Fonction utilitaire retournant une nouvelle couleur 
        //! correspondant à la couleur courante éclaircie d'un certain 
        //! facteur.
        //! 
        //! \details L'éclaircissement est réalisé en modifiant exclusivement 
        //! la luminosité dans l'espace colorimétrique `HSL`.
        //! 
        //! Le facteur correspond donc au pourcentage pour :
        //! - ne rien changer : 0%
        //! - mettre complètement blanc : 100%
        //! 
        //! \param factor Correspond au pourcentage d'éclaircissement. Cette 
        //! valeur est limitée dans l'intervalle [0, 1]. 
        //! 
        //! \return La nouvelle couleur éclaircie.
        Color lighter(float factor = 0.5) const;
        // to do : saturated
        // to do : desaturated

        //!
        //!
        //! \brief Mutateur définissant la composante rouge.
        //! 
        //! \param red Le niveau de rouge avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setRed(float red);
        //!
        //!
        //! \brief Mutateur définissant la composante verte.
        //! 
        //! \param green Le niveau de vert avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setGreen(float green);
        //!
        //!
        //! \brief Mutateur définissant la composante bleue.
        //! 
        //! \param blue Le niveau de bleu avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setBlue(float blue);
        //!
        //!
        //! \brief Mutateur définissant la composante alpha.
        //! 
        //! \param alpha Le niveau d'opacité avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setAlpha(float alpha);
        //!
        //!
        //! \brief Mutateur définissant les composantes chromatiques de la couleur.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param red Le niveau de rouge.
        //! \param green Le niveau de vert.
        //! \param blue Le niveau de bleu.
        void set(float red, float green, float blue);
        //!
        //!
        //! \brief Mutateur définissant les composantes de la couleur.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param red Le niveau de rouge.
        //! \param green Le niveau de vert.
        //! \param blue Le niveau de bleu.
        //! \param alpha Le niveau d'opacité.
        void set(float red, float green, float blue, float alpha);
        //!
        //!
        //! \brief Mutateur définissant la composante de teinte dans l'espace
        //! colorimétrique `HSL`.
        //! 
        //! \param hue La teinte avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setHslHue(float hue);
        //!
        //!
        //! \brief Mutateur définissant la composante de saturation dans 
        //! l'espace colorimétrique `HSL`.
        //! 
        //! \param saturation Le niveau de saturation avec une valeur normalisée. La 
        //! valeur est limitée à l'intervalle [0.0, 1.0].
        void setHslSaturation(float saturation);
        //!
        //!
        //! \brief Mutateur définissant la composante de luminosité dans 
        //! l'espace colorimétrique `HSL`.
        //! 
        //! \param lightness Le niveau de luminosité avec une valeur normalisée. La 
        //! valeur est limitée à l'intervalle [0.0, 1.0].
        void setHslLightness(float lightness);
        //!
        //!
        //! \brief Mutateur définissant les composantes de teinte, saturation 
        //! et luminosité de l'espace colorimétrique `HSL`.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param hue La teinte.
        //! \param saturation Le niveau de saturation.
        //! \param lightness Le niveau de luminosité.
        void setHsl(float hue, float saturation, float lightness);
        //!
        //!
        //! \brief Mutateur définissant les composantes de teinte, saturation, 
        //! luminosité et alpha de l'espace colorimétrique `HSL`.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param hue La teinte.
        //! \param saturation Le niveau de saturation.
        //! \param lightness Le niveau de luminosité.
        //! \param alpha Le niveau d'opacité.
        void setHsl(float hue, float saturation, float lightness, float alpha);
        //!
        //!
        //! \brief Mutateur définissant la composante de teinte dans l'espace
        //! colorimétrique `HSV`.
        //! 
        //! \param hue La teinte avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setHsvHue(float hue);
        //!
        //!
        //! \brief Mutateur définissant la composante de saturation dans l'espace
        //! colorimétrique `HSV`.
        //! 
        //! \param saturation Le niveau de saturation avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setHsvSaturation(float saturation);
        //!
        //!
        //! \brief Mutateur définissant la composante de valeur dans l'espace
        //! colorimétrique `HSV`.
        //! 
        //! \param value Le niveau de valeur avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setHsvValue(float value);
        //!
        //!
        //! \brief Mutateur définissant les composantes de teinte, saturation 
        //! et valeur de l'espace colorimétrique `HSV`.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param hue La teinte.
        //! \param saturation Le niveau de saturation.
        //! \param value Le niveau de valeur.
        void setHsv(float hue, float saturation, float value);
        //!
        //!
        //! \brief Mutateur définissant les composantes de teinte, saturation, 
        //! valeur et alpha de l'espace colorimétrique `HSV`.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param hue La teinte.
        //! \param saturation Le niveau de saturation.
        //! \param value Le niveau de valeur.
        //! \param alpha Le niveau d'opacité.
        void setHsv(float hue, float saturation, float value, float alpha);
        //!
        //!
        //! \brief Génère une nouvelle couleur à partir de l'espace 
        //! colorimétrique `HSL`.
        //! 
        //! \code
        //!     Color myColor;
        //!     myColor = Color::fromHsl(0.75f, 0.25f, 0.45f);
        //! \endcode
        //! 
        //! \param hue La teinte.
        //! \param saturation Le niveau de saturation.
        //! \param lightness Le niveau de luminosité.
        //! \param alpha Le niveau d'opacité.
        //! \return La couleur produite.
        static Color fromHsl(float hue, float saturation, float lightness, float alpha = 1.0f);
        //!
        //!
        //! \brief Génère une nouvelle couleur à partir de l'espace 
        //! colorimétrique `HSV`.
        //! 
        //! \code
        //!     Color myColor;
        //!     myColor = Color::fromHsv(0.3f, 0.85f, 0.75f, 0.5f);
        //! \endcode
        //! 
        //! \param hue La teinte.
        //! \param saturation Le niveau de saturation.
        //! \param value Le niveau de valeur.
        //! \param alpha Le niveau d'opacité.
        //! \return La couleur produite.
        static Color fromHsv(float hue, float saturation, float value, float alpha = 1.0f);
        //!
        //!
        //! \brief Mélange la couleur actuelle et une autre.
        //! 
        //! \details Le mélange ce fait avec une proportion de la couleur 
        //! courante et de la couleur spécifiée.
        //! 
        //! \param otherColor La couleur à mélanger à celle-ci.
        //! \param blendFactor Le pourcentage de couleur à préserver. Le 
        //! pourcentage est défini entre 0 et 1 et sera limité à cet 
        //! intervalle. Par exemple, la valeur 0.25 garde 25% de la présente 
        //! couleur et 75% de la couleur donnée.
        //! \param blendAlpha La valeur indiquant si le canal alpha 
        //! doit être mélangé. Si oui, mélange l'opacité. Sinon, la 
        //! valeur alpha reste la même que la couleur courante.
        void blend(Color const& otherColor, float blendFactor = 0.5, bool blendAlpha = false);
        //! 
        //! 
        //! \brief Mutateur assombrissant la couleur courante d'un certain 
        //! facteur.
        //! 
        //! \details L'assombrissement est réalisé en modifiant exclusivement 
        //! la luminosité dans l'espace colorimétrique `HSL`.
        //! 
        //! Le facteur correspond donc au pourcentage pour :
        //! - ne rien changer : 0%
        //! - mettre complètement noir : 100%
        //! 
        //! \param factor Correspond au pourcentage d'assombrissement. Cette valeur est limitée dans l'intervalle [0, 1]. 
        void darken(float factor = 0.5);
        //! 
        //! 
        //! \brief Mutateur éclaircissant la couleur d'un certain facteur.
        //! 
        //! \details L'éclaircissement est réalisé en modifiant exclusivement 
        //! la luminosité dans l'espace colorimétrique `HSL`.
        //! 
        //! Le facteur correspond donc au pourcentage pour :
        //! - ne rien changer : 0%
        //! - mettre complètement blanc : 100%
        //! 
        //! \param factor Correspond au pourcentage d'éclaircissement. Cette 
        //! valeur est limitée dans l'intervalle [0, 1]. 
        void lighten(float factor = 0.5);
        // to do : saturate
        // to do : desaturate


        //! 
        //! 
        //! \brief Mutateur réinitialisant aléatoirement la couleur.
        //! 
        //! \param randomizeAlpha Ce paramètre détermine si le canal alpha 
        //! est défini aléatoirement ou non.
        void randomize(bool randomizeAlpha = false);
        //! 
        //! 
        //! \brief Mutateur réinitialisant aléatoirement la couleur via 
        //! l'espace colorimétrique `HSL`.
        //! 
        //! \details Les canaux de teinte, saturation et de luminosité sont 
        //! générés par l'interval spécifié [min, max]. Le canal alpha 
        //! n'est pas modifié.
        //! 
        //! Toutes les valeurs sont limitées a`l'intervalle [1, 0]. 
        //! 
        //! \param hueFrom Début de l'intervalle pour la teinte.
        //! \param hueTo Fin de l'intervalle pour la teinte.
        //! \param saturationFrom Début de l'intervalle pour la saturation.
        //! \param saturationTo Fin de l'intervalle pour la saturation.
        //! \param lightnessFrom Début de l'intervalle pour la luminosité.
        //! \param lightnessTo Fin de l'intervalle pour la luminosité.
        void randomize( float hueFrom, float hueTo, 
                        float saturationFrom = 0.85f, float saturationTo = 1.0f, 
                        float lightnessFrom = 0.45f, float lightnessTo = 0.55f);
        //! 
        //! 
        //! \brief Mutateur réinitialisant aléatoirement la couleur via 
        //! l'espace colorimétrique `HSL`.
        //! 
        //! \details Les canaux de teinte, saturation, luminosité et alpha 
        //! sont générés par l'interval spécifié [min, max].
        //! 
        //! Toutes les valeurs sont limitées a`l'intervalle [1, 0]. 
        //! 
        //! \param hueFrom Début de l'intervalle pour la teinte.
        //! \param hueTo Fin de l'intervalle pour la teinte.
        //! \param saturationFrom Début de l'intervalle pour la saturation.
        //! \param saturationTo Fin de l'intervalle pour la saturation.
        //! \param lightnessFrom Début de l'intervalle pour la luminosité.
        //! \param lightnessTo Fin de l'intervalle pour la luminosité.
        //! \param alphaFrom Début de l'intervalle pour alpha.
        //! \param alphaTo Fin de l'intervalle pour alpha.
        void randomize( float hueFrom, float hueTo, 
                        float saturationFrom, float saturationTo, 
                        float lightnessFrom, float lightnessTo, 
                        float alphaFrom, float alphaTo);
        //! 
        //! 
        //! \brief Fonction utilitaire retournant une couleur aléatoirement 
        //! définie.
        //! 
        //! \param randomizeAlpha Ce paramètre détermine si le canal alpha 
        //! est défini aléatoirement ou non.
        //! \return La couleur définie aléatoirement.
        static Color randomized(bool randomizeAlpha = false);
        //! 
        //! 
        //! \brief Fonction utilitaire retournant une couleur aléatoirement 
        //! définie via l'espace colorimétrique `HSL`.
        //! 
        //! \details Les canaux de teinte, saturation et de luminosité sont 
        //! générés par l'interval spécifié [min, max]. Le canal alpha 
        //! n'est pas modifié.
        //! 
        //! Toutes les valeurs sont limitées a`l'intervalle [1, 0]. 
        //! 
        //! \param hueFrom Début de l'intervalle pour la teinte.
        //! \param hueTo Fin de l'intervalle pour la teinte.
        //! \param saturationFrom Début de l'intervalle pour la saturation.
        //! \param saturationTo Fin de l'intervalle pour la saturation.
        //! \param lightnessFrom Début de l'intervalle pour la luminosité.
        //! \param lightnessTo Fin de l'intervalle pour la luminosité.
        //! \return La couleur définie aléatoirement.
        static Color randomized(float hueFrom, float hueTo,
                                float saturationFrom = 0.85f, float saturationTo = 1.0f, 
                                float lightnessFrom = 0.45f, float lightnessTo = 0.55f);
        //! 
        //! 
        //! \brief Fonction utilitaire retournant une couleur aléatoirement 
        //! définie via l'espace colorimétrique `HSL`.
        //! 
        //! \details Les canaux de teinte, saturation, luminosité et alpha 
        //! sont générés par l'interval spécifié [min, max].
        //! 
        //! Toutes les valeurs sont limitées a`l'intervalle [1, 0]. 
        //! 
        //! \param hueFrom Début de l'intervalle pour la teinte.
        //! \param hueTo Fin de l'intervalle pour la teinte.
        //! \param saturationFrom Début de l'intervalle pour la saturation.
        //! \param saturationTo Fin de l'intervalle pour la saturation.
        //! \param lightnessFrom Début de l'intervalle pour la luminosité.
        //! \param lightnessTo Fin de l'intervalle pour la luminosité.
        //! \param alphaFrom Début de l'intervalle pour alpha.
        //! \param alphaTo Fin de l'intervalle pour alpha.
        //! \return La couleur définie aléatoirement.
        static Color randomized(float hueFrom, float hueTo,
                                float saturationFrom, float saturationTo, 
                                float lightnessFrom, float lightnessTo, 
                                float alphaFrom, float alphaTo);


        static Color const Transparent;     //!< Couleur prédéfinie <span style = "background-color: #00000000; border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _transparent_
        static Color const NoColor;         //!< Couleur prédéfinie <span style = "background-color: #00000000; border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _synonyme de transparent_
        static Color const Black;           //!< Couleur prédéfinie <span style = "background-color: #000000;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _noir_
        static Color const Red;             //!< Couleur prédéfinie <span style = "background-color: #FF0000;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _rouge_
        static Color const Green;           //!< Couleur prédéfinie <span style = "background-color: #00FF00;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _vert_
        static Color const Blue;            //!< Couleur prédéfinie <span style = "background-color: #0000FF;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _bleu_
        static Color const Yellow;          //!< Couleur prédéfinie <span style = "background-color: #FFFF00;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _jaune_
        static Color const Cyan;            //!< Couleur prédéfinie <span style = "background-color: #00FFFF;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _cyan_
        static Color const Magenta;         //!< Couleur prédéfinie <span style = "background-color: #FF00FF;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _magenta_
        static Color const White;           //!< Couleur prédéfinie <span style = "background-color: #FFFFFF;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _blanc_
        static Color const Orange;          //!< Couleur prédéfinie <span style = "background-color: #FF8000;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _orange_
        static Color const Lime;            //!< Couleur prédéfinie <span style = "background-color: #80FF00;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _lime_
        static Color const Fuchsia;         //!< Couleur prédéfinie <span style = "background-color: #FF0080;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _fushia_
        static Color const Violet;          //!< Couleur prédéfinie <span style = "background-color: #8000FF;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _violet_
        static Color const Aqua;            //!< Couleur prédéfinie <span style = "background-color: #00FF80;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _aqua_
        static Color const Sky;             //!< Couleur prédéfinie <span style = "background-color: #0080FF;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _ciel_
        static Color const LightGray;       //!< Couleur prédéfinie <span style = "background-color: #404040;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _gris pâle_
        static Color const Gray;            //!< Couleur prédéfinie <span style = "background-color: #808080;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _gris moyen_
        static Color const DarkGray;        //!< Couleur prédéfinie <span style = "background-color: #C0C0C0;   border: 2px solid #444444; height: 1.2em; width: 3em; display: inline-block; vertical-align: top;"></span> _gris foncé_
        static Color gray(float level = 0.5); //!< Retourne une couleur du niveau de gris spécifié : [level, level, level, 1.0]

    private:
        float mRed;
        float mGreen;
        float mBlue;
        float mAlpha;

        static float clamp(float value);
        static float hslHueToRGB(float p, float q, float t);
    };

} // namespace ezgame



#endif // _EZGAME_COLOR_H_