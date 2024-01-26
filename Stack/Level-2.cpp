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

// LRU implementataion!


int main(){

}