#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Scheduler.h"

class Game {
public:
    void start();

private:
    std::vector<Player> players;
    void initializePlayers();
};

#endif