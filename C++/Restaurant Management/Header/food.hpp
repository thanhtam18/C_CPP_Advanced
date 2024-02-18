/*
    File:   food.hpp
    Author: Thanh Tam
    Date:   13/2/2024
    Description: This header file declare functions and macro for file food.cpp
*/
#ifndef _FOOD_H
#define _FOOD_H

#include <string>

using namespace std;

class Food{
    private:
        int id;
        string name;
        int prices;
    public:
        Food(string name, int prices) :
        name(name), prices(prices){
            static int id = 1000;
            this->id = id;
            id++;
        };
        void setPrices(int newPrices);
        int getId();
        string getName();
        int getPrices();
};


#endif