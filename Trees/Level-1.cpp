#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        left = right = NULL;
    }
};

// Lowest Common Ancestor of a Binary Tree!
Node* findLCA(Node* root,Node* u, Node* v) {
    if(root == NULL) return root;
    if(u == NULL || v == NULL)return NULL;
    if(root == u || root == v){
        return root;
    }
    Node* a = findLCA(root->left,u, v);
    Node* b = findLCA(root->right, u, v);
    if(a == NULL && b == NULL) return NULL;
    else if(a != NULL && b == NULL) return a;
    else if(a == NULL && b != NULL) return b;
    else return root;
}

// kth Ancestor in a Binary Tree!
int kthAncestor(Node* root,int k,int node,int &ans){
    if(root == NULL) return -1;
    if(root->data == node) return 0;
    int a = kthAncestor(root->left,k,node,ans);
    int b = kthAncestor(root->right,k,node,ans);
    if(a == -1 && b == -1) return -1;
    int maxi = max(a,b);
    if(maxi + 1 == k){
        ans = root->data;
    }
    return maxi+1;
}

// Root to leaf Path having sum equal to target
void help(Node* root,int targetSum,int sum,vector<vector<int>>&ans,vector<int>v){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
        sum += root->data;
        if(sum == targetSum){
            ans.push_back(v);
        }
        return;
    }
    v.push_back(root->data);
    sum += root->data;
    help(root->left,targetSum,sum,ans,v);
    help(root->right,targetSum,sum,ans,v);
}

int main(){

}