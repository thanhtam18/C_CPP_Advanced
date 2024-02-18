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

list<Order> Table :: getListOrder(){
    return listOrder;
}