#include <menu.hpp>

void addStudent(list<SinhVien> &dataBase){
    while(1){
        int key;
        string tenSV;
        int tuoiSV, gioiTinh;
        GioiTinh gioiTinhSV;
        float diemToan, diemLy, diemHoa;
        cout<<"------ Them Sinh Vien ------"<<endl;
        cout<<"Nhap Ten Sinh Vien: ";
        cin>>tenSV;
        do{
        cout<<"Nhap Tuoi Sinh Vien: ";
        cin>>tuoiSV;
        }while(tuoiSV < 0 || tuoiSV > 100);
        do{
        cout<<"Nhap Gioi Tinh Sinh Vien:  0.Nam   1.Nu     Ban Chon: ";
        cin>>gioiTinh;
        }while(gioiTinh != 0 && gioiTinh != 1);
        gioiTinhSV = (GioiTinh)gioiTinh;
        do{
        cout<<"Nhap Diem Toan: ";
        cin>>diemToan;
        }while(diemToan < 0 || diemToan > 10);
        do{
        cout<<"Nhap Diem Ly: ";
        cin>>diemLy;
        }while(diemLy < 0 || diemLy > 10);
        do{
        cout<<"Nhap Diem Hoa: ";
        cin>>diemHoa;      
        }while(diemHoa < 0 || diemHoa > 10);
        SinhVien sv(tenSV, tuoiSV, gioiTinhSV, diemToan, diemLy, diemHoa);
        dataBase.push_back(sv);
        cout<<"-------------------------------"<<endl;
        cout<<"ID: "<<sv.getMSSV()<<endl
            <<"Ten: "<<sv.getTenSV()<<endl
            <<"Tuoi: "<<sv.getTuoi()<<endl
            <<"Gioi Tinh: "<<((sv.getGioiTinh() == NU) ? "Nu" : "Nam")<<endl
            <<"Toan: "<<sv.getDiemToan()<<" Ly: "<<sv.getDiemLy()<<" Hoa: "<<sv.getDiemHoa()<<endl
            <<"Diem TB: "<<sv.getDiemTrungBinh()<<endl
            <<"Hoc Luc: ";
            switch(sv.getHocLuc()){
                case GIOI:
                    cout<<"Gioi"<<endl;
                    break;
                case KHA:
                    cout<<"Kha"<<endl;
                    break;
                case TRUNG_BINH:
                    cout<<"Trung Binh"<<endl;
                    break;
                case YEU:
                    cout<<"Yeu"<<endl;
                    break;
            }
        cout<<"-------------------------------"<<endl;
        do{
            cout<<"1. Them sinh vien khac\r\n"
                <<"0. Quay lai\r\n"
                <<"Vui long chon: ";
            cin>>key;
            switch(key){
                case 0:
                    return;
                case 1:
                    break;
                default:
                    cout<<"Chon khong hop le"<<endl;
                    break;
            }
        }while(key != 0 && key != 1);
    }
} 

void editStudent(list<SinhVien> &dataBase){
    cout<<"------ Sua Sinh Vien ------"<<endl;
    string ten, newName;
    int id, tuoi, gioiTinh;
    float toan, ly, hoa;
    int index = 0;
    cout<<"Nhap ten cua sinh vien: ";
    cin>>ten;
    cout<<"-------------------------------"<<endl;
    for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
        if(item->getTenSV().compare(ten) == 0){
            if(index == 0){
                cout<<setw(8)<<left<<"STT"<<setw(2)<<left<<"|";
                cout<<setw(8)<<left<<"ID"<<setw(2)<<left<<"|";
                cout<<setw(8)<<left<<"Ten"<<endl;
            }
            index++;        
            cout<<setw(8)<<left<<index<<setw(2)<<left<<"|"
                <<setw(8)<<left<<item->getMSSV()<<setw(2)<<left<<"|"
                <<setw(8)<<left<<item->getTenSV()<<endl;
        }
    }
    cout<<"-------------------------------"<<endl;
    cout<<"Nhap ID cua sinh vien muon sua: ";
    cin>>id;
    for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
        if(item->getMSSV() == id){
            cout<<"-------------------------------"<<endl;
            cout<<"ID: "<<item->getMSSV()<<endl
                <<"Ten: "<<item->getTenSV()<<endl
                <<"Tuoi: "<<item->getTuoi()<<endl
                <<"Gioi Tinh: "<<((item->getGioiTinh() == NU) ? "Nu" : "Nam")<<endl
                <<"Toan: "<<item->getDiemToan()<<" Ly: "<<item->getDiemLy()<<" Hoa: "<<item->getDiemHoa()<<endl
                <<"Diem TB: "<<item->getDiemTrungBinh()<<endl
                <<"Hoc Luc: ";
                switch(item->getHocLuc()){
                    case GIOI:
                        cout<<"Gioi"<<endl;
                        break;
                    case KHA:
                        cout<<"Kha"<<endl;
                        break;
                    case TRUNG_BINH:
                        cout<<"Trung Binh"<<endl;
                        break;
                    case YEU:
                        cout<<"Yeu"<<endl;
                        break;
                }
            cout<<"-------------------------------"<<endl; 
            int key;
            while(1){
                SUB_MENU("Sua Ten", "Sua Tuoi", "Sua Gioi Tinh", "Sua diem Toan", "Sua diem Ly", "Sua diem Hoa", "Quay lai");
                cout<<"Vui long chon: ";
                cin>>key;
                switch(key){
                    case 1:
                        cout<<"--- Sua Ten ---\r\n"
                            <<"Vui long nhap ten: ";
                        cin>>newName;
                        item->setTen(newName);
                        break;
                    case 2:
                        cout<<"--- Sua Tuoi ---\r\n"
                            <<"Vui long nhap tuoi: ";
                        cin>>tuoi;
                        item->setTuoi(tuoi);
                        break;
                    case 3:
                        cout<<"--- Sua Gioi Tinh ---"<<endl;
                        do{
                            cout<<"Nhap Gioi Tinh Sinh Vien:  0.Nam   1.Nu    Ban Chon: ";
                            cin>>gioiTinh;
                        }while(gioiTinh != 0 && gioiTinh != 1);
                        item->setGioiTinh((GioiTinh)gioiTinh);
                        break;
                    case 4:
                        cout<<"--- Sua diem Toan ---"<<endl;
                        do{
                            cout<<"Nhap Diem Toan: ";
                            cin>>toan;
                        }while(toan < 0 || toan > 10);
                        break;
                    case 5:
                        cout<<"--- Sua diem Ly ---"<<endl;
                        do{
                            cout<<"Nhap Diem Ly: ";
                            cin>>ly;
                        }while(ly < 0 || ly > 10);
                        break;
                    case 6:
                        cout<<"--- Sua diem Hoa ---"<<endl;
                        do{
                            cout<<"Nhap Diem Hoa: ";
                            cin>>hoa;
                        }while(hoa < 0 || hoa > 10);
                        break;
                    case 0:
                        return;
                    default:
                        cout<<"Khong hop le"<<endl;
                        break;
                }
                if(key >= 1 && key <= 6){
                    cout<<"----------------------------\r\n"
                        <<"1. Quay lai\r\n"
                        <<"0. Thoat\r\n"
                        <<"Vui long chon: ";
                    cin>>key;
                    if(key == 0)
                        return;
                    cout<<"----------------------------"<<endl;
                }
            }
        }
    }
}

void removeStudent(list<SinhVien> &dataBase){
    while(1){
        int index = 0;
        int id;
        string ten;
        bool isRemoved = false;
        int key;
        cout<<"------ Xoa Sinh Vien ------"<<endl;
        cout<<"Nhap ten cua Sinh Vien: ";
        cin>>ten;
        cout<<"-------------------------------"<<endl;
        for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
            if(item->getTenSV().compare(ten) == 0){       
                if(index == 0){
                    cout<<setw(8)<<left<<"STT"<<setw(2)<<left<<"|";
                    cout<<setw(8)<<left<<"ID"<<setw(2)<<left<<"|";
                    cout<<setw(8)<<left<<"Ten"<<endl;
                }
                index++;        
                cout<<setw(8)<<left<<index<<setw(2)<<left<<"|"
                    <<setw(8)<<left<<item->getMSSV()<<setw(2)<<left<<"|"
                    <<setw(8)<<left<<item->getTenSV()<<endl;
            }
        }
        cout<<"-------------------------------"<<endl;
        cout<<"Nhap ID cua Sinh Vien muon xoa: ";
        cin>>id;
        for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
            if(item->getMSSV() == id){
                dataBase.erase(item);
                isRemoved = true;
                cout<<"Xoa thanh cong"<<endl;
                cout<<"----------------------------"<<endl;
                break;
            }
        }
        if(!isRemoved){
            cout<<"ID khong ton tai"<<endl;
            cout<<"----------------------------"<<endl;
        }
        cout<<"1. Xoa sinh vien khac\r\n"
            <<"0. Quay lai\r\n"
            <<"Vui long chon: ";
        cin>>key;
        if(key == 0)
            return;
    }
}

void displaySearchStudent(list<SinhVien> &dataBase, SearchType type, ...){
    va_list arg;
    va_start(arg, type);
    int index = 0;
    string ten;
    int id;
    switch(type){
        case NAME:
            ten = va_arg(arg, string);
            for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
                if(item->getTenSV().compare(ten) == 0){
                    if(index == 0){
                        cout<<setw(6)<<left<<"STT"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"ID"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Ten"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Tuoi"<<setw(3)<<left<<"|"
                            <<setw(10)<<left<<"Gioi Tinh"<<setw(6)<<left<<"|"
                            <<setw(9)<<left<<"Diem TB"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Xep loai"<<endl;   
                    }
                    index++;        
                    cout<<setw(6)<<left<<index<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getMSSV()<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getTenSV()<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getTuoi()<<setw(6)<<left<<"|"
                        <<setw(7)<<left<<((item->getGioiTinh() == NU) ? "Nu" : "Nam")<<setw(6)<<left<<"|"
                        <<setw(9)<<left<<item->getDiemTrungBinh()<<setw(6)<<left<<"|";
                    switch(item->getHocLuc()){
                        case GIOI:
                            cout<<setw(6)<<left<<"Gioi"<<endl;
                            break;
                        case KHA:
                            cout<<setw(6)<<left<<"Kha"<<endl;
                            break;
                        case TRUNG_BINH:
                            cout<<setw(6)<<left<<"Trung Binh"<<endl;
                            break;
                        case YEU:
                            cout<<setw(6)<<left<<"Yeu"<<endl;
                            break;
                    }
                }
            }
            break;
        case ID:
            id = va_arg(arg, int);
            for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
                if(item->getMSSV() == id){       
                    if(index == 0){
                        cout<<setw(6)<<left<<"STT"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"ID"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Ten"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Tuoi"<<setw(3)<<left<<"|"
                            <<setw(10)<<left<<"Gioi Tinh"<<setw(6)<<left<<"|"
                            <<setw(9)<<left<<"Diem TB"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Xep loai"<<endl;   
                    }
                    index++;        
                    cout<<setw(6)<<left<<index<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getMSSV()<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getTenSV()<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getTuoi()<<setw(6)<<left<<"|"
                        <<setw(7)<<left<<((item->getGioiTinh() == NU) ? "Nu" : "Nam")<<setw(6)<<left<<"|"
                        <<setw(9)<<left<<item->getDiemTrungBinh()<<setw(6)<<left<<"|";
                    switch(item->getHocLuc()){
                        case GIOI:
                            cout<<setw(6)<<left<<"Gioi"<<endl;
                            break;
                        case KHA:
                            cout<<setw(6)<<left<<"Kha"<<endl;
                            break;
                        case TRUNG_BINH:
                            cout<<setw(6)<<left<<"Trung Binh"<<endl;
                            break;
                        case YEU:
                            cout<<setw(6)<<left<<"Yeu"<<endl;
                            break;
                    }
                }
            }
            break;
    }
}

void searchStudent(list<SinhVien> &dataBase){
    int key, id;
    string ten;
    cout<<"------ Tim kiem Sinh Vien ------"<<endl;
    while(1){
        SUB_MENU("Tim kiem theo ten","Tim kiem theo ID", "Quay lai");
        cout<<"Vui long chon: ";
        cin>>key;
        switch((SearchType)key){
            case NAME:
                cout<<"------ Tim theo ten ------\r\n"
                    <<"Vui long nhap ten: ";
                cin>>ten;
                cout<<"----------------------------"<<endl;
                displaySearchStudent(dataBase, NAME, ten);
                cout<<"----------------------------"<<endl;
                break;
            case ID:
                cout<<"------ Tim theo ID ------\r\n"
                    <<"Vui long nhap ID: ";
                cin>>id;
                cout<<"----------------------------"<<endl;
                displaySearchStudent(dataBase, ID, id);
                cout<<"----------------------------"<<endl;
                break;
            case 0:
                return;
            default:
                cout<<"Khong hop le"<<endl;
                break;
        }
        cout<<"1. Tim sinh vien khac\r\n"
            <<"0. Quay lai\r\n"
            <<"Vui long chon: ";
        cin>>key;
        if(key == 0)
            return;
    }
}

bool soSanhTen(list<SinhVien>::iterator item1, list<SinhVien>::iterator item2){
    int index = 0;
    while(item1->getTenSV()[index] != '\0' && item2->getTenSV()[index]!='\0' && item1->getTenSV()[index] == item2->getTenSV()[index]){
        index++;
    }
    if(((int)item1->getTenSV()[index] - (int)item2->getTenSV()[index]) > 0) 
        return true;
    else 
        return false;
}

bool soSanhDiemToan(list<SinhVien>::iterator item1, list<SinhVien>::iterator item2){
    if((item1->getDiemToan() - item2->getDiemToan()) > 0)
        return true;
    else
        return false;
}

bool soSanhDiemLy(list<SinhVien>::iterator item1, list<SinhVien>::iterator item2){
    if((item1->getDiemLy() - item2->getDiemLy()) > 0)
        return true;
    else
        return false;
}

bool soSanhDiemHoa(list<SinhVien>::iterator item1, list<SinhVien>::iterator item2){
    if((item1->getDiemHoa() - item2->getDiemHoa()) > 0)
        return true;
    else
        return false;
}

bool soSanhDiemTB(list<SinhVien>::iterator item1, list<SinhVien>::iterator item2){
    if((item1->getDiemTrungBinh() - item2->getDiemTrungBinh()) > 0)
        return true;
    else
        return false;
}

void sort(list<SinhVien> &dataBase, bool (*sortFuntion)(list<SinhVien>::iterator item1, list<SinhVien>::iterator item2)){
    for(list<SinhVien>::iterator i = dataBase.begin(); i != dataBase.end(); i++){
        for(list<SinhVien>::iterator j = dataBase.begin(); j != dataBase.end(); j++){
            if(sortFuntion(j,i)){   
                SinhVien temp = *i;
                *i = *j;
                *j = temp; 
            }
        }
    }
}

void displayListStudent(list<SinhVien> &dataBase){
    int key;
    cout<<"------ Danh sach Sinh Vien ------"<<endl;
    cout<<"-------------------------------------------"<<endl;
    int index = 0;
    for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){      
        if(index == 0){
            cout<<setw(6)<<left<<"STT"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"ID"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Ten"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Tuoi"<<setw(3)<<left<<"|"
                <<setw(10)<<left<<"Gioi Tinh"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Toan"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Ly"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Hoa"<<setw(6)<<left<<"|"
                <<setw(9)<<left<<"Diem TB"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Xep loai"<<endl;   
        }
        index++;        
        cout<<setw(6)<<left<<index<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getMSSV()<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getTenSV()<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getTuoi()<<setw(6)<<left<<"|"
            <<setw(7)<<left<<((item->getGioiTinh() == NU) ? "Nu" : "Nam")<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getDiemToan()<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getDiemLy()<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getDiemHoa()<<setw(6)<<left<<"|"
            <<setw(9)<<left<<item->getDiemTrungBinh()<<setw(6)<<left<<"|";
        switch(item->getHocLuc()){
            case GIOI:
                cout<<setw(6)<<left<<"Gioi"<<endl;
                break;
            case KHA:
                cout<<setw(6)<<left<<"Kha"<<endl;
                break;
            case TRUNG_BINH:
                cout<<setw(6)<<left<<"Trung Binh"<<endl;
                break;
            case YEU:
                cout<<setw(6)<<left<<"Yeu"<<endl;
                break;
        }
    }
    cout<<"-------------------------------------------"<<endl;
    do{
        cout<<"0. Quay lai\r\n"
            <<"Vui long chon: ";
        cin>>key;
    }while(key != 0);
}

void sortStudent(list<SinhVien> &dataBase){
    int key;
    cout<<"------ Sap xep Sinh Vien ------"<<endl;
    while(1){
        SUB_MENU("Sap xep theo ten","Sap xep theo diem toan", "Sap xep theo diem ly", "Sap xep theo diem hoa", "Sap xep theo diem trung binh", "Quay lai");
        cout<<"Vui long chon: ";
        cin>>key;
        switch((SortType)key){
            case TEN:
                sort(dataBase, soSanhTen);
                break;
            case DIEM_TOAN:
                sort(dataBase, soSanhDiemToan);
                break;
            case DIEM_LY:
                sort(dataBase, soSanhDiemLy);
                break;
            case DIEM_HOA:
                sort(dataBase, soSanhDiemHoa);
                break;
            case DIEM_TB:
                sort(dataBase, soSanhDiemTB);
                break;
            case 0:
                return;
        }
        cout<<"Sap xep thanh cong"<<endl;
        cout<<"-------------------------------------------"<<endl;
        int index = 0;
        for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){      
            if(index == 0){
                cout<<setw(6)<<left<<"STT"<<setw(6)<<left<<"|"
                    <<setw(6)<<left<<"ID"<<setw(6)<<left<<"|"
                    <<setw(6)<<left<<"Ten"<<setw(6)<<left<<"|"
                    <<setw(6)<<left<<"Tuoi"<<setw(3)<<left<<"|"
                    <<setw(10)<<left<<"Gioi Tinh"<<setw(6)<<left<<"|"
                    <<setw(9)<<left<<"Diem TB"<<setw(6)<<left<<"|"
                    <<setw(6)<<left<<"Xep loai"<<endl;   
            }
            index++;        
            cout<<setw(6)<<left<<index<<setw(6)<<left<<"|"
                <<setw(6)<<left<<item->getMSSV()<<setw(6)<<left<<"|"
                <<setw(6)<<left<<item->getTenSV()<<setw(6)<<left<<"|"
                <<setw(6)<<left<<item->getTuoi()<<setw(6)<<left<<"|"
                <<setw(7)<<left<<((item->getGioiTinh() == NU) ? "Nu" : "Nam")<<setw(6)<<left<<"|"
                <<setw(9)<<left<<item->getDiemTrungBinh()<<setw(6)<<left<<"|";
            switch(item->getHocLuc()){
                case GIOI:
                    cout<<setw(6)<<left<<"Gioi"<<endl;
                    break;
                case KHA:
                    cout<<setw(6)<<left<<"Kha"<<endl;
                    break;
                case TRUNG_BINH:
                    cout<<setw(6)<<left<<"Trung Binh"<<endl;
                    break;
                case YEU:
                    cout<<setw(6)<<left<<"Yeu"<<endl;
                    break;
            }
        }
        cout<<"-------------------------------------------"<<endl;
        cout<<"1. Sap xep kieu khac\r\n"
            <<"0. Quay lai\r\n"
            <<"Vui long chon: ";
        cin>>key;
        if(key == 0)
            return;
    }
}

void saveListStudent(list<SinhVien> &dataBase){
    FILE *filePtr = fopen("database.csv", "w");
    fprintf(filePtr, "ID,Ten,GioiTinh,Toan,Ly,Hoa,DiemTB,XepLoai\n");
    for(auto item : dataBase){
        fprintf(filePtr, "%d,%s,%s,%0.1f,%0.1f,%0.1f,%0.1f\n", item.getMSSV(), item.getTenSV().c_str(), (item.getGioiTinh() == NU) ? "Nu" : "Nam", item.getDiemToan(), item.getDiemLy(), item.getDiemHoa(), item.getDiemTrungBinh());
    }
    fclose(filePtr);
}