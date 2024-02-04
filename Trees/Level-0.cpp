#include<bits/stdc++.h>
using namespace std;

/* Binary Trees is a non-linear data structure where each node has atmost 2 children namley left and right!
    --> Some terms : Parent, Children, Ancestor, Descendant, Sibling, Leaf, etc.
*/


// Structure of Tree's Node!
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
       this->data = data;
       left = right = NULL;
    }
};

// Constructing a Binary Tree!
Node* buildTree(Node* root){
    int data;
    cin >> data;
    if(data == -1){
       return NULL;
    }
    root = new Node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

// 1. DFS Traversals -->
// Preorder Traversal for the Binary Tree!
void preorder(Node* root){
    if(root == NULL){
       return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal for the Binary Tree!
void inorder(Node* root){
    if(root == NULL){
       return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal for the Binary Tree!
void postorder(Node* root){
    if(root == NULL){
       return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 2. BFS Traversal-->
// Level Order Traversal for the Binary Tree!
void levelOrder(Node* root){
    if(root == NULL){
       return ;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        if(front == NULL){
            q.pop();
            if(!q.empty()){
               q.push(NULL);
               cout << endl;
            }
        }else{
            cout << front->data <<  " ";
            q.pop();
            if(front->left){
               q.push(front->left);
            }
            if(front->right){
               q.push(front->right);
            }
        }
    }
}

int main(){
    
}
