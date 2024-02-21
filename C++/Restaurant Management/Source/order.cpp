#include <order.hpp>
/*
Description: This function to retrieve the Food associated with the Order.
Input: None
Output: Food object representing the ordered food item.
*/
Food Order :: getFood(){
    return food;
}
/*
Description: This function to retrieve the quantity of the ordered food item in the Order.
Input: None
Output: Integer representing the quantity of the ordered food item.
*/
int Order :: getFoodQuantity(){
    return quantity;
}
/*
Description: Setter function to update the quantity of the ordered food item in the Order.
Input:
    quantity: The new quantity to set for the ordered food item.
Output: None
*/
void Order :: setFoodQuantity(int quantity){
    this->quantity = quantity;
}