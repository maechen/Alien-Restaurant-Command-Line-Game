#include <iostream>
#include <fstream>
#include "Player.h"
using namespace std;

Player::Player()
{
    name_ = "";
    energy_ = 100;
    order_taken_1_ = false;
    order_taken_2_ = false;
    order_taken_3_ = false;
    order_taken_4_ = false;
    order_taken_5_ = false;
    order_taken_critic_ = false;
}

string Player::getName()
{
    return name_;
}

void Player::setName(string name)
{
    name_ = name;
}

int Player::getEnergy()
{
    return energy_;
}

void Player::decreaseEnergy25()
{
    energy_-= 25;
}

void Player::refillEnergy()
{
    energy_ = 100;
    // this means that the energy bar is filled all the way
}

bool Player::serverSlip() // probability that affects the player's score of satisfaction
{
    srand(time(0));
    int probability = (rand() % (10 - 1 + 1)) + 1;
    if(probability > 0 && probability < 4)
    {
        return true; // slip happened
    }
    
    return false; // slip doesn't happen
}

void Player::setOrderTaken(int table_num, bool taken)
{
    if(table_num == 1){
        order_taken_1_ = taken;
    }
    else if(table_num == 2){
        order_taken_2_ = taken;
    }
    else if(table_num == 3){
        order_taken_3_ = taken;
    }
    else if(table_num == 4){
        order_taken_4_ = taken;
    }
    else if(table_num == 5){
        order_taken_5_ = taken;
    }
}

bool Player::getOrderTaken(int table_num){
    if(table_num == 1){
        return order_taken_1_;
    }
    else if(table_num == 2){
        return order_taken_2_;
    }
    else if(table_num == 3){
        return order_taken_3_;
    }
    else if(table_num == 4){
        return order_taken_4_;
    }
    else if(table_num == 5){
        return order_taken_5_;
    }
    return false;
}

void Player::setOrderTakenCritic(bool order_taken_critic)
{
    order_taken_critic_ = order_taken_critic;
}

bool Player::getOrderTakenCritic()
{
    return order_taken_critic_;
}


