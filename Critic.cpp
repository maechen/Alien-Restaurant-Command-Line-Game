#include <iostream>
#include <vector>
#include "Critic.h"
using namespace std;

// part of hierachy where Customer is the parent class, Critic is the child class

/*
The Critic class is considered the "final boss"
*/
Critic::Critic()
{
    name_ = "Jurblag Bonflimflam"; // name of the critic
    satisfaction1_ = 100;
    satisfaction2_ = 100;
    satisfaction3_ = 100;
}

string Critic::getName()
{
    return name_;
}

int Critic::getSatisfaction1()
{
    return satisfaction1_;
}

int Critic::getSatisfaction2()
{
    return satisfaction2_;
}

int Critic::getSatisfaction3()
{
    return satisfaction3_;
}

void Critic::decreaseSatisfactionApp20()
{
    satisfaction1_ -= 20;
}

void Critic::decreaseSatisfactionEntree20(){
    satisfaction1_ -= 20;
}

void Critic::decreaseSatisfactionDessert20()
{
    satisfaction3_ -= 20;
}

