#include <table.hpp>
/*
Description: Constructor for initializing a Table object with the provided parameters.
Input:
    id: Integer representing the unique identifier of the table.
    status: Boolean indicating the status of the table
    menu: List of Food objects representing the menu available at the table.
Output: None
*/
Table :: Table(int id, bool status, list<Food> menu){
    this->tableId = id;
    this->tableStatus = status;
    this->menu = menu;
}
/*
Description: This function to retrieve the unique identifier of the table.
Input: None
Output: Integer representing the unique identifier of the table.
*/
int Table :: getTableId(){
    return tableId;
}
/*
Description: This function to retrieve the status of the table 
Input: None
Output: Boolean indicating the status of the table
*/
bool Table :: getTableStatus(){
    return tableStatus;
}
/*
Description: Function to place a food order for the table.
Input:
    order: Order object representing the food items to be ordered.
Output: None
*/
void Table :: orderFood(Order order){
    listOrder.push_back(order);
}
/*

*/
void Table :: deleteFood(Order order){
    for(list<Order>::iterator i = listOrder.begin(); i != listOrder.end(); i++){
        if(i->getFood().getId() != order.getFood().getId()){
            continue;
        }
        if(i->getFoodQuantity() > order.getFoodQuantity()){
            i->setFoodQuantity((i->getFoodQuantity() - order.getFoodQuantity()));
        }
        else if(i->getFoodQuantity() == order.getFoodQuantity()){
            listOrder.erase(i);
        }
    }
}
/*
Description: Function to delete specific food items from the table's existing orders.
Input:
    order: Order object representing the food items to be removed from the orders.
Output: None
*/
list<Order> Table :: getListOrder(){
    return listOrder;
}
/*
Description: This function to retrieve the list of available food items in the table's menu.
Input: None
Output: List of Food objects representing the menu of the table.
*/
list<Food> Table :: getListFood(){
    return menu;
}
/*
Description: This function to update the status of the table 
Input:
    status: Boolean indicating the new status of the table
Output: None
*/
void Table :: setTableStatus(bool status){
    this->tableStatus = status;
}
/*
Description: Function to modify an existing food item in the table's orders.
Input:
    oldOrder: Order object representing the original food item to be modified.
    newOrder: Order object representing the updated food item.
Output: None
*/
void Table :: changeFood(Order oldOrder, Order newOrder){
    for(list<Order>::iterator i = listOrder.begin(); i != listOrder.end(); i++){
        if(i->getFood().getId() != oldOrder.getFood().getId()){
            continue;
        }
        *i = newOrder;
        break;
    }
}
/*
Description: Function to calculate the total bill for the table based on its current orders.
Input: None
Output: Integer representing the total bill amount for the table.
*/
int Table :: getBill(){
    for(auto item : listOrder){
        bill += item.getFoodQuantity() * item.getFood().getPrices();
    }
    return bill;
}
/*
Description: Function to process payment and clear orders for the table.
Input: None
Output: None
*/
void Table :: makeAPayment(){
    tableStatus = false;
    bill = 0;
    for(list<Order>::iterator i = listOrder.begin(); i != listOrder.end(); i++){
        listOrder.erase(i);
    }
}

