#include <table.hpp>

Table :: Table(int id, bool status, list<Food> menu){
    this->tableId = id;
    this->tableStatus = status;
    this->menu = menu;
}

int Table :: getTableId(){
    return tableId;
}

bool Table :: getTableStatus(){
    return tableStatus;
}

void Table :: orderFood(Order order){
    listOrder.push_back(order);
}

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

list<Order> Table :: getListOrder(){
    return listOrder;
}

list<Food> Table :: getListFood(){
    return menu;
}

void Table :: setTableStatus(bool status){
    this->tableStatus = status;
}

void Table :: changeFood(Order oldOrder, Order newOrder){
    for(list<Order>::iterator i = listOrder.begin(); i != listOrder.end(); i++){
        if(i->getFood().getId() == oldOrder.getFood().getId()){
            cout<<"delete\r\n";
        }
        
        //listOrder.erase(i);
        break;
    }
}

