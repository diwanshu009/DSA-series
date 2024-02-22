#include<bits/stdc++.h>
#include<climits.h>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

// BST to sorted doubly Linked List!
void convert(Node* root,Node* &head){
    if(root == NULL) return;
    convert(root->right,head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;
    convert(root->left,head);
}

// ⭐️ Largest BST in a Binary Tree!
class BST{
    public:
    int maxi;
    int mini;
    int size;
    BST(int maxi,int mini,int size){
        this->maxi = maxi;
        this->mini = mini;
        this->size = size;
    }
};

BST help(Node* root){
    if(root == NULL){
        return BST(INT_MIN,INT_MAX,0);
    }
    BST a = help(root->left);
    BST b = help(root->right);
    if(root->data > a.maxi && root->data < b.mini){
        return BST(max(root->data,b.maxi),min(a.mini,root->data),a.size+b.size+1);
    }else{
        return BST(INT_MAX,INT_MIN,max(a.size,b.size));
    }
}

int largestBST(Node * root){
    return help(root).size;
}

// ⭐️ BST iterator -->
class BSTiterator{

private: stack<Node*>st;
public:
    BSTiterator(Node *root){
        pushAll(root);
    }

    int next(){
        Node* ans = st.top();
        st.pop();
        pushAll(ans->right);
        return ans->data;
    }

    bool hasNext(){
        return !st.empty();
    }

private :
    void pushAll(Node* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
};

// ⭐️ Recover BST / Correct BST
class Solution {
    private:
    Node* prev;
    Node* first;
    Node* last;
    Node* mid;
public:

    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        if(prev != NULL && (prev->data >root->data)){
            if(first == NULL){
                first = prev;
                mid = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(Node* root) {
        first = mid = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data,last->data);
        else if(first && mid) swap(first->data,mid->data);
    }
};

// ⭐️ Build BST from preorder Traversal!
Node* buildBST(vector<int>&arr,int lb,int ub,int& i){
    if(i >= arr.size()){
        return NULL;
    }
    Node* root = NULL;
    if(arr[i] > lb && arr[i] < ub){
        root = new Node(arr[i++]);
        root->left = buildBST(arr,lb,root->data,i);
        root->right = buildBST(arr,root->data,ub,i);
    }
    return root;
}
 
Node* constructBST(vector<int> &arr) {
    if(arr.size() == 0) return NULL;
    int i = 0;
    int lb = INT_MIN;
    int ub = INT_MAX;
    return buildBST(arr,lb,ub,i);
}

// Similar question --> Create BST from PostOrder Traversal!

// Similar question --> Validate preorder traversal in BST!

//Cousins in Binary Tree!
vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(A);
    while(q.size()){
        int n = q.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            TreeNode* t = q.front();
            q.pop();
            if(t->left) { q.push(t->left); v.push_back({t->left->val, t->val});}
            if(t->right) { q.push(t->right); v.push_back({t->right->val, t->val});}
        }
        int p = -1;
        for(auto i : v){
            if(i.first == B){
                p = i.second;
                break;
            }
        }
        if(p != -1){
            for(auto i : v){
                if(i.second != p) ans.push_back(i.first);
            }
        }
    }
    return ans;
}

// ⭐️ Brothers from different roots! (Inorder traversal using stack)


int main(){

}