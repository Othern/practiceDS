#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void quickSort(vector<int>& data, int start, int end){
    if(start >= end) return;
    int left = start+1;
    int right = end;
    int pivot = start;
    
    while(left <= right){
        while(left <= right && data[left] < data[pivot]) left++;
        while(left <= right && data[right] > data[pivot]) right--;
        if(left < right) swap(data[left],data[right]);
    }
    swap(data[right],data[pivot]);
    quickSort(data, start, right - 1);
    quickSort(data, right + 1, end);
    return ;

}
int quickSelect(vector<int> data, int start, int end, int k){
    if (start > end) return -1; // invalid range
    int left = start+1;
    int right = end;
    int pivot = start;
    
    while(left <= right){
        while(left <= right && data[left] < data[pivot]) left++;
        while(left <= right && data[right] > data[pivot]) right--;
        if(left < right) swap(data[left],data[right]);
    }
    swap(data[right],data[pivot]);
    if(k == right + 1) return data[right];
    else if(k < right + 1) return quickSelect(data, start, right - 1, k);
    else return quickSelect(data, right + 1, end, k);   
}
int main(){
    int x[] = {1,2,3,8, 4, 5, 7 };
    int n = 7;
    vector<int> data;
    for(int i = 0; i <n; i++) data.push_back(x[i]);
    quickSort(data,0, data.size()-1);
    for(int i = 0; i <n; i++) cout << data[i] << " ";
    cout << endl << quickSelect(data,0, data.size()-1, 5);
    return 0;
}