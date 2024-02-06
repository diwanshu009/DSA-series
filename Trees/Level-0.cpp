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

// Maximum depth of Binary Tree (Height of Binary Tree)
int maxDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    return max(a,b)+1;
}

// Diameter of Tree
int diameterOfBinaryTree(Node* root) {
    if(root==NULL){
        return 0;
    }
    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = maxDepth(root->left) + maxDepth(root->right);
    return max(op1,max(op2,op3));
}

// Check if two trees are mirror/identical (Must try!)

// Balanced Binary Tree (abs(diff)<=1) !
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int a = height(root->left);
    if(a == -1) return -1;
    int b = height(root->right);
    if(b == -1) return -1;
    if(abs(a-b)>1) return -1;
    return max(a,b)+1;
}

bool isBalanced(Node* root) {
    return height(root)!=-1;
}

// Sum Tree (Do try!)

int main(){
    
}
