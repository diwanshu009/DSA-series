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

// ⭐️ Lowest Common Ancestor of a Binary Tree!
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

// ⭐️ Construct tree from Inorder and Preorder Traversal!
int findPos(vector<int>& inorder,int s,int e,int el){
    for(int i=s;i<=e;i++){
        if(inorder[i] == el){
            return i;
        }
    }
    return -1;
}

Node* buildTree1(vector<int>&preorder,vector<int>&inorder,int &i,int s,int e){ // s->0, e->inorder.size()-1;
    if(i >= preorder.size() || s > e){
        return NULL;
    }
    int el = preorder[i++];
    int j = findPos(inorder,s,e,el);
    Node* root = new Node(el);
    root->left = buildTree1(preorder,inorder,i,s,j-1);
    root->right = buildTree1(preorder,inorder,i,j+1,e);
    return root;
}

// Construct tree from Inorder and PostOrder Traversal!
Node* buildTree2(vector<int>&inorder,vector<int>&postorder,int &i,int s,int e){
    if(i<0 || s>e){
        return NULL;
    }
    int el = postorder[i--];
    Node* root = new Node(el);
    int j = findPos(inorder,s,e,el);
    root->right = buildTree2(inorder,postorder,i,j+1,e);
    root->left = buildTree2(inorder,postorder,i,s,j-1);
    return root;
}

// ⭐️ Top View of Binary Tree!
vector<int> getTopView(Node *root){
    map<int,int>mp;
    queue<pair<int,Node*>>q;
    q.push({0, root});
    while(!q.empty()){
        int d = q.front().first;
        Node* front = q.front().second;
        q.pop();
        if(mp.find(d) == mp.end()){
            mp[d] = front->data;
        }
        if(front->left){
            q.push({d-1,front->left});
        }
        if(front->right){
            q.push({d+1,front->right});
        }
    }
    vector<int>ans;
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}

// Bottom view of Binary Tree!
vector<int> bottomView(Node* root){
    vector<int>ans;
    map<int,int>mp;
    queue<pair<int,Node*>>q;
    q.push({0,root});
    while(!q.empty()){
        int d = q.front().first;
        Node* front = q.front().second;
        q.pop();
        mp[d] = front->data;
        if(front->left){
            q.push({d-1,front->left});
        }
        if(front->right){
            q.push({d+1,front->right});
        }
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}

// ⭐️ Left View Of Binary Tree!
void leftView(vector<int>&ans,int level,Node *root){
    if(root == NULL){
        return ;
    }
    if(ans.size() == level){
        ans.push_back(root->data);
    }
    leftView(ans,level+1,root->left);
    leftView(ans,level+1,root->right);
}
// In Right view, call the right part first!

// ⭐️ Boundary Traversal!
void left(Node*root,vector<int>&ans){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        return ;
    }
    ans.push_back(root->data);
    if(root->left){
        left(root->left,ans);
    }else{
        left(root->right,ans);
    }
}

void leaf(Node*root,vector<int>&ans){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void right(Node*root,vector<int>&ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right==NULL){
        return;
    }if(root->right){
        right(root->right,ans);
    }else{
        right(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int>ans;
    if(root == NULL) return ans;
    if(root->left == NULL && root->right==NULL) return {root->data};
    ans.push_back(root->data);
    left(root->left,ans);
    leaf(root,ans);
    right(root->right,ans);
    return ans;
}

int main(){

}