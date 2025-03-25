/*
一個社會研究組織採用了一組簡單的參數來模擬我們國家政黨運作的行為。
參數之一是一個正整數h，h稱為罷會(hartal)參數，它表示同一個政黨連續兩次連續罷會的間隔天數。
儘管該參數有點過於簡單，但還是能用於預測政黨罷會造成的影響。

以下範例為您說明：
考慮現在有三個政黨。假設h1 = 3，h2 = 4，h3 = 8，其中hi是第i方的罷會參數。
現在，我們將模擬這三個方在N = 14天的罷會行為。
模擬的起始天一定是星期天，並假設在每週的假日(星期五和星期六)不會有任何罷會情形。

輸入第一行有一個整數T，代表有T組測資。
每組測資第一行包含一個整數N (7 ≤ N ≤ 3650)，N代表模擬的天數。
下一行包含一個整數P (1 ≤ P ≤ 100)，表示有幾個政黨。
接下來的P行，第i行包含一個正整數hi(永遠不會是7的倍數)，代表第i個政黨的罷會參數。
*/
#include <iostream>
#include <vector>
using namespace std; 
int main(){
    vector<int> h;
    int n;
    int parties;
    int days;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> days;
        cin >> parties;
        for(int j=0; j< parties; j++){
            int temp;
            cin >> temp;
            h.push_back(temp);
        }
        int count =0;
        for(int j=1; j<= days; j++){
            for(int k=0; k< parties; k++){
                if(j % h[k] == 0 && !(j % 7 == 0 || j % 7 == 6)){
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}