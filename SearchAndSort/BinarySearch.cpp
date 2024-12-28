#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int binarySearch(vector<int> data, int key){
   
    int left = 0;
    int right = data.size()-1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(data[mid] == key){
            cout << "Found " << key << " at index " << mid << endl; 
            return mid;
        }else if(key < data[mid]){
            right = mid -1;
        }else{
            left = mid + 1;
        }
    }
    cout << "Can not Found " << key << endl; 
    return -1;
}

int main(){
    int x[] = {1,2,3, 4, 5, 7, 8 ,10,23,29,32 };
    int n = 11;
    vector<int> data;
    for(int i = 0; i <n; i++) data.push_back(x[i]);
    int index = binarySearch(data,29);
    index  = binarySearch(data,40);
    return 0;
}
