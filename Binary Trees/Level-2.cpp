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

// ⭐️ Vertical Traversal of Binary Tree! (Hard)
vector<vector<int>> verticalTraversal(Node* root) {
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    map<int,map<int,multiset<int>>>mp;
    queue<pair<Node*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node*& temp = front.first;
        auto coordinate = front.second;
        int& row = coordinate.first;
        int& col = coordinate.second;
        mp[col][row].insert(temp->data);
        if(temp->left){
            q.push({temp->left,{row+1,col-1}});
        }
        if(temp->right){
            q.push({temp->right,{row+1,col+1}});
        }
    }
    for(auto i:mp){
        auto& colMap = i.second;
        vector<int>v;
        for(auto it:colMap){
            auto& mSet = it.second;
            v.insert(v.end(),mSet.begin(),mSet.end());
        }
        ans.push_back(v);
    }
    return ans;
}

// ⭐️ K-Sum Paths (Path Sum - III)


int main(){

}