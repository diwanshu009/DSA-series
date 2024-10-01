#include<bits/stdc++.h>
using namespace std;

// --> HARD but interesting !!

// ⭐️ Matrix Chain Multiplication
int help(int arr[],int i,int j,int n,vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int a = arr[i-1]*arr[k]*arr[j] + help(arr,i,k,n,dp) + help(arr,k+1,j,n,dp);
        ans = min(ans,a);
    }
    return dp[i][j] = ans;
}

int main(){

}