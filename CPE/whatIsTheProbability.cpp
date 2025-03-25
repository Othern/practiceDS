#include <iostream>
#include <iomanip> // for setprecision and fixed
#include <cmath>
/*
機率一直是電腦演算法不可或缺的一部分。
在確定性算法無法在短時間內解決問題的地方，概率性算法已應運而生。
在這個問題上，我們不處理任何概率算法。我們將僅嘗試確定某個玩家的獲勝機率。

我們透過類似擲骰子的方式來玩這個遊戲 (他不像普通骰子一樣有六個面)。
如果某個特定事件發生在玩家擲骰子時 (例如獲得數字3，獲得綠色的一面或其他任何東西)，則宣佈為獲勝者。

此遊戲可以有N個玩家。
第一個玩家將擲骰子，然後第二個玩家，最後是第N個玩家，再來是第一個玩家，依此類推。
當玩家獲得期望的結果時，宣佈為獲勝者，比賽停止。
您必須確定其中一名 (第i名) 的獲勝機率。
*/
using namespace std;
int main(){
    int sets, n, i;
    double p, pi;
    cin >> sets;
    for(int j =0; j<sets ; j++){
        cin >> n >> p >> i; 
        if(p < 0.00001){
            cout << fixed << setprecision(4) << 0 << endl;
            continue;
        }
        pi = pow(1-p, i-1) * p / (1 - pow(1-p,n));
        cout << fixed<< setprecision(4) << pi << endl;
    }
    return 0;
}