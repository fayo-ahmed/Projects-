#include "Game.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL)); // Seed the random number generator

    Game game;
    game.start();

    return 0;
}