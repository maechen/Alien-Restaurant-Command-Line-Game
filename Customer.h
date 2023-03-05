#include <iostream>
#include <vector>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

/*
Customer class stores the player's name and keeps track of their energy level
Customer class is parent class of Critic Class
*/
class Customer
{
    protected:
        int table_;
        int satisfaction_;
        string order_[6]; // array that contains the customer's orders
        bool order_delivered_;

    public:
        Customer();
        int getTable(); // getters/setters for customer's table location
        void setTable(int table_num);
        int getSatisfaction(); // gets customer satisfaction
        void foodRating(int food_val); // calls decreaseSatisfaction based on food value
        void decreaseSatisfaction20(); // decreases satisfaction by 20
        void decreaseSatisfaction10(); // decreases satisfaction by 10
        void decreaseSatisfaction5();  // decreases satisfaction by 5
        void readCustomerOrders(string filename); // reading from a file of the customer's order
        string getCustomerOrder(int customer_count); // gets the customer order from the file with the correct order
        void setOrderDelivered(bool stat);
        bool getOrderDelivered();
        

};

#endif