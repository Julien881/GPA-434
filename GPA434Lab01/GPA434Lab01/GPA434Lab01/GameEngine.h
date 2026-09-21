#pragma once
#include <EzGame>
#include "Arena.h"
#include "Dome.h"

namespace ArenaConfig //Paramètre de l'arène
{
    constexpr float width {750.0f};
    constexpr float height{500.0f};
}

class GameEngine {
public:
    GameEngine()
        : mText("EzGame", 36.0f, ezgame::Vect2d(400.0f, 100.0f), ezgame::Color(0.15f, 0.25f, 1.0f), ezgame::Alignment::CenterCenter)
        , mCircle(50.0f, ezgame::Vect2d(400.0f, 300.0f), ezgame::Color::Yellow, ezgame::Color::Red, 5.0f)
        , gameArena(ArenaConfig::width, ArenaConfig::height)
        , gameDome(gameArena)
    { 
    }

    // Les 6 fonctions répondant aux exigences du concept de GameEngine
    float width() const;
    float height() const;
    std::string title() const;
    std::string iconFileName()const;
    bool processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer);                                                            
    void processDisplay(ezgame::Screen& screen);
    
private:

    ezgame::Text mText;
    ezgame::Circle mCircle;
    Arena gameArena; 
    Dome gameDome;

    bool isAppStillRunning(ezgame::Keyboard const& keyboard);

};