#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <vector>

using namespace std;
mutex key;
bool gCheck = false;
vector<int> gProducts;
condition_variable gCond_Var;

void producer(){
    lock_guard<mutex> lock(key);
    for(int i = 0; i < 10; i++){
        gProducts.push_back(i);
    }
    for(int item : gProducts){
        cout<<"producer: "<<item<<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    gCheck = true;
    gCond_Var.notify_one();
}
void consumer(){
    unique_lock<mutex> lock(key);
    gCond_Var.wait(lock, []{return gCheck;});
    if(gCheck)
        for(int item : gProducts)
            cout<<"consumer: "<<item<<endl;
    lock.unlock();
}
int main() 
{
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}