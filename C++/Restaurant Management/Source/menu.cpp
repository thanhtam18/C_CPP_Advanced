#include <menu.hpp>

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

int managerSetQuantity(Manager &mn){
    int key;
    int quantity;
    cout<<"--- Set quantity table ---\r\n"
        <<"Enter quantity table: ";
    cin>>quantity;  
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
                f = item;
                isExist = true;
                break;
            }
        }
        if(!isExist){
            cout<<"ID do not exist"<<endl;
            return;
        }
        cout<<"Enter new prices: ";
        cin>>prices;
        f.setPrices(prices);
        mn.editFood(f);
        cout<<"--- Successful ---\r\n";
        do{
            cout<<"1. Edit other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);     
    }while(key == 1); 
}

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
        Food f("",0);
        for(auto item : list){
            if(item.getId() == id){
                cout<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
                cout<<setw(10)<<left<<item.getId()
                    <<setw(10)<<left<<item.getName()
                    <<setw(10)<<left<<item.getPrices()<<endl;
                f = item;
                isExist = true;
                break;
            }
        }
        if(!isExist){
            cout<<"ID do not exist"<<endl;
            return;
        }
        mn.removeFood(f);
        cout<<"--- Successful ---\r\n";
        do{
            cout<<"1. Remove other food\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
        }while(key != 0 && key != 1);     
    }while(key == 1);
}

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

void employerPrintList(Employer &em){
    int index = 1;
    list<Food> list = em.getListFood();
    cout<<setw(6)<<left<<"STT"<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
    for(auto item : list){
        cout<<setw(6)<<left<<index++
            <<setw(10)<<left<<item.getId()
            <<setw(10)<<left<<item.getName()
            <<setw(10)<<left<<item.getPrices()<<endl;
    }    
}

void orderFood(Employer &em){
    int id,quantity;
    bool isExist = false;
    cout<<"--- Order Food ---"<<endl;
    employerPrintList(em);
    cout<<"Enter ID of Food want to order: ";
    cin>>id;
    cout<<"------------------------\r\n";
    list<Food> list = em.getListFood();
    Food f("",0);
    for(auto item : list){
        if(item.getId() == id){
            cout<<setw(10)<<left<<"ID"<<setw(10)<<left<<"Name"<<setw(10)<<left<<"Prices"<<endl;
            cout<<setw(10)<<left<<item.getId()
                <<setw(10)<<left<<item.getName()
                <<setw(10)<<left<<item.getPrices()<<endl;
            f = item;
            isExist = true;
            break;
        }
    }
    if(!isExist){
        cout<<"ID do not exist"<<endl;
        return;
    }
    cout<<"Enter quantity want to order";
    cin>>quantity;
    Order order(f, quantity);

}

void employerHandle(Manager &mn){
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
        SUB_MENU("Order Food", "Cancel Food", "Change Food", "Remove Food", "List Order Food", "Payment", "Return");
        cout<<"Your chose: ";
        cin>>key;
        switch (key){
            case 1:
                orderFood(em);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 0:
                return;
        }
    }    
}