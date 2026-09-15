#include <EzGame>
#include "GameEngine.h"


// Point d'entrée du programme
int WinMain()
{
    ezgame::Application app;    // < instantiation d'objet de la classe ezgame::Application
    app.run<GameEngine>();      // < exécution de la fonction run -> démarre la boucle principale

    return 0;
}