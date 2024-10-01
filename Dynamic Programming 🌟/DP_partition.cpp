#include<bits/stdc++.h>
using namespace std;

// --> HARD but interesting !!

// ⭐️ Matrix Chain Multiplication
int MCM(int arr[],int i,int j,int n,vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int a = arr[i-1]*arr[k]*arr[j] + MCM(arr,i,k,n,dp) + MCM(arr,k+1,j,n,dp);
        ans = min(ans,a);
    }
    return dp[i][j] = ans;
}

// ⭐️ Palindrome Partitioning 2
bool isPal(string &s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int dp[2001][2001];

int PP2(string &s,int i,int j){
    if(i>=j) return 0;
    if(isPal(s,i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        if (isPal(s,i,k)){
            ans = min(ans, 1 + PP2(s,k+1,j));
        }
    }
    return dp[i][j] = ans;
}

// Minimum cost to cut a stick
int cutStick(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    for(int ind =i;ind<=j;ind++){
        int cost = arr[j+1]-arr[i-1] + cutStick(arr,i,ind-1,dp) + cutStick(arr,ind+1,j,dp);
        mini = min(cost,mini);
    }
    return dp[i][j] = mini;
}

int minCost(int n, vector<int>& arr) {
    int c = arr.size();
    arr.insert(arr.begin(),0);
    arr.push_back(n);
    sort(arr.begin(),arr.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return cutStick(arr,1,c,dp);
}

// ⭐️ Evaluate boolean expression to True
long long help(string& s,int i ,int j,int isTrue,vector<vector<vector<int>>>&dp){
    if(i>j) return 0;
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    if(i==j){
        if(isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }
    long long ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2){
        long long lt = help(s,i,k-1,1,dp);
        long long rt = help(s,k+1,j,1,dp);
        long long lf = help(s,i,k-1,0,dp);
        long long rf = help(s,k+1,j,0,dp);
        if(s[k]=='&'){
            if(isTrue) ways = (ways + (lt*rt));
            else ways = (ways + (lf*rf) + (lf*rt) + (lt*rf));
        }else if(s[k]=='|'){
            if(isTrue) ways =  (ways + (lt*rt) + (lf*rt) + (lt*rf));
            else ways = (ways + (lf*rf));
        }else if(s[k]=='^'){
            if(isTrue) ways = (ways + (lt*rf) + (lf*rt));
            else ways = (ways + (lf*rf) + (lt*rt));
        }
    }
    return  dp[i][j][isTrue] = ways;
}

// Do Try --> Partition array for maximum Sum

// ⭐️ Egg Dropping

// ⭐️ Burst Balloons


int main(){

}