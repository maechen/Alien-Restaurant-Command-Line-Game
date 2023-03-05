#include <iostream>
#include <fstream>
#include <vector>
#include "Kitchen.h"
using namespace std;

Kitchen::Kitchen()
{
    got_order_ = false;
    correct_food_ = false;
    correct_app_ = false;
    correct_entree_ = false;
    correct_dessert_ = false;
}

void Kitchen::displayCustomerOrder() // displays different dish options from the kitchen
{
    cout << "Options" << endl;
    cout << "-------------------------------------" << endl;
    for(int i = 1; i < 4; i++){
        cout << i << ". " << order_[i-1] << endl;
    }
    cout << "-------------------------------------" << endl;

}

string Kitchen::getCustomerOrder(int customer_count)
{
    return order_[customer_count - 1];
}

void Kitchen::readCustomerOrder(string filename) // reads the orders from a file
{
    int i = 0;
    string line;
    ifstream fin;
    fin.open(filename);
    if(!fin.fail()){
        while(getline(fin, line)){
            if(line != ""){               
                order_[i] = line;
                i++;
            }
        }
    }
}

void Kitchen::displayAppetizers() // displays appetizer options
{
    cout << "Appetizers" << endl;
    cout << "-------------------------------------" << endl;
    for(int i = 1; i < 4; i++){
        cout << i << ". " << appetizers_[i-1] << endl;
    }
    cout << "-------------------------------------" << endl;

}

void Kitchen::readAppetizer(string filename) // reads the appetizer from a file
{
    int i = 0;
    string line;
    ifstream fin;
    fin.open(filename);
    if(!fin.fail()){
        while(getline(fin, line)){
            if(line != ""){               
                appetizers_[i] = line;
                i++;
            }
        }
    }
}

void Kitchen::displayEntrees() // displays entrees options
{
    cout << "Entrees: " << endl;
    cout << "-------------------------------------" << endl;
    for(int i = 1; i < 4; i++){
        cout << i << ". " << entrees_[i-1] << endl;
    }
    cout << "-------------------------------------" << endl;
}

void Kitchen::readEntrees(string filename) // read entrees from a file
{
    int i = 0;
    ifstream fin;
    string line;
    fin.open(filename);

    if(!fin.fail())
    {
        while(getline(fin, line))
        {
            if(line != "")
            {
                entrees_[i] = line;
                i++;
            }
        }
    }
}

void Kitchen::displayDesserts() // display dessert options
{
    cout << "Desserts: " << endl;
    cout << "-------------------------------------" << endl;
    for(int i = 1; i < 4; i++){
        cout << i << ". " << desserts_[i-1] << endl;
    }
    cout << "-------------------------------------" << endl;
}

void Kitchen::readDesserts(string filename)
{
    int i = 0;
    string line;
    ifstream fin;
    fin.open(filename);
    if(!fin.fail()){
        while(getline(fin, line)){
            if(line != ""){               
                desserts_[i] = line;
                i++;
            }
        }
    }
}

void Kitchen::setCorrectFood(int chosen_order, string customer_order) // compares if it is the correct dish
{
    if(order_[chosen_order - 1] == customer_order)
    {
        correct_food_ = true;
    }
}

bool Kitchen::getCorrectFood()
{
    return correct_food_;
}

void Kitchen::setCorrectApp(int chosen_order, string app) // compares if it is the correct dish
{
    if(appetizers_[chosen_order - 1] == app){
        correct_app_ = true;
    }

    correct_app_ = false;
}

bool Kitchen::getCorrectApp()
{
    return correct_app_;
}

void Kitchen::setCorrectEntree(int chosen_order, string entree) // compares if it is the correct dish
{
    if(entrees_[chosen_order - 1] == entree){
        correct_entree_ = true;
    }

    correct_entree_ = false;
}

bool Kitchen::getCorrectEntree()
{
    return correct_entree_;
}

void Kitchen::setCorrectDessert(int chosen_order, string dessert) // compares if it is the correct dish
{
    if(desserts_[chosen_order - 1] == dessert){
        correct_dessert_ = true;
    }

    correct_dessert_ = false;
}

bool Kitchen::getCorrectDessert()
{
    return correct_dessert_;
}

int Kitchen::assignFoodVal() // food values that determine the quality
{
    srand(time(0));
    int val = (rand() % (6 - 1 + 1)) + 1;
    return val;
}

bool Kitchen::gotOrderAtKitchen()
{
    return got_order_;
}

void Kitchen::setWentToKitchenStatus(bool wentToKitchen)
{
    got_order_ = wentToKitchen;
}