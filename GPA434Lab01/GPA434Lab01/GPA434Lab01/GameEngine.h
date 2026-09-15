#pragma once
#include <EzGame>

class GameEngine {
public:
    GameEngine()
        : mText("EzGame", 36.0f, ezgame::Vect2d(400.0f, 100.0f), ezgame::Color(0.15f, 0.25f, 1.0f), ezgame::Alignment::CenterCenter)
        , mCircle(50.0f, ezgame::Vect2d(400.0f, 300.0f), ezgame::Color::Yellow, ezgame::Color::Red, 5.0f)
    {
    }

    // Les 6 fonctions répondant aux exigences du concept

    float width() const;
    float height() const;
    std::string title() const;
    std::string iconFileName()const;
    bool processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer);                                                                                  // ----+     |

    void processDisplay(ezgame::Screen& screen);

private:
    ezgame::Text mText;
    ezgame::Circle mCircle;

};