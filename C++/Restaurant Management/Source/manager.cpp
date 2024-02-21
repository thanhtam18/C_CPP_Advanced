#include <manager.hpp>
/*
Description: This function to update the quantity of tables managed by the Manager.
Input:
    quantity: The new quantity of tables to set for the Manager.
Output: None
*/
void Manager :: setTableQuantity(int quantity){
    *tableQuantity = quantity;
}
/*
Description: Function to add a new Food item to the database managed by the Manager.
Input:
    food: The Food object to be added to the database.
Output: None
*/
void Manager :: addFood(Food food){
    dataBaseFood->push_back(food);
}
/*
Description: Function to edit an existing Food item in the database managed by the Manager.
Input:
    food: The updated Food object to replace the existing item in the database.
Output: None
*/
void Manager :: editFood(Food food){
    for(list<Food>::iterator i = dataBaseFood->begin(); i != dataBaseFood->end(); i++){
        if(i->getId() == food.getId()){
            *i = food;
            break;
        }
    }    
}
/*
Description: Function to remove an existing Food item from the database managed by the Manager.
Input:
    food: The Food object to be removed from the database.
Output: None
*/
void Manager :: removeFood(Food food){
    for(list<Food>::iterator i = dataBaseFood->begin(); i != dataBaseFood->end(); i++){
        if(i->getId() == food.getId()){
            dataBaseFood->erase(i);
            break;
        }
    }    
}
/*
Description: This function to retrieve the list of Food items in the database managed by the Manager.
Input: None
Output: List of Food objects representing the database of the Manager.
*/
list<Food> Manager :: getListFood(){
    return *dataBaseFood;
}
/*
Description: This function to retrieve the quantity of tables managed by the Manager.
Input: None
Output: Integer representing the quantity of tables.
*/
int Manager :: getTableQuantity(){
    return *tableQuantity;
}