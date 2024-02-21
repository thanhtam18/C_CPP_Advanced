#include <food.hpp>

/*
Description: Setter function to update the prices of the food item.
Input:
    newPrices: The new prices to set for the food item.
Output: None
*/
void Food :: setPrices(int newPrices){
    this->prices = newPrices;
}
/*
Description: This function to retrieve the unique identifier (id) of the food item.
Input: None
Output: Integer representing the unique identifier of the food item.
*/
int Food :: getId(){
    return id;
}
/*
Description: This function to retrieve the name of the food item.
Input: None
Output: String representing the name of the food item.
*/
string Food :: getName(){
    return name;
}
/*
Description: This function to retrieve the prices of the food item.
Input: None
Output: Integer representing the prices of the food item.
*/
int Food :: getPrices(){
    return prices;
}