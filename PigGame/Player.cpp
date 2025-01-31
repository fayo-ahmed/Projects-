#include "Player.h"
#include "Utils.h"
#include <iostream>

Player::Player(int _id) : id(_id), arrivalTime(0), burstTime(5), startTime(0), waitingTime(0),
                          turnaroundTime(0), currentScore(0), remainingTurns(5) {}

void Player::inputAttributes() {
    std::cout << "Enter arrival time for Player " << id << ": ";
    std::cin >> arrivalTime;
    std::cout << "Enter burst time for Player " << id << ": ";
    std::cin >> burstTime;
}

void Player::playTurn() {
    while (remainingTurns > 0 && currentScore < 100) {
        std::cout << "\nTurn " << (5 - remainingTurns + 1) << " - Player " << id << "'s turn:\n";
        int turnScore = 0;
        bool rolledOne = false;

        while (true) {
            int diceRoll = rollDice();
            std::cout << "You rolled: " << diceRoll << std::endl;

            if (diceRoll == 1) {
                std::cout << "Oops! You rolled a 1 and lost all your points.\n";
                rolledOne = true;
                break;
            }

            turnScore += diceRoll;
            std::cout << "Total score so far: " << (currentScore + turnScore) << std::endl;

            if (currentScore + turnScore >= 100) {
                std::cout << "Congratulations, Player " << id << "! You are the winner!\n";
                currentScore += turnScore;
                return;
            }

            std::string choice;
            std::cout << "Roll again? (yes/no): ";
            std::cin >> choice;

            if (choice == "no") {
                break;
            } else if (choice != "yes") {
                std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";
            }
        }

        if (!rolledOne) {
            currentScore += turnScore;
        }
        remainingTurns--;
    }

    std::cout << "Total Score for Player " << id << ": " << currentScore << std::endl;
}

int Player::getScore() const { return currentScore; }
int Player::getId() const { return id; }
int Player::getArrivalTime() const { return arrivalTime; }
int Player::getBurstTime() const { return burstTime; }
int Player::getWaitingTime() const { return waitingTime; }
int Player::getTurnaroundTime() const { return turnaroundTime; }
void Player::setStartTime(int startTime) { this->startTime = startTime; }
void Player::setWaitingTime(int waitingTime) { this->waitingTime = waitingTime; }
void Player::setTurnaroundTime(int turnaroundTime) { this->turnaroundTime = turnaroundTime; }

int Player::getStartTime() const { 
    return startTime; 
}

void Player::setBurstTime(int time) { 
    burstTime = time; 
}
