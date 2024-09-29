#include<bits/stdc++.h>
using namespace std;

// ⭐️ Ninja's Training
int help(vector<vector<int>>&arr,int i,int last,vector<vector<int>>&dp){
    if(i == 0){
        int maxi = -1;
        for(int j=0;j<arr[0].size();j++){
            if(j!=last){
                maxi = max(maxi,arr[0][j]);
            }
        }
        return maxi;
    }
    if(dp[i][last]!=-1) return dp[i][last];
    int ans = 0;
    for(int j=0;j<3;j++){
        int a = -1;
        if(j!=last){
            a = arr[i][j]+help(arr,i-1,j,dp);
        }
        ans = max(ans,a);
    }
    return dp[i][last] = ans;
}

// ⭐️ Unique Paths 2
int uniquePaths2(vector<vector<int>>&arr,int i,int j,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(arr[i][j]) return 0;
    if(i == 0 && j == 0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = help(arr,i-1,j,dp)+help(arr,i,j-1,dp);
}

// Similar ques --> Min. Path Sum in a Matrix , Max. Falling Path Sum

// ⭐️ 3D DP -> Chocolates Pickup
int chocolate(vector<vector<int>>&grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp){
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>= grid[0].size()) return -1e8;
    if(i == grid.size()-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi = 0;
    for(int x=-1;x<=1;x++){
        for(int y=-1;y<=1;y++){
            int a = 0;
            if(j1 == j2) a = grid[i][j1]+chocolate(grid,i+1,j1+x,j2+y,dp);
            else a = grid[i][j1]+grid[i][j2]+chocolate(grid,i+1,j1+x,j2+y,dp);
            maxi = max(maxi,a);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int main(){

}