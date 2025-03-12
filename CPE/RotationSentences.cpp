#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
在這個問題中你必須將數列文字往順時針方向旋轉90度。也就是說將原本由左到右，由上到下的句子輸出成由上到下，由右到左。
*/

int main(){
    int n;
    string line;
    vector<string> sentences;
    while(cin >> n){
        cin.ignore(); // Fix: Ignore leftover newline
        int length = 0;
        sentences.clear();

        // calculate maximum length
        for(int i=0; i < n; i++){
            getline(cin,line);
            line.size() //要轉格式
            length = max(length, static_cast<int>(line.size()));
            sentences.push_back(line);
        }
        // add space to fill up
        for(int i=0; i < sentences.size(); i++){
            for(int j=0; j< length - sentences.size(); j++){
                sentences[i] += ' ';
            }
        }
        
        // 順時針旋轉90度
        for(int i=0; i < length; i++){
            for(int j= length -1; j >=0; j--){
                cout << sentences[j][i];
            }
            cout << endl;
        }

    }
    return 0;
}