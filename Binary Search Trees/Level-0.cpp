/* Binary Search Tree is a node-based binary tree data structure which has the following properties:

   --> The left subtree of a node contains only nodes with keys lesser than the node’s key.
   --> The right subtree of a node contains only nodes with keys greater than the node’s key.
   --> The left and right subtree each must also be a binary search tree
*/

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

// Search a node in a BST
Node* search(Node* root,int val){
    Node* temp = root;
    while(temp){
        if(temp->data == val){
            return temp;
        }else if(temp->data > val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return NULL;
}

// Creation,Insertion,Deletion,Min./Max.element in a BST!

// ⭐️ Inorder traversal of a BST is always sorted!
