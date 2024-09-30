#include<bits/stdc++.h>
using namespace std;

// Buy and Sell Stock 2 (Infinite transitions)
int BS2(vector<int>&prices,int i,bool buy,vector<vector<int>>&dp){
    if(i>=prices.size()) return 0;
    int price = 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy){
        price = max(0+BS2(prices,i+1,1,dp),-prices[i]+BS2(prices,i+1,0,dp));
    }else{
        price = max(0+BS2(prices,i+1,0,dp),prices[i]+BS2(prices,i+1,1,dp));
    }
    return dp[i][buy] = price;
}

// Buy and Sell Stock 3 --> Atmost 2 transactions

// ⭐️ Buy and Sell Stock 4 --> Atmost K transactions
// ( In Space optimisation --> )
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>after(2,vector<int>(k+1,0));
    vector<vector<int>>curr(2,vector<int>(k+1,0));
    for(int i=n-1;i>=0;i--){
        for(int z = 1;z<=k;z++){
            curr[1][z]= max(-prices[i]+after[0][z],after[1][z]);
            curr[0][z] = max(prices[i]+after[1][z-1],after[0][z]);
        }
        after = curr;
    }
    return curr[1][k];
}

// Buy and Sell Stock 5 --> Cooldown period (After selling go to i+2)

// Buy and Sell Stock 6 --> with transaction fee (After selling subtract the transaction fee)

int main(){

}