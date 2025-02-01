#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
using namespace std;

class minHeap {
    private:
        vector<int> data;
        void adjust(int idx){
            int n = data.size()-1;
            int k = data[idx];
            int child = idx * 2  + 1;
            while(child <= n){
                if(child + 1 <= n && data[child + 1] < data[child]) child++;
                if(data[child] < k){
                    data[ (child-1) / 2] = data[child];
                    child = child * 2 + 1;
                }
                else break;
            }
            data[(child-1) / 2] = k;
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
        void printMin(){
            cout << data[0];
        }
        void delMin(){
            data[0] = data[data.size()-1];
            data.pop_back();
            adjust(0);
        }
        void print() {
        int n = data.size();
        if (n == 0) {
            cout << "Tree is empty." << endl;
            return;
        }

        int levels = log2(n) + 1;  // 計算樹的高度

        int index = 0;  // 追蹤當前處理的節點索引

        for (int level = 0; level < levels; ++level) {
            int numNodes = pow(2, level);  // 該層的節點數
            int maxSpacing = pow(2, levels - level) - 1;  // 層級間距計算

            // 前導空格，確保整體對齊
            cout << string(maxSpacing / 2, ' ');

            for (int i = 0; i < numNodes && index < n; ++i, ++index) {
                cout << setw(2) << data[index];  // 設定數字寬度，確保對齊
                if (i < numNodes - 1) {
                    cout << string(maxSpacing, ' ');  // 設定間距
                }
            }
            cout << endl;
        }
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
    cout << endl << "---------- After extract min value --------- " << endl;
    h.delMin();
    h.print();
    return 0;
}