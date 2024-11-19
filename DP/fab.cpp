#include <iostream>
using namespace std;

int fab(int x) {
    if (x <= 1) return x;
    return fab(x-1) + fab(x-2);
}
int fabDP(int x){
    if (x <= 1) return x;
    int x1 = 0, x2 = 1;
    for(int i=2; i<=x; i++){
        int t = x2;
        x2 += x1;
        x1 = t;
    }
    return x2;
}
int main() {
    cout << fab(30) << endl; // Should output 55
    cout << fabDP(20) << endl; // Should output 55
    return 0;
}