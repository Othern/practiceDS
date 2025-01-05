#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// [Hoarz] 版本
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
// [Algorithm] 版本
int partition(vector<int>& data, int start, int end) {
    int pivot = end;           // Choose the pivot as the last element
    int right = end - 1;       // Right boundary of the array excluding pivot
    int i = start - 1;         // Index for the last smaller element

    for (int j = start; j <= right; j++) { // Iterate through the array
        if (data[j] <= data[pivot]) {      // If element <= pivot
            i++;                           // Increment position for smaller element
            swap(data[i], data[j]);        // Swap to place it in the correct section
        }
    }
    swap(data[i + 1], data[pivot]);        // Place the pivot in its correct position
    return i + 1;                          // Return the pivot's position
}

void quickSort2(vector<int>& data, int start, int end){
    if(start >= end) return;
    int m = partition(data, start,end);
    quickSort2(data,start, m - 1);
    quickSort2(data,m + 1, end);
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
    int x[] = {1,2,3,81, 43, 15, 72,91,0,4,8 };
    int n = 11;
    vector<int> data;
    for(int i = 0; i <n; i++) data.push_back(x[i]);
    quickSort(data,0, data.size()-1);
    cout << "Result : ";
    for(int i = 0; i <n; i++) cout << data[i] << " ";
    cout << endl << quickSelect(data,0, data.size()-1, 5);
    return 0;
}