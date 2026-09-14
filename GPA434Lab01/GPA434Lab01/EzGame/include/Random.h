#pragma once
#ifndef _EZGAME_RANDOM_H_
#define _EZGAME_RANDOM_H_


// Inclusion des bibliothèques
#include <concepts>
#include <random>
#include <limits>


//! \cond PRIVATE
template <typename T>
concept Enumeration = std::is_enum_v<T>;
//! \endcond


// Déclaration du namespace ezgame
namespace ezgame {


    //! \class Random
    //! 
    //! \brief Classe statique générant des valeurs aléatoires de divers types.
    //!
    //! Cette classe offre une collection de méthodes statiques permettant de 
    //! générer des valeurs aléatoires. Elle est conçue pour être purement 
    //! statique et ne peut donc pas être instanciée. 
    //! 
    //! Les types pouvant être générés sont :
    //!  - booléen `bool`
    //!  - entier `int` (tous les entiers avec leurs variantes de taille et de 
    //!    signe)
    //!  - réel `float` (toutes les tailles de points flottant)
    //!  - enumération `enum` (une énumération quelconque)
    //! 
    //! Les valeurs générées le sont de façon pseudo-aléatoire avec une 
    //! distribution uniforme.
    //! 
    //! Cette classe est générique et n'est pas spécifiquement liée à `EzGame`.
    //! 
    class Random
    {
    public:
        //! cond PRIVATE
        Random() = delete;
        Random(Random const&) = delete;
        Random(Random &&) = delete;
        Random& operator=(Random const&) = delete;
        Random& operator=(Random &&) = delete;
        ~Random() = delete;
        //! endcond

        //! 
        //! 
        //! \brief Génère un booléen selon la probabilité donnée.
        //! 
        //! \details La probabilité correspond au pourcentage d'obtenir 
        //! la valeur vraie. Cette valeur est limitée dans l'intervalle [0, 1].
        //! 
        //! \param probability La probabilité pour laquelle l'évènement est 
        //! vrai. Correspond à un pourcentage déterminé dans l'intervalle [0, 1].
        //! 
        //! \return Un booléen généré aléatoirement.
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un booléen aléatoire avec une probabilité de 50% faux et 50% vrai
        //!     bool myFirstEvent{ Random::event() }; 
        //! 
        //!     // un booléen aléatoire avec une probabilité de 25% faux et 75% vrai
        //!     bool mySecondEvent{ Random::event(0.75f) }; 
        //! \endcode
        static bool event(float probability = 0.5f);
        //!
        //!
        //! \brief Génère un entier selon la plage totale existante pour 
        //! le type spécifié.
        //! 
        //! \details Cette fonction est un `template` non déductible. Ainsi, 
        //! il est obligatoire de fournir le type souhaité.
        //! 
        //! \return La valeur entière générée aléatoirement.
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un nombre aléatoire dans l'intervalle : 
        //!     //  - [-2^31, 2^31 - 1]
        //!     //  - [-2'147'483'648, 2'147'483'647]
        //!     int value0{ Random::integer<int>() }; 
        //!
        //!     // un nombre aléatoire dans l'intervalle : 
        //!     //  - [0, 2^64]
        //!     //  - [0, 18'446'744'073'709'551'615]
        //!     size_t value1{ Random::integer<size_t>() }; 
        //! \endcode
        template <std::integral int_type> static int_type integer();
        //!
        //!
        //! \brief Génère un entier selon la plage [0, maximum].
        //! 
        //! \details Cette fonction est un `template` déductible. Ainsi, 
        //! il n'est pas obligatiore de fournir le type souhaité. 
        //! 
        //! \param maximum La valeur plafond de l'intervalle détermine 
        //! la portée dans laquelle le nombre aléatoire est généré, au 
        //! sein de l'intervalle [0, maximum].
        //! \return La valeur entière générée aléatoirement selon 
        //! l'intervalle [0, maximum].
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un entier aléatoire dans l'intervalle [0, 100]
        //!     int value0{ Random::integer(100) };
        //! 
        //!     // un entier non signé aléatoire dans l'intervalle [0, 1000]
        //!     size_t value1{ Random::integer<size_t>(1000) }; 
        //! \endcode
        template <std::integral int_type> static int_type integer(int_type maximum);
        //!
        //!
        //! \brief Génère un entier selon la plage [minimum, maximum].
        //! 
        //! \details Cette fonction est un `template` déductible. Ainsi, 
        //! il n'est pas obligatoire de fournir le type souhaité (à condition 
        //! d'utiliser le même type pour les deux arguments).
        //! 
        //! \param minimum La valeur plancher de l'intervalle détermine 
        //! la portée dans laquelle le nombre aléatoire est généré, au 
        //! sein de l'intervalle [minimum, maximum].
        //! \param maximum La valeur plafond de l'intervalle détermine 
        //! la portée dans laquelle le nombre aléatoire est généré, au 
        //! sein de l'intervalle [minimum, maximum].
        //! \return La valeur entière générée aléatoirement selon 
        //! l'intervalle [minimum, maximum].
        //!
        //! Exemple d'utilisation :
        //! \code 
        //!     // un entier aléatoire dans l'intervalle [-100, 100]
        //!     int value0{ Random::integer(-100, 100) };
        //! 
        //!     // un entier non signé aléatoire dans l'intervalle [100, 200]
        //!     size_t value1{ Random::integer<size_t>(100, 200) }; 
        //! \endcode
        template <std::integral int_type> static int_type integer(int_type minimum, int_type maximum);
        //!
        //!
        //! \brief Génère un réel selon la plage [0, 1].
        //! 
        //! \details Cette fonction est un `template` non déductible. Ainsi, 
        //! il est obligatiore de fournir le type souhaité. 
        //! 
        //! \return La valeur réelle générée aléatoirement selon 
        //! l'intervalle [0, 1].
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un nombre aléatoire dans l'interval [0, 1]
        //!     float value0{ Random::real<float>() }; 
        //!
        //!     // un nombre aléatoire dans l'interval [0, 1]
        //!     double value1{ Random::real<double>() }; 
        //! \endcode
        template <std::floating_point real_type> static real_type real();
        //!
        //!
        //! \brief Génère un réel selon la plage [0, maximum].
        //! 
        //! \details Cette fonction est un `template` déductible. Ainsi, 
        //! il n'est pas obligatiore de fournir le type souhaité. 
        //! 
        //! \param maximum La valeur plafond de l'intervalle détermine 
        //! la portée dans laquelle le nombre aléatoire est généré, au 
        //! sein de l'intervalle [0, maximum].
        //! \return La valeur réelle générée aléatoirement selon 
        //! l'intervalle [0, maximum].
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un réel aléatoire dans l'interval [0, 100]
        //!     float value0{ Random::real(100.0f) };
        //! 
        //!     // un entier non signé aléatoire dans l'interval [0, 1000]
        //!     double value1{ Random::real<double>(-10.0, 0.0) }; 
        //! \endcode
        template <std::floating_point real_type> static real_type real(real_type maximum);
        //!
        //!
        //! \brief Génère un réel selon la plage [minimum, maximum].
        //! 
        //! \details Cette fonction est un `template` déductible. Ainsi, 
        //! il n'est pas obligatoire de fournir le type souhaité (à condition 
        //! d'utiliser le même type pour les deux arguments).
        //! 
        //! \param minimum La valeur plancher de l'intervalle détermine 
        //! la portée dans laquelle le nombre aléatoire est généré, au 
        //! sein de l'intervalle [minimum, maximum].
        //! \param maximum La valeur plafond de l'intervalle détermine 
        //! la portée dans laquelle le nombre aléatoire est généré, au 
        //! sein de l'intervalle [minimum, maximum].
        //! \return La valeur réelle générée aléatoirement selon 
        //! l'intervalle [minimum, maximum].
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un réel aléatoire dans l'interval [-100.0f, 100.0f]
        //!     float value0{ Random::real(-100.0f, 100.0f) };
        //! 
        //!     // un réel aléatoire dans l'interval [-1000.0, -500.0]
        //!     double value1{ Random::real(-1000.0, -500.0) }; 
        //! \endcode
        template <std::floating_point real_type> static real_type real(real_type minimum, real_type maximum);
        //!
        //!
        //! \brief Génère un énumérateur parmi ceux donnés.
        //! 
        //! \details Cette fonction est un `template` déductible. Ainsi, 
        //! il n'est pas nécessaire de fournir le type souhaité. Toutefois, 
        //! il est essentiel que tous les énumérateurs soient du même type 
        //! énuméré.
        //! 
        //! \param firstEnumerator Un émumérateur.
        //! \param allOtherEnumerators Un nombre variable d'arguments du même 
        //! type que firstEnumerator.
        //! \return L'énumérateur généré aléatoirement parmi tous ceux passés 
        //! en argument.
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un SwitchState aléatoire
        //!     enum class SwitchState { Off, On };
        //!     SwitchState state{ Random::enumerator(SwitchState::Off, SwitchState::On) };
        //! 
        //!     // un AccessLevel aléatoire
        //!     enum class AccessLevel { Admin, User, Guest };
        //!     AccessLevel level{ Random::enumerator(AccessLevel::Admin, AccessLevel::User, AccessLevel::Guest) }; 
        //! 
        //!     // un jour ouvrable aléatoire parmi mercredi, jeudi ou vendredi uniquement
        //!     enum class WorkDay { Monday, Tuesday, Wednesday, Thursday, Friday };
        //!     WorkDay workDay{ Random::enumerator(WorkDay::Wednesday, WorkDay::Thursday, WorkDay::Friday) };
        //! \endcode
        template <Enumeration enum_type, Enumeration... enum_types>
        static enum_type enumerator(enum_type firstEnumerator, enum_types... allOtherEnumerators);
        //!
        //!
        //! \brief Génère un énumérateur entre le premier défini et le 
        //! _compte_-ième donné.
        //! 
        //! \details Cette fonction est un `template` non déductible. Ainsi, 
        //! est est obligatoire de fournir le type énuméré souhaité. 
        //! 
        //! Cette fonction ne fonctionne que pour les énumérations 
        //! où tous les énumérateurs sont défini entre 0 et enumeratorCount - 1.
        //! 
        //! \param enumeratorCount Le nombre d'énumérateur existants pour 
        //! cette énumération. Attention, il faut que tous les énumérateurs 
        //! soient définis de 0 à enumeratorCount - 1.
        //! \return L'énumérateur généré aléatoirement parmi tous ceux passés 
        //! en argument.
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un SwitchState aléatoire
        //!     enum class SwitchState { Off, On };
        //!     SwitchState state{ Random::enumerator<SwitchState>(2) };
        //! 
        //!     // un AccessLevel aléatoire
        //!     enum class AccessLevel { Admin, User, Guest };
        //!     AccessLevel level{ Random::enumerator<AccessLevel>(3) };
        //! \endcode
        template <Enumeration enum_type>
        static enum_type enumerator(size_t enumeratorCount);
        //!
        //!
        //! \brief Génère un énumérateur.
        //! 
        //! \details Cette fonction est un `template` déductible. Ainsi, 
        //! il n'est pas nécessaire de fournir le type souhaité.
        //! 
        //! Cette fonction ne fonctionne que pour les énumérations 
        //! où tous les énumérateurs sont défini entre 0 et n - 1.
        //! 
        //! \param lastEnumerator Le dernier énumérateur défini.
        //! \param lastIsCountEnumerator Détermine sur le dernier 
        //! énumérateur n'est qu'un énumérateur technique de compte 
        //! (généralement appelé `_count_` ou similairement).
        //! \return L'énumérateur généré aléatoirement parmi ceux précisés.
        //! 
        //! Exemple d'utilisation :
        //! \code 
        //!     // un SwitchState aléatoire
        //!     enum class SwitchState { Off, On };
        //!     SwitchState state{ Random::enumerator(SwitchState::On) };
        //! 
        //!     // deux AccessLevel aléatoires
        //!     enum class AccessLevel { Admin, User, Guest, __count__ };
        //!     AccessLevel level0{ Random::enumerator(AccessLevel::Guest, false) };
        //!     AccessLevel level1{ Random::enumerator(AccessLevel::__count__, true) };
        //! \endcode
        template <Enumeration enum_type>
        static enum_type enumerator(enum_type lastEnumerator, bool lastIsCountEnumerator = false);

    private:
        static std::default_random_engine smEngine;
    };










    
    //! \cond PRIVATE
    template<std::integral int_type>
    inline int_type Random::integer() {
        return integer(std::numeric_limits<int_type>::min(), std::numeric_limits<int_type>::max());
    }

    template<std::integral int_type>
    inline int_type Random::integer(int_type maximum) {
        return integer(int_type{}, maximum);
    }

    template<std::integral int_type>
    inline int_type Random::integer(int_type minimum, int_type maximum) {
        return std::uniform_int_distribution<int_type>(minimum, maximum)(smEngine);
    }

    template<std::floating_point real_type>
    inline real_type Random::real() {
        return real<real_type>(real_type{}, real_type{ 1.0 });
    }

    template<std::floating_point real_type>
    inline real_type Random::real(real_type maximum) {
        return real(real_type{}, maximum);
    }

    template<std::floating_point real_type>
    inline real_type Random::real(real_type minimum, real_type maximum) {
        return std::uniform_real_distribution<real_type>(minimum, maximum)(smEngine);
    }

    template<Enumeration enum_type, Enumeration ...enum_types>
    inline enum_type Random::enumerator(enum_type firstEnumerator, enum_types ...allOtherEnumerators)
    {
        std::initializer_list<enum_type> values({ firstEnumerator, allOtherEnumerators... });
        std::uniform_int_distribution<std::size_t> distribution(0, values.size() - 1);
        return *(values.begin() + distribution(smEngine));
    }

    template<Enumeration enum_type>
    inline enum_type Random::enumerator(size_t enumeratorCount) {
        std::uniform_int_distribution<std::size_t> distribution(0, enumeratorCount - 1);
        return static_cast<enum_type>(distribution(smEngine));
    }

    template<Enumeration enum_type>
    inline enum_type Random::enumerator(enum_type lastEnumerator, bool lastIsCountEnumerator) {
        return enumerator<enum_type>(static_cast<size_t>(lastEnumerator) + (lastIsCountEnumerator ? 1 : 0));
    }
    //! \endcond

} // namespace ezgame


#endif // _EZGAME_RANDOM_H_