#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
mutex carMutex;

/*
lock_guard: sẽ lock mutex ngay sau khi khởi tạo và sẽ tự động unlock ngay khi kết thúc task. Người dùng không thể tự unlock
unique_clock: sẽ lock mutex ngay sau khi khởi tạo và người dùng có thể tự unlock bằng hàm unlock()
*/
void driveCar(string name){
    //unique_lock<mutex> carLock(carMutex);
    lock_guard<mutex> carLock(carMutex);
    cout<<name<<" is driving"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<name<<" is done driving"<<endl;
    //carLock.unlock();
}

int main() 
{
    thread t1(driveCar,"Tam");
    thread t2(driveCar,"Long");
    t1.join();
    t2.join();
    return 0;
}