#include <iostream>
#include <thread>
#include <chrono> //thư viện tạo delay

using namespace std;

void Task1(){
    int index = 0;
    for(;;){
        cout<<index++<<endl;
        this_thread::sleep_for(chrono::seconds(1));  // delay 1s
    }
}

void Task2(){
    for(;;){
        cout<<"Hello"<<endl;
        this_thread::sleep_for(chrono::seconds(3)); // delay 3s
    }
}

int main(int argc, char const *argv[])
{
    thread t1(Task1);
    thread t2(Task2);
    t1.join();
    t2.join();
    return 0;
}
