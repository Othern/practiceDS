#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

int maximunPrice(vector<int> nums) {
    // current_sum記錄當前陣列累積值，max_sum記錄最大累積值
    int max_sum = 0, current_sum = 0;
    for (int num : nums) {
        // 如果 current_sum + num 更大，我們選擇累積和
        // 如果 num 本身更大，則丟棄之前的和，從這個元素重新開始。
        current_sum = max(num, current_sum + num);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    // 範例陣列，使用 push_back 方法填充
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);

    // 呼叫 maximunPrice 函式
    int result = maximunPrice(nums);

    // 印出結果
    cout << "最大子陣列的和是: " << result << endl;

    return 0;
}