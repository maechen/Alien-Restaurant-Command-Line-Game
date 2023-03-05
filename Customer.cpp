#include <iostream>
#include <fstream>
#include "Customer.h"

using namespace std;

Customer::Customer()
{
    table_ = -1;
    satisfaction_ = 100;
    order_delivered_ = false;
}

int Customer::getTable()
{
    return table_;
}

void Customer::setTable(int table_num)
{
    table_ = table_num;
}

int Customer::getSatisfaction()
{
    return satisfaction_;
}

void Customer::decreaseSatisfaction20()
{
    // for bad food quality & wrong food served
    satisfaction_ -= 20;
}

void Customer::decreaseSatisfaction10()
{
    // for slipping and dirty tables
    satisfaction_ -= 10;
}

void Customer::decreaseSatisfaction5()
{
    // for average food quality
    satisfaction_ -= 5;
}

void Customer::foodRating(int food_val)
{
    
    if(food_val == 1 || food_val == 2){
        decreaseSatisfaction10();
    }
    else if(food_val == 3 || food_val == 4){
        decreaseSatisfaction5();
    }

    // if the food value is 5-6 then the satisfaction stays the same
}

void Customer::readCustomerOrders(string filename)
{
    int i = 0;
    string line;
    ifstream fin;
    fin.open(filename);
    if(!fin.fail()){ // reads through every line of file
        while(getline(fin, line)){
            if(line != ""){               
                order_[i] = line;
                i++;
            }
        }
    }
}

string Customer::getCustomerOrder(int customer_count)
{
   return order_[customer_count - 1];  // array index start at 0, but we need tables 1-5
}

void Customer::setOrderDelivered(bool stat){
    order_delivered_ = stat;
}

bool Customer::getOrderDelivered(){
    return order_delivered_;
}


