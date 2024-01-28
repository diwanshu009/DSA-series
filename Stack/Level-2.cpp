// Would urge you to first go through previous levels!

#include<bits/stdc++.h>
using namespace std;

// minimum bracket reversal to make balanced parantheses
  // -> first remove the balanced one (brackets) in stack!
  // -> then pop out the top 2 bracket, if same bracket, then count+=1, else count+=2

// ⭐️ Remove all adjacent duplicates in string II 
string removeDuplicateSubstrings(int n, int k, string &s){
    stack<pair<char,int>>st;
    string ans = "";
    for(int i=0;i<s.size();i++){
        if(!st.empty() && st.top().first==s[i]){
            st.top().second++;
            if(st.top().second==k){
                st.pop();
            }
        }else{
            st.push({s[i],1});
        }
    }
    while(st.size()){
        while(st.top().second--){
            ans += st.top().first;
        }
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// next greater element in LinkedList! (easy)
// --> vector<int> nextLargerNodes(ListNode* head) {
//         vector<int>ans;
//         while(head){
//             ans.push_back(head->val);
//             head = head->next;
//         }
//         stack<int>st;
//         for(int i=0;i<ans.size();i++){
//             while(!st.empty() && ans[i] > ans[st.top()]){
//                 int kid = st.top();
//                 st.pop();
//                 ans[kid] = ans[i];
//             }
//             st.push(i);
//         }
//         while(st.size()){
//             ans[st.top()] = 0;
//             st.pop();
//         }
//         return ans;
//     }

// ⭐️ celebrity problem
int celebrity(vector<vector<int> >& M, int n) {
    stack<int>st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()!=1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(M[a][b]){ // a is not celebrity
            st.push(b);
        }else{
            st.push(a);
        }
    }
    int celebrity = st.top();
    for(int i=0;i<n;i++){
        if(M[celebrity][i]){
            return -1;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=celebrity && M[i][celebrity]==0){
            return -1;
        }
    }
    return celebrity;
}

// ⭐️ N Stacks In an Array (HARD)
class NStack{

    public:
    int *a,*top,*next;
    int freespot;
    int n;
    int size;

    NStack(int N, int S){
        this->n = N;
        this->size = S;
        freespot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<size;i++){
            next[i] = i+1;
        }
        next[size-1] = -1;
    }

    bool push(int x, int m){
        if(freespot==-1){
            return false;
        }
        int index = freespot;
        freespot = next[index];
        a[index] = x;
        next[index] = top[m-1];
        top[m-1] = index;
        return true;
    }

    int pop(int m){
        if(top[m-1]==-1){
            return -1;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        int ans = a[index];
        next[index] = freespot;
        freespot = index;
        return ans;
    }
};

// online stack span (monotonic stack!)
class StockSpanner {
public:
    stack<pair<int,int>>st;

    StockSpanner() {
        
    }
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first<=price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

// Do try simplify path, decode string and trapping rain water problem!

// Car fleet ⭐️
class Solution {
    class Car{
        public:
        int pos;
        int speed;
        Car(int pos,int speed){
            this->pos = pos;
            this->speed = speed;
        }
    };
    static bool comp(Car& a,Car& b){
        return a.pos < b.pos;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>car;
        for(int i=0;i<position.size();i++){
            Car c(position[i],speed[i]);
            car.push_back(c);
        }
        sort(car.begin(),car.end(),comp);
        stack<float>st;
        for(auto c:car){
            float time = (target-c.pos)/((float)c.speed);
            while(!st.empty() && time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};

// remove k digits!
string removeKDigits(string num, int k) {
    stack<char>st;
    for(int i=0;i<num.size();i++){
        while(!st.empty() && num[i]<st.top() && k>0){
            k--;
            st.pop();
        }
        st.push(num[i]);
    }
    while(k--){
        st.pop();
    }
    string ans = "";
    while(st.size()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int i = 0;
    while(ans[i]=='0'){
        i++;
    }
    string output = ans.substr(i,ans.size());
    if(output.size()==0) return "0";
    return output;
}

// Asteroid collision (Stack->TLE, using deque!)

// ⭐️ sum of subarray minimum (monotonic stack)!
int mod = 1e9+7;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int>left(n,0);
    vector<int>right(n,0);
    stack<pair<int,int>>st;
    stack<pair<int,int>>st2;
    for(int i=0;i<n;i++){
        int count = 1;
        while(!st.empty() && st.top().first>arr[i]){
            count += st.top().second;
            st.pop();
        }
        left[i] = count;
        st.push({arr[i],count});
    }
    for(int i=n-1;i>=0;i--){
        int count = 1;
        while(!st2.empty() && st2.top().first >= arr[i]){
            count += st2.top().second;
            st2.pop();
        }
        right[i] = count;
        st2.push({arr[i],count});
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans = (ans + (arr[i]* (((long long)(left[i]*right[i])%mod))%mod)%mod)%mod;
    }
    return ans;
}

// LRU cache implementataion!
struct Node{
    int key,val;
    Node*next, *prev;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        next=prev=nullptr;
    }
};

class LRUCache{
public:
    int capacity;
    unordered_map<int,Node*> mp;
    Node *head, *tail;

    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insertNode(Node* node){
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
    }

    LRUCache(int capacity){
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        int ans=-1;
        if(!mp.count(key)){
            return ans;
        }
        ans = mp[key]->val;
        deleteNode(mp[key]);
        insertNode(mp[key]);
        return ans;
    }

    void put(int key, int value){
        if(mp.count(key)){
            auto it=mp[key];
            deleteNode(it);
            it->val = value;
            insertNode(it);
        }
        else{
            if(mp.size()==capacity){
                mp[key] = new Node(key,value);
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                insertNode(mp[key]);
            }
            else{
                mp[key] = new Node(key,value);
                insertNode(mp[key]);
            }
        }
    }
};


int main(){

}