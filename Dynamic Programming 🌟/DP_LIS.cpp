#include<bits/stdc++.h>
using namespace std;

// ⭐️ Longest Increasing Subsequence (Memoization)
int LIS(vector<int>&nums,int i,int prev,vector<vector<int>>&dp){
    if(i>=nums.size()) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int include = 0;
    if(prev==-1 || nums[i]>nums[prev]){
        include = 1+ LIS(nums,i+1,i,dp);
    }
    int exclude = 0+ LIS(nums,i+1,prev,dp);
    return dp[i][prev+1] = max(include,exclude);
}

// Optimised version -->
int lis(vector<int> &arr) {
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        if(ans.empty() || arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }else{
            int ind = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[ind] = arr[i];
        }
    }
    int maxi = ans.size();
    return maxi;
}

// ⭐️ Now Printing the LIS
vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    vector<int>dp(n,1);
    vector<int>hash(n,0);
    int lastIndex = 1;
    int maxi = 1;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                dp[i] = 1+dp[j];
                hash[i] =j;
            }
        }
        if(dp[i]>maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int>ans;
    ans.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// Similar question --> Longest String Chain ( ["a","ba","bda","bdca"] )
// Largest Divisible Set

// ⭐️ Longest Bitonic Sequence ( First inc. then dec. )
int LongestBitonicSequence(vector<int>arr){
	int n = arr.size();
	vector<int>dp1(n,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				dp1[i] = max(dp1[i],1+dp1[j]);
			}
		}
	}
	vector<int>dp2(n,1);
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				dp2[i] = max(dp2[i],1+dp2[j]);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans= max(ans,dp1[i]+dp2[i]-1);
	}
	return ans;
}

// Must Try --> Number of Longest Increasing Subsequences 

int main(){

}