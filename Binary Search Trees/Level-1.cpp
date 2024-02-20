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

// 

int main(){

}