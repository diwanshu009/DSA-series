#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right= NULL;
    }
};

// Do try Zig-Zag Traversal!

// ⭐️ Diagonal Traversal of Binary Tree!
vector<int> diagonalPath(Node* root) {
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp != NULL){
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}

// ⭐️ Vertical Traversal of Binary Tree!


int main(){

}