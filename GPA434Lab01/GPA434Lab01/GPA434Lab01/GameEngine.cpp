#include "GameEngine.h"

// Les 6 fonctions répondant aux exigences du concept

float GameEngine::width()const { return 800.0f; }
float GameEngine::height()const { return 600.0f; }
std::string GameEngine::title()const { return "EzGame demo"; }
std::string GameEngine::iconFileName()const { return ""; }

bool GameEngine::processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer) {
    if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Space)) {
        mCircle.move(ezgame::Vect2d::fromRandomized() * 2.5f);
    }
    return !keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape);
}

void GameEngine::processDisplay(ezgame::Screen& screen) {
    screen.clear();
    screen.draw(mText);
    screen.draw(mCircle);
}