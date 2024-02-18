#ifndef _TABLE_H
#define _TABLE_H

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
        

        int getTableId();
        bool getTableStatus();
        void orderFood(Order order);
        void deleteFood(Order order);
        list<Order> getListOrder();
        void makeAPayment();


};

#endif