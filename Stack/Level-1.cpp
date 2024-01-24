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

// ⭐️ longest valid parantheses (HARD)
int longestValidParentheses(string str){
    if(str.size()==0) return 0;
    stack<int>st;
    st.push(-1);
    int len = 0;
    for(int i=0;i<str.size();i++){
        if(str[i] == '('){
            st.push(i);
        }else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }else{
                len = max(len,i-st.top());
            }
        }
    }
    return len;
}

// next smaller element
vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(st.top()>=arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}

// ⭐️ Largest area in a histogram (HARD)
vector<int> nextSmaller(vector<int>&heights){
    int n = heights.size();
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr = heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int>&heights){
    int n = heights.size();
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int curr = heights[i];
        while(st.top()!=-1 &&heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    vector<int>ans1= nextSmaller(heights);
    vector<int>ans2= prevSmaller(heights);
    int maxrect = 0;
    for(int i=0;i<heights.size();i++){
        if(ans1[i]==-1){
            ans1[i]=heights.size();
        }
        int length = heights[i];
        int width = ans1[i]-ans2[i]-1;
        int area = length * width;
        maxrect = max(area,maxrect);
    }
    return maxrect;
}

// infix, postfix and prefix conversions ⭐️
int priority(char &ch){
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch== '-') return 1;
    return -1;
}

string infixToPostfix(string s){
	string ans = "";
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            st.push(s[i]);
        }else if( ('a'<= s[i] && s[i] <= 'z') || ('A'<= s[i] && s[i] <= 'Z') || ('0'<= s[i] && s[i] <= '9') ){
            ans += s[i];
        }else if(s[i]==')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(st.size()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

// similarly we can do other conversions as well!

int main(){

}