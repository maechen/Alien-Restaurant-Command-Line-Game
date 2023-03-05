#include <iostream>
#include <vector>
using namespace std;

#ifndef KITCHEN_H
#define KITCHEN_H

/*
The Kitchen class is going to have arrays of food and the values for them
*/
class Kitchen
{
    private:
        string order_[3]; // array of dishes displayed
        string appetizers_[3]; // course options
        string entrees_[3];
        string desserts_[3];
        bool got_order_;
        bool correct_food_;
        bool correct_app_;
        bool correct_entree_;
        bool correct_dessert_;

    public:
        Kitchen();
        void displayCustomerOrder(); // displays the customer's order from a file
        string getCustomerOrder(int customer_count); // returns the table's order
        void readCustomerOrder(string filename); // reads the customer's from a file
        void displayAppetizers(); // displays/reads appetizers from file
        void readAppetizer(string filename);
        void displayEntrees(); // displays/reads entrees from file
        void readEntrees(string filename);
        void displayDesserts();  // displays/reads desserts from file
        void readDesserts(string filename);
        void readOrder(vector<string> order, string filename);  // reads order from the critic
        void setCorrectFood(int chosen_order, string customer_order); // comparing if the dishes are correct
        bool getCorrectFood();
        void setCorrectApp(int chosen_order, string app);
        bool getCorrectApp();
        void setCorrectEntree(int chosen_order, string entree);
        bool getCorrectEntree();
        void setCorrectDessert(int chosen_order, string dessert);
        bool getCorrectDessert();
        int assignFoodVal(); // food values that determines the quality
        bool gotOrderAtKitchen(); // status of getting an order from the kitchen
        void setWentToKitchenStatus(bool wentToKitchen);  // status of going to kitchen w/ order
};

#endif