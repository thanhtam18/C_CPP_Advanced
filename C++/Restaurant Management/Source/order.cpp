#include <order.hpp>

Food Order :: getFood(){
    return food;
}

int Order :: getFoodQuantity(){
    return quantity;
}

void Order :: setFoodQuantity(int quantity){
    this->quantity = quantity;
}