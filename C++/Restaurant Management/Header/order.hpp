#ifndef _ORDER_H
#define _ORDER_H

#include <food.hpp>

using namespace std;

class Order{
    private:
        Food food;
        int quantity;
    public:
        Order(Food food, int quantity) :
            food(food), quantity(quantity){};

        void setFoodQuantity(int quantity);
        Food getFood();
        int getFoodQuantity();
};

#endif