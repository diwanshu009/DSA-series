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

// Do try simplify path and decode string questions!

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

// LRU implementataion!


int main(){

}