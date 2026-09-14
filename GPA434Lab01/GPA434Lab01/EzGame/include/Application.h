#pragma once
#ifndef _EZGAME_APPLICATION_H_
#define _EZGAME_APPLICATION_H_


// Inclusion des bibliothèques
#include <memory>
#include <string>
#include <functional>


//! \brief Le namespace ezgame réuni l'ensemble de la librairie EzGame.
namespace ezgame {

    class Screen;
    class Timer;
    class Keyboard;

    //! \concept GameEngineRequirements
    //!
    //! \brief Ce concept vérifie qu'une classe satisfait aux exigences 
    //! nécessaires afin de servir de moteur de jeu pour la bibliothèque 
    //! `EzGame`.
    //! 
    //! \tparam T Le type que le concept évalue.
    //! 
    //! \details 
    //! 
    //! La fonction ezgame::Application::run démarre la boucle principale 
    //! et exécute le moteur de jeu. Afin de rester générique et de pouvoir 
    //! exécuter n'importe quel moteur de jeu, on passe à cette fonction la 
    //! classe en tant que paramètre `template`. Ce paramètre doit toutefois 
    //! correspondre à l'interface de programmation attendue et ce concept 
    //! détermine les exigences minimum attendues.
    //! 
    //! Les exigences sont que la classe T possède :
    //! - les opérations en lecture seule suivantes :
    //!   - `float width() const` : fonction retournant la taille horizontale de la surface graphique.
    //!   - `float height() const` : fonction retournant la taille verticale de la surface graphique.
    //!   - `string title() const` : fonction retournant le titre de la fenêtre graphique.
    //!   - `string iconFileName() const` : fonction retournant le nom du fichier de l'icône de la fenêtre graphique (dossier relatif et nom de fichier complet).
    //! - les opérations en lecture et écriture suivantes :
    //!   - `bool processEvents(Keyboard const& keyboard, Timer const& timer)` : fonction servant faire le traitement de chaque pas de simulation. Lorsque la fonction retourne faux, l'application termine immédiatement.
    //!   - `void processDisplay(Screen & screen)` : fonction servant à redessiner la fenêtre graphique à chaque pas de simulation.
    //! 
    //! Pour être considéré compatibles, il est essentiel que les critères 
    //! suivants soient **strictement identiques** pour chaque fonction:
    //!  - le nom
    //!  - la signature (incluant les `&` et `const` - ne pas oublié que la 
    //!    mention `const` de fin de fonction fait partie de la signature)
    //!  - le type de retour
    //! 
    //! \cond PRIVATE
    template<typename T>
    concept GameEngineRequirements = requires(T ge, T const gec, ezgame::Keyboard const& k, ezgame::Timer const& t, ezgame::Screen & s) {
        { gec.width() } -> std::same_as<float>;
        { gec.height() } -> std::same_as<float>;
        { gec.title() } -> std::same_as<std::string>;
        { gec.iconFileName() } -> std::same_as<std::string>;
        { ge.processEvents(k, t) } -> std::same_as<bool>;
        { ge.processDisplay(s) } -> std::same_as<void>;
    };
    //! \endcond
        

    //! \class Application
    //! 
    //! \brief Constitue l'application elle-même. 
    //!
    //! \details La classe Application est au coeur de la 
    //! bibliothèque `EzGame` et simplifie le développement en faisant 
    //! la gestion :
    //!  - des messages de `Windows`
    //!  - de la fenêtre de l'application
    //!  - de l'affichage de la surface graphique
    //!  - du clavier
    //!  - du temps écoulé
    //!  - de la boucle principale en faisant les appels nécessaires
    //! 
    //! La classe repose sur l'appel de la fonction Application::run qui 
    //! implémente la boucle principale du programme. Cette boucle est 
    //! basée sur deux fonctions appelées en boucle l'une après l'autre. 
    //! Cette boucle permet de rendre l'application interactive. Ces 
    //! fonctions ont des rôles précis et sont appelées à chaque pas de 
    //! simulation :
    //!  1. Application::processEvents : mettre à jour le modèle 
    //! (considérant les entrées du clavier et le temps écoulé)
    //!  2. Application::processDisplay : mettre à jour l'affichage
    //!
    //! Pour exécuter une application `EzGame` il suffit de créer un objet 
    //! de la classe Application et d'appeler la fonction Application::run 
    //! afin de démarrer l'application graphique. 
    //!
    //! Voici un exemple de code minimal où le moteur de jeu est donné :
    //! 
    //! \code
    //! 
    //! #include <EzGame>
    //! #include "MyAwesomeGameEngine.h" // <<< le moteur de jeu
    //! 
    //! int WinMain()
    //! {
    //!     Application app;
    //!     app.run<MyAwesomeGameEngine>();
    //!     //      ^-- ici on suppose que la classe MyAwesomeGameEngine 
    //!     // répond à toutes les exigences du concept GameEngineRequirements
    //! 
    //!     return 0;
    //! }
    //! \endcode
    //! 
    //! On remarque que le programme utilise la fonction `WinMain` plutôt que 
    //! la fonction `main` comme point d'entrée du programme.
    //! 
    class Application
    {
    public:
        // Constructeurs et destructeur
        //! \brief Constructeur par défaut.
        Application();
        //!
        //! \cond PRIVATE
        Application(Application const&) = delete;
        Application(Application &&) = delete;
        Application& operator=(Application const&) = delete;
        Application& operator=(Application &&) = delete;
        //! \endcond
        //!
        //! \brief Destructeur.
        ~Application(); 
        //!
        //!
        // Accesseurs
        // 
        //! \brief Accesseur retournant la largeur de la surface graphique. 
        //! 
        //! \details La surface graphique est initialisée lors de l'appel de 
        //! la fonction Application::run. 
        //! 
        //! Si cette fonction n'a pas été exécutée, la valeur est 0. 
        //! D'ailleurs, la valeur 0 indique que l'application n'a pas été 
        //! initialisée.
        //! 
        //! À l'appel de la fonction Application::run, la valeur obtenue par 
        //! le `GameEngine` est bornée dans l'intervalle [64, 2048].
        //! 
        //! \return La dimension horizontale de la surface graphique.
        size_t width() const;
        //!
        //!
        //! \brief Accesseur retournant la hauteur de la surface graphique.
        //! 
        //! \details La surface graphique est initialisée lors de l'appel de 
        //! la fonction Application::run. 
        //! 
        //! Si cette fonction n'a pas été exécutée, la valeur est 0. 
        //! D'ailleurs, la valeur 0 indique que l'application n'a pas été 
        //! initialisée.
        //! 
        //! À l'appel de la fonction Application::run, la valeur obtenue par 
        //! le `GameEngine` est bornée dans l'intervalle [64, 2048].
        //! 
        //! \return La dimension verticale de la surface graphique.
        size_t height() const;
        //!
        //! 
        //! \brief Accesseur retournant le titre de la fenêtre.
        //! 
        //! \details L'application est initialisée lors de l'appel de la 
        //! fonction Application::run. 
        //! 
        //! Si cette fonction n'a pas été exécutée, la valeur par défaut est 
        //! la chaîne de caractères `"EzGame"`. 
        //! 
        //! À l'appel de la fonction Application::run, si la chaîne de 
        //! caractères obtenue par le `GameEngine` est vide, la valeur est 
        //! celle par défaut : `"EzGame"`.
        //! 
        //! \return Le titre de l'application.
        std::string title() const;
        //!
        //! 
        //! \brief Accesseur retournant le nom du fichier image utilisé pour 
        //! l'icône de l'application.
        //! 
        //! \details L'application est initialisée lors de l'appel de la 
        //! fonction Application::run. 
        //! 
        //! La chaîne de caractères peut inclure en préfixe le chemin relatif 
        //! du fichier selon le dossier d'exécution courant (`CWD` - 
        //! _Current Wirking Directory_). Si le fichier n'est pas accessible au 
        //! démarrage da l'application, l'icône par défaut de `Windows` est 
        //! affichée.
        //! 
        //! Si cette fonction n'a pas été exécutée, la valeur par défaut est 
        //! la chaîne de caractères `"EzGameLogoMedium.png"`. 
        //! 
        //! À l'appel de la fonction Application::run, si la chaîne de 
        //! caractères obtenue par le `GameEngine` est vide, la valeur est 
        //! celle par défaut : `"EzGameLogoMedium.png"`.
        //! 
        //! \return le nom du fichier image utilisé pour l'icône de 
        //! l'application.
        std::string iconFileName() const;
        //! 
        //! 
        // Fonction utilitaire
        // 
        //! \brief Exécute l'application en utilisant le moteur donné en 
        //! argument `template`.
        //! 
        //! \details L'appel de cette fonction lance l'exécution formelle du 
        //! programme. C'est elle qui initialise l'application :
        //! - taille de la surface graphique
        //! - titre et icône de l'application 
        //! 
        //! Cette fonction constitue la boucle principale du programme. Elle 
        //! est bloquante tant que la boucle n'est pas terminée. La fin de 
        //! son exécution dépend de la valeur de retour de la fonction 
        //! `processEvents` (voir les détails plus bas).
        //! 
        //! Cette fonction est une fonction `template` nécessitant une classe 
        //! répondant au concept ezgame::GameEngineRequirements. Un `template` 
        //! permet de passer une classe et non un objet à titre d'argument. Ce 
        //! type de passage se fait entre chevrons `<...>` et non entre 
        //! parenthèses `(...)`. 
        //! 
        //! Vous devez absolument consulter la documentation du concept 
        //! ezgame::GameEngineRequirements pour comprendre quels sont les 
        //! éléments attendus du moteur de jeu.
        //! 
        //! Finalement, il est important de comprendre que l'application tourne 
        //! en boucle et appel indéfiniment les deux fonctions obligatoires :
        //! - `processEvents`
        //! - `processDisplay`
        //! 
        //! La valeur retournée par la fonction `processEvents` détermine la 
        //! fin de la boucle : 
        //!  - si vrai : poursuit l'exécution normale du programme
        //!  - si faux : l'application termine immédiatement et abruptement
        //! 
        //! Ainsi, le corps du programme se résume à :
        //! \verbatim
        //
        //          Application app;
        //          app.run<GameEngine>()
        //          [ start ]>──────────-┐
        //                               │
        //                               │
        //              ┌────────────────V────────────────┐
        //              │ initialisation de l'application │
        //              │        par le GameEngine        │
        //              └────────────────V────────────────┘
        //                               │
        //                               │
        //          ┌─[ while ]───────────────────────────────┐
        //          │                    │                    │
        //          │           ┌────────V────────┐           │
        //          │       ┌───>  processEvents  │           │
        //          │       │   └────────V────────┘           │
        //          │       │            │                    │
        //          │       │            V                    │
        //          │       │           _^_                   │
        //          │       │        _-'   '-_  faux          │
        //          │       │       <         >───────────────│─────>[ out ]
        //          │       │        '-_   _-'                │
        //          │       │           'v'                   │
        //          │       │       vrai │                    │
        //          │       │            │                    │
        //          │       │   ┌────────V────────┐           │
        //          │       │   | processDisplay  |           │
        //          │       │   └────────V────────┘           │
        //          │       │            │                    │
        //          │       └────────────┘                    │
        //          │                                         │
        //          └─────────────────────────────────────────┘
        //
        // \endverbatim
        //! 
        //! 
        //! 
        //! \tparam GE La classe représentant le moteur de jeu. Cette classe 
        //! doit répondre à toutes les exigences du concept 
        //! ezgame::GameEngineRequirements. 
        //! 
        template <GameEngineRequirements GE>
        void run();

    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
        void * w();

        friend class Screen;

        using UpdateModelFunction = bool(Keyboard const&, Timer const&);
        using UpdateViewFunction = void(Screen&);
        void run(std::function<UpdateModelFunction> updateModel, std::function<UpdateViewFunction> updateView);
        void setup(size_t width, size_t height, std::string const & title, std::string const & iconFileName);
    };













    //! \cond PRIVATE
    template <GameEngineRequirements GE>
    inline void Application::run() {
        GE gameEngine;
        setup(static_cast<size_t>(gameEngine.width()), static_cast<size_t>(gameEngine.height()), gameEngine.title(), gameEngine.iconFileName());
        run(std::bind(&GE::processEvents, &gameEngine, std::placeholders::_1, std::placeholders::_2), 
            std::bind(&GE::processDisplay, &gameEngine, std::placeholders::_1));
    }
    //! \endcond



} // namespace ezgame


#endif // _EZGAME_APPLICATION_H_