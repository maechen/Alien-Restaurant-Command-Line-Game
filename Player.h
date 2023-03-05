#include <iostream>
#include <vector>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

/*
Player class stores the player's name and keeps track of their energy level
*/
class Player
{
    private:
        string name_; // name of the player
        int energy_; // energy level of the player 
        string orders_[5]; // customer orders
        string critic_orders_[3];
        bool order_taken_1_; // orders taken from tables 1-5
        bool order_taken_2_;
        bool order_taken_3_;
        bool order_taken_4_;
        bool order_taken_5_;
        bool order_taken_critic_; // order taken from critic

    public:
        Player();
        string getName();
        void setName(string);
        int getEnergy(); // gets energy of the 
        void refillEnergy();  // will fill energy bar  
        void decreaseEnergy25(); // decreases energy by 25
        bool serverSlip(); // random probability that makes server fall, decreasing customer satisfaction
        void setOrderTaken(int table_num, bool taken);
        bool getOrderTaken(int table_num);
        void setOrderTakenCritic(bool order_taken_crtic);
        bool getOrderTakenCritic();

};

#endif