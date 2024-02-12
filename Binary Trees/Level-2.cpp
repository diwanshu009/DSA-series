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

// ⭐️ K-Sum Paths (Path Sum - III) (HARD!)
void check(Node* root,vector<int>&ans,int &count,int k){
    if(root == NULL){
        return;
    }
    ans.push_back(root->data);
    check(root->left,ans,count,k);
    check(root->right,ans,count,k);
    int sum = 0;
    for(int i=ans.size()-1;i>=0;i--){
        sum += ans[i];
        if(sum == k){
            count++;
        }
    }
    ans.pop_back();
}

int noWays(Node* root, int k) {
    vector<int>ans;
    int count = 0;
    check(root,ans,count,k);
    return count;
}


// ⭐️ Binary Tree Maximum Path Sum (HARD!)
int path(Node* root,int &sum){
    if(root == NULL){
        return 0;
    }
    int a = path(root->left,sum);
    int b = path(root->right,sum);
    a = max(a,0);
    b = max(b,0);
    sum = max(sum,a+b+root->data);
    return max(a,b)+root->data;
}

int maxPathSum(Node* root) {
    int sum = INT_MIN;
    path(root,sum);
    return sum;
}

// House Robber III / Maximum sum of non- adjacent nodes!
pair<int,int> help(Node* root){
    if(root == NULL){
        return {0,0};
    }
    pair<int,int>a = help(root->left);
    pair<int,int>b = help(root->right);

    pair<int,int>ans;
    ans.first = root->data+a.second+b.second;
    ans.second = max(a.first,a.second) + max(b.first,b.second);
    return ans;
}

int rob(Node* root) {
    pair<int,int>ans = help(root);
    return max(ans.first,ans.second);
}

// ⭐️ Find Duplicate Subtrees
string help(Node* root,unordered_map<string,int>&mp,vector<Node*>&ans){
    if(root == NULL){
        return "N";
    }
    string a = help(root->left,mp,ans);
    string b = help(root->right,mp,ans);
    string c = to_string(root->data) + " " + a + " " + b;
    if(mp.find(c) != mp.end()){
        if(mp[c] == 1){
            ans.push_back(root);
        }
        mp[c]++;
    }else{
        mp[c] = 1;
    }
    return c;
}

vector<Node*> findDuplicateSubtrees(Node* root) {
    vector<Node*>ans;
    unordered_map<string,int>mp;
    help(root,mp,ans);
    return ans;
}

int main(){

}