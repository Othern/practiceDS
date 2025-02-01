#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
using namespace std;

vector<int> mergeSort(vector<int> data, int l, int r) {
    if (l == r) {
        return vector<int>{data[l]};
    }

    int m = l + (r - l) / 2;
    vector<int> data1 = mergeSort(data, l, m);
    vector<int> data2 = mergeSort(data, m + 1, r);

    int l1 = data1.size();
    int l2 = data2.size();
    int i1 = 0, i2 = 0, k = 0;
    vector<int> result(l1 + l2);

    // Merge step
    while (i1 < l1 && i2 < l2) {
        if (data1[i1] <= data2[i2]) {
            result[k++] = data1[i1++];
        } else {
            result[k++] = data2[i2++];
        }
    }

    // Append remaining elements
    while (i1 < l1) {
        result[k++] = data1[i1++];
    }
    while (i2 < l2) {
        result[k++] = data2[i2++];
    }

    return result;
}

int main(){
    vector<int> arr = {5, 2, 9, 1, 6, 3};
    vector<int> sorted = mergeSort(arr, 0, arr.size() - 1);

    for (int num : sorted) {
        cout << num << " ";
    }

    return 0;
}