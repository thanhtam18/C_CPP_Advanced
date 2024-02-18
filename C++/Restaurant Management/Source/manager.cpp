#include <manager.hpp>

void Manager :: setTableQuantity(int quantity){
    *tableQuantity = quantity;
}

void Manager :: addFood(Food food){
    dataBaseFood->push_back(food);
}

void Manager :: editFood(Food food){
    for(list<Food>::iterator i = dataBaseFood->begin(); i != dataBaseFood->end(); i++){
        if(i->getId() == food.getId()){
            *i = food;
            break;
        }
    }    
}

void Manager :: removeFood(Food food){
    for(list<Food>::iterator i = dataBaseFood->begin(); i != dataBaseFood->end(); i++){
        if(i->getId() == food.getId()){
            dataBaseFood->erase(i);
            break;
        }
    }    
}

list<Food> Manager :: getListFood(){
    return *dataBaseFood;
}

int Manager :: getTableQuantity(){
    return *tableQuantity;
}