#include<bits/stdc++.h>
using namespace std;

// paranthesis type questions!

// ⭐️ valid paranthesis
bool isValidParenthesis(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }else if(!st.empty()){
            if(st.top()=='(' && s[i]==')'){
                st.pop();
            }else if(st.top() == '{' && s[i] == '}') {
                st.pop();
            }else if(st.top()=='[' && s[i]==']'){
                st.pop();
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    if(st.size()==0) return true;
    return false;
}

// Min stack
class MinStack {
public:
    vector<pair<int,int>>st;
    // a vector in which we are able to get the access of the smallest element in O(1) time

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int>p = make_pair(val,val);
            st.push_back(p);
        }else{
            pair<int,int>p;
            p.first=val;
            p.second=min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

int main(){

}