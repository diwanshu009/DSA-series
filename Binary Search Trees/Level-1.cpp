#include<bits/stdc++.h>

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

int main(){

}