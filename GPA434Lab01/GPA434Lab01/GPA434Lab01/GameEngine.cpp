#include <Keyboard.h>
#include "GameEngine.h"


// Les 6 fonctions répondant aux exigences du concept
float GameEngine::width()const { return gameArena.width();}
float GameEngine::height()const { return gameArena.height();}
std::string GameEngine::title()const { return "EzGame demo"; }
std::string GameEngine::iconFileName()const { return ""; }

bool GameEngine::processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer) {
    
    gameArena.Center();//à enlever 
    float small = gameArena.smallerSize();//à enlever
    ezgame::Vect2d testPos (700,600);//à enlever
    ezgame::Vect2d validPos = gameArena.restrictedPosition(testPos);//à enlever
    ezgame::Vect2d warpedPos = gameArena.warpedPosition(testPos);//à enlever

    float radius = gameDome.radius(); // à enlever
    ezgame::Vect2d positon = gameDome.position();// à enlever
    ezgame::Circle cercle = gameDome.circle();// à enlever
    ezgame::Color couleur = gameDome.color();// à enlever
    gameDome.setColors(ezgame::Color::Yellow);



    return GameEngine::isAppStillRunning(keyboard);
}

void GameEngine::processDisplay(ezgame::Screen& screen) {
    gameArena.draw(screen);
    gameDome.draw(screen);
}

bool GameEngine::isAppStillRunning(ezgame::Keyboard const& keyboard) {
    return !(keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape));
 }

