#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Player.h"

class Scheduler {
public:
    static void FCFS(std::vector<Player> &players);
    static void SJF(std::vector<Player> &players);
    static void RR(std::vector<Player> &players, int quantum);
};

#endif