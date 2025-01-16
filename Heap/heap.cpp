#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class minHeap {
    private:
        vector<int> data;
        void adjust(int idx){
            int n = data.size();
            int x = data[idx];
            int minChildIdx = 2 * idx + 1;

            while (minChildIdx < n) { // Ensure the current node has at least one child
                if (minChildIdx + 1 < n && data[minChildIdx + 1] < data[minChildIdx]) {
                    minChildIdx++; // Use the smaller child
                }
                if (data[minChildIdx] < x) {
                    data[(minChildIdx-1)/2] = data[minChildIdx]; // Move smaller child up
                    minChildIdx = 2 * minChild +1;            // Move to the child position
                } else {
                    break; // Heap property is restored
                }
            }

            data[(minChildIdx-1)/2] = x; // Pla
        }

    public:
        void insert(int x){
            data.push_back(x);
            // 如果index 從1開始，則改成 data.size()
            int n = data.size() - 1;
            // 如果index 從1開始，則改成 n > 1
            while(n > 0){
                int par = (n - 1) / 2;
                // 如果index 從1開始，則改成 n / 2
                if(x < data[par]){
                    data[n] = data[par];
                    n = par;
                }else break;    
            }
            // 如果index 從1開始，則改成 n > 1
            data[n] = x;
        }
        
        void buildHeapFromVector(const vector<int>& input) {
            data = input;

            // 從最後一個父點開始
            for (int i = (data.size()-1 )/ 2 ; i >= 0; --i) {
                adjust(i);
            }
        }


        void print(){
            for(int i=0; i< data.size(); i++) cout << data[i] << " ";
        }

       
};

int main(){
    // minHeap h;
    // h.insert(2);
    // h.insert(3);
    // h.insert(1);
    // h.insert(4);
    // h.insert(6);
    // h.insert(0);
    // h.insert(5);
    // h.print();
    // 用向量初始化
    vector<int> input;
    int arr[] = {10, 20, 15, 30, 40, 50, 100, 25, 35};
    for(int i=0; i<9; i++) input.push_back(arr[i]);

    minHeap h;
    h.buildHeapFromVector(input);
    h.print();
    return 0;
}