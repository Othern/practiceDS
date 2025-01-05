#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void InsertionSortLinkList(Node* head){
    if (!head || !head->next) return; // No need to sort if list is empty or has one element.
    Node* sorted = nullptr; // Start with an empty sorted list.
    Node* curr = head;
    while(curr != nullptr){
        Node* next = curr -> next;
        // Find the position to insert the current node in the sorted list.
        if (!sorted || sorted->val >= curr->val) {
            // Insert at the beginning of the sorted list.
            curr->next = sorted;
            sorted = curr;
        } else {
            // Traverse the sorted list to find the correct position.
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->val < curr->val) {
                temp = temp->next;
            }
            // Insert the node at the correct position.
            curr->next = temp->next;
            temp->next = curr;
        }

        curr = next; // Move to the next node in the original list.
    }

    head = sorted; // Update the head to the new sorted list.
}

void Insert(vector<int>& data,int val, int i){
    // 如果用小於等於，則此insertion sort會變的unstable
    while(val < data[i] && i >=0){
        data[i + 1] = data[i];
        i--;
    }
    data[i + 1] = val;
    // for(int i =0; i<data.size(); i++) cout << data[i] << " ";
    // cout << endl;    
    return;
}
// 二分搜索查找插入位置
int BinarySearch(const vector<int>& data, int val, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; // 返回插入位置
}
void BinaryInsert(vector<int>& data, int val, int i) {
    // 使用二分搜索查找插入位置
    int pos = BinarySearch(data, val, 0, i);
    
    // 将 [pos, i] 范围的元素向右移动
    for (int j = i; j >= pos; j--) {
        data[j + 1] = data[j];
    }
    
    // 在 pos 位置插入值
    data[pos] = val;
    
    return;
}

void InsertionSortArray(vector<int>& data){
    for(int i = 1; i < data.size(); i++){
        //BinaryInsert(data,data[i],i-1);
        Insert(data,data[i],i-1);
    }
}

void PrintLinkedList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr ->next;
    } 
    cout << endl;
}

int main(){
    int x[] = {1, 2, 23, 4, 3, 29, 5, 8 , 10, 7, 32, 8};
    vector<int> data;
    int n = 12;
    Node* curr = new Node();
    Node* dummy = curr;
    for(int i = 0; i <n; i++){
        data.push_back(x[i]);
        Node* next = new Node();
        next -> val = x[i];
        curr -> next = next;
        curr = curr -> next;
    } 
    Node* head = dummy -> next;
    PrintLinkedList(head);
    InsertionSortLinkList(head);
    PrintLinkedList(head);
    InsertionSortArray(data);
    for(int i =0; i<n; i++) cout << data[i] << " ";
    cout << endl;
    return 0;
}