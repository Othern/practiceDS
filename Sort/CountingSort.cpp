#include <iostream>
#include <vector>
using namespace std;

vector<int> CountingSort(vector<int> data){
    // range 0 ~ 9
    vector<int> count;
    for(int i=0; i<=9; i++)count.push_back(0);
    for(int i=0; i< data.size(); i++)count[data[i]]++;

    vector<int> end;
    for(int i=0; i<=9; i++)end.push_back(0);
    end[0] = count[0] -1;
    for(int i=1; i<=9; i++){
        end[i] = end[i-1] + count[i];
    }
    vector<int> result;
    for(int i=0; i< data.size(); i++)result.push_back(0);

    for(int i=0; i< data.size(); i++){
        result[end[data[i]]] = data[i];
        end[data[i]]--;
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