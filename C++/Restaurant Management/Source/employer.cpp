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
Description: This function to retrieve the list of tables managed by the Employer.
Input: None
Output: Vector of Table objects representing the tables managed by the Employer.
*/
vector<Table> Employer :: getListTable(){
    return listTable;
}

/*
Description: This function to retrieve the list of Food items in the Employer's database.
Input: None
Output: List of Food objects representing the database of the Employer.
*/
list<Food> Employer :: getListFood(){
    return listFood;
}

/*
Description: This function to retrieve a specific Table by its table number.
Input:
    tableNumber: The unique identifier of the table to retrieve.
Output: Table object representing the specified table; an empty Table if not found.
*/
Table Employer :: getTable(int tableNumber){
    for(auto item : listTable){
        if(item.getTableId() == tableNumber){
            return item;
        }
    }
    return Table();
}

/*
Description: Function to perform various operations on a specified table.
Input:
    tableNumber: The unique identifier of the table to handle.
    type: Enumerated type (Type) indicating the operation to be performed (ORDER, CANCEL, PAYMENT, CHANGE).
    ...: Variable number of arguments based on the specified operation type.
Output: None
*/
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
            case PAYMENT:
                listTable[i].makeAPayment();
                break;
            case CHANGE:
                Order oldOrder = va_arg(arg,Order);
                Order newOrder = va_arg(arg,Order);
                listTable[i].changeFood(oldOrder, newOrder);
                break;
        }
    }
    va_end(arg); 
}

/*
Description: Function to set the status (occupied/unoccupied) of a specified table.
Input:
    tableNumber: The unique identifier of the table to update.
    status: Boolean indicating the new status of the table (true for occupied, false for unoccupied).
Output: None
*/
void Employer :: setStatus(int tableNumber, bool status){
    for(vector<Table>::size_type i = 0; i < listTable.size(); i++){
        if(listTable[i].getTableId() == tableNumber){
            listTable[i].setTableStatus(status);
            return;
        }
    } 
}
