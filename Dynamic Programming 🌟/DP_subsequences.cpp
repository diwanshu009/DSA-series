#include<bits/stdc++.h>
using namespace std;

// ⭐️ Subset Sum problem
bool subset(vector<int>&arr,int i,int sum,vector<vector<int>>&dp){
    if(sum == 0) return true;
    if(i == 0) return arr[0] == sum;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int take = false;
    if(arr[i]<=sum){
        take = subset(arr,i-1,sum-arr[i],dp);
    }
    int notTake = subset(arr,i-1,sum,dp);
    return dp[i][sum] = take | notTake;
}

// Similar questions --> Partition equal subset sum, ⭐️ Partition Set Into 2 Subsets With Min Absolute Sum Diff
 
// Similar questions --> Count subsets with sum k, ⭐️ Count Partitions with Given Difference or ( Target Sum )

// ⭐️ Coin Change (Can try Coin change 2 also)
int coinChange(vector<int>&num,int x,int i,vector<vector<int>>&dp){
    if(x == 0) return 0;
    if(x<0) return INT_MAX;
    if(i<0) return INT_MAX;
    if(dp[i][x] != -1) return dp[i][x];
    int a = coinChange(num,x-num[i],i,dp);
    if(a!=INT_MAX) a += 1;
    int b = coinChange(num,x,i-1,dp);
    return dp[i][x] = min(a,b);
}

// ⭐️ KnapSack pattern (0/1 --> no duplicacy || Unbounded --> Dupliactes are allowed)
int unboundedKnapSack(int W,int wt[],int val[],int i,vector<vector<int>>&dp){
    if(i == 0){
        if(wt[0]<=W) return (W/wt[0])*val[0];
        else return 0;
    }
    if(dp[i][W]!=-1) return dp[i][W];
    int take = 0;
    if(wt[i]<=W){
        take = val[i]+unboundedKnapSack(W-wt[i],wt,val,i,dp);
    }
    int notTake = unboundedKnapSack(W,wt,val,i-1,dp);
    return dp[i][W] = max(take,notTake);
}

// Similar question --> Rod Cutting Problem

int main(){

}