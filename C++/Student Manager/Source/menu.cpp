#include <menu.hpp>

/*
Description: This function allows the user to input information for a new student and adds them to the database.
Input: 
    dataBase: The list representing the database of students.
Ouput: None
*/
void addStudent(list<Student> &dataBase){
    while(1){
        int key;
        string nameOfStudent;
        int ageOfStudent, gender;
        Gender genderOfStudent;
        float mathsScore, physicsScore, chemistryScore;
        cout<<"------ Add Student ------"<<endl;
        cout<<"Enter name of Student: ";
        cin>>nameOfStudent;
        do{
        cout<<"Enter age of Student: ";
        cin>>ageOfStudent;
        }while(ageOfStudent < 0 || ageOfStudent > 100);
        do{
        cout<<"Enter gender of Student:  0.Male   1.Female     Your chose: ";
        cin>>gender;
        }while(gender != 0 && gender != 1);
        genderOfStudent = (Gender)gender;
        do{
        cout<<"Enter Maths Score: ";
        cin>>mathsScore;
        }while(mathsScore < 0 || mathsScore > 10);
        do{
        cout<<"Enter Physics Score: ";
        cin>>physicsScore;
        }while(physicsScore < 0 || physicsScore > 10);
        do{
        cout<<"Enter Chemistry Score: ";
        cin>>chemistryScore;      
        }while(chemistryScore < 0 || chemistryScore > 10);
        Student student(nameOfStudent, ageOfStudent, genderOfStudent, mathsScore, physicsScore, chemistryScore);
        dataBase.push_back(student);
        cout<<"-------------------------------"<<endl;
        cout<<"Student Code: "<<student.getStudentCode()<<endl
            <<"Name: "<<student.getName()<<endl
            <<"Age: "<<student.getAge()<<endl
            <<"Gender: "<<((student.getGender() == FEMALE) ? "Female" : "Male")<<endl
            <<"Maths: "<<student.getMathsScore()<<" Physics: "<<student.getPhysicsScore()<<" Chemistry: "<<student.getChemistryScore()<<endl
            <<"Average: "<<student.getAverageScore()<<endl
            <<"Academic performance: ";
            switch(student.getAcademicPerformance()){
                case DISTINCTION:
                    cout<<"Distinction"<<endl;
                    break;
                case CREDIT:
                    cout<<"Credit"<<endl;
                    break;
                case AVERAGE:
                    cout<<"Average"<<endl;
                    break;
                case POOR:
                    cout<<"Poor"<<endl;
                    break;
            }
        cout<<"-------------------------------"<<endl;
        do{
            cout<<"1. Add more student\r\n"
                <<"0. Return\r\n"
                <<"Your chose: ";
            cin>>key;
            switch(key){
                case 0:
                    return;
                case 1:
                    break;
                default:
                    cout<<"Invalid option"<<endl;
                    break;
            }
        }while(key != 0 && key != 1);
    }
} 

/*
Description: This function allows the user to select a student from the database and modify their information.
Input: 
    dataBase: The list representing the database of students.
Ouput: None
*/
void editStudent(list<Student> &dataBase){
    cout<<"------ Edit Student ------"<<endl;
    string name, newName;
    int studentCode, age, gender;
    float mathsScore, physicsScore, chemistryScore;
    int index = 0;
    cout<<"Enter name of Student: ";
    cin>>name;
    cout<<"-------------------------------"<<endl;
    for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
        if(item->getName().compare(name) == 0){
            if(index == 0){
                cout<<setw(8)<<left<<"Ordinal Number"<<setw(2)<<left<<"|";
                cout<<setw(8)<<left<<"Student Code"<<setw(2)<<left<<"|";
                cout<<setw(8)<<left<<"Name"<<endl;
            }
            index++;        
            cout<<setw(14)<<left<<index<<setw(2)<<left<<"|"
                <<setw(12)<<left<<item->getStudentCode()<<setw(2)<<left<<"|"
                <<setw(10)<<left<<item->getName()<<endl;
        }
    }
    cout<<"-------------------------------"<<endl;
    cout<<"Enter Student Code of Student want to edit: ";
    cin>>studentCode;
    for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
        if(item->getStudentCode() == studentCode){
            cout<<"-------------------------------"<<endl;
            cout<<"Student Code: "<<item->getStudentCode()<<endl
                <<"Name: "<<item->getName()<<endl
                <<"Age: "<<item->getAge()<<endl
                <<"Gender: "<<((item->getGender() == FEMALE) ? "Female" : "Male")<<endl
                <<"Maths: "<<item->getMathsScore()<<" Physics: "<<item->getPhysicsScore()<<" Chemistry: "<<item->getChemistryScore()<<endl
                <<"Average: "<<item->getAverageScore()<<endl
                <<"Academic performance: ";
                switch(item->getAcademicPerformance()){
                    case DISTINCTION:
                        cout<<"Distinction"<<endl;
                        break;
                    case CREDIT:
                        cout<<"Credit"<<endl;
                        break;
                    case AVERAGE:
                        cout<<"Average"<<endl;
                        break;
                    case POOR:
                        cout<<"Poor"<<endl;
                        break;
                }
            cout<<"-------------------------------"<<endl; 
            int key;
            while(1){
                SUB_MENU("Edit Name", "Edit Age", "Edit Gender", "Edit Maths Score", "Edit Physics Score", "Edit Chemistry Score", "Return");
                cout<<"Your chose: ";
                cin>>key;
                switch(key){
                    case 1:
                        cout<<"--- Edit Name ---\r\n"
                            <<"Enter name: ";
                        cin>>newName;
                        item->setName(newName);
                        break;
                    case 2:
                        cout<<"--- Edit Age ---\r\n"
                            <<"Enter age: ";
                        cin>>age;
                        item->setAge(age);
                        break;
                    case 3:
                        cout<<"--- Edit Gender ---"<<endl;
                        do{
                            cout<<"Chose gender:  0.Male   1.Female    Your chose: ";
                            cin>>gender;
                        }while(gender != 0 && gender != 1);
                        item->setGender((Gender)gender);
                        break;
                    case 4:
                        cout<<"--- Edit Maths Score ---"<<endl;
                        do{
                            cout<<"Enter score: ";
                            cin>>mathsScore;
                        }while(mathsScore < 0 || mathsScore > 10);
                        break;
                    case 5:
                        cout<<"--- Edit Physics Scrore ---"<<endl;
                        do{
                            cout<<"Enter score: ";
                            cin>>physicsScore;
                        }while(physicsScore < 0 || physicsScore > 10);
                        break;
                    case 6:
                        cout<<"--- Edit Chemistry Score ---"<<endl;
                        do{
                            cout<<"Enter score: ";
                            cin>>chemistryScore;
                        }while(chemistryScore < 0 || chemistryScore > 10);
                        break;
                    case 0:
                        return;
                    default:
                        cout<<"Invalid option"<<endl;
                        break;
                }
                if(key >= 1 && key <= 6){
                    cout<<"----------------------------\r\n"
                        <<"1. Return\r\n"
                        <<"0. Exit\r\n"
                        <<"Your chose: ";
                    cin>>key;
                    if(key == 0)
                        return;
                    cout<<"----------------------------"<<endl;
                }
            }
        }
    }
}

/*
Description: This function allows the user to select a student from the database and remove them.
Input: 
    dataBase: The list representing the database of students.
Ouput: None
*/
void removeStudent(list<Student> &dataBase){
    while(1){
        int index = 0;
        int studentCode;
        string name;
        bool isRemoved = false;
        int key;
        cout<<"------ Remove Student ------"<<endl;
        cout<<"Enter name of Student: ";
        cin>>name;
        cout<<"-------------------------------"<<endl;
        for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
            if(item->getName().compare(name) == 0){       
                if(index == 0){
                    cout<<setw(8)<<left<<"Ordinal Number"<<setw(2)<<left<<"|";
                    cout<<setw(8)<<left<<"Student Code"<<setw(2)<<left<<"|";
                    cout<<setw(8)<<left<<"Name"<<endl;
                }
                index++;        
                cout<<setw(14)<<left<<index<<setw(2)<<left<<"|"
                    <<setw(12)<<left<<item->getStudentCode()<<setw(2)<<left<<"|"
                    <<setw(10)<<left<<item->getName()<<endl;
            }
        }
        cout<<"-------------------------------"<<endl;
        cout<<"Enter ID of student want to remove: ";
        cin>>studentCode;
        for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
            if(item->getStudentCode() == studentCode){
                dataBase.erase(item);
                isRemoved = true;
                cout<<"Successful"<<endl;
                cout<<"----------------------------"<<endl;
                break;
            }
        }
        if(!isRemoved){
            cout<<"ID does not exist"<<endl;
            cout<<"----------------------------"<<endl;
        }
        cout<<"1. Remove more student\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>key;
        if(key == 0)
            return;
    }
}


/*
Description: This function displays students from the database based on the specified search criteria such as name or student code
Input: 
    dataBase: The list representing the database of students.
    type: The search type (SearchType enum).
    ...: Additional parameters based on the search type
Ouput: None
*/
void displaySearchStudent(list<Student> &dataBase, SearchType type, ...){
    va_list arg;
    va_start(arg, type);
    int index = 0;
    string name;
    int studentCode;
    switch(type){
        case STUDENT_NAME:
            name = va_arg(arg, string);
            for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
                if(item->getName().compare(name) == 0){
                    if(index == 0){
                        cout<<setw(6)<<left<<"Ordinal Number"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Student Code"<<setw(6)<<left<<"|"
                            <<setw(10)<<left<<"Name"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Age"<<setw(3)<<left<<"|"
                            <<setw(10)<<left<<"Gender"<<setw(6)<<left<<"|"
                            <<setw(9)<<left<<"Average Score"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Academic performance"<<endl;   
                    }
                    index++;        
                    cout<<setw(14)<<left<<index<<setw(6)<<left<<"|"
                        <<setw(12)<<left<<item->getStudentCode()<<setw(6)<<left<<"|"
                        <<setw(10)<<left<<item->getName()<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getAge()<<setw(6)<<left<<"|"
                        <<setw(7)<<left<<((item->getGender() == FEMALE) ? "Female" : "Male")<<setw(6)<<left<<"|"
                        <<setw(13)<<left<<item->getAverageScore()<<setw(6)<<left<<"|";
                    switch(item->getAcademicPerformance()){
                        case DISTINCTION:
                            cout<<setw(6)<<left<<"Distinction"<<endl;
                            break;
                        case CREDIT:
                            cout<<setw(6)<<left<<"Credit"<<endl;
                            break;
                        case AVERAGE:
                            cout<<setw(6)<<left<<"Average"<<endl;
                            break;
                        case POOR:
                            cout<<setw(6)<<left<<"Poor"<<endl;
                            break;
                    }
                }
            }
            break;
        case STUDENT_CODE:
            studentCode = va_arg(arg, int);
            for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
                if(item->getStudentCode() == studentCode){       
                    if(index == 0){
                        cout<<setw(6)<<left<<"Ordinal Number"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Student Code"<<setw(6)<<left<<"|"
                            <<setw(10)<<left<<"Name"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Age"<<setw(3)<<left<<"|"
                            <<setw(10)<<left<<"Gender"<<setw(6)<<left<<"|"
                            <<setw(9)<<left<<"Average Score"<<setw(6)<<left<<"|"
                            <<setw(6)<<left<<"Academic performance"<<endl;   
                    }
                    index++;        
                    cout<<setw(14)<<left<<index<<setw(6)<<left<<"|"
                        <<setw(12)<<left<<item->getStudentCode()<<setw(6)<<left<<"|"
                        <<setw(10)<<left<<item->getName()<<setw(6)<<left<<"|"
                        <<setw(6)<<left<<item->getAge()<<setw(6)<<left<<"|"
                        <<setw(7)<<left<<((item->getGender() == FEMALE) ? "Female" : "Male")<<setw(6)<<left<<"|"
                        <<setw(13)<<left<<item->getAverageScore()<<setw(6)<<left<<"|";
                    switch(item->getAcademicPerformance()){
                        case DISTINCTION:
                            cout<<setw(6)<<left<<"Distinction"<<endl;
                            break;
                        case CREDIT:
                            cout<<setw(6)<<left<<"Credit"<<endl;
                            break;
                        case AVERAGE:
                            cout<<setw(6)<<left<<"Average"<<endl;
                            break;
                        case POOR:
                            cout<<setw(6)<<left<<"Poor"<<endl;
                            break;
                    }
                }
            }
            break;
    }
}

/*
Description: This function allows the user to search for a student based on criteria such as name or student code.
Input: 
    dataBase: The list representing the database of students.
Ouput: None
*/
void searchStudent(list<Student> &dataBase){
    int key, studentCode;
    string name;
    cout<<"------ Search Student ------"<<endl;
    while(1){
        SUB_MENU("Search Name","Search Student Code", "Return");
        cout<<"Your chose: ";
        cin>>key;
        switch((SearchType)key){
            case STUDENT_NAME:
                cout<<"------ Search Name ------\r\n"
                    <<"Enter Name: ";
                cin>>name;
                cout<<"----------------------------"<<endl;
                displaySearchStudent(dataBase, STUDENT_NAME, name);
                cout<<"----------------------------"<<endl;
                break;
            case STUDENT_CODE:
                cout<<"------ Search Student Code ------\r\n"
                    <<"Enter Student Code: ";
                cin>>studentCode;
                cout<<"----------------------------"<<endl;
                displaySearchStudent(dataBase, STUDENT_CODE, studentCode);
                cout<<"----------------------------"<<endl;
                break;
            case 0:
                return;
            default:
                cout<<"Invalid option"<<endl;
                break;
        }
        cout<<"1. Search other student\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>key;
        if(key == 0)
            return;
    }
}

/*
Description: This function compares two students based on their names.
Input:
    item1: Iterator pointing to the first student.
    item2: Iterator pointing to the second student.
Output: True if the name of the first student is less than the name of the second student; otherwise, false.
*/
bool compareName(list<Student>::iterator item1, list<Student>::iterator item2){
    int index = 0;
    while(item1->getName()[index] != '\0' && item2->getName()[index]!='\0' && item1->getName()[index] == item2->getName()[index]){
        index++;
    }
    if(((int)item1->getName()[index] - (int)item2->getName()[index]) > 0) 
        return true;
    else 
        return false;
}

/*
Description: This function compares two students based on their mathematics scores.
Input:
    item1: Iterator pointing to the first student.
    item2: Iterator pointing to the second student.
Output: True if the mathematics score of the first student is greater than the mathematics score of the second student; otherwise, false.
*/
bool comapreMathScore(list<Student>::iterator item1, list<Student>::iterator item2){
    if((item1->getMathsScore() - item2->getMathsScore()) > 0)
        return true;
    else
        return false;
}

/*
Description: This function compares two students based on their physics scores.
Input:
    item1: Iterator pointing to the first student.
    item2: Iterator pointing to the second student.
Output: True if the physics score of the first student is greater than the physics score of the second student; otherwise, false.
*/
bool comparePhysicScore(list<Student>::iterator item1, list<Student>::iterator item2){
    if((item1->getPhysicsScore() - item2->getPhysicsScore()) > 0)
        return true;
    else
        return false;
}

/*
Description: This function compares two students based on their chemistry scores.
Input:
    item1: Iterator pointing to the first student.
    item2: Iterator pointing to the second student.
Output: True if the chemistry score of the first student is greater than the chemistry score of the second student; otherwise, false.
*/
bool compareChemistryScore(list<Student>::iterator item1, list<Student>::iterator item2){
    if((item1->getChemistryScore() - item2->getChemistryScore()) > 0)
        return true;
    else
        return false;
}

/*
Description: This function compares two students based on their average scores.
Input:
    item1: Iterator pointing to the first student.
    item2: Iterator pointing to the second student.
Output: True if the average score of the first student is greater than the average score of the second student; otherwise, false.
*/
bool compareAverageScore(list<Student>::iterator item1, list<Student>::iterator item2){
    if((item1->getAverageScore() - item2->getAverageScore()) > 0)
        return true;
    else
        return false;
}

/*
Description: This function sorts the list of students in the database using the specified custom comparison function.
Input:
    dataBase: The list representing the database of students.
    sortFunction: The custom comparison function for sorting students.
Output: None
*/
void sort(list<Student> &dataBase, bool (*sortFuntion)(list<Student>::iterator item1, list<Student>::iterator item2)){
    for(list<Student>::iterator i = dataBase.begin(); i != dataBase.end(); i++){
        for(list<Student>::iterator j = dataBase.begin(); j != dataBase.end(); j++){
            if(sortFuntion(j,i)){   
                Student temp = *i;
                *i = *j;
                *j = temp; 
            }
        }
    }
}

/*
Description: This function prints the information of all students in the database.
Input: 
    dataBase: The list representing the database of students.
Ouput: None
*/
void displayListStudent(list<Student> &dataBase){
    int key;
    cout<<"------ List Student ------"<<endl;
    cout<<"-------------------------------------------"<<endl;
    int index = 0;
    for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){      
        if(index == 0){
            cout<<setw(6)<<left<<"Ordinal Number"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Student Code"<<setw(6)<<left<<"|"
                <<setw(10)<<left<<"Name"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Age"<<setw(3)<<left<<"|"
                <<setw(10)<<left<<"Gender"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Maths"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Physics"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Chemistry"<<setw(6)<<left<<"|"
                <<setw(9)<<left<<"Average Score"<<setw(6)<<left<<"|"
                <<setw(6)<<left<<"Academic performance"<<endl;   
        }
        index++;        
        cout<<setw(14)<<left<<index<<setw(6)<<left<<"|"
            <<setw(12)<<left<<item->getStudentCode()<<setw(6)<<left<<"|"
            <<setw(10)<<left<<item->getName()<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getAge()<<setw(6)<<left<<"|"
            <<setw(7)<<left<<((item->getGender() == FEMALE) ? "Female" : "Male")<<setw(6)<<left<<"|"
            <<setw(6)<<left<<item->getMathsScore()<<setw(6)<<left<<"|"
            <<setw(7)<<left<<item->getPhysicsScore()<<setw(6)<<left<<"|"
            <<setw(9)<<left<<item->getChemistryScore()<<setw(6)<<left<<"|"
            <<setw(13)<<left<<item->getAverageScore()<<setw(6)<<left<<"|";
        switch(item->getAcademicPerformance()){
            case DISTINCTION:
                cout<<setw(6)<<left<<"Distinction"<<endl;
                break;
            case CREDIT:
                cout<<setw(6)<<left<<"Credit"<<endl;
                break;
            case AVERAGE:
                cout<<setw(6)<<left<<"Average"<<endl;
                break;
            case POOR:
                cout<<setw(6)<<left<<"Poor"<<endl;
                break;
        }
    }
    cout<<"-------------------------------------------"<<endl;
    do{
        cout<<"0. Return\r\n"
            <<"Your chose: ";
        cin>>key;
    }while(key != 0);
}

/*
Description: This function allows the user to choose a sorting criteria such as name, average score,... and sorts the list accordingly.
Input: 
    dataBase: The list representing the database of students.
Ouput: None
*/
void sortStudent(list<Student> &dataBase){
    int key;
    cout<<"------ Sort Student ------"<<endl;
    while(1){
        SUB_MENU("Sort Name","Sort Maths Score", "Sort Physics Score", "Sort Chemistry Score", "Sort Average Score", "Return");
        cout<<"Your chose: ";
        cin>>key;
        switch((SortType)key){
            case NAME:
                sort(dataBase, compareName);
                break;
            case MATHS_SCORE:
                sort(dataBase, comapreMathScore);
                break;
            case PHYSICS_SCORE:
                sort(dataBase, comparePhysicScore);
                break;
            case CHEMISTRY_SCORE:
                sort(dataBase, compareChemistryScore);
                break;
            case AVERAGE_SCORE:
                sort(dataBase, compareAverageScore);
                break;
            case 0:
                return;
        }
        cout<<"Successfull"<<endl;
        cout<<"-------------------------------------------"<<endl;
        int index = 0;
        for(list<Student>::iterator item = dataBase.begin(); item != dataBase.end(); item++){      
            if(index == 0){
                cout<<setw(6)<<left<<"Ordinal Number"<<setw(6)<<left<<"|"
                    <<setw(6)<<left<<"Student Code"<<setw(6)<<left<<"|"
                    <<setw(10)<<left<<"Name"<<setw(6)<<left<<"|"
                    <<setw(6)<<left<<"Age"<<setw(3)<<left<<"|"
                    <<setw(10)<<left<<"Gender"<<setw(6)<<left<<"|"
                    <<setw(9)<<left<<"Average Score"<<setw(6)<<left<<"|"
                    <<setw(6)<<left<<"Academic performance"<<endl;   
            }
            index++;        
            cout<<setw(14)<<left<<index<<setw(6)<<left<<"|"
                <<setw(12)<<left<<item->getStudentCode()<<setw(6)<<left<<"|"
                <<setw(10)<<left<<item->getName()<<setw(6)<<left<<"|"
                <<setw(6)<<left<<item->getAge()<<setw(6)<<left<<"|"
                <<setw(7)<<left<<((item->getGender() == FEMALE) ? "Female" : "Male")<<setw(6)<<left<<"|"
                <<setw(13)<<left<<item->getAverageScore()<<setw(6)<<left<<"|";
            switch(item->getAcademicPerformance()){
                case DISTINCTION:
                    cout<<setw(6)<<left<<"Distinction"<<endl;
                    break;
                case CREDIT:
                    cout<<setw(6)<<left<<"Credit"<<endl;
                    break;
                case AVERAGE:
                    cout<<setw(6)<<left<<"Average"<<endl;
                    break;
                case POOR:
                    cout<<setw(6)<<left<<"Poor"<<endl;
                    break;
            }
        }
        cout<<"-------------------------------------------"<<endl;
        cout<<"1. Sort other type\r\n"
            <<"0. Return\r\n"
            <<"Your chose: ";
        cin>>key;
        if(key == 0)
            return;
    }
}

/*
Description: This function saves the current state of the database to a file for future use.
Input: 
    dataBase: The list representing the database of students.
Ouput: None
*/
void saveListStudent(list<Student> &dataBase){
    FILE *filePtr = fopen("database.csv", "w");
    fprintf(filePtr, "StudentScore,Name,Gender,Maths,Physics,Chemistry,Average,AcademicPerformance\n");
    for(auto item : dataBase){
        fprintf(filePtr, "%d,%s,%s,%0.1f,%0.1f,%0.1f,%0.1f,", item.getStudentCode(), item.getName().c_str(), 
                                                            (item.getGender() == FEMALE) ? "Female" : "Male", item.getMathsScore(), 
                                                            item.getPhysicsScore(), item.getChemistryScore(), item.getAverageScore());
        switch(item.getAcademicPerformance()){
            case DISTINCTION:
                fprintf(filePtr,"Distinction\n");
                break;
            case CREDIT:
                fprintf(filePtr,"Credit\n");
                break;
            case AVERAGE:
                fprintf(filePtr,"Average\n");
                break;
            case POOR:
                fprintf(filePtr,"Poor\n");
                break;
        }
    }
    fclose(filePtr);
    cout<<"----------------------------------\r\n"
        <<"Successful\r\n"
        <<"----------------------------------\r\n";
}