/*
    File:   manager.hpp
    Author: Thanh Tam
    Date:   13/2/2024
    Description: This header file declare functions and macro for file manager.cpp
*/
#ifndef _MANAGER_H
#define _MANAGER_H

#include <food.hpp>
#include <list>

using namespace std;

class Manager{
    private:
        list<Food> *dataBaseFood;
        int *tableQuantity;
        string passWord;
    public:
        Manager(list<Food> *dataBase, int *quantity, string passWord = "ADMIN"){
            dataBaseFood = dataBase;
            tableQuantity = quantity;
            this->passWord = passWord;
        }
        void setTableQuantity(int quantity);
        void addFood(Food food);
        void editFood(Food food);
        void removeFood(Food food);
        list<Food> getListFood();
        int getTableQuantity();
};

#endif