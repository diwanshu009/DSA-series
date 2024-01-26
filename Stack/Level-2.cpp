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

// LRU implementataion!


int main(){

}