#include <menu.hpp>
/*
Description: Function to print the list of food items managed by the Manager.
Input:
    mn: Reference to a Manager object representing the manager with the food database to be printed.
Output: None
*/
void managerPrintList(Manager &mn){
    int index = 1;
    list<Food> list = mn.getListFood();
    cout<<setw(6)<<left<<"STT"<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
    for(auto item : list){
        cout<<setw(6)<<left<<index++
            <<setw(10)<<left<<item.getId()
            <<setw(10)<<left<<item.getName()
            <<setw(10)<<left<<item.getPrices()<<endl;
    }
}
/*
Description: Function to set the quantity of tables managed by the Manager.
Input:
    mn: Reference to a Manager object representing the manager whose table quantity is to be set.
Output: The function returns the user's choice.
*/
int managerSetQuantity(Manager &mn){
    int key;
    int quantity;
    cout<<"--- Set quantity table ---\r\n";
    do{
        cout<<"Enter quantity table: ";
        cin>>quantity;  
    }while(quantity <= 0);
    mn.setTableQuantity(quantity);
    cout<<"--- Successful ---\r\n";
    do{
        cout<<"1. Return\r\n"
            <<"0. Exit\r\n"
            <<"Your chose: ";
        cin>>key;
    }while(key != 0 && key != 1);  
    return key;
}
/*
Description: Function to interactively add new food items to the database managed by the Manager.
Input:
    mn: Reference to a Manager object representing the manager with the food database to be updated.
Output: None
*/
void managerAddFood(Manager &mn){
    int key;
    do{
        string name;
        int prices;
        cout<<"--- Add Food ---"<<endl;
        cout<<"Enter Name of Food: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Prices of Food: ";
        cin>>prices;
        Food f(name, prices);
        mn.addFood(f);
        cout<<"------------------------\r\n"
            <<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
        cout<<setw(10)<<left<<f.getId()
            <<setw(10)<<left<<f.getName()
            <<setw(10)<<left<<f.getPrices()<<endl;
        cout<<"--- Successful ---\r\n";
        do{
            cout<<"1. Add other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);     
    }while(key == 1);
}
/*
Description: Function to interactively edit existing food items in the database managed by the Manager.
Input:
    mn: Reference to a Manager object representing the manager with the food database to be updated.
Output: None
*/
void managerEditFood(Manager &mn){
    int key;
    int prices, id;
    do{
        bool isExist = false;
        cout<<"--- Edit Food ---"<<endl;
        cout<<"List Food:"<<endl;
        managerPrintList(mn);
        cout<<"Enter ID of Food want to edit: ";
        cin>>id;
        cout<<"------------------------\r\n";
        list<Food> list = mn.getListFood();
        Food f("",0);
        for(auto item : list){
            if(item.getId() == id){
                cout<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
                cout<<setw(10)<<left<<item.getId()
                    <<setw(10)<<left<<item.getName()
                    <<setw(10)<<left<<item.getPrices()<<endl;
                cout<<"Enter new prices: ";
                cin>>prices;
                item.setPrices(prices);
                mn.editFood(item);
                isExist = true;
                break;
            }
        }
        if(!isExist){
            cout<<"ID do not exist"<<endl;
            return;
        }
        cout<<"--- Successful ---\r\n";
        do{
            cout<<"1. Edit other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);     
    }while(key == 1); 
}
/*
Description: Function to interactively remove existing food items from the database managed by the Manager.
Input:
    mn: Reference to a Manager object representing the manager with the food database to be updated.
Output: None
*/
void managerRemoveFood(Manager &mn){
    int key;
    int id;
    do{
        bool isExist = false;
        cout<<"--- Remove Food ---"<<endl;
        cout<<"List Food:"<<endl;
        managerPrintList(mn);
        cout<<"Enter ID of Food want to remove: ";
        cin>>id;
        cout<<"------------------------\r\n";
        list<Food> list = mn.getListFood();
        for(auto item : list){
            if(item.getId() == id){
                cout<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
                cout<<setw(10)<<left<<item.getId()
                    <<setw(10)<<left<<item.getName()
                    <<setw(10)<<left<<item.getPrices()<<endl;
                mn.removeFood(item);
                isExist = true;
                break;
            }
        }
        if(!isExist){
            cout<<"ID do not exist"<<endl;
            return;
        }
        
        cout<<"--- Successful ---\r\n";
        do{
            cout<<"1. Remove other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);     
    }while(key == 1);
}
/*
Description: Function to handle managerial operations and interactions.
Input:
    mn: Reference to a Manager object representing the manager with the food database to be managed.
Output: None
*/
void managerHandle(Manager &mn){
    int key;
    while(1){
        cout<<"--- Manager ---"<<endl;
        SUB_MENU("Set quantity table", "Add Food", "Edit Food", "Remove Food", "List Food", "Return");
        cout<<"Your chose: ";
        cin>>key;
        switch (key){
            case 1:
                if(managerSetQuantity(mn) == 0)  return;
                break;
            case 2:
                managerAddFood(mn);
                break;
            case 3:
                managerEditFood(mn);
                break;
            case 4:
                managerRemoveFood(mn);
                break;
            case 5:
                cout<<"--- Menu ---"<<endl;
                managerPrintList(mn);
                cout<<"---------------------"<<endl;
                do{
                    cout<<"1. Return\r\n"
                        <<"0. Exit\r\n"
                        <<"Your chose: ";
                    cin>>key;
                    if(key == 0)
                        return;
                }while(key != 0 && key != 1);  
                break;
            case 0:
                return;
        }
    }
}
/*
Description: Function to print the list of orders for a specific table managed by the Employer.
Input:
    em: Reference to an Employer object representing the employer managing the tables and orders.
    tableNumber: Integer representing the table number for which the orders are to be printed.
Output: None
*/
void employerPrintListOrder(Employer &em, int tableNumber){
    cout<<"--------------------------------------------\r\n";
    list<Order> list = em.getTable(tableNumber).getListOrder();
    if(list.size() == 0){
        cout<<"Have not order yet"<<endl;
        return;
    }
    int index = 1;
    for(auto item : list){
        if(index == 1){
        cout<<setw(10)<<left<<"Index"<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<setw(10)<<left<<"Quantity"<<endl;
        }
        cout<<setw(10)<<left<<index++
            <<setw(10)<<left<<item.getFood().getId()
            <<setw(10)<<left<<item.getFood().getName()
            <<setw(10)<<left<<item.getFood().getPrices()
            <<setw(10)<<left<<item.getFoodQuantity()<<endl;
    }
    cout<<"--------------------------------------------\r\n";
}
/*
Description: Function to interactively take food orders for a specific table managed by the Employer.
Input:
    em: Reference to an Employer object representing the employer managing the tables and orders.
    tableNumber: Integer representing the table number for which the orders are to be taken.
Output: None
*/
void orderFood(Employer &em, int tableNumber){
    int key;
    int id,quantity;
    do{
        bool isExist = false;
        cout<<"--- Order Food ---"<<endl;
        int index = 1;
        list<Food> list = em.getTable(tableNumber).getListFood();
        cout<<setw(6)<<left<<"STT"<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
        for(auto item : list){
            cout<<setw(6)<<left<<index++
                <<setw(10)<<left<<item.getId()
                <<setw(10)<<left<<item.getName()
                <<setw(10)<<left<<item.getPrices()<<endl;
        }   
        cout<<"Enter ID of Food want to order: ";
        cin>>id;
        cout<<"------------------------\r\n";
        for(auto item : list){
            if(item.getId() == id){
                cout<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
                cout<<setw(10)<<left<<item.getId()
                    <<setw(10)<<left<<item.getName()
                    <<setw(10)<<left<<item.getPrices()<<endl;
                cout<<"Enter quantity want to order: ";
                cin>>quantity;
                Order order(item, quantity);
                em.tableHandle(tableNumber, ORDER, order);
                isExist = true;
                employerPrintListOrder(em, tableNumber);
                em.setStatus(tableNumber,true);
                break;
            }
        }
        if(!isExist){
            cout<<"ID do not exist"<<endl;
            return;
        }
        do{
            cout<<"1. Order other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);  
    }while(key == 1);
}
/*
Description: Function to interactively cancel food orders for a specific table managed by the Employer.
Input:
    em: Reference to an Employer object representing the employer managing the tables and orders.
    tableNumber: Integer representing the table number for which the orders are to be canceled.
Output: None
*/
void cancelFood(Employer &em, int tableNumber){
    int key,id;
    int quantity;
    do{
        bool isExist = false;
        cout<<"--- Cancel Food ---"<<endl;
        employerPrintListOrder(em, tableNumber);
        cout<<"Enter ID of Food want to cancel: ";
        cin>>id;
        cout<<"------------------------\r\n";
        list<Order> list = em.getTable(tableNumber).getListOrder();
        for(auto item : list){
            if(item.getFood().getId() == id){
                cout<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<setw(10)<<left<<"Quantity"<<endl;
                cout<<setw(10)<<left<<item.getFood().getId()
                    <<setw(10)<<left<<item.getFood().getName()
                    <<setw(10)<<left<<item.getFood().getPrices()
                    <<setw(10)<<left<<item.getFoodQuantity()<<endl;
                do{
                cout<<"Enter quantity want to cancel: ";
                cin>>quantity;
                }while(quantity > item.getFood().getPrices());
                isExist = true;
                Order order(item.getFood(), quantity);
                em.tableHandle(tableNumber, CANCEL, order);
                break;
            }
        }
        if(!isExist){
            cout<<"ID do not exist"<<endl;
            return;
        }
        do{
            cout<<"1. Cancel other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);  
    }while(key == 1);
}
/*
Description: Function to interactively change food orders for a specific table managed by the Employer.
Input:
    em: Reference to an Employer object representing the employer managing the tables and orders.
    tableNumber: Integer representing the table number for which the orders are to be changed.
Output: None
*/
void changeFood(Employer &em, int tableNumber){
    int key;
    int id, newId, quantity;
    do{
        bool isSuccess = false;
        cout<<"--- Change Food ---"<<endl;
        employerPrintListOrder(em, tableNumber);
        cout<<"Enter ID of Food want to change: ";
        cin>>id;
        cout<<"------------------------\r\n";
        int index = 1;
        list<Order> listOrder = em.getTable(tableNumber).getListOrder();
        list<Food> list = em.getTable(tableNumber).getListFood();
        cout<<setw(6)<<left<<"STT"<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
        for(auto item : list){
            cout<<setw(6)<<left<<index++
                <<setw(10)<<left<<item.getId()
                <<setw(10)<<left<<item.getName()
                <<setw(10)<<left<<item.getPrices()<<endl;
        }  
        cout<<"Enter ID of new Food: ";
        cin>>newId;
        cout<<"Enter quantity of new Food: ";
        cin>>quantity;
        cout<<"------------------------\r\n";
        for(auto item : listOrder){
            if(item.getFood().getId() != id)
                continue;
            for(auto item2 : list){
                if(item2.getId() != newId)
                    continue;
                if(item2.getId() == newId){
                    Order newOrder{item2, quantity};
                    em.tableHandle(tableNumber, CHANGE, item, newOrder);
                    isSuccess = true;
                    break;
                }
            }
            break;
        }
        if(!isSuccess){
            cout<<"Change failed"<<endl;
            return;
        }
        do{
            cout<<"1. Change other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);  
    }while(key == 1);
}

/*
Description: Function to interactively handle the payment process for a specific table managed by the Employer.
Input:
    em: Reference to an Employer object representing the employer managing the tables and orders.
    tableNumber: Integer representing the table number for which the payment is to be processed.

Output:
    Returns a boolean indicating whether the payment was successfully processed.
*/
bool payment(Employer &em, int tableNumber){
    int key;
    if(em.getTable(tableNumber).getBill() == 0){
        cout<<"---------------------"<<endl;
        cout<<"Have not order yet"<<endl;
        cout<<"---------------------"<<endl;
        return false;
    }
    cout<<"--- Payment ---"<<endl;
    cout<<"List Food ordered:"<<endl;
    employerPrintListOrder(em, tableNumber);
    cout<<"Sum: "<<em.getTable(tableNumber).getBill()<<endl;
    cout<<"VAT: 10%\r\n"
        <<"Total: "<< (em.getTable(tableNumber).getBill() + (em.getTable(tableNumber).getBill())*10/100)<<endl;
    cout<<"--------------------------------------------\r\n";
    do{
        cout<<"1. Make a Payment\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>key;
        if(key == 1){
            em.tableHandle(tableNumber, PAYMENT);
            cout<<"----- Successful -----\r\n";
            return true;
        }
    }while(key != 0 && key != 1);  
    return false;
}
/*
Description: Function to handle the interactive management tasks for an employer.
Input:
    mn: Reference to a Manager object representing the manager with information about food and table quantity.
Output: None
*/
void employerHandle(Manager &mn){
    if(mn.getTableQuantity() == 0){
        cout<<"---------------------"<<endl;
        cout<<"Please set quantity table"<<endl;
        cout<<"---------------------"<<endl;
        return;
    }
    int key;
    int tableNumber;
    static Employer em(mn.getListFood(), mn.getTableQuantity());
    while(1){
        cout<<"--- Employer ---"<<endl;
        vector<Table> listTable = em.getListTable();
        cout<<setw(15)<<left<<"Table Number: ";
        for(auto table : listTable){
            cout<<setw(5)<<left<<table.getTableId();
        }
        cout<<"\r\n";
        cout<<setw(15)<<left<<"Status: ";
        for(auto table : listTable){
            cout<<setw(5)<<left<<(table.getTableStatus() ? "X" : "O");
        }
        cout<<"\r\n--------------------------------------------\r\n";
        do{
        cout<<"Chose table (0. Return): ";
        cin>>tableNumber;
        if(tableNumber == 0)
            return;
        }while(tableNumber < 0 || tableNumber > mn.getTableQuantity());
        do{
            SUB_MENU("Order Food", "Cancel Food", "Change Food", "List Order Food", "Payment", "Return");
            cout<<"Your chose: ";
            cin>>key;
            switch (key){
                case 1:
                    orderFood(em, tableNumber);
                    break;
                case 2:
                    cancelFood(em, tableNumber);
                    break;
                case 3:
                    changeFood(em, tableNumber);
                    break;
                case 4:
                    int chose;
                    cout<<"--- List Order Food ---"<<endl;
                    employerPrintListOrder(em, tableNumber);
                    do{
                        cout<<"0. Return\r\n"
                            <<"Your chose: ";
                        cin>>chose;
                    }while(chose != 0);  
                    break;
                case 5:
                    if(payment(em, tableNumber)) key = 0;
                    break;
                case 0:
                    break;
            }
        }while(key != 0);
    }
}