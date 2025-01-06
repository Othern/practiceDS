#include <iostream>
#include <vector>
using namespace std;

vector<int> CountingSort(vector<int> data){
    // range 0 ~ 9
    vector<int> count;
    for(int i=0; i<=9; i++)count.push_back(0);
    for(int i=0; i< data.size(); i++)count[data[i]]++;

    // 由start 開始放，才會stable
    vector<int> start;
    for(int i=0; i<=9; i++)start.push_back(0);
    start[0] = 0;
    for(int i=1; i<=9; i++){
        start[i] = count[i-1] + start[i-1];
    }
    vector<int> result;
    for(int i=0; i< data.size(); i++)result.push_back(0);

    for(int i=0; i< data.size(); i++){
        result[start[data[i]]] = data[i];
        start[data[i]]++;
    }
    return result;
}

int main(){
    int x[] = {1,2,3,3, 3, 5, 7,9,4,8, 2,2,1,6,7};
    int n = 15;
    vector<int> data;
    for(int i = 0; i <n; i++) data.push_back(x[i]);
    
    vector<int> result = CountingSort(data); 
    cout << "Result : ";
    for(int i = 0; i <n; i++) cout << result[i] << " ";
}