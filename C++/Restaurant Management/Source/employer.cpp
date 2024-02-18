#include <employer.hpp>

Employer :: Employer(list<Food> dataBase, int quantity, string passWord){
    this->listFood = dataBase;
    this->quantity = quantity;
    this->passWord = passWord;
    for(int i = 1; i <= quantity; i++){
        Table tb(i);
        listTable.push_back(tb);
    }
}

vector<Table> Employer :: getListTable(){
    return listTable;
}

list<Food> Employer :: getListFood(){
    return listFood;
}

Table Employer :: getTable(int id){
    for(auto item : listTable){
        if(item.getTableId() == id){
            return item;
        }
    }
}