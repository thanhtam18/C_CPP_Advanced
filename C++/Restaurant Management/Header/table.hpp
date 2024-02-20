/*
    File:   table.hpp
    Author: Thanh Tam
    Date:   13/2/2024
    Description: This header file declare functions and macro for file table.cpp
*/
#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <food.hpp>
#include <order.hpp>
#include <list>

using namespace std;

class Table{
    private:
        int tableId;
        bool tableStatus;
        list<Food> menu;
        list<Order> listOrder;
        int bill;
    public:
        Table(int id = 0, bool status = false, list<Food> menu = {});
        
        void setTableStatus(bool status);

        int getTableId();
        bool getTableStatus();
        void orderFood(Order order);
        void deleteFood(Order order);
        void changeFood(Order oldOrder, Order newOrder);
        list<Order> getListOrder();
        list<Food> getListFood();
        int getBill();
        void makeAPayment();


};

#endif