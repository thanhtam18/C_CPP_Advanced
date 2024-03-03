#include <iostream>
#include <memory>
using namespace std;
//giống cấp phát động nhưng tự động hủy bộ nhớ sau khi kết thúc hàm mà không cần phải delete[]
void display(){
    unique_ptr<int> var(new int(18));
    cout<<"var: "<<*var<<endl;
    unique_ptr<int[]> arr(new int[5]);
    for(int i = 0; i < 5; i++)
        arr[i] = i*2;
    for(int i = 0; i < 5; i++){
        arr[i] = i*2;
        cout<<"arr["<<i<<"]: "<<arr[i]<<endl;
    }
}
//2 con trỏ cùng trỏ vào 1 vùng nhớ cấp phát động và cũng tự thu hồi sau khi kết thúc hàm;
void test(){
    shared_ptr<int> sprt1(new int(10));
    shared_ptr<int> sptr2 = sprt1;
    cout<<*sprt1<<endl;
    cout<<*sptr2<<endl;
}

int main(int argc, char const *argv[])
{
    //cấp phát động bình thường
    int *ptr = new int;
    *ptr = 18;
    delete[]ptr;
    int *arr = new int[5];
    delete[]arr; 
    display();
    test();
    return 0;
}
