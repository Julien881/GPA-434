#pragma once
#ifndef _EZGAME_TIMER_H_
#define _EZGAME_TIMER_H_


// Inclusion des bibliothèques
#include <cstdint>
#include <memory>


// Déclaration du namespace ezgame
namespace ezgame {

    //! \class Timer
    //! 
    //! \brief Classe utilitaire donnant accès à des métriques de temps écoulé.
    //! 
    //! \details Cette classe donne un accès facile :
    //!  - au temps écoulé :
    //!    - depuis le démarrage de l'application
    //!    - depuis le dernier tic
    //!  - en :
    //!    - milliseconde (un nombre entier de 64 bits)
    //!    - seconde (un nombre réel de 32 bits)
    //!  - une estimation du nombre de tics par seconde.
    //!
    class Timer
    {
    public:
        //!
        //!
        //! \brief Retourne le temps écoulé depuis le dernier tic en 
        //! microseconde.
        //! 
        //! \details Le temps écoulé est calculé entre chaque appel 
        //! de la fonction `processEvents`.
        //! 
        //! \return Le temps écoulé depuis le dernier tic.
        int64_t sinceLastTic() const;
        //!
        //!
        //! \brief Retourne le temps écoulé depuis le démarrage de 
        //! l'application en microseconde.
        //! 
        //! \details Le temps donné est celui depuis la création de 
        //! l'application (objet Application) et non depuis l'appel de 
        //! la fonction Application::run.
        //! 
        //! \return Le temps écoulé depuis la création de l'application.
        int64_t sinceStartup() const;
        //!
        //!
        //! \brief Retourne le temps écoulé depuis le dernier tic en 
        //! seconde. 
        //! 
        //! \details Le temps écoulé est calculé entre chaque appel 
        //! de la fonction `processEvents`.
        //!
        //! Attention, la conversion en nombre réel engendre 
        //! une perte de précision.
        //! 
        //! \return Le temps écoulé depuis le dernier tic (approximation).
        float secondSinceLastTic() const;
        //!
        //!
        //! \brief Retourne le temps écoulé depuis le démarrage de 
        //! l'application en seconde.
        //! 
        //! \details Le temps donné est celui depuis la création de 
        //! l'application (objet Application) et non depuis l'appel de 
        //! la fonction Application::run.
        //! 
        //! Attention, la conversion en nombre réel engendre 
        //! une perte de précision.
        //! 
        //! \return Le temps écoulé depuis la création de l'application 
        //! (approximation).
        float secondSinceStartup() const;
        //!
        //!
        //! \brief Retourne une estimation du nombre de tic par 
        //! seconde moyen (_frame per second_).
        //! 
        //! \details Attention, l'estimation est basée sur une moyenne du temps
        //! écoulé entre chacun des _n_ derniers tics. Ainsi, les _n_ 
        //! premières évaluations sont approximatives et biaisées. 
        //! 
        //! La valeur _n_ est par défaut 1000.
        //! 
        //! \return Une estimation du nombre de tic par seconde.
        float fpsEstimation() const;

    private:
        Timer(size_t framesUsedForFPS = 1000);
        Timer(Timer const &) = delete;
        Timer(Timer &&) = delete;
        Timer& operator=(Timer const &) = delete;
        Timer& operator=(Timer &&) = delete;
        ~Timer();

        friend class Application;

        struct Impl;
        std::unique_ptr<Impl> mImpl;

        void tic();
    };

} // namespace ezgame

#endif // _EZGAME_TIMER_H_