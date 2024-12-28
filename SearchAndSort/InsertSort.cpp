#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void InsertSort(Node* head){
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

void PrintLinkedList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr ->next;
    } 
    cout << endl;
}

int main(){
    int x[] = {1, 2, 23, 4, 3, 29, 5, 8 , 10, 7, 32};
    int n = 11;
    Node* curr = new Node();
    Node* dummy = curr;
    for(int i = 0; i <n; i++){
        Node* next = new Node();
        next -> val = x[i];
        curr -> next = next;
        curr = curr -> next;
    } 
    Node* head = dummy -> next;
    PrintLinkedList(head);
    InsertSort(head);
    PrintLinkedList(head);
    return 0;
}