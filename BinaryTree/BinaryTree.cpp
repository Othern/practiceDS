#include <iostream>
using namespace std;
// 定義二元樹節點結構
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr),parent(nullptr) {}
};

TreeNode* create(int val){
    TreeNode* t = new TreeNode(val);
    return t;
}
void insert(TreeNode* t,int val){
    if(t == nullptr){
        t->val = val;
        return;
    } 
    TreeNode* node = new TreeNode(val);
    TreeNode* prev = nullptr;
    while(t != nullptr){
        prev = t;
        if(val <= t -> val)t = t-> left;
        else t = t -> right;
        
    }
    node -> parent = prev;
    if(val <= prev->val){
        prev -> left = node;
    }
    else{
        prev -> right = node;
    } 
}

void delFirst(TreeNode** t){
    if((*t) == nullptr){
        cout << "已經空了 \n";
        return;
    } 
    //以左子樹最右進行填補
    if((*t)-> left == nullptr){
        TreeNode* temp = *t;
        *t = (*t) ->right;
        delete temp;
        return ;
    }
    // 找左子樹的最右節點
    TreeNode* parent = nullptr;  // 用於記錄最右節點的父節點
    TreeNode* curr = (*t)->left;
    while (curr->right != nullptr) {
        parent = curr;
        curr = curr->right;
    }
    (*t) -> val = curr->val;
    // 刪除最右節點
    if (parent != nullptr) {
        parent->right = curr->left;  // 用最右節點的左子樹取代它的位置
    } else {
        (*t)->left = curr->left;    // 若 parent 為空，意味著 curr 是左子樹的根
    }
    delete curr;  // 釋放記憶體
    
}

void print(TreeNode* t){
    if(t == nullptr) return;
    print(t -> left);
    cout << t->val << " ";
    print(t -> right);
}

void swapT(TreeNode* t){
    if(t == nullptr) return ;
    swap(t->left,t->right);
    swapT(t->left);
    swapT(t->right);
}

TreeNode* find(TreeNode* t,int val){
    if(t == nullptr) return nullptr;
    if(t -> val == val) return t;
    else if(t->val > val){
        return find(t -> left, val);
    }else{
        return find(t -> right, val);
    }
}
// inorder的下一個是誰
// inorder (LDR)
void successorT(TreeNode* t){
    //case 1 DR
    if(t->right != nullptr){
        TreeNode* curr = t -> right;
        while(curr -> left != nullptr)curr = curr->left;
        cout <<  curr -> val << "\n";
    }
    //case 2 LD
    else{
        TreeNode* curr = t -> parent;
        while(curr != nullptr && curr->right == t){
            t = curr;
            curr = curr ->parent;
        }
        cout << curr -> val << "\n";
    }
    
    
    return;
}
int main(){
    TreeNode* BT = create(5);
    insert(BT,10);
    insert(BT,2); 
    insert(BT,3); 
    insert(BT,8); 
    insert(BT,7); 
    print(BT);
    cout << "\n";
    successorT(BT);
    successorT(find(BT,3));
    // swapT(BT);
    // print(BT);
    // cout << "\n";
    while(BT != nullptr){
        delFirst(&BT);
        print(BT);
        cout << "\n";
    }
    
    

}