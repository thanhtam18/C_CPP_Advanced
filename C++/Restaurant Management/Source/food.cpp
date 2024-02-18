#include <food.hpp>


void Food :: setPrices(int newPrices){
    this->prices = newPrices;
}
int Food :: getId(){
    return id;
}
string Food :: getName(){
    return name;
}
int Food :: getPrices(){
    return prices;
}