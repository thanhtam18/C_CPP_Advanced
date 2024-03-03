#include <iostream>
#include <list>

using namespace std;




int main(int argc, char const *argv[])
{
    list<int> arr = {1,2,3,4,5};
    arr.push_back(7);
    for(list<int>::iterator it = arr.begin(); it != arr.end(); it++){
        if(*it == 2)
            arr.insert(it,44);
    }
    for(list<int>::iterator it = arr.begin(); it != arr.end(); it++){
        cout<<" "<<*it;
    }
    for(auto item : arr){
        cout<<" "<<item;
    }
    return 0;
}
