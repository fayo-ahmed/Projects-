#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(int id);
    void inputAttributes();
    void playTurn();
    int getScore() const;
    int getId() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getWaitingTime() const;
    int getTurnaroundTime() const;
    int getStartTime() const; // Added method
    void setStartTime(int startTime);
    void setWaitingTime(int waitingTime);
    void setTurnaroundTime(int turnaroundTime);
    void setBurstTime(int burstTime); // Added method

private:
    int id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int waitingTime;
    int turnaroundTime;
    int currentScore;
    int remainingTurns;
};

#endif