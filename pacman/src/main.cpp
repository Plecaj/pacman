#ifndef PLATFORM_WINDOWS 
#include <iostream>
int main() {
    std::cout << "Game only supports Windows" << std::endl;
}
#endif

#include "core/game.h"

int main() {
    Game game;
    game.run();
}
