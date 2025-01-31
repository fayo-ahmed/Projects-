#include "Game.h"
#include <iostream>

void Game::initializePlayers() {
    int numPlayers = 2; // Example: 2 players
    for (int i = 0; i < numPlayers; ++i) {
        Player player(i + 1);
        player.inputAttributes();
        players.push_back(player);
    }
}

void Game::start() {
    initializePlayers();

    Scheduler::FCFS(players);
    Scheduler::SJF(players);

    int quantum = 2; // Example time quantum for Round Robin
    Scheduler::RR(players, quantum);
}