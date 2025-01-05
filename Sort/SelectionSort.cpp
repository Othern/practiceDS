#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void SelectionSort(vector<int>& data){
    for(int i = 0; i < data.size(); i++){
        int minInd = i;
        for(int j = i; j < data.size(); j++){
            if(data[minInd] > data[j]){
                minInd = j;
            }
        }
        swap(data[i], data[minInd]);
    }
    return;
}
void PrintList(vector<int> data){
    for(int i=0; i< data.size(); i++) cout << data[i] << " ";
    cout << endl;
}
int main(){
    int x[] = {1, 2, 23, 4, 3, 29, 5, 8 , 10, 7, 32};
    int n = 11;
    vector<int> data; 
    for(int i=0; i< n; i++) data.push_back(x[i]);
    PrintList(data);
    SelectionSort(data);
    PrintList(data);
    return 0;
}