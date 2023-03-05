#include <iostream>
#include <fstream>
#include "Table.h"
using namespace std;

Table::Table()
{
    clean_ = true;
    available_ = true;
}

bool Table::getCleanStatus()
{
  return clean_;  
}

void Table::setCleanStatus(bool clean)
{
    clean_ = clean;
}

bool Table::getAvailability()
{
    return available_;
}

void Table::setAvailability(bool available)
{
   available_ = available; 
}