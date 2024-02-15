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

// Flatten a Binary Tree to Linked List!
void flattenBinaryTree(Node* root){
    Node* curr = root;
    while(curr){
        if(curr->left){
            Node* pred = curr->left;
            while(pred->right){
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// ⭐️ Burning Tree (HARD)!
Node* help(Node* root,int x,unordered_map<Node*,Node*>&mp){
    queue<Node*>q;
    q.push(root);
    Node* target = NULL;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front->data == x){
            target = front;
        }
        if(front->left){
            mp[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            mp[front->right] = front;
            q.push(front->right);
        }
    }
    return target;
}
 
int burn(Node* target,unordered_map<Node*,Node*>&mp){
    queue<Node*>q;
    q.push(target);
    map<Node*,bool>burnt;
    burnt[target] = 1;
    int t = 0;
    while(!q.empty()){
        int size = q.size();
        bool b = 0;
        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();
            if(front->left && !burnt[front->left]){
                burnt[front->left] = 1;
                b = 1;
                q.push(front->left);
            }
            if(front->right && !burnt[front->right]){
                burnt[front->right] = 1;
                b = 1;
                q.push(front->right);
            }
            if(mp[front] && !burnt[mp[front]]){
                burnt[mp[front]] = 1;
                b = 1;
                q.push(mp[front]);
            }
        }
        if(b) t++;
    }
    return t; 
}
 
int solve(Node* root, int x) {
    unordered_map<Node*,Node*>mp;
    Node* target = help(root,x,mp);
    int time = burn(target,mp);
    return time;
}

// Do try --> Nodes which are k distance from the target node (Simliar question!)

// Serialize and Deserialize a Binary Tree (HARD)!
string serialize(Node* root) {
    if(root == NULL){
        return "";
    }
    queue<Node*>q;
    string s = "";
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            s += "#,";
        }else{
            s += to_string(front->data) + ",";
        }
        if(front){
            q.push(front->left);
            q.push(front->right);
        }
    }
    return s;
}

Node* deserialize(string data) {
    if(data.size() == 0) return NULL; 
    stringstream s(data);
    string str; 
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node*> q; 
    q.push(root); 
    while(!q.empty()) {
        Node *node = q.front(); 
        q.pop(); 
        getline(s, str, ',');
        if(str == "#") {
            node->left = NULL; 
        }
        else {
            Node* leftNode = new Node(stoi(str)); 
            node->left = leftNode; 
            q.push(leftNode); 
        }
        getline(s, str, ',');
        if(str == "#") {
            node->right = NULL; 
        }
        else {
            Node* rightNode = new Node(stoi(str)); 
            node->right = rightNode;
            q.push(rightNode); 
        }
    }
    return root; 
}

// Morris Traversal!
vector<int> getInOrderTraversal(Node *root){
    vector<int>ans;
    if(root == NULL) return ans;
    Node* curr = root;
    while(curr){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            Node* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main(){

}