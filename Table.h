#include <iostream>
using namespace std;

#ifndef TABLE_H
#define TABLE_H

/*
Determines if a table is available, unavailable, clean, and dirty
*/
class Table
{
    private:
        bool clean_;
        bool available_;
        bool order_taken_;

    public:
        Table();
        bool getCleanStatus(); // getters/setters for the status of the table
        void setCleanStatus(bool clean);
        bool getAvailability(); // if the table is available or not
        void setAvailability(bool available); 
};

#endif