#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cassert>
#include "Player.h"
#include "Customer.h"
#include "Critic.h"
#include "Kitchen.h"
#include "Table.h"
#include "Map.h"
#include "auxilliary_functions.cpp"

using namespace std;

void displayEnergy(int energy){
    cout << BLACK << "Your Energy Level: " << YELLOW << energy << RESET << endl;
}

void writeToFile(int satisf1, int satisf2, int satisf3, int satisf4, int satisf5)
{
    ofstream fout;
    fout.open("customer_satisfaction.txt");
    fout << satisf1 << endl;
    fout << satisf2 << endl;
    fout << satisf3 << endl;
    fout << satisf4 << endl;
    fout << satisf5 << endl;

    fout.close();
}

void bubbleSort()
{
    int satisfaction[5];
    int index = 0;
    ifstream fin;
    string line;
    fin.open("customer_satisfaction.txt");
    if(!fin.fail()){
        while(getline(fin, line)){
            if(line != ""){           
                satisfaction[index] = stoi(line);
                index++;
            }
        }
    }

    int tempVal;
    for (int j = 0; j < 5; j++)
    {
        for (int i = j + 1; i < 5; i++)
        {
            if (satisfaction[i-1] < satisfaction[i])
            {
                tempVal = satisfaction[i - 1];
                satisfaction[j] = satisfaction[j + 1];
                satisfaction[i - 1] = satisfaction[i];
                satisfaction[i] = tempVal;
            }
                
        }
    }

    cout << "These were your customer stats (Highest to Lowest):" << endl;
    cout << satisfaction[0] << ", ";
    cout << satisfaction[1] << ", ";
    cout << satisfaction[2] << ", ";
    cout << satisfaction[3] << ", ";
    cout << "and " << satisfaction[4] << endl;

}



int main()
{
    system("clear");
    char cont_exit;
    Player p;

    cout << BLUE << "Last night was WILD!" << endl;
    cout << "You and your friends ended up partying with some aliens on a space ship." << endl;
    cout << "After a blurry night, you woke up alone." << endl;
    cout << "Frantically, you got up and went outside..." << endl;
    cout << endl;
    cout << "Wait... you're in space!!!" << endl;
    cout << endl;
    cout << "In search of answers, you wander towards the nearest town that seemed to be busy with some kind of life." << endl;
    cout << "After talking to some friendly citizens, you've concluded that been abudcted by aliens called Blubons, " << endl;
    cout << "and they took you to their home planet Mirandonia. With no way to go back to planet Earth, you decide " << endl;
    cout << "you have to make a living on Mirandonia. " << endl;
    cout << endl;
    cout << "You stumble upon a poster, and it says that they are hiring servers. Eager to get started you proudly put" << endl;
    cout << "on your new work attire with a flashy name badge that says... <<type your name here>> " << RESET;
    string name;
    cin >> name;
    p.setName(name);

    system("clear");

    cout << BLUE << "Last night was WILD!" << endl;
    cout << "You and your friends ended up partying with some aliens on a space ship." << endl;
    cout << "After a blurry night, you woke up alone." << endl;
    cout << "Frantically, you got up and went outside..." << endl;
    cout << endl;
    cout << "Wait... you're in space!!!" << endl;
    cout << endl;
    cout << "In search of answers, you wander towards the nearest town that seemed to be busy with some kind of life." << endl;
    cout << "After talking to some friendly citizens, you've concluded that been abudcted by aliens called Blubons, " << endl;
    cout << "and they took you to their home planet Mirandonia. With no way to go back to planet Earth, you decide " << endl;
    cout << "you have to make a living on Mirandonia. " << endl;
    cout << endl;
    cout << "You stumble upon a poster, and it says that they are hiring servers. Eager to get started you proudly put" << endl;
    cout << "on your new work attire with a flashy name badge that says... " << BOLDYELLOW << name << "!" << RESET << endl;
    cout << endl;
    cout << BLACK << "(Enter 'c' to continue)" << RESET << endl;
    cin >> cont_exit;
    if(cont_exit == 'c'){
        system("clear");
    }
    else{
        while( cont_exit != 'c'){
            cout << BLACK << "Please enter valid input." << RESET << endl;
            cin >> cont_exit;
        }
        system("clear");
    }


    cout << BOLDWHITE << "Instructions: " << RESET << "Congrats on getting hired at " << CYAN << "le GastroGnome!" << RESET <<" This restaurant is notorious for its wide" << endl;
    cout << "variety of dishes that cater to alien customers. It is up to you to serve these customers the correct" << endl;
    cout << "dish, and when you serve five customers a " << MAGENTA << "food critic " << RESET << "will enter the restaurant..." << endl;
    cout << endl;
    cout << "• Use the WASD keys and press Enter to move" << endl;
    cout << "• Be sure to..." << endl;
    cout << "   • seat your customers" << endl;
    cout << "   • take their order" << endl;
    cout << "   • clean the tables before sitting down customers (they are all clean at the beginning)" << endl;
    cout << "   • go to the kitchen to select the food" << endl;
    cout << "   • deliver the dish to the customer" << endl;
    cout << "   • take a lunch break when your energy is running low!" << endl;
    cout << "• Your shift will end when you serve the critic" << endl;
    cout << endl;
    cout << "Here's an example of the map you will see below:" << endl;
    cout << endl;
    cout << "------------" << endl;
    cout << "------------" << endl;
    cout << "--🍱------🍽️--" << endl;
    cout << "------------" << endl;
    cout << "------------" << endl;
    cout << "--①---------" << endl;
    cout << "---------②--" << endl;
    cout << "--③---------" << endl;
    cout << "---------④--" << endl;
    cout << "--⑤---------" << endl;
    cout << "------------" << endl;
    cout << "😄----------👽" << endl;
    cout << endl;
    cout << "😄 - this is you!" << endl;
    cout << "① - the tables are labeled with numbers" << endl;
    cout << "👽 - these are the customers" << endl;
    cout << "🍱 - this is where you take your lunch breaks" << endl;
    cout << "🍽️ - this is the kitchen where you get the food" << endl;
    cout << endl;
    cout << BLUE << "Are you ready to start your shift? " << endl;
    cout << endl;
    cout << BLACK << "(Enter 'c' to continue)" << RESET << endl;
    cin >> cont_exit;
    if(cont_exit == 'c'){
        system("clear");
    }
    else{
        while( cont_exit != 'c'){
            cout << BLACK << "Please enter valid input." << RESET << endl;
            cin >> cont_exit;
        }
        system("clear");
    }
    
    int customer_count = 0;
    int chosen_order;
    Map m;
    Table t1;
    Table t2;
    Table t3;
    Table t4;
    Table t5;
    Customer c1;
    Customer c2;
    Customer c3;
    Customer c4;
    Customer c5;
    Critic final_boss;
    c1.readCustomerOrders("customer_orders.txt");
    c2.readCustomerOrders("customer_orders.txt");
    c3.readCustomerOrders("customer_orders.txt");
    c4.readCustomerOrders("customer_orders.txt");
    c5.readCustomerOrders("customer_orders.txt");
    final_boss.readCustomerOrders("customer_orders.txt");
    Kitchen k1;
    Kitchen k2;
    Kitchen k3;
    Kitchen k4;
    Kitchen k5;
    Kitchen k_critic;
    m.addNPC(11, 11);

    // Location of the tables
    m.addTable(5, 2); // Table #1
    m.addTable(6, 9); // Table #2
    m.addTable(7, 2); // Table #3
    m.addTable(8, 9); // Table #4
    m.addTable(9, 2); // Table #5
    
    while(true)
    {
        m.displayMap();
        displayEnergy(p.getEnergy());

        if(m.getPlayerCol() == 11 && m.getPlayerRow() == 11 && m.isCriticLocation(11, 11)) // when the critic arrives
        {
            int table_num_critic;
            cout << "You must seat the food critic!" << endl;
            cout << "What table would you like to seat them at? (Enter a number between 1 and 5)" << endl;
            cin >> table_num_critic;

            if(table_num_critic < 1 || table_num_critic > 5)
            {
                do
                {   
                    cout << BLACK << "Please enter a valid input." << RESET << endl;
                    cout << "What table would you like to seat them at? (Enter a number between 1 and 5)" << endl;
                    cin >> table_num_critic;  

                }while(table_num_critic < 1 || table_num_critic > 5);
            }
            system("clear");
            switch(table_num_critic)
            {
                case 1:
                if(t1.getCleanStatus() == false && customer_count == 1)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c1.decreaseSatisfaction10();
                }
                else if(t1.getCleanStatus() == false && customer_count == 2)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c2.decreaseSatisfaction10();
                }
                else if(t1.getCleanStatus() == false && customer_count == 3)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c3.decreaseSatisfaction10();
                }
                else if(t1.getCleanStatus() == false && customer_count == 4)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c4.decreaseSatisfaction10();
                }
                else if(t1.getCleanStatus() == false && customer_count == 5)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                else if(t1.getCleanStatus() == false && customer_count == 6)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                m.removeTable(5, 2);
                m.removeCritic(11, 11);
                m.addCritic(5, 2);
                m.move('a');
                t1.setCleanStatus(false);
                t1.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                final_boss.setTable(1);
                cout << BOLDWHITE << final_boss.getName() << " has been seated at table 1" << RESET << endl;
                cout << "The infamous critic " << BOLDMAGENTA << final_boss.getName() << RESET << " has arrived at the restaurant!" << endl;
                cout << "It is your job to serve him a three course meal to his liking, good luck!" << BLACK << "(Don't make us look bad...)" << RESET << endl;
                cout << endl;
                cout << BLACK << "Use WASD to move again" << RESET <<endl;
                break;

                case 2:
                if(t2.getCleanStatus() == false && customer_count == 1)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c1.decreaseSatisfaction10();
                }
                else if(t2.getCleanStatus() == false && customer_count == 2)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c2.decreaseSatisfaction10();
                }
                else if(t2.getCleanStatus() == false && customer_count == 3)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c3.decreaseSatisfaction10();
                }
                else if(t2.getCleanStatus() == false && customer_count == 4)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c4.decreaseSatisfaction10();
                }
                else if(t2.getCleanStatus() == false && customer_count == 5)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                else if(t2.getCleanStatus() == false && customer_count == 6)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                m.removeTable(6, 9);
                m.removeCritic(11, 11);
                m.addCritic(6, 9);
                m.move('a');
                t2.setCleanStatus(false);
                t2.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                final_boss.setTable(2);
                cout << BOLDWHITE << final_boss.getName() << " has been seated at table 1" << RESET << endl;
                cout << "The infamous critic " << BOLDMAGENTA << final_boss.getName() << RESET << " has arrived at the restaurant!" << endl;
                cout << "It is your job to serve him a three course meal to his liking, good luck!" << BLACK << "(Don't make us look bad...)" << RESET << endl;
                cout << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
                break;

                case 3:
                if(t3.getCleanStatus() == false && customer_count == 1)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c1.decreaseSatisfaction10();
                }
                else if(t3.getCleanStatus() == false && customer_count == 2)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c2.decreaseSatisfaction10();
                }
                else if(t3.getCleanStatus() == false && customer_count == 3)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c3.decreaseSatisfaction10();
                }
                else if(t3.getCleanStatus() == false && customer_count == 4)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c4.decreaseSatisfaction10();
                }
                else if(t3.getCleanStatus() == false && customer_count == 5)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                else if(t3.getCleanStatus() == false && customer_count == 6)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                m.removeTable(7, 2);
                m.removeCritic(11, 11);
                m.addCritic(7, 2);
                m.move('a');
                t3.setCleanStatus(false);
                t3.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                final_boss.setTable(3);
                cout << BOLDWHITE << final_boss.getName() << " has been seated at table 1" << RESET << endl;
                cout << "The infamous critic " << BOLDMAGENTA << final_boss.getName() << RESET << " has arrived at the restaurant!" << endl;
                cout << "It is your job to serve him a three course meal to his liking, good luck!" << BLACK << "(Don't make us look bad...)" << RESET << endl;
                cout << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
                break;

                case 4:
                if(t4.getCleanStatus() == false && customer_count == 1)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c1.decreaseSatisfaction10();
                }
                else if(t4.getCleanStatus() == false && customer_count == 2)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c2.decreaseSatisfaction10();
                }
                else if(t4.getCleanStatus() == false && customer_count == 3)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c3.decreaseSatisfaction10();
                }
                else if(t4.getCleanStatus() == false && customer_count == 4)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c4.decreaseSatisfaction10();
                }
                else if(t4.getCleanStatus() == false && customer_count == 5)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                else if(t4.getCleanStatus() == false && customer_count == 6)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                m.removeTable(8, 9);
                m.removeCritic(11, 11);
                m.addCritic(8, 9);
                m.move('a');
                t4.setCleanStatus(false);
                t4.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                final_boss.setTable(4);
                cout << BOLDWHITE << final_boss.getName() << " has been seated at table 1" << RESET << endl;
                cout << "The infamous critic " << BOLDMAGENTA << final_boss.getName() << RESET << " has arrived at the restaurant!" << endl;
                cout << "It is your job to serve him a three course meal to his liking, good luck!" << BLACK << "(Don't make us look bad...)" << RESET << endl;
                cout << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
                break;

                case 5:
                if(t5.getCleanStatus() == false && customer_count == 1)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c1.decreaseSatisfaction10();
                }
                else if(t5.getCleanStatus() == false && customer_count == 2)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c2.decreaseSatisfaction10();
                }
                else if(t5.getCleanStatus() == false && customer_count == 3)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c3.decreaseSatisfaction10();
                }
                else if(t5.getCleanStatus() == false && customer_count == 4)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c4.decreaseSatisfaction10();
                }
                else if(t5.getCleanStatus() == false && customer_count == 5)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                else if(t5.getCleanStatus() == false && customer_count == 6)
                {
                    cout << "The customer sat uncomfortably in the chair with obvious stains from an unknown origin..." << endl;
                    c5.decreaseSatisfaction10();
                }
                m.removeTable(9, 2);
                m.removeCritic(11, 11);
                m.addCritic(9, 2);
                m.move('a');
                t5.setCleanStatus(false);
                t5.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                final_boss.setTable(5);
                cout << BOLDWHITE << final_boss.getName() << " has been seated at table 1" << RESET << endl;
                cout << "The infamous critic " << BOLDMAGENTA << final_boss.getName() << RESET << " has arrived at the restaurant!" << endl;
                cout << "It is your job to serve him a three course meal to his liking, good luck!" << BLACK << "(Don't make us look bad...)" << RESET << endl;
                cout << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
                break;
            }
            cout << customer_count << endl;
        }
        else if(m.getPlayerCol() == 11 && m.getPlayerRow() == 11 && m.isNPCLocation(11,11)) // seating a customer
        {
            int table_num;
            cout << "You must seat this customer!" << endl;
            cout << "What table would you like to seat them at? (Enter a number between 1 and 5)" << endl;
            cin >> table_num;

            if(table_num < 1 || table_num > 5)
            {
                do
                {   
                   cout << BLACK << "Please enter a valid input." << RESET << endl;
                    cout << "What table would you like to seat them at? (Enter a number between 1 and 5)" << endl;
                    cin >> table_num;  

                }while(table_num < 1 || table_num > 5);
            }
            system("clear");
            switch(table_num)
            {
                case 1:
                m.removeTable(5, 2);
                m.removeNPC(11, 11);
                m.addNPC(5, 2);
                m.move('a');
                p.decreaseEnergy25();
                t1.setCleanStatus(false);
                t1.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                if(customer_count == 1){
                    c1.setTable(1);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 1" << RESET << endl;
                }
                else if(customer_count == 2){
                    c2.setTable(1);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 1" << RESET << endl;
                }
                else if(customer_count == 3){
                    c3.setTable(1);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 1" << RESET << endl;
                }
                else if(customer_count == 4){
                    c4.setTable(1);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 1" << RESET << endl; 
                }
                else if(customer_count == 5){
                    c5.setTable(1);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 1" << RESET << endl;
                }
                cout << BLACK << "Use WASD to move again" << RESET <<endl;
                break;

                case 2:
                m.removeTable(6, 9);
                m.removeNPC(11, 11);
                m.addNPC(6, 9);
                m.move('a');
                p.decreaseEnergy25();
                t2.setCleanStatus(false);
                t2.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                if(customer_count == 1){
                    c1.setTable(2);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 2" << RESET << endl;
                }
                else if(customer_count == 2){
                    c2.setTable(2);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 2" << RESET << endl;
                }
                else if(customer_count == 3){
                    c3.setTable(2);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 2" << RESET << endl;
                }
                else if(customer_count == 4){
                    c4.setTable(2);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 2" << RESET << endl; 
                }
                else if(customer_count == 5){
                    c5.setTable(2);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 2" << RESET << endl;
                }
                cout << BLACK << "Use WASD to move again" << RESET <<endl;
                break;

                case 3:
                m.removeTable(7, 2);
                m.removeNPC(11, 11);
                m.addNPC(7, 2);
                m.move('a');
                p.decreaseEnergy25();
                t3.setCleanStatus(false);
                t3.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                if(customer_count == 1){
                    c1.setTable(3);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 3" << RESET << endl;
                }
                else if(customer_count == 2){
                    c2.setTable(3);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 3" << RESET << endl;
                }
                else if(customer_count == 3){
                    c3.setTable(3);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 3" << RESET << endl;
                }
                else if(customer_count == 4){
                    c4.setTable(3);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 3" << RESET << endl; 
                }
                else if(customer_count == 5){
                    c5.setTable(3);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 3" << RESET << endl;
                }
                cout << BLACK << "Use WASD to move again" << RESET <<endl;
                break;

                case 4:
                m.removeTable(8, 9);
                m.removeNPC(11, 11);
                m.addNPC(8, 9);
                m.move('a');
                p.decreaseEnergy25();
                t4.setCleanStatus(false);
                t4.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                if(customer_count == 1){
                    c1.setTable(4);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 4" << RESET << endl;
                }
                else if(customer_count == 2){
                    c2.setTable(4);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 4" << RESET << endl;
                }
                else if(customer_count == 3){
                    c3.setTable(4);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 4" << RESET << endl;
                }
                else if(customer_count == 4){
                    c4.setTable(4);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 4" << RESET << endl; 
                }
                else if(customer_count == 5){
                    c5.setTable(4);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 4" << RESET << endl;
                }
                cout << BLACK << "Use WASD to move again" << RESET <<endl;
                break;

                case 5:
                m.removeTable(9, 2);
                m.removeNPC(11, 11);
                m.addNPC(9, 2);
                m.move('a');
                p.decreaseEnergy25();
                t5.setCleanStatus(false);
                t5.setAvailability(false);
                customer_count++;
                m.displayMap();
                displayEnergy(p.getEnergy());
                if(customer_count == 1){
                    c1.setTable(5);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 5" << RESET << endl;
                }
                else if(customer_count == 2){
                    c2.setTable(5);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 5" << RESET << endl;
                }
                else if(customer_count == 3){
                    c3.setTable(5);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 5" << RESET << endl;
                }
                else if(customer_count == 4){
                    c4.setTable(5);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 5" << RESET << endl; 
                }
                else if(customer_count == 5){
                    c5.setTable(5);
                    cout << BOLDWHITE << "Customer " << customer_count << " has been seated at table 5" << RESET << endl;
                }
                cout << BLACK << "Use WASD to move again" << RESET <<endl;
                break;
            }
        }


        // Table One functions
        if(p.getOrderTakenCritic() == false && m.isCriticLocation(5,2) && m.getPlayerRow() == 5 && m.getPlayerCol() == 2) // taking the critic's order at table one
        {
            cout << "Press 'c' to take " << MAGENTA << final_boss.getName() << RESET << "'s order or press WASD to move again" << endl;
            cin >> cont_exit;
            if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                do{
                    cout << BLACK << "Please enter a valid input." << RESET <<endl;
                    cin >> cont_exit;
                }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
            }
            system("clear");
            switch(cont_exit)
            {
                case 'w': 
                    m.move('w');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'a': 
                    m.move('a');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 's': 
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'd': 
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'c':
                    system("clear");
                    cout << BOLDMAGENTA << "Greetings, I would like the finest items on the menu... " << RESET << endl;
                    cout << BOLDWHITE << final_boss.getCustomerOrder(customer_count) << RESET << endl;
                    cout << endl;
                    cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                    cin >> cont_exit;
                    if(cont_exit != 'e')
                    {
                        do
                        {
                            cout << BLACK << "Please enter a valid input." << RESET << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'e');
                    }
                    system("clear");
                    p.setOrderTaken(1, true);
                    p.setOrderTakenCritic(true);
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << BOLDWHITE << final_boss.getName() <<"'s order has been taken" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                    break;
            }
        }
        else if(p.getOrderTakenCritic() == true && k_critic.gotOrderAtKitchen() == true && m.isCriticLocation(5,2) && m.getPlayerRow() == 5 && m.getPlayerCol() == 2)
        {
                cout << "Press 'c' to deliver the order to Table 1" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                    {
                        while(cont_exit != 'c'){
                            cout << BLACK << "Please enter valid input." << RESET << endl;
                            cin >> cont_exit;
                        }
                    }
                if(cont_exit == 'c')
                {
                    system("clear");
                }
                if(cont_exit == 'c')
                {
                    cout << MAGENTA << "Interesting... I will send in my evaluations later. Thank you for the courses tonight.✧" << RESET << endl;
                    final_boss.setOrderDelivered(true);
                    if(p.serverSlip())
                    {
                        final_boss.decreaseSatisfaction20();
                    }
                    if(k_critic.getCorrectApp() == false)
                    {
                        final_boss.decreaseSatisfactionApp20();
                    }
                    if(k_critic.getCorrectEntree() == false)
                    {
                        final_boss.decreaseSatisfactionEntree20();
                    }
                    if(k_critic.getCorrectDessert() == false)
                    {
                        final_boss.decreaseSatisfactionDessert20();
                    }
                    if(k_critic.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                    {
                        final_boss.decreaseSatisfaction10();
                    }
                    if(k_critic.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                    {
                        final_boss.decreaseSatisfaction5();
                    }
                }
                if(final_boss.getOrderDelivered() == true)
                {
                    system("clear");
                    cout << YELLOW << "Congrats! You finished the game!" << RESET << endl; // ending seq
                    cout << CYAN << "------" << BOLDYELLOW << "STATS" << CYAN << "---" << YELLOW << "OF" << CYAN << "---" << BOLDYELLOW << p.getName() << CYAN << "------" << RESET <<endl;
                    cout << "Customers Served: " << customer_count << endl;
                    writeToFile(c1.getSatisfaction(), c2.getSatisfaction(), c3.getSatisfaction(), c4.getSatisfaction(), c5.getSatisfaction());
                    bubbleSort();
                    cout << "Critic Three Course Meal Ratings: " << endl;
                    cout << "Appetizer Rating: " << BOLDWHITE << final_boss.getSatisfaction1() << RESET << endl;
                    cout << "Entrees Rating: " << BOLDWHITE << final_boss.getSatisfaction2() << RESET << endl;
                    cout << "Dessert Rating: " << BOLDWHITE << final_boss.getSatisfaction3() << RESET << endl;
                    int avg = (final_boss.getSatisfaction1() + final_boss.getSatisfaction2() + final_boss.getSatisfaction3() + final_boss.getSatisfaction()) / 4.0;
                    cout << "Critic Overall Review: " << BOLDRED << avg << RESET << endl;
                    cout << BOLDCYAN << "Game Over!" << RESET <<endl;
                    cout << BLACK << "Thank you for playing." << RESET << endl;
                    return 0;
                }
        }
        else if(m.getPlayerCol() == 2 && m.getPlayerRow() == 5 && customer_count <= 5)
        {
            if(t1.getAvailability() == false && p.getOrderTaken(1) == false) // taking the customer's order
            {
                cout << "Press 'c' to take table one's order or press WASD to move again" << endl;
                cin >> cont_exit;
                if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                    do{
                        cout << BLACK << "Please enter a valid input." << RESET <<endl;
                        cin >> cont_exit;
                    }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
                }
                system("clear");
                switch(cont_exit)
                {
                    case 'w': 
                        m.move('w');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'a': 
                        m.move('a');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 's': 
                        m.move('s');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'd': 
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'c':
                        system("clear");
                        cout << "Blorb there! I would like to order ";
                        if(customer_count == 1){
                            cout << BOLDWHITE << c1.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 2){
                            cout << BOLDWHITE << c2.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 3){
                            cout << BOLDWHITE << c3.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 4){
                            cout << BOLDWHITE << c4.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 5){
                            cout << BOLDWHITE << c5.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        cin >> cont_exit;
                        if(cont_exit != 'e')
                        {
                            do
                            {
                                cout << BLACK << "Please enter a valid input." << RESET <<endl;
                                cin >> cont_exit;
                            }while(cont_exit != 'e');
                        }
                        system("clear");
                        p.setOrderTaken(1, true);
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        cout << BOLDWHITE << "Table one's order has been taken" << RESET << endl;
                        cout << BLACK << "Use WASD to move again" << RESET << endl;
                        break;
                }
            }
            if(t1.getAvailability() == false && p.getOrderTaken(1) == true) // delivering the order to the customer
            {
                if(customer_count == 1 && k1.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 1" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c1.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        if(k1.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        else if(k1.getCorrectFood() == true)
                        {
                            cout << "Mmmm!! This was exactly what I needed!" << endl;
                        }
                        if(k1.assignFoodVal() == 1 && k1.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction10();
                        }
                        if(k1.assignFoodVal() == 3 && k1.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 2 && k2.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 1" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c2.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        if(k2.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        else if(k2.getCorrectFood() == true)
                        {
                            cout << "Mmmm!! This was exactly what I needed!" << endl;
                        }
                        if(k2.assignFoodVal() == 1 && k2.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction10();
                        }
                        if(k2.assignFoodVal() == 3 && k2.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 3 && k3.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 1" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c3.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        if(k3.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        else if(k3.getCorrectFood() == true)
                        {
                            cout << "Mmmm!! This was exactly what I needed!" << endl;
                        }
                        if(k3.assignFoodVal() == 1 && k3.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction10();
                        }
                        if(k3.assignFoodVal() == 3 && k3.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 4 && k4.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 1" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c4.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        if(k4.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        else if(k4.getCorrectFood() == true)
                        {
                            cout << "Mmmm!! This was exactly what I needed!" << endl;
                        }
                        if(k4.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction10();
                        }
                        if(k4.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 5 && k5.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 1" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c5.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        if(k5.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        else if(k5.getCorrectFood() == true)
                        {
                            cout << "Mmmm!! This was exactly what I needed!" << endl;
                        }
                        if(k5.assignFoodVal() == 1 && k5.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction10();
                        }
                        if(k5.assignFoodVal() == 3 && k5.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                

                if(c1.getOrderDelivered() == true){
                    int c1_table = c1.getTable();
                    if(c1_table == 1)
                    {
                        m.removeNPC(5,2);
                        m.addTable(5,2);
                        t1.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c1.setOrderDelivered(false);
                        p.setOrderTaken(1, false);
                    } 
                }
                else if(c2.getOrderDelivered() == true)
                {
                    int c2_table = c2.getTable();
                    if(c2_table == 1)
                    {
                        m.removeNPC(5,2);
                        m.addTable(5,2);
                        t1.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c2.setOrderDelivered(false);
                        p.setOrderTaken(1, false);
                    } 
                }
                else if(c3.getOrderDelivered() == true)
                {
                    int c3_table = c3.getTable();
                    if(c3_table == 1)
                    {
                        m.removeNPC(5,2);
                        m.addTable(5,2);
                        t1.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c3.setOrderDelivered(false);
                        p.setOrderTaken(1, false);
                    } 
                }
                else if(c4.getOrderDelivered() == true)
                {
                    int c4_table = c4.getTable();
                    if(c4_table == 1)
                    {
                        m.removeNPC(5,2);
                        m.addTable(5,2);
                        t1.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c4.setOrderDelivered(false);
                        p.setOrderTaken(1, false);
                    } 
                }
                else if(c5.getOrderDelivered() == true)
                {
                    int c5_table = c5.getTable();
                    if(c5_table == 1)
                    {
                        m.removeNPC(5,2);
                        m.addTable(5,2);
                        t1.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c5.setOrderDelivered(false);
                        p.setOrderTaken(1, false);
                    } 
                }
            }
            if(t1.getAvailability() == true && t1.getCleanStatus() == false) // cleaning the table
            {
                cout << "Press 'c' to clean the table" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                {
                    while(cont_exit != 'c'){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> cont_exit;
                    }
                }
                if(cont_exit == 'c'){
                    t1.setCleanStatus(true);
                    cout << BOLDWHITE << "Table one was successfully cleaned!" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
                
                t1.setCleanStatus(true); 
            }
            else if (t1.getAvailability() == false && p.getOrderTaken(1) == true)
            {
                cout << RED << "You already took my order! Where is my order?! \\(◣_◢)/" << RESET << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }

        }

        // Table two functions
        if(p.getOrderTakenCritic() == false && m.isCriticLocation(6,9) && m.getPlayerRow() == 6 && m.getPlayerCol() == 9) // taking the critic's order at table one
        {
            cout << "Press 'c' to take " << MAGENTA << final_boss.getName() << RESET << "'s order or press WASD to move again" << endl;
            cin >> cont_exit;
            if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                do{
                    cout << BLACK << "Please enter a valid input." << RESET <<endl;
                    cin >> cont_exit;
                }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
            }
            system("clear");
            switch(cont_exit)
            {
                case 'w': 
                    m.move('w');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'a': 
                    m.move('a');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 's': 
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'd': 
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'c':
                    system("clear");
                    cout << BOLDMAGENTA << "Greetings, I would like the finest items on the menu... " << RESET << endl;
                    cout << BOLDWHITE << final_boss.getCustomerOrder(customer_count) << RESET << endl;
                    cout << endl;
                    cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                    cin >> cont_exit;
                    if(cont_exit != 'e')
                    {
                        do
                        {
                            cout << BLACK << "Please enter a valid input." << RESET << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'e');
                    }
                    system("clear");
                    p.setOrderTaken(2, true);
                    p.setOrderTakenCritic(true);
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << BOLDWHITE << final_boss.getName() <<"'s order has been taken" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                    break;
            }
        }
        else if(p.getOrderTakenCritic() == true && k_critic.gotOrderAtKitchen() == true && m.isCriticLocation(6,9) && m.getPlayerRow() == 6 && m.getPlayerCol() == 9)
        {
                cout << "Press 'c' to deliver the order to Table 1" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                    {
                        while(cont_exit != 'c'){
                            cout << BLACK << "Please enter valid input." << RESET << endl;
                            cin >> cont_exit;
                        }
                    }
                if(cont_exit == 'c')
                {
                    system("clear");
                }
                if(cont_exit == 'c')
                {
                    cout << MAGENTA << "Interesting... I will send in my evaluations later. Thank you for the courses tonight.✧" << RESET << endl;
                    final_boss.setOrderDelivered(true);
                    if(p.serverSlip())
                    {
                        final_boss.decreaseSatisfaction20();
                    }
                    if(k_critic.getCorrectApp() == false)
                    {
                        final_boss.decreaseSatisfactionApp20();
                    }
                    if(k_critic.getCorrectEntree() == false)
                    {
                        final_boss.decreaseSatisfactionEntree20();
                    }
                    if(k_critic.getCorrectDessert() == false)
                    {
                        final_boss.decreaseSatisfactionDessert20();
                    }
                    if(k_critic.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                    {
                        final_boss.decreaseSatisfaction10();
                    }
                    if(k_critic.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                    {
                        final_boss.decreaseSatisfaction5();
                    }
                }
                if(final_boss.getOrderDelivered() == true)
                {
                    system("clear");
                    cout << YELLOW << "Congrats! You finished the game!" << RESET << endl; // ending seq
                    cout << CYAN << "------" << BOLDYELLOW << "STATS" << CYAN << "---" << YELLOW << "OF" << CYAN << "---" << BOLDYELLOW << p.getName() << CYAN << "------" << RESET <<endl;
                    cout << "Customers Served: " << customer_count << endl;
                    writeToFile(c1.getSatisfaction(), c2.getSatisfaction(), c3.getSatisfaction(), c4.getSatisfaction(), c5.getSatisfaction());
                    bubbleSort();
                    cout << "Critic Three Course Meal Ratings: " << endl;
                    cout << "Appetizer Rating: " << BOLDWHITE << final_boss.getSatisfaction1() << RESET << endl;
                    cout << "Entrees Rating: " << BOLDWHITE << final_boss.getSatisfaction2() << RESET << endl;
                    cout << "Dessert Rating: " << BOLDWHITE << final_boss.getSatisfaction3() << RESET << endl;
                    int avg = (final_boss.getSatisfaction1() + final_boss.getSatisfaction2() + final_boss.getSatisfaction3() + final_boss.getSatisfaction()) / 4.0;
                    cout << "Critic Overall Review: " << BOLDRED << avg << RESET << endl;
                    cout << BOLDCYAN << "Game Over!" << RESET <<endl;
                    cout << BLACK << "Thank you for playing." << RESET << endl;
                    return 0;
                }
        }
        else if(m.getPlayerCol() == 9 && m.getPlayerRow() == 6 && customer_count <= 5)
        {
            if(t2.getAvailability() == false && p.getOrderTaken(2) == false) // taking the customer's order
            {
                cout << "Press 'c' to take table one's order or press WASD to move again" << endl;
                cin >> cont_exit;
                if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                    do{
                        cout << BLACK << "Please enter a valid input." << RESET <<endl;
                        cin >> cont_exit;
                    }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
                }
                system("clear");
                switch(cont_exit)
                {
                    case 'w': 
                        m.move('w');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'a': 
                        m.move('a');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 's': 
                        m.move('s');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'd': 
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'c':
                        system("clear");
                        cout << "Blorb there! I would like to order ";
                        if(customer_count == 1){
                            cout << BOLDWHITE << c1.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 2){
                            cout << BOLDWHITE << c2.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 3){
                            cout << BOLDWHITE << c3.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 4){
                            cout << BOLDWHITE << c4.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 5){
                            cout << BOLDWHITE << c5.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        cin >> cont_exit;
                        if(cont_exit != 'e')
                        {
                            do
                            {
                                cout << BLACK << "Please enter a valid input." << RESET <<endl;
                                cin >> cont_exit;
                            }while(cont_exit != 'e');
                        }
                        system("clear");
                        p.setOrderTaken(2, true);
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        cout << BOLDWHITE << "Table two's order has been taken" << RESET << endl;
                        cout << BLACK << "Use WASD to move again" << RESET << endl;
                        break;
                }
            }

            if(t2.getAvailability() == false && p.getOrderTaken(2) == true) // delivering the order to the customer
            {
                if(customer_count == 1 && k1.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 2" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c1.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        if(k1.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        else if(k1.getCorrectFood() == true)
                        {
                            cout << "Well done!" << endl;
                        }
                        if(k1.assignFoodVal() == 1 && k1.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction10();
                        }
                        if(k1.assignFoodVal() == 3 && k1.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 2 && k2.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 2" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c2.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        if(k2.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        else if(k2.getCorrectFood() == true)
                        {
                            cout << "Well done!" << endl;
                        }
                        if(k2.assignFoodVal() == 1 && k2.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction10();
                        }
                        if(k2.assignFoodVal() == 3 && k2.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 3 && k3.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 2" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c3.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        if(k3.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        else if(k3.getCorrectFood() == true)
                        {
                            cout << "Well done!" << endl;
                        }
                        if(k3.assignFoodVal() == 1 && k3.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction10();
                        }
                        if(k3.assignFoodVal() == 3 && k3.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 4 && k4.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 2" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c4.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        if(k4.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        else if(k4.getCorrectFood() == true)
                        {
                            cout << "Well done!" << endl;
                        }
                        if(k4.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction10();
                        }
                        if(k4.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 5 && k5.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 2" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c5.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        if(k5.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        else if(k5.getCorrectFood() == true)
                        {
                            cout << "Well done!" << endl;
                        }
                        if(k5.assignFoodVal() == 1 && k5.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction10();
                        }
                        if(k5.assignFoodVal() == 3 && k5.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }

                if(c1.getOrderDelivered() == true){
                    int c1_table = c1.getTable();
                    if(c1_table == 2)
                    {
                        m.removeNPC(6,9);
                        m.addTable(6,9);
                        t2.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c1.setOrderDelivered(false);
                        p.setOrderTaken(2, false);
                    } 
                }
                else if(c2.getOrderDelivered() == true)
                {
                    int c2_table = c2.getTable();
                    if(c2_table == 2)
                    {
                        m.removeNPC(6,9);
                        m.addTable(6,9);
                        t2.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c2.setOrderDelivered(false);
                        p.setOrderTaken(2, false);
                    } 
                }
                else if(c3.getOrderDelivered() == true)
                {
                    int c3_table = c3.getTable();
                    if(c3_table == 2)
                    {
                        m.removeNPC(6,9);
                        m.addTable(6,9);
                        t2.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c3.setOrderDelivered(false);
                        p.setOrderTaken(2, false);
                    } 
                }
                else if(c4.getOrderDelivered() == true)
                {
                    int c4_table = c4.getTable();
                    if(c4_table == 2)
                    {
                        m.removeNPC(6,9);
                        m.addTable(6,9);
                        t2.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c4.setOrderDelivered(false);
                        p.setOrderTaken(2, false);
                    } 
                }
                else if(c5.getOrderDelivered() == true)
                {
                    int c5_table = c5.getTable();
                    if(c5_table == 2)
                    {
                        m.removeNPC(6,9);
                        m.addTable(6,9);
                        t2.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c5.setOrderDelivered(false);
                        p.setOrderTaken(2, false);
                    } 
                } 
            }
            else if(t2.getAvailability() == true && t2.getCleanStatus() == false) // cleaning the table
            {
                cout << "Press 'c' to clean the table" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                {
                    while(cont_exit != 'c'){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> cont_exit;
                    }
                }
                if(cont_exit == 'c'){
                    t2.setCleanStatus(true);
                    cout << BOLDWHITE << "Table two was successfully cleaned!" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
                
                t2.setCleanStatus(true); 
            }
            else if (t2.getAvailability() == false && p.getOrderTaken(2) == true)
            {
                cout << RED << "You already took my order! Where is my order?! \\(◣_◢)/" << RESET << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }
        }


        // Table three functions
        if(p.getOrderTakenCritic() == false && m.isCriticLocation(7,2) && m.getPlayerRow() == 7 && m.getPlayerCol() == 2) // taking the critic's order at table one
        {
            cout << "Press 'c' to take " << MAGENTA << final_boss.getName() << RESET << "'s order or press WASD to move again" << endl;
            cin >> cont_exit;
            if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                do{
                    cout << BLACK << "Please enter a valid input." << RESET <<endl;
                    cin >> cont_exit;
                }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
            }
            system("clear");
            switch(cont_exit)
            {
                case 'w': 
                    m.move('w');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'a': 
                    m.move('a');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 's': 
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'd': 
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'c':
                    system("clear");
                    cout << BOLDMAGENTA << "Greetings, I would like the finest items on the menu... " << RESET << endl;
                    cout << BOLDWHITE << final_boss.getCustomerOrder(customer_count) << RESET << endl;
                    cout << endl;
                    cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                    cin >> cont_exit;
                    if(cont_exit != 'e')
                    {
                        do
                        {
                            cout << BLACK << "Please enter a valid input." << RESET << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'e');
                    }
                    system("clear");
                    p.setOrderTaken(3, true);
                    p.setOrderTakenCritic(true);
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << BOLDWHITE << final_boss.getName() <<"'s order has been taken" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                    break;
            }
        }
        else if(p.getOrderTakenCritic() == true && k_critic.gotOrderAtKitchen() == true && m.isCriticLocation(7,2) && m.getPlayerRow() == 7 && m.getPlayerCol() == 2)
        {
                cout << "Press 'c' to deliver the order to Table 1" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                    {
                        while(cont_exit != 'c'){
                            cout << BLACK << "Please enter valid input." << RESET << endl;
                            cin >> cont_exit;
                        }
                    }
                if(cont_exit == 'c')
                {
                    system("clear");
                }
                if(cont_exit == 'c')
                {
                    cout << MAGENTA << "Interesting... I will send in my evaluations later. Thank you for the courses tonight.✧" << RESET << endl;
                    final_boss.setOrderDelivered(true);
                    if(p.serverSlip())
                    {
                        final_boss.decreaseSatisfaction20();
                    }
                    if(k_critic.getCorrectApp() == false)
                    {
                        final_boss.decreaseSatisfactionApp20();
                    }
                    if(k_critic.getCorrectEntree() == false)
                    {
                        final_boss.decreaseSatisfactionEntree20();
                    }
                    if(k_critic.getCorrectDessert() == false)
                    {
                        final_boss.decreaseSatisfactionDessert20();
                    }
                    if(k_critic.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                    {
                        final_boss.decreaseSatisfaction10();
                    }
                    if(k_critic.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                    {
                        final_boss.decreaseSatisfaction5();
                    }
                }
                if(final_boss.getOrderDelivered() == true)
                {
                    system("clear");
                    cout << YELLOW << "Congrats! You finished the game!" << RESET << endl; // ending seq
                    cout << CYAN << "------" << BOLDYELLOW << "STATS" << CYAN << "---" << YELLOW << "OF" << CYAN << "---" << BOLDYELLOW << p.getName() << CYAN << "------" << RESET <<endl;
                    cout << "Customers Served: " << customer_count << endl;
                    writeToFile(c1.getSatisfaction(), c2.getSatisfaction(), c3.getSatisfaction(), c4.getSatisfaction(), c5.getSatisfaction());
                    bubbleSort();
                    cout << "Critic Three Course Meal Ratings: " << endl;
                    cout << "Appetizer Rating: " << BOLDWHITE << final_boss.getSatisfaction1() << RESET << endl;
                    cout << "Entrees Rating: " << BOLDWHITE << final_boss.getSatisfaction2() << RESET << endl;
                    cout << "Dessert Rating: " << BOLDWHITE << final_boss.getSatisfaction3() << RESET << endl;
                    int avg = (final_boss.getSatisfaction1() + final_boss.getSatisfaction2() + final_boss.getSatisfaction3() + final_boss.getSatisfaction()) / 4.0;
                    cout << "Critic Overall Review: " << BOLDRED << avg << RESET << endl;
                    cout << BOLDCYAN << "Game Over!" << RESET <<endl;
                    cout << BLACK << "Thank you for playing." << RESET << endl;
                    return 0;
                }
        }
        else if(m.getPlayerCol() == 2 && m.getPlayerRow() == 7 && customer_count <= 5)
        {
            if(t3.getAvailability() == false && p.getOrderTaken(3) == false) // taking the customer's order
            {
                cout << "Press 'c' to take table three's order or press WASD to move again" << endl;
                cin >> cont_exit;
                if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                    do{
                        cout << BLACK << "Please enter a valid input." << RESET << endl;
                        cin >> cont_exit;
                    }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
                }
                system("clear");
                switch(cont_exit)
                {
                    case 'w': 
                        m.move('w');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'a': 
                        m.move('a');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 's': 
                        m.move('s');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'd': 
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'c':
                        system("clear");
                        cout << "Blorb there! I would like to order ";
                        if(customer_count == 1){
                            cout << BOLDWHITE << c1.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 2){
                            cout << BOLDWHITE << c2.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 3){
                            cout << BOLDWHITE << c3.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 4){
                            cout << BOLDWHITE << c4.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 5){
                            cout << BOLDWHITE << c5.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        cin >> cont_exit;
                        if(cont_exit != 'e')
                        {
                            do
                            {
                                cout << BLACK << "Please enter a valid input." << RESET << endl;
                                cin >> cont_exit;
                            }while(cont_exit != 'e');
                        }
                        system("clear");
                        p.setOrderTaken(3, true);
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        cout << BOLDWHITE << "Table three's order has been taken" << RESET << endl;
                        cout << BLACK << "Use WASD to move again" << RESET << endl;
                        break;
                }
            }

            if(t3.getAvailability() == false && p.getOrderTaken(3) == true) // delivering the order to the customer
            {
                if(customer_count == 1 && k1.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 3" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c1.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        if(k1.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        else if(k1.getCorrectFood() == true)
                        {
                            cout << "YOOOO THIS FIRE FR" << endl;
                        }
                        if(k1.assignFoodVal() == 1 && k1.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction10();
                        }
                        if(k1.assignFoodVal() == 3 && k1.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if(cont_exit == 'c'){
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                        else{
                            while( cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << endl;
                                cin >> cont_exit;
                            }
                            system("clear");
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 2 && k2.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 3" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c2.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        if(k2.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        else if(k2.getCorrectFood() == true)
                        {
                            cout << "YOOOO THIS FIRE FR" << endl;
                        }
                        if(k2.assignFoodVal() == 1 && k2.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction10();
                        }
                        if(k2.assignFoodVal() == 3 && k2.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 3 && k3.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 3" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c3.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        if(k3.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        else if(k3.getCorrectFood() == true)
                        {
                            cout << "YOOOO THIS FIRE FR" << endl;
                        }
                        if(k3.assignFoodVal() == 1 && k3.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction10();
                        }
                        if(k3.assignFoodVal() == 3 && k3.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 4 && k4.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 3" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c4.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        if(k4.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        else if(k4.getCorrectFood() == true)
                        {
                            cout << "YOOOO THIS FIRE FR" << endl;
                        }
                        if(k4.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction10();
                        }
                        if(k4.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 5 && k5.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 3" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c5.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        if(k5.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        else if(k5.getCorrectFood() == true)
                        {
                            cout << "YOOOO THIS FIRE FR" << endl;
                        }
                        if(k5.assignFoodVal() == 1 && k5.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction10();
                        }
                        if(k5.assignFoodVal() == 3 && k5.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }

                if(c1.getOrderDelivered() == true){
                    int c1_table = c1.getTable();
                    if(c1_table == 3)
                    {
                        m.removeNPC(7,2);
                        m.addTable(7,2);
                        t3.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c1.setOrderDelivered(false);
                        p.setOrderTaken(3, false);
                    } 
                }
                else if(c2.getOrderDelivered() == true)
                {
                    int c2_table = c2.getTable();
                    if(c2_table == 3)
                    {
                        m.removeNPC(7,2);
                        m.addTable(7,2);
                        t3.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c2.setOrderDelivered(false);
                        p.setOrderTaken(3, false);
                    } 
                }
                else if(c3.getOrderDelivered() == true)
                {
                    int c3_table = c3.getTable();
                    if(c3_table == 3)
                    {
                        m.removeNPC(7,2);
                        m.addTable(7,2);
                        t3.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c3.setOrderDelivered(false);
                        p.setOrderTaken(3, false);
                    } 
                }
                else if(c4.getOrderDelivered() == true)
                {
                    int c4_table = c4.getTable();
                    if(c4_table == 3)
                    {
                        m.removeNPC(7,2);
                        m.addTable(7,2);
                        t3.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c4.setOrderDelivered(false);
                        p.setOrderTaken(3, false);
                    } 
                }
                else if(c5.getOrderDelivered() == true)
                {
                    int c5_table = c5.getTable();
                    if(c5_table == 3)
                    {
                        m.removeNPC(7,2);
                        m.addTable(7,2);
                        t3.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c5.setOrderDelivered(false);
                        p.setOrderTaken(3, false);
                    } 
                }
            }
            else if(t3.getAvailability() == true && t3.getCleanStatus() == false) // cleaning the table
            {
                cout << "Press 'c' to clean the table" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                {
                    while(cont_exit != 'c'){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> cont_exit;
                    }
                }
                if(cont_exit == 'c'){
                    t3.setCleanStatus(true);
                    cout << BOLDWHITE << "Table three was successfully cleaned!" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
                
                t3.setCleanStatus(true); 
            }
            else if (t3.getAvailability() == false && p.getOrderTaken(3) == true)
            {
                cout << RED << "You already took my order! Where is my order?! \\(◣_◢)/" << RESET << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }

        }

        // Table four functions
        if(p.getOrderTakenCritic() == false && m.isCriticLocation(8,9) && m.getPlayerRow() == 8 && m.getPlayerCol() == 9) // taking the critic's order at table one
        {
            cout << "Press 'c' to take " << MAGENTA << final_boss.getName() << RESET << "'s order or press WASD to move again" << endl;
            cin >> cont_exit;
            if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                do{
                    cout << BLACK << "Please enter a valid input." << RESET << endl;
                    cin >> cont_exit;
                }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
            }
            system("clear");
            switch(cont_exit)
            {
                case 'w': 
                    m.move('w');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'a': 
                    m.move('a');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 's': 
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'd': 
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'c':
                    system("clear");
                    cout << BOLDMAGENTA << "Greetings, I would like the finest items on the menu... " << RESET << endl;
                    cout << BOLDWHITE << final_boss.getCustomerOrder(customer_count) << RESET << endl;
                    cout << endl;
                    cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                    cin >> cont_exit;
                    if(cont_exit != 'e')
                    {
                        do
                        {
                            cout << BLACK << "Please enter a valid input." << RESET << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'e');
                    }
                    system("clear");
                    p.setOrderTaken(4, true);
                    p.setOrderTakenCritic(true);
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << BOLDWHITE << final_boss.getName() <<"'s order has been taken" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                    break;
            }
        }
        else if(p.getOrderTakenCritic() == true && k_critic.gotOrderAtKitchen() == true && m.isCriticLocation(8,9) && m.getPlayerRow() == 8 && m.getPlayerCol() == 9)
        {
                cout << "Press 'c' to deliver the order to Table 1" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                    {
                        while(cont_exit != 'c'){
                            cout << BLACK << "Please enter valid input." << RESET << endl;
                            cin >> cont_exit;
                        }
                    }
                if(cont_exit == 'c')
                {
                    system("clear");
                }
                if(cont_exit == 'c')
                {
                    cout << MAGENTA << "Interesting... I will send in my evaluations later. Thank you for the courses tonight.✧" << RESET << endl;
                    final_boss.setOrderDelivered(true);
                    if(p.serverSlip())
                    {
                        final_boss.decreaseSatisfaction20();
                    }
                    if(k_critic.getCorrectApp() == false)
                    {
                        final_boss.decreaseSatisfactionApp20();
                    }
                    if(k_critic.getCorrectEntree() == false)
                    {
                        final_boss.decreaseSatisfactionEntree20();
                    }
                    if(k_critic.getCorrectDessert() == false)
                    {
                        final_boss.decreaseSatisfactionDessert20();
                    }
                    if(k_critic.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                    {
                        final_boss.decreaseSatisfaction10();
                    }
                    if(k_critic.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                    {
                        final_boss.decreaseSatisfaction5();
                    }
                }
                if(final_boss.getOrderDelivered() == true)
                {
                    system("clear");
                    cout << YELLOW << "Congrats! You finished the game!" << RESET << endl; // ending seq
                    cout << CYAN << "------" << BOLDYELLOW << "STATS" << CYAN << "---" << YELLOW << "OF" << CYAN << "---" << BOLDYELLOW << p.getName() << CYAN << "------" << RESET <<endl;
                    cout << "Customers Served: " << customer_count << endl;
                    writeToFile(c1.getSatisfaction(), c2.getSatisfaction(), c3.getSatisfaction(), c4.getSatisfaction(), c5.getSatisfaction());
                    bubbleSort();
                    cout << "Critic Three Course Meal Ratings: " << endl;
                    cout << "Appetizer Rating: " << BOLDWHITE << final_boss.getSatisfaction1() << RESET << endl;
                    cout << "Entrees Rating: " << BOLDWHITE << final_boss.getSatisfaction2() << RESET << endl;
                    cout << "Dessert Rating: " << BOLDWHITE << final_boss.getSatisfaction3() << RESET << endl;
                    int avg = (final_boss.getSatisfaction1() + final_boss.getSatisfaction2() + final_boss.getSatisfaction3() + final_boss.getSatisfaction()) / 4.0;
                    cout << "Critic Overall Review: " << BOLDRED << avg << RESET << endl;
                    cout << BOLDCYAN << "Game Over!" << RESET <<endl;
                    cout << BLACK << "Thank you for playing." << RESET << endl;
                    return 0;
                }
        }
        else if(m.getPlayerCol() == 9 && m.getPlayerRow() == 8 && customer_count <= 5)
        {
            if(t4.getAvailability() == false && p.getOrderTaken(4) == false) // taking the customer's order
            {
                cout << "Press 'c' to take table four's order or press WASD to move again" << endl;
                cin >> cont_exit;
                if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd')
                {
                    do
                    {
                        cout << BLACK << "Please enter a valid input." << RESET << endl;
                        cin >> cont_exit;
                    }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
                }
                system("clear");
                switch(cont_exit)
                {
                    case 'w': 
                        m.move('w');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'a': 
                        m.move('a');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 's': 
                        m.move('s');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'd': 
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'c':
                        system("clear");
                        cout << "Blorb there! I would like to order ";
                        if(customer_count == 1)
                        {
                            cout << BOLDWHITE << c1.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 2)
                        {
                            cout << BOLDWHITE << c2.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 3)
                        {
                            cout << BOLDWHITE << c3.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 4)
                        {
                            cout << BOLDWHITE << c4.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 5)
                        {
                            cout << BOLDWHITE << c5.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        cin >> cont_exit;
                        if(cont_exit != 'e')
                        {
                            do
                            {
                                cout << BLACK << "Please enter a valid input." << RESET << endl;
                                cin >> cont_exit;
                            }while(cont_exit != 'e');
                        }
                        system("clear");
                        p.setOrderTaken(4, true);
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        cout << BOLDWHITE << "Table four's order has been taken" << RESET << endl;
                        cout << BLACK << "Use WASD to move again" << RESET << endl;
                        break;
                }
            }

            if(t4.getAvailability() == false && p.getOrderTaken(4) == true) // delivering the order to the customer
            {
                if(customer_count == 1 && k1.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 4" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c1.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        if(k1.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        else if(k1.getCorrectFood() == true)
                        {
                            cout << "Scrumpdidl-icious, ya got the best food in town!" << endl;
                        }
                        if(k1.assignFoodVal() == 1 && k1.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction10();
                        }
                        if(k1.assignFoodVal() == 3 && k1.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 2 && k2.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 4" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c2.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        if(k2.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        else if(k2.getCorrectFood() == true)
                        {
                            cout << "Scrumpdidl-icious, ya got the best food in town!" << endl;
                        }
                        if(k2.assignFoodVal() == 1 && k2.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction10();
                        }
                        if(k2.assignFoodVal() == 3 && k2.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 3 && k3.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 4" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c3.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        if(k3.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        else if(k3.getCorrectFood() == true)
                        {
                            cout << "Scrumpdidl-icious, ya got the best food in town!" << endl;
                        }
                        if(k3.assignFoodVal() == 1 && k3.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction10();
                        }
                        if(k3.assignFoodVal() == 3 && k3.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 4 && k4.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 4" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c4.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        if(k4.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        else if(k4.getCorrectFood() == true)
                        {
                            cout << "Scrumpdidl-icious, ya got the best food in town!" << endl;
                        }
                        if(k4.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction10();
                        }
                        if(k4.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 5 && k5.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 4" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c5.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        if(k5.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        else if(k5.getCorrectFood() == true)
                        {
                            cout << "Scrumpdidl-icious, ya got the best food in town!" << endl;
                        }
                        if(k5.assignFoodVal() == 1 && k5.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction10();
                        }
                        if(k5.assignFoodVal() == 3 && k5.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                    
                if(c1.getOrderDelivered() == true){
                    int c1_table4 = c1.getTable();
                    if(c1_table4 == 4)
                    {
                        m.removeNPC(8,9);
                        m.addTable(8,9);
                        t4.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c1.setOrderDelivered(false);
                        p.setOrderTaken(4, false);
                    } 
                }
                else if(c2.getOrderDelivered() == true)
                {
                    int c2_table = c2.getTable();
                    if(c2_table == 4)
                    {
                        m.removeNPC(8,9);
                        m.addTable(8,9);
                        t4.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c2.setOrderDelivered(false);
                        p.setOrderTaken(4, false);
                    } 
                }
                else if(c3.getOrderDelivered() == true)
                {
                    int c3_table = c3.getTable();
                    if(c3_table == 4)
                    {
                        m.removeNPC(8,9);
                        m.addTable(8,9);
                        t4.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c3.setOrderDelivered(false);
                        p.setOrderTaken(4, false);
                    } 
                }
                else if(c4.getOrderDelivered() == true)
                {
                    int c4_table = c4.getTable();
                    if(c4_table == 4)
                    {
                        m.removeNPC(8,9);
                        m.addTable(8,9);
                        t4.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c4.setOrderDelivered(false);
                        p.setOrderTaken(4, false);
                    } 
                }
                else if(c5.getOrderDelivered() == true)
                {
                    int c5_table = c5.getTable();
                    if(c5_table == 4)
                    {
                        m.removeNPC(8,9);
                        m.addTable(8,9);
                        t4.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c5.setOrderDelivered(false);
                        p.setOrderTaken(4, false);
                    } 
                }
            }
            else if(t4.getAvailability() == true && t4.getCleanStatus() == false) // cleaning the table
            {
                cout << "Press 'c' to clean the table" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                {
                    while(cont_exit != 'c'){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> cont_exit;
                    }
                }
                if(cont_exit == 'c'){
                    t1.setCleanStatus(true);
                    cout << BOLDWHITE << "Table four was successfully cleaned!" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
                
                t4.setCleanStatus(true); 
            }
            else if (t4.getAvailability() == false && p.getOrderTaken(1) == true)
            {
                cout << RED << "You already took my order! Where is my order?! \\(◣_◢)/" << RESET << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }

        }


        // Table five functions
        if(p.getOrderTakenCritic() == false && m.isCriticLocation(9,2) && m.getPlayerRow() == 9 && m.getPlayerCol() == 2) // taking the critic's order at table one
        {
            cout << "Press 'c' to take " << MAGENTA << final_boss.getName() << RESET << "'s order or press WASD to move again" << endl;
            cin >> cont_exit;
            if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                do{
                    cout << BLACK << "Please enter a valid input." << RESET << endl;
                    cin >> cont_exit;
                }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
            }
            system("clear");
            switch(cont_exit)
            {
                case 'w': 
                    m.move('w');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'a': 
                    m.move('a');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 's': 
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'd': 
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    break;
                case 'c':
                    system("clear");
                    cout << BOLDMAGENTA << "Greetings, I would like the finest items on the menu... " << RESET << endl;
                    cout << BOLDWHITE << final_boss.getCustomerOrder(customer_count) << RESET << endl;
                    cout << endl;
                    cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                    cin >> cont_exit;
                    if(cont_exit != 'e')
                    {
                        do
                        {
                            cout << BLACK << "Please enter a valid input." << RESET << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'e');
                    }
                    system("clear");
                    p.setOrderTaken(5, true);
                    p.setOrderTakenCritic(true);
                    m.move('d');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << BOLDWHITE << final_boss.getName() <<"'s order has been taken" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                    break;
            }
        }
        else if(p.getOrderTakenCritic() == true && k_critic.gotOrderAtKitchen() == true && m.isCriticLocation(9,2) && m.getPlayerRow() == 9 && m.getPlayerCol() == 2)
        {
                cout << "Press 'c' to deliver the order to Table 1" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                    {
                        while(cont_exit != 'c'){
                            cout << BLACK << "Please enter valid input." << RESET << endl;
                            cin >> cont_exit;
                        }
                    }
                if(cont_exit == 'c')
                {
                    system("clear");
                }
                if(cont_exit == 'c')
                {
                    cout << MAGENTA << "Interesting... I will send in my evaluations later. Thank you for the courses tonight.✧" << RESET << endl;
                    final_boss.setOrderDelivered(true);
                    if(p.serverSlip())
                    {
                        final_boss.decreaseSatisfaction20();
                    }
                    if(k_critic.getCorrectApp() == false)
                    {
                        final_boss.decreaseSatisfactionApp20();
                    }
                    if(k_critic.getCorrectEntree() == false)
                    {
                        final_boss.decreaseSatisfactionEntree20();
                    }
                    if(k_critic.getCorrectDessert() == false)
                    {
                        final_boss.decreaseSatisfactionDessert20();
                    }
                    if(k_critic.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                    {
                        final_boss.decreaseSatisfaction10();
                    }
                    if(k_critic.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                    {
                        final_boss.decreaseSatisfaction5();
                    }
                }
                if(final_boss.getOrderDelivered() == true)
                {
                    system("clear");
                    cout << YELLOW << "Congrats! You finished the game!" << RESET << endl; // ending seq
                    cout << CYAN << "------" << BOLDYELLOW << "STATS" << CYAN << "---" << YELLOW << "OF" << CYAN << "---" << BOLDYELLOW << p.getName() << CYAN << "------" << RESET <<endl;
                    cout << "Customers Served: " << customer_count << endl;
                    writeToFile(c1.getSatisfaction(), c2.getSatisfaction(), c3.getSatisfaction(), c4.getSatisfaction(), c5.getSatisfaction());
                    bubbleSort();
                    cout << "Critic Three Course Meal Ratings: " << endl;
                    cout << "Appetizer Rating: " << BOLDWHITE << final_boss.getSatisfaction1() << RESET << endl;
                    cout << "Entrees Rating: " << BOLDWHITE << final_boss.getSatisfaction2() << RESET << endl;
                    cout << "Dessert Rating: " << BOLDWHITE << final_boss.getSatisfaction3() << RESET << endl;
                    int avg = (final_boss.getSatisfaction1() + final_boss.getSatisfaction2() + final_boss.getSatisfaction3() + final_boss.getSatisfaction()) / 4.0;
                    cout << "Critic Overall Review: " << BOLDRED << avg << RESET << endl;
                    cout << BOLDCYAN << "Game Over!" << RESET <<endl;
                    cout << BLACK << "Thank you for playing." << RESET << endl;
                    return 0;
                }
        }
        else if(m.getPlayerCol() == 2 && m.getPlayerRow() == 9 && customer_count <= 5)
        {
            if(t5.getAvailability() == false && p.getOrderTaken(5) == false) // taking the customer's order
            {
                cout << "Press 'c' to take table five's order or press WASD to move again" << endl;
                cin >> cont_exit;
                if(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd'){
                    do{
                        cout << BLACK << "Please enter a valid input." << RESET << endl;
                        cin >> cont_exit;
                    }while(cont_exit != 'c' && cont_exit != 'w' && cont_exit != 'a' && cont_exit != 's' && cont_exit != 'd');
                }
                system("clear");
                switch(cont_exit)
                {
                    case 'w': 
                        m.move('w');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'a': 
                        m.move('a');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 's': 
                        m.move('s');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'd': 
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        break;
                    case 'c':
                        system("clear");
                        cout << "Blorb there! I would like to order ";
                        if(customer_count == 1)
                        {
                            cout << BOLDWHITE << c1.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 2)
                        {
                            cout << BOLDWHITE << c2.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 3)
                        {
                            cout << BOLDWHITE << c3.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 4)
                        {
                            cout << BOLDWHITE << c4.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        else if(customer_count == 5)
                        {
                            cout << BOLDWHITE << c5.getCustomerOrder(customer_count) << RESET << endl;
                            cout << endl;
                            cout << "Press 'e' to exit. Make sure to remember the order!" << endl;
                        }
                        cin >> cont_exit;
                        if(cont_exit != 'e')
                        {
                            do
                            {
                                cout << BLACK << "Please enter a valid input." << RESET << endl;
                                cin >> cont_exit;
                            }while(cont_exit != 'e');
                        }
                        system("clear");
                        p.setOrderTaken(5, true);
                        m.move('d');
                        m.displayMap();
                        displayEnergy(p.getEnergy());
                        cout << BOLDWHITE << "Table five's order has been taken" << RESET << endl;
                        cout << BLACK << "Use WASD to move again" << RESET << endl;
                        break;
                }
            }

            if(t5.getAvailability() == false && p.getOrderTaken(5) == true) // delivering the order to the customer
            {
                if(customer_count == 1 && k1.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 5" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c1.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        if(k1.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction20();
                        }
                        else if(k1.getCorrectFood() == true)
                        {
                            cout << "Į̵̢̛̱̩̖̗͕̳̼̮̪̳̼̣̹̜͙̳̝͓̜̝̣͎̺͋́̀̑̀̎̓͐͆͑̍̐̔̃̉͐̏̂͒̑̍́̀́̀͑̚̚̚͝͝͝ͅ ̵̡̛̛̦͈̹͎̝̗̬̲̥̘̝͍̜͎͋̉̆͋̔̍̈́̀̓͊̇̈́̊̌̀̓̄͗̈͋̎͐̂̌͒̈́̽́̈́̉̒̌͂͗͂̓͋͊̉̓́̑̍͘̚͝͝͝ͅͅt̸̨̧̡̡̧̛͇̝̳̟̜̹̹͕̝̲͉̪͖̱͈̫͓̘̜̞͇͈̜͚͍̗̞̜̦͔̼̤̜͛͂̈̎̽̇̉̽̓͗́̔̋̀͋̉̎̇̈͑͗́̋̊͌̅͐͒͐̉̆̐̔͐̈́̾̀̇̃̄̊̾̇̚͘͘͜͠͝ͅͅͅĥ̷̢̡̛̛̳̩̼̲͖̗̗̜̩͉̣͎̰̯̝̟̠̰̗̝͖̗͖̰̪̥̪͉̠̞̯͊͗̒̑̽̔̾̈́̇̅̀͛̍̓͑͂̒̈́̈̎̈́̏͘͜͠͝ͅï̶̧̧̢̡̛̠͎͕͓̩̞̻̲̯͙͔̗͚̹̲̤̝͉͊̐͑̊̉̓́͊̇͑̀̉͛̏͐͋̅̓͂͘̕̚̕͜͝͝ͅn̶̛̛̛̟̗͈̣͔̅͌̋̑̔̉͗͐̅͋̐̀̎̒̉̾̃̏͛̄͑̔͆̋̈́̂̈́̅̈́́͗̐̽͋̓̕̕͝͝͠͝͠͝͝͠k̴̨̢̨̧̛̙̩̠̱͔͎̭̦̘͔͎͍̠͚̼̼͉̱̥̺̜͚̰̼̱͎̟̝̗͇͙͎̬̩̹̙͖̪̣̲͆̆̇͂͋͗̀̏̊̊̀̉͛͋̔̏̓̈́̈̽͊̅͂̕͘͘͜͜͝ͅ ̷̠̗̻̩̱̮͊̐̓̈́̔͌̓̅͋̈͐͛̀́̋̽̈́̿́̌̃̓̃̅̏̕͠͠ť̶̡̧̧̛̙̠̭̭͕͈̗͎͖͓͓̼̰͚̘̘̪̬̺̘̩̩̦̪̼̮̼̣̼̼̿́͋͊́̔̄̃̈́̓̊̿̎̀̐͋̎̈́̚̕̚̕͝ͅh̸̢̠̟̖̩̳̼̭͕͙͕̉̌͌̋̔͒̂̿͝͝å̸̢̡̡̜̤͖̹͖͖̤̲̙͓̫͍̹̳̹̫̗͖͍̖͖͓̩̻̭̰̥͓̼̣͉͓̞̜͖̠͓̖͇̗͈̰̙͙͊̓́̒̀̃͌͛̽͒̈́͛̌̀͂̊̅̌́͂̊̈́̄̕̚͠͝t̷̨̡̡̡̡̢̡̛̛͓͍̺̖̳̖̞̦̟̮̹̦̗͕͚͎̦͍̩͈͍̥͍̼̗̲͍͇͖̟̘̤̺̦̗̼͇̙̪͇̳̔̇͐̉̀͂̈̄͆̋̀̑̽̈́̿̈́̔̏̎͐̑̀͌̋͐͌̑̕̚͘͠͠͝ ̵̢̢̢̢͔̮̼͓̼̰͙͓̳̝͎͉̜̬͈̪̖̬̬̠͚̗̜̹̹̜͖̙̘͖͇̤͚̮͍̞͇̳̜͚̱̜͇̝̂̆̎́́̎̽́̽̒̓͌̚͜͜t̸̢̨̧̧̨̢̛̛̖͓̙͇͎͓̘̗͈͉̫̻̗̠̺̣͙̱̮̝͍̞̖͙̦͇̟̲͕̮͎̲̠̣̦͊͛̂̆́̌̓̒̔̑̋̿̅͌͆͆͛̽͑̍̽̐͌̑͐͋̀̏̍̌̈̊̍́͛̐̍̿̄͘̕͝͝͝h̷̨̢̧̯̣̲̩̳̣̪̙͙͎̮͙̙̣͚̳̤̳̻͎̘͎̹̝̥͔̺͔̖͔͍̼͈̲̞̣͍͖͇̋̊̓̎̔̑̊͜͜͜͠ͅͅȩ̶̨̧̡̡̢̡̛͇̩͔̲͓͍̥̞̯̙̗̟̱̞̯̯̹̞͓̼̤͚̤̱͉͚̦̳͎͇͉͕͑̍̀̀͂͗̑̈͌̅̿̔̐͒̅̈̆̌̿̽͋̐͂̎͂͑̏̿̔̌̏̍͗͗͐͘̚͜͠͝ͅͅś̵͓͕̦͎̺̠̦̫̣̞͖̟͎̀̉͛͐̐̎͊̅͗̇̑́̋̓͂̔́͝ḛ̴̢̛̞̭̮̤͍̫͔̤̙̙̥̮͈͇̹̺̫̳̿̂̔͌̔̎̿̓͗͒̋̑͑͂͐̈͋́́͐̈́́͆̊́̔̽͂́͗̐̓̏͑͋̃̚̕̕̚͠͝͝͝ ̸̧̛̺̖̻͔̤̺̹̜͖͈̗̯̙͕̣̖̻̱̰̳̦̣̭̩̐̑̊̋̄̈́̍̎̅͋̃̀̃͛̓͆̋͊̄͂̉̆͑̌̃́͆͛͋̐͛͌͗͛̋̆͑̋̔̀́͘͘͘̕͜͝͝ͅw̵̡̢̡̨̧͎̳̺̙͎̘̹̦̲̝̮͇͓̘̦̦̼͎͈̪̩̗̱̝͖̖̣̪͇͆͋̇́͑́͛̈́̒̎̀̓̌̌̓̿̂͐́̋̃̾͊̊̇̈͋̾̑̅̔̊̏̈́̊͂́̋̊̕̕̚͘̕͝e̸̡̛͔͉̘̖̠̰̰̭͓͈͊̂̄͂͐̍̓̎̆̌͐̎̈́̂́͐̈́͊̈̀̅͆̃̈́̅̏̄͋̋̀͗̀͆́̈́̅̿̀̽́̌̕̚͘̚͝͠ͅŗ̷͙̻̱̣̜͉̃̄̅̾̇̽͌̈́e̸̡̛̛̤̠̫̪̲̞̺̗͙̮̼̗̘̼̅̏͌͛̔͋̍̃́̾̌̌͐̎̂̊̊̆́͑͐͗̅̿͊̀̊͌̀̊̀͘͘̕͜͠͝͠͝ͅ ̸̦̮̍̍͋t̸͕̘̖̬͙͙͍̮̦͋̅̎̽̈̀̈̾̂͒̉̽̿͑̈́͑͆͒͆̀̔̊̍̀̏̂̈́͋́̿̐̄́̎̓̚͘͠͝͠͠͠h̸̢̡̢̧̛̛̙̳̜̠̩̭̗̠̰̥͓̦̖̥̙̤͚͔̱̠̰̫̼̘̹̰̞̻̗̬͍̖̪̜̖̬̗͚̭̓̄̃̐́̄̍̓̉̂͑̃̃̾͐̄̑̍́͐̐̐̿̕̚͘͜͜ė̵͙̘̤͔͉͓̣̹̺̠̼͎͖̣̲̀̓͐̏̔̓̒̂͑́̌̉̈̐̿́̚̕͘͠ ̶̡̛͎̝̝̜̝͔̻͓̮̬̳̦͓͍̥͎͔̝͚̩̘͕̩̩̌̈́͐̓̂̄̂̿́͌̂́͌̂̔͂̉̐͋́̽̐̎̈́͋͒͐͌̔̾̀͊̒̚͘͘̕͝ͅb̵̬͙̰̗͈̣̪̤̣͉͖͚̙̗̰͑͊̈́̓̀̍̓͗̋̽̓̊̽̏̒̏͗̎̆̀̌͠͠͝͝͝e̸̘͚̬͇̣͖̟͍͈̤͙͕̻̞̦̩̤̤͎̱̼͚̣̠͖̖̙͕̣͚̬̗̥̘̅̃͂̽̇̎́̈́̚͜ͅş̸̨̢̡̨̧͔̫̬͖̮̭̭͍͙̺̹͕͓̪͕̯͇̩̘̗̮̜̜̲͓͎̲͚̖̘̦̣̩͍̯̘̼̠̼̺̎̽̐̔̽͑̂̂͐̀̏̂̓͘͝ͅţ̴̛̟̤̥̭̤̜̠̠̠̫̫̺̲̞͍͕̭̦̗̤͇̹͇̥͙͖̘̠̳̮͚͖͕̗̺̠̭̭̦̟̹͒̍͐̃̄͐̇̔͜͠ͅ ̸̧̧̼͍̬̺͎̫̫̻̗͙̮̣̑̐̂͊͋͛̐́̾͆͋͌̏̀̐͐͐͛̍̎͛̂̂͋̐̅̍͂̒͌͑̑́͋̈́́̈́̂̄̕͘̚̕͝͠ḑ̶̨̡̛̪̺̞͎̭̦̱̜̗̩̗͚̣̻̫̙͍͓̩͔̻̩͍̱͔̲̦̪͓̳͉͖͓͑̀̓̐̐̔͛̇̽̓͛̄̉̐̌̍͋͌̀̒̄̊̀͊̒̃̿̿͑͆̔̽̈́̽̿͋̔̋̀͛̕͘͘͠ḯ̵̡͕̬͖̟̖͚͙̳̞͔̩̖̺̖͉͖̰̤̬̰̥̺̘̺̹̗͉͝͠ṣ̸̨̢̢̢̹̻̦̦̯̝̬̤͍̬͉̼̦̞͔̠̘̱͔̮̮̝̫̪̞͈̘̤̱̥̙̪͍̥̼̻̟̱̻̫̦͋̊̉̈́̑͋̂̄̎͐̅̽́́̍̿̊̅͘̕̚͝͝ḩ̴̢͔͕̰̩̞̣̹̻̻̻͙͙̞͙̳͍̖̻̯͔̋̄̔͋͗̈́͗̀́̏̊̏̓̃̚͠͠ȩ̴̲͓̤͇̭̑͊͗͋̉͒̕ṡ̸̡̡̡̛̠̱̠̩̻͓̝̻͕̞̬̖̼̘̳̬͎͍̪̹͕̙̝̯̠̥̜͈͔̘̼̥͖̰̪̖̼̰̘͙̤̈́̈̈́́̓̕ͅͅ ̸̧̡̧̢̠̠̼̪̳̙̠̮͎͖̜̙͚̘̪̖̺̹̭͂͊̓͑̎̎̇̾̂̂͂̌̃̄͆̔̒́̑̄͆̾͗̐̌̒͋̐̉̍̂̇͊́͐͗̈́̓͌̏͋̈́̕͘̕͘̕͜͜͝͠͝ͅͅI̷̢̢̡̩̤̲͔̜̺̻̙̳̰̗̭̫͈̼͎̞̤̜͖̠̰͎̩̭͍̰̜̣̜̟̘̙̼̗̗͒̀͂̓͛̐̄͐̓̄́̔͜͜͝͝ ̸̧̡̢̢̢̛̭͉̝̺̯̼̩̗̲͙͇̜͚̞̤͕̝̪͕̖̫̻̝̯̩͖̘͔̮̹̖͓̦̰͎̤̎̾̍̂̾́̈́͒̀̈́͑̋͗̾̂̈́̈̅̃̏͝͝͝ͅḩ̷̢̱̬̫̲̤̻̭̯͈͚́̓̀̏͌̐̍̐̈́͜͜a̵̡͙̯͈͉̞̤͔̯̯͋̓̍͑͊͌̂͐̋̇̄̎̍̏̃v̵̡̡͓̫̘̪͎̘̪̪͖͎̫̰͍̰̲̇̈́́̃͌͜ę̴̡͓̬̗̣̫̭͖͍̆̉̎̎̀ ̸̡̪͈͙̫̝̻̠̲͔͙͉̒̈͛͋̽̈͜ȇ̷̡̡̛̯̟̪͍͙̝̺̳̳̥̣̉́͊̈́͗̀̅͂̃̉́̍͗̎̍̃͋̂̔͘͜͝͝v̴̡̛̬̟̲͔̖̭̦̦̫̥̪̲̥̯͙̻͓͕̰͉͇̥͚̺͕̙̻̮̥̹̤̠̱͈͇͉̘͙̖̙̱̜̄̆̒̈́ͅͅé̷̯͓̙͍̬̯̟̮͇̾̈́̈́̆̈̊͐̒̈̐̀͂̑͌͗̽̎̌̉̃̓̽̒̿̈̎̍͌͛̿̔̓͐̈́͐͌̏̓́̀͊͘͘͝͝r̸̢̘̭̖̹̰̖͉͔͔̣̩̜͊͒̀̅̌̎́͛̎̌̊́̐̾̆͆̿̑̏̋̒͘͘͝ ̵̡̢̢̡͎̱̪͕̳̠̤̪̗͖͓̳̮̗͓̜͓̪͙͈̝̲̫͙̥̦̱̭̼͔͚̼͛̍͂̀͆͗́̂̀̄͑͌̈̅̎́̈̏̿̾̏̀͋͛́͋͌́͜͜͝͠͝͝ͅͅḧ̸͕̖̥̗͓̳̩̙́͂͊͑̃͒̍͆̅̋̈́̉̃͐̌̚͜͜͠ą̶̡̘̬͚̖̰̻̝̼̲͈̗̣̱̖͎̦͓̣͇̳̟̰̤̞̺͎̣̫̦̲͍̰̥͙̹̼̰̺̺͎̦̫͛̃̿̌͊̑͐̀̐̈́̒̊̿̾́́̑́̎̈́͆̒́͆̆͛̕͘̕̚̚̚͝͠͝ͅd̷̢̛̛͖̠̟̺͇̬̳͕͕͓̽̔́͆̉͂̇̂́̿̆̒̀̽͂̔͂̒̆͛̃͆̍̉̉̈́̆͑̇͆̌͑̌͛̈́̃̚̚̕̚͠͝͝!̴̨̢̧̢̛̠͍͖̦͕̼̮͓͕̗̜̲̞̹̘͕͙̠̼̹̬͕̹̗̼̰̗̺̱̦͛̒͌͂̆̉͛́̍̆̄͒̽̈́͑͗͂͗͛̀̄͋̈́̇̍͛̑̆̅́̒̀̍͂̑̕̕̕͜͜͜͝͝͝" << endl; // don't worry, it's just a font :)
                        }
                        if(k1.assignFoodVal() == 1 && k1.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction10();
                        }
                        if(k1.assignFoodVal() == 3 && k1.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c1.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 2 && k2.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 5" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c2.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        if(k2.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction20();
                        }
                        else if(k2.getCorrectFood() == true)
                        {
                            cout << "Į̵̢̛̱̩̖̗͕̳̼̮̪̳̼̣̹̜͙̳̝͓̜̝̣͎̺͋́̀̑̀̎̓͐͆͑̍̐̔̃̉͐̏̂͒̑̍́̀́̀͑̚̚̚͝͝͝ͅ ̵̡̛̛̦͈̹͎̝̗̬̲̥̘̝͍̜͎͋̉̆͋̔̍̈́̀̓͊̇̈́̊̌̀̓̄͗̈͋̎͐̂̌͒̈́̽́̈́̉̒̌͂͗͂̓͋͊̉̓́̑̍͘̚͝͝͝ͅͅt̸̨̧̡̡̧̛͇̝̳̟̜̹̹͕̝̲͉̪͖̱͈̫͓̘̜̞͇͈̜͚͍̗̞̜̦͔̼̤̜͛͂̈̎̽̇̉̽̓͗́̔̋̀͋̉̎̇̈͑͗́̋̊͌̅͐͒͐̉̆̐̔͐̈́̾̀̇̃̄̊̾̇̚͘͘͜͠͝ͅͅͅĥ̷̢̡̛̛̳̩̼̲͖̗̗̜̩͉̣͎̰̯̝̟̠̰̗̝͖̗͖̰̪̥̪͉̠̞̯͊͗̒̑̽̔̾̈́̇̅̀͛̍̓͑͂̒̈́̈̎̈́̏͘͜͠͝ͅï̶̧̧̢̡̛̠͎͕͓̩̞̻̲̯͙͔̗͚̹̲̤̝͉͊̐͑̊̉̓́͊̇͑̀̉͛̏͐͋̅̓͂͘̕̚̕͜͝͝ͅn̶̛̛̛̟̗͈̣͔̅͌̋̑̔̉͗͐̅͋̐̀̎̒̉̾̃̏͛̄͑̔͆̋̈́̂̈́̅̈́́͗̐̽͋̓̕̕͝͝͠͝͠͝͝͠k̴̨̢̨̧̛̙̩̠̱͔͎̭̦̘͔͎͍̠͚̼̼͉̱̥̺̜͚̰̼̱͎̟̝̗͇͙͎̬̩̹̙͖̪̣̲͆̆̇͂͋͗̀̏̊̊̀̉͛͋̔̏̓̈́̈̽͊̅͂̕͘͘͜͜͝ͅ ̷̠̗̻̩̱̮͊̐̓̈́̔͌̓̅͋̈͐͛̀́̋̽̈́̿́̌̃̓̃̅̏̕͠͠ť̶̡̧̧̛̙̠̭̭͕͈̗͎͖͓͓̼̰͚̘̘̪̬̺̘̩̩̦̪̼̮̼̣̼̼̿́͋͊́̔̄̃̈́̓̊̿̎̀̐͋̎̈́̚̕̚̕͝ͅh̸̢̠̟̖̩̳̼̭͕͙͕̉̌͌̋̔͒̂̿͝͝å̸̢̡̡̜̤͖̹͖͖̤̲̙͓̫͍̹̳̹̫̗͖͍̖͖͓̩̻̭̰̥͓̼̣͉͓̞̜͖̠͓̖͇̗͈̰̙͙͊̓́̒̀̃͌͛̽͒̈́͛̌̀͂̊̅̌́͂̊̈́̄̕̚͠͝t̷̨̡̡̡̡̢̡̛̛͓͍̺̖̳̖̞̦̟̮̹̦̗͕͚͎̦͍̩͈͍̥͍̼̗̲͍͇͖̟̘̤̺̦̗̼͇̙̪͇̳̔̇͐̉̀͂̈̄͆̋̀̑̽̈́̿̈́̔̏̎͐̑̀͌̋͐͌̑̕̚͘͠͠͝ ̵̢̢̢̢͔̮̼͓̼̰͙͓̳̝͎͉̜̬͈̪̖̬̬̠͚̗̜̹̹̜͖̙̘͖͇̤͚̮͍̞͇̳̜͚̱̜͇̝̂̆̎́́̎̽́̽̒̓͌̚͜͜t̸̢̨̧̧̨̢̛̛̖͓̙͇͎͓̘̗͈͉̫̻̗̠̺̣͙̱̮̝͍̞̖͙̦͇̟̲͕̮͎̲̠̣̦͊͛̂̆́̌̓̒̔̑̋̿̅͌͆͆͛̽͑̍̽̐͌̑͐͋̀̏̍̌̈̊̍́͛̐̍̿̄͘̕͝͝͝h̷̨̢̧̯̣̲̩̳̣̪̙͙͎̮͙̙̣͚̳̤̳̻͎̘͎̹̝̥͔̺͔̖͔͍̼͈̲̞̣͍͖͇̋̊̓̎̔̑̊͜͜͜͠ͅͅȩ̶̨̧̡̡̢̡̛͇̩͔̲͓͍̥̞̯̙̗̟̱̞̯̯̹̞͓̼̤͚̤̱͉͚̦̳͎͇͉͕͑̍̀̀͂͗̑̈͌̅̿̔̐͒̅̈̆̌̿̽͋̐͂̎͂͑̏̿̔̌̏̍͗͗͐͘̚͜͠͝ͅͅś̵͓͕̦͎̺̠̦̫̣̞͖̟͎̀̉͛͐̐̎͊̅͗̇̑́̋̓͂̔́͝ḛ̴̢̛̞̭̮̤͍̫͔̤̙̙̥̮͈͇̹̺̫̳̿̂̔͌̔̎̿̓͗͒̋̑͑͂͐̈͋́́͐̈́́͆̊́̔̽͂́͗̐̓̏͑͋̃̚̕̕̚͠͝͝͝ ̸̧̛̺̖̻͔̤̺̹̜͖͈̗̯̙͕̣̖̻̱̰̳̦̣̭̩̐̑̊̋̄̈́̍̎̅͋̃̀̃͛̓͆̋͊̄͂̉̆͑̌̃́͆͛͋̐͛͌͗͛̋̆͑̋̔̀́͘͘͘̕͜͝͝ͅw̵̡̢̡̨̧͎̳̺̙͎̘̹̦̲̝̮͇͓̘̦̦̼͎͈̪̩̗̱̝͖̖̣̪͇͆͋̇́͑́͛̈́̒̎̀̓̌̌̓̿̂͐́̋̃̾͊̊̇̈͋̾̑̅̔̊̏̈́̊͂́̋̊̕̕̚͘̕͝e̸̡̛͔͉̘̖̠̰̰̭͓͈͊̂̄͂͐̍̓̎̆̌͐̎̈́̂́͐̈́͊̈̀̅͆̃̈́̅̏̄͋̋̀͗̀͆́̈́̅̿̀̽́̌̕̚͘̚͝͠ͅŗ̷͙̻̱̣̜͉̃̄̅̾̇̽͌̈́e̸̡̛̛̤̠̫̪̲̞̺̗͙̮̼̗̘̼̅̏͌͛̔͋̍̃́̾̌̌͐̎̂̊̊̆́͑͐͗̅̿͊̀̊͌̀̊̀͘͘̕͜͠͝͠͝ͅ ̸̦̮̍̍͋t̸͕̘̖̬͙͙͍̮̦͋̅̎̽̈̀̈̾̂͒̉̽̿͑̈́͑͆͒͆̀̔̊̍̀̏̂̈́͋́̿̐̄́̎̓̚͘͠͝͠͠͠h̸̢̡̢̧̛̛̙̳̜̠̩̭̗̠̰̥͓̦̖̥̙̤͚͔̱̠̰̫̼̘̹̰̞̻̗̬͍̖̪̜̖̬̗͚̭̓̄̃̐́̄̍̓̉̂͑̃̃̾͐̄̑̍́͐̐̐̿̕̚͘͜͜ė̵͙̘̤͔͉͓̣̹̺̠̼͎͖̣̲̀̓͐̏̔̓̒̂͑́̌̉̈̐̿́̚̕͘͠ ̶̡̛͎̝̝̜̝͔̻͓̮̬̳̦͓͍̥͎͔̝͚̩̘͕̩̩̌̈́͐̓̂̄̂̿́͌̂́͌̂̔͂̉̐͋́̽̐̎̈́͋͒͐͌̔̾̀͊̒̚͘͘̕͝ͅb̵̬͙̰̗͈̣̪̤̣͉͖͚̙̗̰͑͊̈́̓̀̍̓͗̋̽̓̊̽̏̒̏͗̎̆̀̌͠͠͝͝͝e̸̘͚̬͇̣͖̟͍͈̤͙͕̻̞̦̩̤̤͎̱̼͚̣̠͖̖̙͕̣͚̬̗̥̘̅̃͂̽̇̎́̈́̚͜ͅş̸̨̢̡̨̧͔̫̬͖̮̭̭͍͙̺̹͕͓̪͕̯͇̩̘̗̮̜̜̲͓͎̲͚̖̘̦̣̩͍̯̘̼̠̼̺̎̽̐̔̽͑̂̂͐̀̏̂̓͘͝ͅţ̴̛̟̤̥̭̤̜̠̠̠̫̫̺̲̞͍͕̭̦̗̤͇̹͇̥͙͖̘̠̳̮͚͖͕̗̺̠̭̭̦̟̹͒̍͐̃̄͐̇̔͜͠ͅ ̸̧̧̼͍̬̺͎̫̫̻̗͙̮̣̑̐̂͊͋͛̐́̾͆͋͌̏̀̐͐͐͛̍̎͛̂̂͋̐̅̍͂̒͌͑̑́͋̈́́̈́̂̄̕͘̚̕͝͠ḑ̶̨̡̛̪̺̞͎̭̦̱̜̗̩̗͚̣̻̫̙͍͓̩͔̻̩͍̱͔̲̦̪͓̳͉͖͓͑̀̓̐̐̔͛̇̽̓͛̄̉̐̌̍͋͌̀̒̄̊̀͊̒̃̿̿͑͆̔̽̈́̽̿͋̔̋̀͛̕͘͘͠ḯ̵̡͕̬͖̟̖͚͙̳̞͔̩̖̺̖͉͖̰̤̬̰̥̺̘̺̹̗͉͝͠ṣ̸̨̢̢̢̹̻̦̦̯̝̬̤͍̬͉̼̦̞͔̠̘̱͔̮̮̝̫̪̞͈̘̤̱̥̙̪͍̥̼̻̟̱̻̫̦͋̊̉̈́̑͋̂̄̎͐̅̽́́̍̿̊̅͘̕̚͝͝ḩ̴̢͔͕̰̩̞̣̹̻̻̻͙͙̞͙̳͍̖̻̯͔̋̄̔͋͗̈́͗̀́̏̊̏̓̃̚͠͠ȩ̴̲͓̤͇̭̑͊͗͋̉͒̕ṡ̸̡̡̡̛̠̱̠̩̻͓̝̻͕̞̬̖̼̘̳̬͎͍̪̹͕̙̝̯̠̥̜͈͔̘̼̥͖̰̪̖̼̰̘͙̤̈́̈̈́́̓̕ͅͅ ̸̧̡̧̢̠̠̼̪̳̙̠̮͎͖̜̙͚̘̪̖̺̹̭͂͊̓͑̎̎̇̾̂̂͂̌̃̄͆̔̒́̑̄͆̾͗̐̌̒͋̐̉̍̂̇͊́͐͗̈́̓͌̏͋̈́̕͘̕͘̕͜͜͝͠͝ͅͅI̷̢̢̡̩̤̲͔̜̺̻̙̳̰̗̭̫͈̼͎̞̤̜͖̠̰͎̩̭͍̰̜̣̜̟̘̙̼̗̗͒̀͂̓͛̐̄͐̓̄́̔͜͜͝͝ ̸̧̡̢̢̢̛̭͉̝̺̯̼̩̗̲͙͇̜͚̞̤͕̝̪͕̖̫̻̝̯̩͖̘͔̮̹̖͓̦̰͎̤̎̾̍̂̾́̈́͒̀̈́͑̋͗̾̂̈́̈̅̃̏͝͝͝ͅḩ̷̢̱̬̫̲̤̻̭̯͈͚́̓̀̏͌̐̍̐̈́͜͜a̵̡͙̯͈͉̞̤͔̯̯͋̓̍͑͊͌̂͐̋̇̄̎̍̏̃v̵̡̡͓̫̘̪͎̘̪̪͖͎̫̰͍̰̲̇̈́́̃͌͜ę̴̡͓̬̗̣̫̭͖͍̆̉̎̎̀ ̸̡̪͈͙̫̝̻̠̲͔͙͉̒̈͛͋̽̈͜ȇ̷̡̡̛̯̟̪͍͙̝̺̳̳̥̣̉́͊̈́͗̀̅͂̃̉́̍͗̎̍̃͋̂̔͘͜͝͝v̴̡̛̬̟̲͔̖̭̦̦̫̥̪̲̥̯͙̻͓͕̰͉͇̥͚̺͕̙̻̮̥̹̤̠̱͈͇͉̘͙̖̙̱̜̄̆̒̈́ͅͅé̷̯͓̙͍̬̯̟̮͇̾̈́̈́̆̈̊͐̒̈̐̀͂̑͌͗̽̎̌̉̃̓̽̒̿̈̎̍͌͛̿̔̓͐̈́͐͌̏̓́̀͊͘͘͝͝r̸̢̘̭̖̹̰̖͉͔͔̣̩̜͊͒̀̅̌̎́͛̎̌̊́̐̾̆͆̿̑̏̋̒͘͘͝ ̵̡̢̢̡͎̱̪͕̳̠̤̪̗͖͓̳̮̗͓̜͓̪͙͈̝̲̫͙̥̦̱̭̼͔͚̼͛̍͂̀͆͗́̂̀̄͑͌̈̅̎́̈̏̿̾̏̀͋͛́͋͌́͜͜͝͠͝͝ͅͅḧ̸͕̖̥̗͓̳̩̙́͂͊͑̃͒̍͆̅̋̈́̉̃͐̌̚͜͜͠ą̶̡̘̬͚̖̰̻̝̼̲͈̗̣̱̖͎̦͓̣͇̳̟̰̤̞̺͎̣̫̦̲͍̰̥͙̹̼̰̺̺͎̦̫͛̃̿̌͊̑͐̀̐̈́̒̊̿̾́́̑́̎̈́͆̒́͆̆͛̕͘̕̚̚̚͝͠͝ͅd̷̢̛̛͖̠̟̺͇̬̳͕͕͓̽̔́͆̉͂̇̂́̿̆̒̀̽͂̔͂̒̆͛̃͆̍̉̉̈́̆͑̇͆̌͑̌͛̈́̃̚̚̕̚͠͝͝!̴̨̢̧̢̛̠͍͖̦͕̼̮͓͕̗̜̲̞̹̘͕͙̠̼̹̬͕̹̗̼̰̗̺̱̦͛̒͌͂̆̉͛́̍̆̄͒̽̈́͑͗͂͗͛̀̄͋̈́̇̍͛̑̆̅́̒̀̍͂̑̕̕̕͜͜͜͝͝͝" << endl; // don't worry, it's just a font :)
                        }
                        if(k2.assignFoodVal() == 1 && k2.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction10();
                        }
                        if(k2.assignFoodVal() == 3 && k2.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c2.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 3 && k3.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 5" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c3.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        if(k3.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction20();
                        }
                        else if(k3.getCorrectFood() == true)
                        {
                            cout << "Į̵̢̛̱̩̖̗͕̳̼̮̪̳̼̣̹̜͙̳̝͓̜̝̣͎̺͋́̀̑̀̎̓͐͆͑̍̐̔̃̉͐̏̂͒̑̍́̀́̀͑̚̚̚͝͝͝ͅ ̵̡̛̛̦͈̹͎̝̗̬̲̥̘̝͍̜͎͋̉̆͋̔̍̈́̀̓͊̇̈́̊̌̀̓̄͗̈͋̎͐̂̌͒̈́̽́̈́̉̒̌͂͗͂̓͋͊̉̓́̑̍͘̚͝͝͝ͅͅt̸̨̧̡̡̧̛͇̝̳̟̜̹̹͕̝̲͉̪͖̱͈̫͓̘̜̞͇͈̜͚͍̗̞̜̦͔̼̤̜͛͂̈̎̽̇̉̽̓͗́̔̋̀͋̉̎̇̈͑͗́̋̊͌̅͐͒͐̉̆̐̔͐̈́̾̀̇̃̄̊̾̇̚͘͘͜͠͝ͅͅͅĥ̷̢̡̛̛̳̩̼̲͖̗̗̜̩͉̣͎̰̯̝̟̠̰̗̝͖̗͖̰̪̥̪͉̠̞̯͊͗̒̑̽̔̾̈́̇̅̀͛̍̓͑͂̒̈́̈̎̈́̏͘͜͠͝ͅï̶̧̧̢̡̛̠͎͕͓̩̞̻̲̯͙͔̗͚̹̲̤̝͉͊̐͑̊̉̓́͊̇͑̀̉͛̏͐͋̅̓͂͘̕̚̕͜͝͝ͅn̶̛̛̛̟̗͈̣͔̅͌̋̑̔̉͗͐̅͋̐̀̎̒̉̾̃̏͛̄͑̔͆̋̈́̂̈́̅̈́́͗̐̽͋̓̕̕͝͝͠͝͠͝͝͠k̴̨̢̨̧̛̙̩̠̱͔͎̭̦̘͔͎͍̠͚̼̼͉̱̥̺̜͚̰̼̱͎̟̝̗͇͙͎̬̩̹̙͖̪̣̲͆̆̇͂͋͗̀̏̊̊̀̉͛͋̔̏̓̈́̈̽͊̅͂̕͘͘͜͜͝ͅ ̷̠̗̻̩̱̮͊̐̓̈́̔͌̓̅͋̈͐͛̀́̋̽̈́̿́̌̃̓̃̅̏̕͠͠ť̶̡̧̧̛̙̠̭̭͕͈̗͎͖͓͓̼̰͚̘̘̪̬̺̘̩̩̦̪̼̮̼̣̼̼̿́͋͊́̔̄̃̈́̓̊̿̎̀̐͋̎̈́̚̕̚̕͝ͅh̸̢̠̟̖̩̳̼̭͕͙͕̉̌͌̋̔͒̂̿͝͝å̸̢̡̡̜̤͖̹͖͖̤̲̙͓̫͍̹̳̹̫̗͖͍̖͖͓̩̻̭̰̥͓̼̣͉͓̞̜͖̠͓̖͇̗͈̰̙͙͊̓́̒̀̃͌͛̽͒̈́͛̌̀͂̊̅̌́͂̊̈́̄̕̚͠͝t̷̨̡̡̡̡̢̡̛̛͓͍̺̖̳̖̞̦̟̮̹̦̗͕͚͎̦͍̩͈͍̥͍̼̗̲͍͇͖̟̘̤̺̦̗̼͇̙̪͇̳̔̇͐̉̀͂̈̄͆̋̀̑̽̈́̿̈́̔̏̎͐̑̀͌̋͐͌̑̕̚͘͠͠͝ ̵̢̢̢̢͔̮̼͓̼̰͙͓̳̝͎͉̜̬͈̪̖̬̬̠͚̗̜̹̹̜͖̙̘͖͇̤͚̮͍̞͇̳̜͚̱̜͇̝̂̆̎́́̎̽́̽̒̓͌̚͜͜t̸̢̨̧̧̨̢̛̛̖͓̙͇͎͓̘̗͈͉̫̻̗̠̺̣͙̱̮̝͍̞̖͙̦͇̟̲͕̮͎̲̠̣̦͊͛̂̆́̌̓̒̔̑̋̿̅͌͆͆͛̽͑̍̽̐͌̑͐͋̀̏̍̌̈̊̍́͛̐̍̿̄͘̕͝͝͝h̷̨̢̧̯̣̲̩̳̣̪̙͙͎̮͙̙̣͚̳̤̳̻͎̘͎̹̝̥͔̺͔̖͔͍̼͈̲̞̣͍͖͇̋̊̓̎̔̑̊͜͜͜͠ͅͅȩ̶̨̧̡̡̢̡̛͇̩͔̲͓͍̥̞̯̙̗̟̱̞̯̯̹̞͓̼̤͚̤̱͉͚̦̳͎͇͉͕͑̍̀̀͂͗̑̈͌̅̿̔̐͒̅̈̆̌̿̽͋̐͂̎͂͑̏̿̔̌̏̍͗͗͐͘̚͜͠͝ͅͅś̵͓͕̦͎̺̠̦̫̣̞͖̟͎̀̉͛͐̐̎͊̅͗̇̑́̋̓͂̔́͝ḛ̴̢̛̞̭̮̤͍̫͔̤̙̙̥̮͈͇̹̺̫̳̿̂̔͌̔̎̿̓͗͒̋̑͑͂͐̈͋́́͐̈́́͆̊́̔̽͂́͗̐̓̏͑͋̃̚̕̕̚͠͝͝͝ ̸̧̛̺̖̻͔̤̺̹̜͖͈̗̯̙͕̣̖̻̱̰̳̦̣̭̩̐̑̊̋̄̈́̍̎̅͋̃̀̃͛̓͆̋͊̄͂̉̆͑̌̃́͆͛͋̐͛͌͗͛̋̆͑̋̔̀́͘͘͘̕͜͝͝ͅw̵̡̢̡̨̧͎̳̺̙͎̘̹̦̲̝̮͇͓̘̦̦̼͎͈̪̩̗̱̝͖̖̣̪͇͆͋̇́͑́͛̈́̒̎̀̓̌̌̓̿̂͐́̋̃̾͊̊̇̈͋̾̑̅̔̊̏̈́̊͂́̋̊̕̕̚͘̕͝e̸̡̛͔͉̘̖̠̰̰̭͓͈͊̂̄͂͐̍̓̎̆̌͐̎̈́̂́͐̈́͊̈̀̅͆̃̈́̅̏̄͋̋̀͗̀͆́̈́̅̿̀̽́̌̕̚͘̚͝͠ͅŗ̷͙̻̱̣̜͉̃̄̅̾̇̽͌̈́e̸̡̛̛̤̠̫̪̲̞̺̗͙̮̼̗̘̼̅̏͌͛̔͋̍̃́̾̌̌͐̎̂̊̊̆́͑͐͗̅̿͊̀̊͌̀̊̀͘͘̕͜͠͝͠͝ͅ ̸̦̮̍̍͋t̸͕̘̖̬͙͙͍̮̦͋̅̎̽̈̀̈̾̂͒̉̽̿͑̈́͑͆͒͆̀̔̊̍̀̏̂̈́͋́̿̐̄́̎̓̚͘͠͝͠͠͠h̸̢̡̢̧̛̛̙̳̜̠̩̭̗̠̰̥͓̦̖̥̙̤͚͔̱̠̰̫̼̘̹̰̞̻̗̬͍̖̪̜̖̬̗͚̭̓̄̃̐́̄̍̓̉̂͑̃̃̾͐̄̑̍́͐̐̐̿̕̚͘͜͜ė̵͙̘̤͔͉͓̣̹̺̠̼͎͖̣̲̀̓͐̏̔̓̒̂͑́̌̉̈̐̿́̚̕͘͠ ̶̡̛͎̝̝̜̝͔̻͓̮̬̳̦͓͍̥͎͔̝͚̩̘͕̩̩̌̈́͐̓̂̄̂̿́͌̂́͌̂̔͂̉̐͋́̽̐̎̈́͋͒͐͌̔̾̀͊̒̚͘͘̕͝ͅb̵̬͙̰̗͈̣̪̤̣͉͖͚̙̗̰͑͊̈́̓̀̍̓͗̋̽̓̊̽̏̒̏͗̎̆̀̌͠͠͝͝͝e̸̘͚̬͇̣͖̟͍͈̤͙͕̻̞̦̩̤̤͎̱̼͚̣̠͖̖̙͕̣͚̬̗̥̘̅̃͂̽̇̎́̈́̚͜ͅş̸̨̢̡̨̧͔̫̬͖̮̭̭͍͙̺̹͕͓̪͕̯͇̩̘̗̮̜̜̲͓͎̲͚̖̘̦̣̩͍̯̘̼̠̼̺̎̽̐̔̽͑̂̂͐̀̏̂̓͘͝ͅţ̴̛̟̤̥̭̤̜̠̠̠̫̫̺̲̞͍͕̭̦̗̤͇̹͇̥͙͖̘̠̳̮͚͖͕̗̺̠̭̭̦̟̹͒̍͐̃̄͐̇̔͜͠ͅ ̸̧̧̼͍̬̺͎̫̫̻̗͙̮̣̑̐̂͊͋͛̐́̾͆͋͌̏̀̐͐͐͛̍̎͛̂̂͋̐̅̍͂̒͌͑̑́͋̈́́̈́̂̄̕͘̚̕͝͠ḑ̶̨̡̛̪̺̞͎̭̦̱̜̗̩̗͚̣̻̫̙͍͓̩͔̻̩͍̱͔̲̦̪͓̳͉͖͓͑̀̓̐̐̔͛̇̽̓͛̄̉̐̌̍͋͌̀̒̄̊̀͊̒̃̿̿͑͆̔̽̈́̽̿͋̔̋̀͛̕͘͘͠ḯ̵̡͕̬͖̟̖͚͙̳̞͔̩̖̺̖͉͖̰̤̬̰̥̺̘̺̹̗͉͝͠ṣ̸̨̢̢̢̹̻̦̦̯̝̬̤͍̬͉̼̦̞͔̠̘̱͔̮̮̝̫̪̞͈̘̤̱̥̙̪͍̥̼̻̟̱̻̫̦͋̊̉̈́̑͋̂̄̎͐̅̽́́̍̿̊̅͘̕̚͝͝ḩ̴̢͔͕̰̩̞̣̹̻̻̻͙͙̞͙̳͍̖̻̯͔̋̄̔͋͗̈́͗̀́̏̊̏̓̃̚͠͠ȩ̴̲͓̤͇̭̑͊͗͋̉͒̕ṡ̸̡̡̡̛̠̱̠̩̻͓̝̻͕̞̬̖̼̘̳̬͎͍̪̹͕̙̝̯̠̥̜͈͔̘̼̥͖̰̪̖̼̰̘͙̤̈́̈̈́́̓̕ͅͅ ̸̧̡̧̢̠̠̼̪̳̙̠̮͎͖̜̙͚̘̪̖̺̹̭͂͊̓͑̎̎̇̾̂̂͂̌̃̄͆̔̒́̑̄͆̾͗̐̌̒͋̐̉̍̂̇͊́͐͗̈́̓͌̏͋̈́̕͘̕͘̕͜͜͝͠͝ͅͅI̷̢̢̡̩̤̲͔̜̺̻̙̳̰̗̭̫͈̼͎̞̤̜͖̠̰͎̩̭͍̰̜̣̜̟̘̙̼̗̗͒̀͂̓͛̐̄͐̓̄́̔͜͜͝͝ ̸̧̡̢̢̢̛̭͉̝̺̯̼̩̗̲͙͇̜͚̞̤͕̝̪͕̖̫̻̝̯̩͖̘͔̮̹̖͓̦̰͎̤̎̾̍̂̾́̈́͒̀̈́͑̋͗̾̂̈́̈̅̃̏͝͝͝ͅḩ̷̢̱̬̫̲̤̻̭̯͈͚́̓̀̏͌̐̍̐̈́͜͜a̵̡͙̯͈͉̞̤͔̯̯͋̓̍͑͊͌̂͐̋̇̄̎̍̏̃v̵̡̡͓̫̘̪͎̘̪̪͖͎̫̰͍̰̲̇̈́́̃͌͜ę̴̡͓̬̗̣̫̭͖͍̆̉̎̎̀ ̸̡̪͈͙̫̝̻̠̲͔͙͉̒̈͛͋̽̈͜ȇ̷̡̡̛̯̟̪͍͙̝̺̳̳̥̣̉́͊̈́͗̀̅͂̃̉́̍͗̎̍̃͋̂̔͘͜͝͝v̴̡̛̬̟̲͔̖̭̦̦̫̥̪̲̥̯͙̻͓͕̰͉͇̥͚̺͕̙̻̮̥̹̤̠̱͈͇͉̘͙̖̙̱̜̄̆̒̈́ͅͅé̷̯͓̙͍̬̯̟̮͇̾̈́̈́̆̈̊͐̒̈̐̀͂̑͌͗̽̎̌̉̃̓̽̒̿̈̎̍͌͛̿̔̓͐̈́͐͌̏̓́̀͊͘͘͝͝r̸̢̘̭̖̹̰̖͉͔͔̣̩̜͊͒̀̅̌̎́͛̎̌̊́̐̾̆͆̿̑̏̋̒͘͘͝ ̵̡̢̢̡͎̱̪͕̳̠̤̪̗͖͓̳̮̗͓̜͓̪͙͈̝̲̫͙̥̦̱̭̼͔͚̼͛̍͂̀͆͗́̂̀̄͑͌̈̅̎́̈̏̿̾̏̀͋͛́͋͌́͜͜͝͠͝͝ͅͅḧ̸͕̖̥̗͓̳̩̙́͂͊͑̃͒̍͆̅̋̈́̉̃͐̌̚͜͜͠ą̶̡̘̬͚̖̰̻̝̼̲͈̗̣̱̖͎̦͓̣͇̳̟̰̤̞̺͎̣̫̦̲͍̰̥͙̹̼̰̺̺͎̦̫͛̃̿̌͊̑͐̀̐̈́̒̊̿̾́́̑́̎̈́͆̒́͆̆͛̕͘̕̚̚̚͝͠͝ͅd̷̢̛̛͖̠̟̺͇̬̳͕͕͓̽̔́͆̉͂̇̂́̿̆̒̀̽͂̔͂̒̆͛̃͆̍̉̉̈́̆͑̇͆̌͑̌͛̈́̃̚̚̕̚͠͝͝!̴̨̢̧̢̛̠͍͖̦͕̼̮͓͕̗̜̲̞̹̘͕͙̠̼̹̬͕̹̗̼̰̗̺̱̦͛̒͌͂̆̉͛́̍̆̄͒̽̈́͑͗͂͗͛̀̄͋̈́̇̍͛̑̆̅́̒̀̍͂̑̕̕̕͜͜͜͝͝͝" << endl; // don't worry, it's just a font :)
                        }
                        if(k3.assignFoodVal() == 1 && k3.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction10();
                        }
                        if(k3.assignFoodVal() == 3 && k3.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c3.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 4 && k4.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 4" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c4.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        if(k4.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction20();
                        }
                        else if(k4.getCorrectFood() == true)
                        {
                            cout << "Į̵̢̛̱̩̖̗͕̳̼̮̪̳̼̣̹̜͙̳̝͓̜̝̣͎̺͋́̀̑̀̎̓͐͆͑̍̐̔̃̉͐̏̂͒̑̍́̀́̀͑̚̚̚͝͝͝ͅ ̵̡̛̛̦͈̹͎̝̗̬̲̥̘̝͍̜͎͋̉̆͋̔̍̈́̀̓͊̇̈́̊̌̀̓̄͗̈͋̎͐̂̌͒̈́̽́̈́̉̒̌͂͗͂̓͋͊̉̓́̑̍͘̚͝͝͝ͅͅt̸̨̧̡̡̧̛͇̝̳̟̜̹̹͕̝̲͉̪͖̱͈̫͓̘̜̞͇͈̜͚͍̗̞̜̦͔̼̤̜͛͂̈̎̽̇̉̽̓͗́̔̋̀͋̉̎̇̈͑͗́̋̊͌̅͐͒͐̉̆̐̔͐̈́̾̀̇̃̄̊̾̇̚͘͘͜͠͝ͅͅͅĥ̷̢̡̛̛̳̩̼̲͖̗̗̜̩͉̣͎̰̯̝̟̠̰̗̝͖̗͖̰̪̥̪͉̠̞̯͊͗̒̑̽̔̾̈́̇̅̀͛̍̓͑͂̒̈́̈̎̈́̏͘͜͠͝ͅï̶̧̧̢̡̛̠͎͕͓̩̞̻̲̯͙͔̗͚̹̲̤̝͉͊̐͑̊̉̓́͊̇͑̀̉͛̏͐͋̅̓͂͘̕̚̕͜͝͝ͅn̶̛̛̛̟̗͈̣͔̅͌̋̑̔̉͗͐̅͋̐̀̎̒̉̾̃̏͛̄͑̔͆̋̈́̂̈́̅̈́́͗̐̽͋̓̕̕͝͝͠͝͠͝͝͠k̴̨̢̨̧̛̙̩̠̱͔͎̭̦̘͔͎͍̠͚̼̼͉̱̥̺̜͚̰̼̱͎̟̝̗͇͙͎̬̩̹̙͖̪̣̲͆̆̇͂͋͗̀̏̊̊̀̉͛͋̔̏̓̈́̈̽͊̅͂̕͘͘͜͜͝ͅ ̷̠̗̻̩̱̮͊̐̓̈́̔͌̓̅͋̈͐͛̀́̋̽̈́̿́̌̃̓̃̅̏̕͠͠ť̶̡̧̧̛̙̠̭̭͕͈̗͎͖͓͓̼̰͚̘̘̪̬̺̘̩̩̦̪̼̮̼̣̼̼̿́͋͊́̔̄̃̈́̓̊̿̎̀̐͋̎̈́̚̕̚̕͝ͅh̸̢̠̟̖̩̳̼̭͕͙͕̉̌͌̋̔͒̂̿͝͝å̸̢̡̡̜̤͖̹͖͖̤̲̙͓̫͍̹̳̹̫̗͖͍̖͖͓̩̻̭̰̥͓̼̣͉͓̞̜͖̠͓̖͇̗͈̰̙͙͊̓́̒̀̃͌͛̽͒̈́͛̌̀͂̊̅̌́͂̊̈́̄̕̚͠͝t̷̨̡̡̡̡̢̡̛̛͓͍̺̖̳̖̞̦̟̮̹̦̗͕͚͎̦͍̩͈͍̥͍̼̗̲͍͇͖̟̘̤̺̦̗̼͇̙̪͇̳̔̇͐̉̀͂̈̄͆̋̀̑̽̈́̿̈́̔̏̎͐̑̀͌̋͐͌̑̕̚͘͠͠͝ ̵̢̢̢̢͔̮̼͓̼̰͙͓̳̝͎͉̜̬͈̪̖̬̬̠͚̗̜̹̹̜͖̙̘͖͇̤͚̮͍̞͇̳̜͚̱̜͇̝̂̆̎́́̎̽́̽̒̓͌̚͜͜t̸̢̨̧̧̨̢̛̛̖͓̙͇͎͓̘̗͈͉̫̻̗̠̺̣͙̱̮̝͍̞̖͙̦͇̟̲͕̮͎̲̠̣̦͊͛̂̆́̌̓̒̔̑̋̿̅͌͆͆͛̽͑̍̽̐͌̑͐͋̀̏̍̌̈̊̍́͛̐̍̿̄͘̕͝͝͝h̷̨̢̧̯̣̲̩̳̣̪̙͙͎̮͙̙̣͚̳̤̳̻͎̘͎̹̝̥͔̺͔̖͔͍̼͈̲̞̣͍͖͇̋̊̓̎̔̑̊͜͜͜͠ͅͅȩ̶̨̧̡̡̢̡̛͇̩͔̲͓͍̥̞̯̙̗̟̱̞̯̯̹̞͓̼̤͚̤̱͉͚̦̳͎͇͉͕͑̍̀̀͂͗̑̈͌̅̿̔̐͒̅̈̆̌̿̽͋̐͂̎͂͑̏̿̔̌̏̍͗͗͐͘̚͜͠͝ͅͅś̵͓͕̦͎̺̠̦̫̣̞͖̟͎̀̉͛͐̐̎͊̅͗̇̑́̋̓͂̔́͝ḛ̴̢̛̞̭̮̤͍̫͔̤̙̙̥̮͈͇̹̺̫̳̿̂̔͌̔̎̿̓͗͒̋̑͑͂͐̈͋́́͐̈́́͆̊́̔̽͂́͗̐̓̏͑͋̃̚̕̕̚͠͝͝͝ ̸̧̛̺̖̻͔̤̺̹̜͖͈̗̯̙͕̣̖̻̱̰̳̦̣̭̩̐̑̊̋̄̈́̍̎̅͋̃̀̃͛̓͆̋͊̄͂̉̆͑̌̃́͆͛͋̐͛͌͗͛̋̆͑̋̔̀́͘͘͘̕͜͝͝ͅw̵̡̢̡̨̧͎̳̺̙͎̘̹̦̲̝̮͇͓̘̦̦̼͎͈̪̩̗̱̝͖̖̣̪͇͆͋̇́͑́͛̈́̒̎̀̓̌̌̓̿̂͐́̋̃̾͊̊̇̈͋̾̑̅̔̊̏̈́̊͂́̋̊̕̕̚͘̕͝e̸̡̛͔͉̘̖̠̰̰̭͓͈͊̂̄͂͐̍̓̎̆̌͐̎̈́̂́͐̈́͊̈̀̅͆̃̈́̅̏̄͋̋̀͗̀͆́̈́̅̿̀̽́̌̕̚͘̚͝͠ͅŗ̷͙̻̱̣̜͉̃̄̅̾̇̽͌̈́e̸̡̛̛̤̠̫̪̲̞̺̗͙̮̼̗̘̼̅̏͌͛̔͋̍̃́̾̌̌͐̎̂̊̊̆́͑͐͗̅̿͊̀̊͌̀̊̀͘͘̕͜͠͝͠͝ͅ ̸̦̮̍̍͋t̸͕̘̖̬͙͙͍̮̦͋̅̎̽̈̀̈̾̂͒̉̽̿͑̈́͑͆͒͆̀̔̊̍̀̏̂̈́͋́̿̐̄́̎̓̚͘͠͝͠͠͠h̸̢̡̢̧̛̛̙̳̜̠̩̭̗̠̰̥͓̦̖̥̙̤͚͔̱̠̰̫̼̘̹̰̞̻̗̬͍̖̪̜̖̬̗͚̭̓̄̃̐́̄̍̓̉̂͑̃̃̾͐̄̑̍́͐̐̐̿̕̚͘͜͜ė̵͙̘̤͔͉͓̣̹̺̠̼͎͖̣̲̀̓͐̏̔̓̒̂͑́̌̉̈̐̿́̚̕͘͠ ̶̡̛͎̝̝̜̝͔̻͓̮̬̳̦͓͍̥͎͔̝͚̩̘͕̩̩̌̈́͐̓̂̄̂̿́͌̂́͌̂̔͂̉̐͋́̽̐̎̈́͋͒͐͌̔̾̀͊̒̚͘͘̕͝ͅb̵̬͙̰̗͈̣̪̤̣͉͖͚̙̗̰͑͊̈́̓̀̍̓͗̋̽̓̊̽̏̒̏͗̎̆̀̌͠͠͝͝͝e̸̘͚̬͇̣͖̟͍͈̤͙͕̻̞̦̩̤̤͎̱̼͚̣̠͖̖̙͕̣͚̬̗̥̘̅̃͂̽̇̎́̈́̚͜ͅş̸̨̢̡̨̧͔̫̬͖̮̭̭͍͙̺̹͕͓̪͕̯͇̩̘̗̮̜̜̲͓͎̲͚̖̘̦̣̩͍̯̘̼̠̼̺̎̽̐̔̽͑̂̂͐̀̏̂̓͘͝ͅţ̴̛̟̤̥̭̤̜̠̠̠̫̫̺̲̞͍͕̭̦̗̤͇̹͇̥͙͖̘̠̳̮͚͖͕̗̺̠̭̭̦̟̹͒̍͐̃̄͐̇̔͜͠ͅ ̸̧̧̼͍̬̺͎̫̫̻̗͙̮̣̑̐̂͊͋͛̐́̾͆͋͌̏̀̐͐͐͛̍̎͛̂̂͋̐̅̍͂̒͌͑̑́͋̈́́̈́̂̄̕͘̚̕͝͠ḑ̶̨̡̛̪̺̞͎̭̦̱̜̗̩̗͚̣̻̫̙͍͓̩͔̻̩͍̱͔̲̦̪͓̳͉͖͓͑̀̓̐̐̔͛̇̽̓͛̄̉̐̌̍͋͌̀̒̄̊̀͊̒̃̿̿͑͆̔̽̈́̽̿͋̔̋̀͛̕͘͘͠ḯ̵̡͕̬͖̟̖͚͙̳̞͔̩̖̺̖͉͖̰̤̬̰̥̺̘̺̹̗͉͝͠ṣ̸̨̢̢̢̹̻̦̦̯̝̬̤͍̬͉̼̦̞͔̠̘̱͔̮̮̝̫̪̞͈̘̤̱̥̙̪͍̥̼̻̟̱̻̫̦͋̊̉̈́̑͋̂̄̎͐̅̽́́̍̿̊̅͘̕̚͝͝ḩ̴̢͔͕̰̩̞̣̹̻̻̻͙͙̞͙̳͍̖̻̯͔̋̄̔͋͗̈́͗̀́̏̊̏̓̃̚͠͠ȩ̴̲͓̤͇̭̑͊͗͋̉͒̕ṡ̸̡̡̡̛̠̱̠̩̻͓̝̻͕̞̬̖̼̘̳̬͎͍̪̹͕̙̝̯̠̥̜͈͔̘̼̥͖̰̪̖̼̰̘͙̤̈́̈̈́́̓̕ͅͅ ̸̧̡̧̢̠̠̼̪̳̙̠̮͎͖̜̙͚̘̪̖̺̹̭͂͊̓͑̎̎̇̾̂̂͂̌̃̄͆̔̒́̑̄͆̾͗̐̌̒͋̐̉̍̂̇͊́͐͗̈́̓͌̏͋̈́̕͘̕͘̕͜͜͝͠͝ͅͅI̷̢̢̡̩̤̲͔̜̺̻̙̳̰̗̭̫͈̼͎̞̤̜͖̠̰͎̩̭͍̰̜̣̜̟̘̙̼̗̗͒̀͂̓͛̐̄͐̓̄́̔͜͜͝͝ ̸̧̡̢̢̢̛̭͉̝̺̯̼̩̗̲͙͇̜͚̞̤͕̝̪͕̖̫̻̝̯̩͖̘͔̮̹̖͓̦̰͎̤̎̾̍̂̾́̈́͒̀̈́͑̋͗̾̂̈́̈̅̃̏͝͝͝ͅḩ̷̢̱̬̫̲̤̻̭̯͈͚́̓̀̏͌̐̍̐̈́͜͜a̵̡͙̯͈͉̞̤͔̯̯͋̓̍͑͊͌̂͐̋̇̄̎̍̏̃v̵̡̡͓̫̘̪͎̘̪̪͖͎̫̰͍̰̲̇̈́́̃͌͜ę̴̡͓̬̗̣̫̭͖͍̆̉̎̎̀ ̸̡̪͈͙̫̝̻̠̲͔͙͉̒̈͛͋̽̈͜ȇ̷̡̡̛̯̟̪͍͙̝̺̳̳̥̣̉́͊̈́͗̀̅͂̃̉́̍͗̎̍̃͋̂̔͘͜͝͝v̴̡̛̬̟̲͔̖̭̦̦̫̥̪̲̥̯͙̻͓͕̰͉͇̥͚̺͕̙̻̮̥̹̤̠̱͈͇͉̘͙̖̙̱̜̄̆̒̈́ͅͅé̷̯͓̙͍̬̯̟̮͇̾̈́̈́̆̈̊͐̒̈̐̀͂̑͌͗̽̎̌̉̃̓̽̒̿̈̎̍͌͛̿̔̓͐̈́͐͌̏̓́̀͊͘͘͝͝r̸̢̘̭̖̹̰̖͉͔͔̣̩̜͊͒̀̅̌̎́͛̎̌̊́̐̾̆͆̿̑̏̋̒͘͘͝ ̵̡̢̢̡͎̱̪͕̳̠̤̪̗͖͓̳̮̗͓̜͓̪͙͈̝̲̫͙̥̦̱̭̼͔͚̼͛̍͂̀͆͗́̂̀̄͑͌̈̅̎́̈̏̿̾̏̀͋͛́͋͌́͜͜͝͠͝͝ͅͅḧ̸͕̖̥̗͓̳̩̙́͂͊͑̃͒̍͆̅̋̈́̉̃͐̌̚͜͜͠ą̶̡̘̬͚̖̰̻̝̼̲͈̗̣̱̖͎̦͓̣͇̳̟̰̤̞̺͎̣̫̦̲͍̰̥͙̹̼̰̺̺͎̦̫͛̃̿̌͊̑͐̀̐̈́̒̊̿̾́́̑́̎̈́͆̒́͆̆͛̕͘̕̚̚̚͝͠͝ͅd̷̢̛̛͖̠̟̺͇̬̳͕͕͓̽̔́͆̉͂̇̂́̿̆̒̀̽͂̔͂̒̆͛̃͆̍̉̉̈́̆͑̇͆̌͑̌͛̈́̃̚̚̕̚͠͝͝!̴̨̢̧̢̛̠͍͖̦͕̼̮͓͕̗̜̲̞̹̘͕͙̠̼̹̬͕̹̗̼̰̗̺̱̦͛̒͌͂̆̉͛́̍̆̄͒̽̈́͑͗͂͗͛̀̄͋̈́̇̍͛̑̆̅́̒̀̍͂̑̕̕̕͜͜͜͝͝͝" << endl; // don't worry, it's just a font :)
                        }
                        if(k4.assignFoodVal() == 1 && k4.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction10();
                        }
                        if(k4.assignFoodVal() == 3 && k4.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c4.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }
                else if(customer_count == 5 && k5.gotOrderAtKitchen() == true)
                {
                    cout << "Press 'c' to deliver the order to Table 5" << endl;
                    cin >> cont_exit;
                    if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                    if(cont_exit == 'c')
                    {
                        system("clear");
                    }
                    if(cont_exit == 'c')
                    {
                        c5.setOrderDelivered(true);
                        if(p.serverSlip())
                        {
                            cout << "Oops! You slipped and spilt the food. You hurried back to the kitchen and served your customer." << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        if(k5.getCorrectFood() == false)
                        {
                            cout << "Oh no! You delivered the wrong order!" << endl;
                            cout << BLACK << "The customer stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction20();
                        }
                        else if(k5.getCorrectFood() == true)
                        {
                            cout << "Į̵̢̛̱̩̖̗͕̳̼̮̪̳̼̣̹̜͙̳̝͓̜̝̣͎̺͋́̀̑̀̎̓͐͆͑̍̐̔̃̉͐̏̂͒̑̍́̀́̀͑̚̚̚͝͝͝ͅ ̵̡̛̛̦͈̹͎̝̗̬̲̥̘̝͍̜͎͋̉̆͋̔̍̈́̀̓͊̇̈́̊̌̀̓̄͗̈͋̎͐̂̌͒̈́̽́̈́̉̒̌͂͗͂̓͋͊̉̓́̑̍͘̚͝͝͝ͅͅt̸̨̧̡̡̧̛͇̝̳̟̜̹̹͕̝̲͉̪͖̱͈̫͓̘̜̞͇͈̜͚͍̗̞̜̦͔̼̤̜͛͂̈̎̽̇̉̽̓͗́̔̋̀͋̉̎̇̈͑͗́̋̊͌̅͐͒͐̉̆̐̔͐̈́̾̀̇̃̄̊̾̇̚͘͘͜͠͝ͅͅͅĥ̷̢̡̛̛̳̩̼̲͖̗̗̜̩͉̣͎̰̯̝̟̠̰̗̝͖̗͖̰̪̥̪͉̠̞̯͊͗̒̑̽̔̾̈́̇̅̀͛̍̓͑͂̒̈́̈̎̈́̏͘͜͠͝ͅï̶̧̧̢̡̛̠͎͕͓̩̞̻̲̯͙͔̗͚̹̲̤̝͉͊̐͑̊̉̓́͊̇͑̀̉͛̏͐͋̅̓͂͘̕̚̕͜͝͝ͅn̶̛̛̛̟̗͈̣͔̅͌̋̑̔̉͗͐̅͋̐̀̎̒̉̾̃̏͛̄͑̔͆̋̈́̂̈́̅̈́́͗̐̽͋̓̕̕͝͝͠͝͠͝͝͠k̴̨̢̨̧̛̙̩̠̱͔͎̭̦̘͔͎͍̠͚̼̼͉̱̥̺̜͚̰̼̱͎̟̝̗͇͙͎̬̩̹̙͖̪̣̲͆̆̇͂͋͗̀̏̊̊̀̉͛͋̔̏̓̈́̈̽͊̅͂̕͘͘͜͜͝ͅ ̷̠̗̻̩̱̮͊̐̓̈́̔͌̓̅͋̈͐͛̀́̋̽̈́̿́̌̃̓̃̅̏̕͠͠ť̶̡̧̧̛̙̠̭̭͕͈̗͎͖͓͓̼̰͚̘̘̪̬̺̘̩̩̦̪̼̮̼̣̼̼̿́͋͊́̔̄̃̈́̓̊̿̎̀̐͋̎̈́̚̕̚̕͝ͅh̸̢̠̟̖̩̳̼̭͕͙͕̉̌͌̋̔͒̂̿͝͝å̸̢̡̡̜̤͖̹͖͖̤̲̙͓̫͍̹̳̹̫̗͖͍̖͖͓̩̻̭̰̥͓̼̣͉͓̞̜͖̠͓̖͇̗͈̰̙͙͊̓́̒̀̃͌͛̽͒̈́͛̌̀͂̊̅̌́͂̊̈́̄̕̚͠͝t̷̨̡̡̡̡̢̡̛̛͓͍̺̖̳̖̞̦̟̮̹̦̗͕͚͎̦͍̩͈͍̥͍̼̗̲͍͇͖̟̘̤̺̦̗̼͇̙̪͇̳̔̇͐̉̀͂̈̄͆̋̀̑̽̈́̿̈́̔̏̎͐̑̀͌̋͐͌̑̕̚͘͠͠͝ ̵̢̢̢̢͔̮̼͓̼̰͙͓̳̝͎͉̜̬͈̪̖̬̬̠͚̗̜̹̹̜͖̙̘͖͇̤͚̮͍̞͇̳̜͚̱̜͇̝̂̆̎́́̎̽́̽̒̓͌̚͜͜t̸̢̨̧̧̨̢̛̛̖͓̙͇͎͓̘̗͈͉̫̻̗̠̺̣͙̱̮̝͍̞̖͙̦͇̟̲͕̮͎̲̠̣̦͊͛̂̆́̌̓̒̔̑̋̿̅͌͆͆͛̽͑̍̽̐͌̑͐͋̀̏̍̌̈̊̍́͛̐̍̿̄͘̕͝͝͝h̷̨̢̧̯̣̲̩̳̣̪̙͙͎̮͙̙̣͚̳̤̳̻͎̘͎̹̝̥͔̺͔̖͔͍̼͈̲̞̣͍͖͇̋̊̓̎̔̑̊͜͜͜͠ͅͅȩ̶̨̧̡̡̢̡̛͇̩͔̲͓͍̥̞̯̙̗̟̱̞̯̯̹̞͓̼̤͚̤̱͉͚̦̳͎͇͉͕͑̍̀̀͂͗̑̈͌̅̿̔̐͒̅̈̆̌̿̽͋̐͂̎͂͑̏̿̔̌̏̍͗͗͐͘̚͜͠͝ͅͅś̵͓͕̦͎̺̠̦̫̣̞͖̟͎̀̉͛͐̐̎͊̅͗̇̑́̋̓͂̔́͝ḛ̴̢̛̞̭̮̤͍̫͔̤̙̙̥̮͈͇̹̺̫̳̿̂̔͌̔̎̿̓͗͒̋̑͑͂͐̈͋́́͐̈́́͆̊́̔̽͂́͗̐̓̏͑͋̃̚̕̕̚͠͝͝͝ ̸̧̛̺̖̻͔̤̺̹̜͖͈̗̯̙͕̣̖̻̱̰̳̦̣̭̩̐̑̊̋̄̈́̍̎̅͋̃̀̃͛̓͆̋͊̄͂̉̆͑̌̃́͆͛͋̐͛͌͗͛̋̆͑̋̔̀́͘͘͘̕͜͝͝ͅw̵̡̢̡̨̧͎̳̺̙͎̘̹̦̲̝̮͇͓̘̦̦̼͎͈̪̩̗̱̝͖̖̣̪͇͆͋̇́͑́͛̈́̒̎̀̓̌̌̓̿̂͐́̋̃̾͊̊̇̈͋̾̑̅̔̊̏̈́̊͂́̋̊̕̕̚͘̕͝e̸̡̛͔͉̘̖̠̰̰̭͓͈͊̂̄͂͐̍̓̎̆̌͐̎̈́̂́͐̈́͊̈̀̅͆̃̈́̅̏̄͋̋̀͗̀͆́̈́̅̿̀̽́̌̕̚͘̚͝͠ͅŗ̷͙̻̱̣̜͉̃̄̅̾̇̽͌̈́e̸̡̛̛̤̠̫̪̲̞̺̗͙̮̼̗̘̼̅̏͌͛̔͋̍̃́̾̌̌͐̎̂̊̊̆́͑͐͗̅̿͊̀̊͌̀̊̀͘͘̕͜͠͝͠͝ͅ ̸̦̮̍̍͋t̸͕̘̖̬͙͙͍̮̦͋̅̎̽̈̀̈̾̂͒̉̽̿͑̈́͑͆͒͆̀̔̊̍̀̏̂̈́͋́̿̐̄́̎̓̚͘͠͝͠͠͠h̸̢̡̢̧̛̛̙̳̜̠̩̭̗̠̰̥͓̦̖̥̙̤͚͔̱̠̰̫̼̘̹̰̞̻̗̬͍̖̪̜̖̬̗͚̭̓̄̃̐́̄̍̓̉̂͑̃̃̾͐̄̑̍́͐̐̐̿̕̚͘͜͜ė̵͙̘̤͔͉͓̣̹̺̠̼͎͖̣̲̀̓͐̏̔̓̒̂͑́̌̉̈̐̿́̚̕͘͠ ̶̡̛͎̝̝̜̝͔̻͓̮̬̳̦͓͍̥͎͔̝͚̩̘͕̩̩̌̈́͐̓̂̄̂̿́͌̂́͌̂̔͂̉̐͋́̽̐̎̈́͋͒͐͌̔̾̀͊̒̚͘͘̕͝ͅb̵̬͙̰̗͈̣̪̤̣͉͖͚̙̗̰͑͊̈́̓̀̍̓͗̋̽̓̊̽̏̒̏͗̎̆̀̌͠͠͝͝͝e̸̘͚̬͇̣͖̟͍͈̤͙͕̻̞̦̩̤̤͎̱̼͚̣̠͖̖̙͕̣͚̬̗̥̘̅̃͂̽̇̎́̈́̚͜ͅş̸̨̢̡̨̧͔̫̬͖̮̭̭͍͙̺̹͕͓̪͕̯͇̩̘̗̮̜̜̲͓͎̲͚̖̘̦̣̩͍̯̘̼̠̼̺̎̽̐̔̽͑̂̂͐̀̏̂̓͘͝ͅţ̴̛̟̤̥̭̤̜̠̠̠̫̫̺̲̞͍͕̭̦̗̤͇̹͇̥͙͖̘̠̳̮͚͖͕̗̺̠̭̭̦̟̹͒̍͐̃̄͐̇̔͜͠ͅ ̸̧̧̼͍̬̺͎̫̫̻̗͙̮̣̑̐̂͊͋͛̐́̾͆͋͌̏̀̐͐͐͛̍̎͛̂̂͋̐̅̍͂̒͌͑̑́͋̈́́̈́̂̄̕͘̚̕͝͠ḑ̶̨̡̛̪̺̞͎̭̦̱̜̗̩̗͚̣̻̫̙͍͓̩͔̻̩͍̱͔̲̦̪͓̳͉͖͓͑̀̓̐̐̔͛̇̽̓͛̄̉̐̌̍͋͌̀̒̄̊̀͊̒̃̿̿͑͆̔̽̈́̽̿͋̔̋̀͛̕͘͘͠ḯ̵̡͕̬͖̟̖͚͙̳̞͔̩̖̺̖͉͖̰̤̬̰̥̺̘̺̹̗͉͝͠ṣ̸̨̢̢̢̹̻̦̦̯̝̬̤͍̬͉̼̦̞͔̠̘̱͔̮̮̝̫̪̞͈̘̤̱̥̙̪͍̥̼̻̟̱̻̫̦͋̊̉̈́̑͋̂̄̎͐̅̽́́̍̿̊̅͘̕̚͝͝ḩ̴̢͔͕̰̩̞̣̹̻̻̻͙͙̞͙̳͍̖̻̯͔̋̄̔͋͗̈́͗̀́̏̊̏̓̃̚͠͠ȩ̴̲͓̤͇̭̑͊͗͋̉͒̕ṡ̸̡̡̡̛̠̱̠̩̻͓̝̻͕̞̬̖̼̘̳̬͎͍̪̹͕̙̝̯̠̥̜͈͔̘̼̥͖̰̪̖̼̰̘͙̤̈́̈̈́́̓̕ͅͅ ̸̧̡̧̢̠̠̼̪̳̙̠̮͎͖̜̙͚̘̪̖̺̹̭͂͊̓͑̎̎̇̾̂̂͂̌̃̄͆̔̒́̑̄͆̾͗̐̌̒͋̐̉̍̂̇͊́͐͗̈́̓͌̏͋̈́̕͘̕͘̕͜͜͝͠͝ͅͅI̷̢̢̡̩̤̲͔̜̺̻̙̳̰̗̭̫͈̼͎̞̤̜͖̠̰͎̩̭͍̰̜̣̜̟̘̙̼̗̗͒̀͂̓͛̐̄͐̓̄́̔͜͜͝͝ ̸̧̡̢̢̢̛̭͉̝̺̯̼̩̗̲͙͇̜͚̞̤͕̝̪͕̖̫̻̝̯̩͖̘͔̮̹̖͓̦̰͎̤̎̾̍̂̾́̈́͒̀̈́͑̋͗̾̂̈́̈̅̃̏͝͝͝ͅḩ̷̢̱̬̫̲̤̻̭̯͈͚́̓̀̏͌̐̍̐̈́͜͜a̵̡͙̯͈͉̞̤͔̯̯͋̓̍͑͊͌̂͐̋̇̄̎̍̏̃v̵̡̡͓̫̘̪͎̘̪̪͖͎̫̰͍̰̲̇̈́́̃͌͜ę̴̡͓̬̗̣̫̭͖͍̆̉̎̎̀ ̸̡̪͈͙̫̝̻̠̲͔͙͉̒̈͛͋̽̈͜ȇ̷̡̡̛̯̟̪͍͙̝̺̳̳̥̣̉́͊̈́͗̀̅͂̃̉́̍͗̎̍̃͋̂̔͘͜͝͝v̴̡̛̬̟̲͔̖̭̦̦̫̥̪̲̥̯͙̻͓͕̰͉͇̥͚̺͕̙̻̮̥̹̤̠̱͈͇͉̘͙̖̙̱̜̄̆̒̈́ͅͅé̷̯͓̙͍̬̯̟̮͇̾̈́̈́̆̈̊͐̒̈̐̀͂̑͌͗̽̎̌̉̃̓̽̒̿̈̎̍͌͛̿̔̓͐̈́͐͌̏̓́̀͊͘͘͝͝r̸̢̘̭̖̹̰̖͉͔͔̣̩̜͊͒̀̅̌̎́͛̎̌̊́̐̾̆͆̿̑̏̋̒͘͘͝ ̵̡̢̢̡͎̱̪͕̳̠̤̪̗͖͓̳̮̗͓̜͓̪͙͈̝̲̫͙̥̦̱̭̼͔͚̼͛̍͂̀͆͗́̂̀̄͑͌̈̅̎́̈̏̿̾̏̀͋͛́͋͌́͜͜͝͠͝͝ͅͅḧ̸͕̖̥̗͓̳̩̙́͂͊͑̃͒̍͆̅̋̈́̉̃͐̌̚͜͜͠ą̶̡̘̬͚̖̰̻̝̼̲͈̗̣̱̖͎̦͓̣͇̳̟̰̤̞̺͎̣̫̦̲͍̰̥͙̹̼̰̺̺͎̦̫͛̃̿̌͊̑͐̀̐̈́̒̊̿̾́́̑́̎̈́͆̒́͆̆͛̕͘̕̚̚̚͝͠͝ͅd̷̢̛̛͖̠̟̺͇̬̳͕͕͓̽̔́͆̉͂̇̂́̿̆̒̀̽͂̔͂̒̆͛̃͆̍̉̉̈́̆͑̇͆̌͑̌͛̈́̃̚̚̕̚͠͝͝!̴̨̢̧̢̛̠͍͖̦͕̼̮͓͕̗̜̲̞̹̘͕͙̠̼̹̬͕̹̗̼̰̗̺̱̦͛̒͌͂̆̉͛́̍̆̄͒̽̈́͑͗͂͗͛̀̄͋̈́̇̍͛̑̆̅́̒̀̍͂̑̕̕̕͜͜͜͝͝͝" << endl; // don't worry, it's just a font :)
                        }
                        if(k5.assignFoodVal() == 1 && k5.assignFoodVal() == 2) // probability of disgusting food
                        {
                            cout << "Shoot! The cooks burnt the food terribly!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction10();
                        }
                        if(k5.assignFoodVal() == 3 && k5.assignFoodVal() == 4) // probability of average quality food
                        {
                            cout << "You recieved a complaint about finding an unknown alien goo in the food!" << endl;
                            cout << BLACK << "They stormed out of the restaurant... but you decided to get back to work." << endl;
                            cout << "(This may affect your customer satisfaction!)" << RESET << endl;
                            c5.decreaseSatisfaction5();
                        }
                        cout << endl;
                        cout << BLACK << "Press 'c' to continue" << RESET << endl;
                        cin >> cont_exit;
                        if (cont_exit != 'c')
                        {
                            while(cont_exit != 'c'){
                                cout << BLACK << "Please enter valid input." << RESET << endl;
                                cin >> cont_exit;
                            }
                        }
                        if(cont_exit == 'c')
                        {
                            system("clear");
                            m.move('a');
                            m.displayMap();
                            displayEnergy(p.getEnergy());
                            cout << BLACK << "Use WASD to move again" << RESET << endl;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << "Please enter valid input." << endl;
                            cin >> cont_exit;
                        }while(cont_exit != 'c');
                    }
                }

                if(c1.getOrderDelivered() == true)
                {
                    int c1_table5 = c1.getTable();
                    if(c1_table5 == 5){
                        m.removeNPC(9,2);
                        m.addTable(9,2);
                        t5.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c1.setOrderDelivered(false);
                        p.setOrderTaken(5, false);
                    } 
                }
                else if(c2.getOrderDelivered() == true)
                {
                    int c2_table = c2.getTable();
                    if(c2_table == 5){
                        m.removeNPC(9,2);
                        m.addTable(9,2);
                        t5.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c2.setOrderDelivered(false);
                        p.setOrderTaken(5, false);
                    } 
                }
                else if(c3.getOrderDelivered() == true)
                {
                    int c3_table = c3.getTable();
                    if(c3_table == 5){
                        m.removeNPC(9,2);
                        m.addTable(9,2);
                        t5.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c3.setOrderDelivered(false);
                        p.setOrderTaken(5, false);
                    } 
                }
                else if(c4.getOrderDelivered() == true)
                {
                    int c4_table = c4.getTable();
                    if(c4_table == 5){
                        m.removeNPC(9,2);
                        m.addTable(9,2);
                        t5.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c4.setOrderDelivered(false);
                        p.setOrderTaken(5, false);
                    } 
                }
                else if(c5.getOrderDelivered() == true)
                {
                    int c5_table = c5.getTable();
                    if(c5_table == 5)
                    {
                        m.removeNPC(9,2);
                        m.addTable(9,2);
                        t5.setAvailability(true);
                        if(customer_count < 5)
                        {
                            m.addNPC(11, 11);
                        }
                        else
                        {
                            m.addCritic(11,11);
                        }
                        c5.setOrderDelivered(false);
                        p.setOrderTaken(5, false);
                    } 
                }
            }
            else if(t5.getAvailability() == true && t5.getCleanStatus() == false) // cleaning the table
            {
                cout << "Press 'c' to clean the table" << endl;
                cin >> cont_exit;
                if (cont_exit != 'c')
                {
                    while(cont_exit != 'c'){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> cont_exit;
                    }
                }
                if(cont_exit == 'c'){
                    t5.setCleanStatus(true);
                    cout << BOLDWHITE << "Table five was successfully cleaned!" << RESET << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
                
                t5.setCleanStatus(true); 
            }
            else if (t5.getAvailability() == false && p.getOrderTaken(5) == true)
            {
                cout << RED << "You already took my order! Where is my order?! \\(◣_◢)/" << RESET << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }

        }

        if(m.getPlayerCol() == 9 && m.getPlayerRow() == 2) // Kitchen function
        {
            if(customer_count == 1 && p.getOrderTaken(c1.getTable()))
            {
                system("clear");
                k1.readCustomerOrder("kitchen0.txt");
                k1.displayCustomerOrder();
                cout << "Enter a number for the dish you wish to pick: ";
                int dish_num1;
                cin >> dish_num1;
                if (dish_num1 < 1 || dish_num1 > 3)
                {
                    while(dish_num1 < 1 || dish_num1 > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> dish_num1;
                    }
                }
                if(dish_num1 >= 1 || dish_num1 <= 3)
                {
                    system("clear");
                    k1.setWentToKitchenStatus(true);
                    k1.setCorrectFood(dish_num1, "Boleux cheese solution");
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << "You've selected dish number " << dish_num1 << "!" << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
            }
            else if(customer_count == 2 && p.getOrderTaken(c2.getTable()))
            {
                system("clear");
                k2.readCustomerOrder("kitchen1.txt");
                k2.displayCustomerOrder();
                cout << "Enter a number for the dish you wish to pick: ";
                int dish_num2;
                cin >> dish_num2;
                if (dish_num2 < 1 || dish_num2 > 3)
                {
                    while(dish_num2 < 1 || dish_num2 > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> dish_num2;
                    }
                }
                if(dish_num2 >= 1 || dish_num2 <= 3)
                {
                    system("clear");
                    k2.setWentToKitchenStatus(true);
                    k2.setCorrectFood(dish_num2, "Creamy Globguns pasta");
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << "You've selected dish number " << dish_num2 << "!" << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
            }
            else if(customer_count == 3 && p.getOrderTaken(c3.getTable()))
            {
                system("clear");
                k3.readCustomerOrder("kitchen2.txt");
                k3.displayCustomerOrder();
                cout << "Enter a number for the dish you wish to pick: ";
                int dish_num3;
                cin >> dish_num3;
                if (dish_num3 < 1 || dish_num3 > 3)
                {
                    while(dish_num3 < 1 || dish_num3 > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> dish_num3;
                    }
                }
                if(dish_num3 >= 1 || dish_num3 <= 3)
                {
                    system("clear");
                    k3.setWentToKitchenStatus(true);
                    k3.setCorrectFood(dish_num3, "Be'kloren pseudo-nuts");
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << "You've selected dish number " << dish_num3 << "!" << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
            }
            else if(customer_count == 4 && p.getOrderTaken(c4.getTable()))
            {
                system("clear");
                k4.readCustomerOrder("kitchen3.txt");
                k4.displayCustomerOrder();
                cout << "Enter a number for the dish you wish to pick: ";
                int dish_num4;
                cin >> dish_num4;
                if (dish_num4 < 1 || dish_num4 > 3)
                {
                    while(dish_num4 < 1 || dish_num4 > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> dish_num4;
                    }
                }
                if(dish_num4 >= 1 || dish_num4 <= 3)
                {
                    system("clear");
                    k4.setWentToKitchenStatus(true);
                    k4.setCorrectFood(dish_num4, "Ustrois carbo-gammon");
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << "You've selected dish number " << dish_num4 << "!" << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
            }
            else if(customer_count == 5 && p.getOrderTaken(c5.getTable()))
            {
                system("clear");
                k5.readCustomerOrder("kitchen4.txt");
                k5.displayCustomerOrder(); 
                cout << "Enter a number for the dish you wish to pick: ";
                int dish_num5;
                cin >> dish_num5;
                if (dish_num5 < 1 || dish_num5 > 3)
                {
                    while(dish_num5 < 1 || dish_num5 > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> dish_num5;
                    }
                }
                if(dish_num5 >= 1 || dish_num5 <= 3)
                {
                    system("clear");
                    k5.setWentToKitchenStatus(true);
                    k5.setCorrectFood(dish_num5, "Industrial Mesajuc paste in a tube");
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                    cout << "You've selected dish number " << dish_num5 << "!" << endl;
                    cout << BLACK << "Use WASD to move again" << RESET << endl;
                }
            }
            else if(customer_count == 6 && p.getOrderTakenCritic() == true)
            {
                system("clear");
                k_critic.setWentToKitchenStatus(true);
                k_critic.readAppetizer("kitchen_apps.txt");
                k_critic.readEntrees("kitchen_desserts.txt");
                k_critic.readDesserts("kitchen_entrees.txt");
                k_critic.displayAppetizers();
                cout << "Enter a number for the appetizer you wish to pick: ";
                int app_num;
                cin >> app_num;
                if (app_num < 1 || app_num > 3)
                {
                    while(app_num < 1 || app_num > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> app_num;
                    }
                }
                if(app_num >= 1 || app_num <= 3)
                {
                    system("clear");
                    k_critic.setCorrectApp(app_num, "Bananna-flavoured Voltet locusts");
                    k_critic.displayEntrees();
                    cout << "Enter a number for the entree you wish to pick: ";
                }
                int entree_num;
                cin >> entree_num;
                if (entree_num < 1 || entree_num > 3)
                {
                    while(entree_num < 1 || entree_num > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> entree_num;
                    }
                }
                if(entree_num >= 1 || entree_num <= 3)
                {
                    system("clear");
                    k_critic.setCorrectEntree(entree_num, "Oxygenated Lurko moose");
                    k_critic.displayDesserts(); 
                    cout << "Enter a number for the dessert you wish to pick: ";
                }
                int dessert_num;
                cin >> dessert_num;
                if (dessert_num < 1 || dessert_num > 3)
                {
                    while(dessert_num < 1 || dessert_num > 3){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> dessert_num;
                    }
                }
                if(dessert_num >= 1 || dessert_num <= 3)
                {
                    system("clear");
                    k_critic.setCorrectDessert(dessert_num, "Ke'zon chocolate wellington");
                    k_critic.setWentToKitchenStatus(true);
                    m.move('s');
                    m.displayMap();
                    displayEnergy(p.getEnergy());
                }
            }
            else
            {
                system("clear");
                m.move('s');
                m.displayMap();
                displayEnergy(p.getEnergy());
                cout << "You have not placed any orders yet!" << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }
        }

        if(m.getPlayerRow() == 2 && m.getPlayerCol() == 2) // lunch break to refill energy
        {
            if(p.getEnergy() == 100)
            {
                system("clear");
                m.move('s');
                m.displayMap();
                displayEnergy(p.getEnergy());
                cout << "Get back to work! It's not time for lunch yet" << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }
            else if(p.getEnergy() < 100)
            {
                cout << "Press 'c' to take a lunch break" << endl;
                cin >> cont_exit;
                if(cont_exit == 'c'){
                    system("clear");
                }
                else{
                    while( cont_exit != 'c'){
                        cout << BLACK << "Please enter valid input." << RESET << endl;
                        cin >> cont_exit;
                    }
                    system("clear");
                }
                
                system("clear");
                m.move('s');
                m.displayMap();
                p.refillEnergy();
                displayEnergy(p.getEnergy());


                cout << GREEN << "You're ready to get back to work!" << RESET << endl;
                cout << BLACK << "Use WASD to move again" << RESET << endl;
            }
        }
        
        if(p.getEnergy() == 0) // when you run out of energy
        {
            system("clear");
            cout << "Looks like you ran out of energy! You found yourself getting dizzier with each step you take until... " << YELLOW << "*THUD* " << endl;
            cout << BLACK << "(Press 'c' to continue)" << RESET << endl;
            cin >> cont_exit;
            if(cont_exit == 'c'){
                system("clear");
                cout << BOLDRED << "GAME OVER" << endl;
                return 0;
            }
            else{
                while(cont_exit != 'c'){
                    cout << BLACK << "Please enter valid input." << RESET << endl;
                    cin >> cont_exit;
                }
                system("clear");
            }
        }

        
        // moving mechanics
        char keyChar;
        cin >> keyChar;
        m.move(keyChar);
        system("clear");
    }
    
    return 0;
}