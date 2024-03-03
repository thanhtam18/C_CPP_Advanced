#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
.push_back(value);               them phan tu vao cuoi list
.pop_back();                     xoa phan tu o cuoi list
.assign(.size, value)            thay doi gia tri tat ca cac phan tu             
.insert(.begin(), value);        them phan tu vao vi tri bat ki
.erase(.begin());                xoa phan tu o vi tri bat ki
.clear();                        xoa list, thu hoi bo nho cap phat dong.
*/

string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (string s : strs)
            while (s.find(prefix) != 0)
                prefix = prefix.substr(0, prefix.length() - 1);
        return prefix;
    }
    
int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    for(int i = 1; i < size; i++){
        if(nums[i] == nums[i-1]){
            nums.erase(nums.begin()+i);
            size = nums.size();
            i--;
        }
    }
    return size;
}
int main(int argc, char const *argv[])
{
    // vector<string> str = {"flower","flow","flight"};
    // cout<<longestCommonPrefix(str);
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(nums);
    return 0;
}
