#include "Scheduler.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std; // Add this line to avoid prefixing std::

void Scheduler::FCFS(vector<Player> &players) {
    sort(players.begin(), players.end(), [](const Player &a, const Player &b) {
        return a.getArrivalTime() < b.getArrivalTime();
    });

    cout << "\nFCFS Scheduling\n";
    int currentTime = 0;

    for (auto &player : players) {
        player.setStartTime(max(currentTime, player.getArrivalTime()));
        player.setWaitingTime(player.getStartTime() - player.getArrivalTime());
        currentTime = player.getStartTime() + player.getBurstTime();

        player.playTurn();
        player.setTurnaroundTime(currentTime - player.getArrivalTime());

        cout << "Player " << player.getId() << ": Waiting Time = " << player.getWaitingTime()
             << ", Turnaround Time = " << player.getTurnaroundTime() << ", Score = " << player.getScore() << endl;
    }
}

void Scheduler::SJF(vector<Player> &players) {
    sort(players.begin(), players.end(), [](const Player &a, const Player &b) {
        return a.getBurstTime() < b.getBurstTime();
    });

    cout << "\nSJF Scheduling\n";
    int currentTime = 0;

    for (auto &player : players) {
        player.setStartTime(max(currentTime, player.getArrivalTime()));
        player.setWaitingTime(player.getStartTime() - player.getArrivalTime());
        currentTime = player.getStartTime() + player.getBurstTime();

        player.playTurn();
        player.setTurnaroundTime(currentTime - player.getArrivalTime());

        cout << "Player " << player.getId() << ": Waiting Time = " << player.getWaitingTime()
             << ", Turnaround Time = " << player.getTurnaroundTime() << ", Score = " << player.getScore() << endl;
    }
}

void Scheduler::RR(vector<Player> &players, int quantum) {
    sort(players.begin(), players.end(), [](const Player &a, const Player &b) {
        return a.getArrivalTime() < b.getArrivalTime();
    });

    cout << "\nRound Robin Scheduling with Quantum " << quantum << endl;

    queue<Player> readyQueue;
    int currentTime = 0;

    while (!players.empty() || !readyQueue.empty()) {
        while (!players.empty() && players.front().getArrivalTime() <= currentTime) {
            readyQueue.push(players.front());
            players.erase(players.begin());
        }

        if (!readyQueue.empty()) {
            Player currentPlayer = readyQueue.front();
            readyQueue.pop();

            int executionTime = min(quantum, currentPlayer.getBurstTime());
            currentTime += executionTime;
            currentPlayer.setBurstTime(currentPlayer.getBurstTime() - executionTime);

            if (currentPlayer.getBurstTime() > 0) {
                readyQueue.push(currentPlayer);
            } else {
                currentPlayer.playTurn();
                currentPlayer.setTurnaroundTime(currentTime - currentPlayer.getArrivalTime());
                currentPlayer.setWaitingTime(currentPlayer.getTurnaroundTime() - currentPlayer.getBurstTime());

                cout << "Player " << currentPlayer.getId() << ": Waiting Time = " << currentPlayer.getWaitingTime()
                     << ", Turnaround Time = " << currentPlayer.getTurnaroundTime() << ", Score = " << currentPlayer.getScore() << endl;
            }
        } else {
            currentTime = players.front().getArrivalTime();
        }
    }
}