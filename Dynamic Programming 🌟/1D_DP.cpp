#include<bits/stdc++.h>
using namespace std;

// Frog Jump (1 or 2 step at a time)
int frogJump(vector<int>&arr,int i,vector<int>&dp){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int b = INT_MAX;
    int a = abs(arr[i]-arr[i-1]) + frogJump(arr,i-1,dp);
    if(i>1) b = abs(arr[i]-arr[i-2]) + frogJump(arr,i-2,dp);
    return dp[i] = min(a,b);
}

// ⭐️ Frog jump (atmost k steps)
int frog2(vector<int>&arr,int i,int k,vector<int>&dp){
    if(i == 0) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans = INT_MAX;
    for(int j=1;j<=k;j++){
        int a = INT_MAX;
        if(i>=j){
            a =  abs(arr[i]-arr[i-j])+frog2(arr,i-j,k,dp);
        }
        ans = min(a,ans);
    }
    return dp[i] = ans;
}

// ⭐️ House robber problem
int houseRobber(int arr[],int i,vector<int>&dp){
    if(i<0) return 0;
    if(i == 0) return arr[0];
    if(dp[i]!=-1) return dp[i];
    int a = arr[i]+houseRobber(arr,i-2,dp);
    int b = houseRobber(arr,i-1,dp);
    return dp[i] = max(a,b);
}

// ⭐️ Space optimisation of House Robber -->
int help(vector<int>&arr){
    int a = 0;
    int b = arr[0];
    for(int i=1;i<arr.size();i++){
        int include = arr[i]+a;
        int exclude = b;
        int c = max(include,exclude);
        a = b;
        b = c;
    }
    return b;
}

// House Robber 2 --> ( If array is circular --> find max(1,n-1 , 0,n-2) )

int main(){

}