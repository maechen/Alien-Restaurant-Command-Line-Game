#include "Customer.h"
#include <iostream>
#include <vector>
using namespace std;

#ifndef CRITIC_H
#define CRITIC_H

/*
The Critic class is going to determine the quality of food for the customer
Critic is a sub-class of the base class Customer
*/
class Critic: public Customer
{
    private:
        int satisfaction1_;
        int satisfaction2_;
        int satisfaction3_;
        string name_;

    public:
        Critic();
        string getName();
        int getSatisfaction1();
        int getSatisfaction2();
        int getSatisfaction3();
        void decreaseSatisfactionApp20();
        void decreaseSatisfactionEntree20();
        void decreaseSatisfactionDessert20();

};

#endif