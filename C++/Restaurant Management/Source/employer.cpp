#include <employer.hpp>

/*
Description: This constructor initializes a Employer object with the provided parameters..
Input: 
    dataBase: The list representing the database of Food.
    quantity: The quantity of table
    passWord: The password of employer
Ouput: None
*/
Employer :: Employer(list<Food> dataBase, int quantity, string passWord){
    this->listFood = dataBase;
    this->quantity = quantity;
    this->passWord = passWord;
    for(int i = 1; i <= quantity; i++){
        Table tb(i,false, dataBase);
        listTable.push_back(tb);
    }
}

/*
Description: This function returns the list of table.
Input: None
Output: The list table.
*/
vector<Table> Employer :: getListTable(){
    return listTable;
}

list<Food> Employer :: getListFood(){
    return listFood;
}

Table Employer :: getTable(int tableNumber){
    for(auto item : listTable){
        if(item.getTableId() == tableNumber){
            return item;
        }
    }
    return Table();
}

void Employer :: tableHandle(int tableNumber, Type type, ...){
    va_list arg;
    va_start(arg,type); 
    for(vector<Table>::size_type i = 0; i < listTable.size(); i++){
        if(listTable[i].getTableId() != tableNumber){
            continue;
        }
        switch(type){
            case ORDER:
                
                listTable[i].orderFood(va_arg(arg, Order));
                break;
            case CANCEL:
                listTable[i].deleteFood(va_arg(arg, Order));
                break;
            case CHANGE:
                Order oldOrder = va_arg(arg,Order);
                Order newOrder = va_arg(arg,Order);
                listTable[i].changeFood(oldOrder, newOrder);
                break;
            case PAYMENT:

                break;
        }
    }
    va_end(arg); 
}

void Employer :: setStatus(int tableNumber, bool status){
    for(vector<Table>::size_type i = 0; i < listTable.size(); i++){
        if(listTable[i].getTableId() == tableNumber){
            listTable[i].setTableStatus(status);
            return;
        }
    } 
}
