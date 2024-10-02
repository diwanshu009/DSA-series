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

// --> Do Try : Minimum cost to cut a stick

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

// Partition array for maximum Sum
int partition(vector<int>&arr,int i,int k,vector<int>&dp){
    if(i>=arr.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int n = arr.size();
    int len = 0;
    int maxi = INT_MIN;
    int sum = 0;
    int ans = INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxi = max(maxi,arr[j]);
        sum = (maxi*len) + partition(arr,j+1,k,dp);
        ans = max(sum,ans);
    }
    return dp[i] = ans;
}

// ⭐️ Super Egg Drop
int superEgg(int e,int f,vector<vector<int>>&dp){ // TLE
    if(e == 1 || f <= 1) return f;
    if(dp[e][f]!=-1) return dp[e][f];
    int ans = INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1+max(superEgg(e-1,k-1,dp),superEgg(e,f-k,dp));
        ans = min(ans,temp);
    }
    return dp[e][f] = ans;
}

// Space Optimization + Binary Search ( Optimized code for super egg drop )
int superEggDrop(int e, int f) {
    vector<int>prev(10001,0);
    for (int i = 1; i <= f; i++) prev[i] = i;
    vector<int>curr(10001,0);
    for(int i=2;i<=e;i++){
        for (int j = 1; j <= f; j++) {
            curr[j] = INT_MAX;
            int low = 1, high = j;
            while (low <= high) {
                int mid = (low + high) / 2;
                int break_case = prev[mid - 1]; 
                int no_break_case = curr[j - mid]; 
                int temp = 1 + max(break_case, no_break_case);
                curr[j] = min(curr[j], temp);
                if (break_case > no_break_case) high = mid - 1; 
                else low = mid + 1;
            }
        }
        prev = curr;
    }
    return prev[f];
}

// ⭐️ Burst Balloons
int burstBalloon(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans = INT_MIN;
	for(int k=i;k<=j;k++){
		int a = arr[i-1]*arr[k]*arr[j+1];
		int c = burstBalloon(i, k - 1, arr, dp) + burstBalloon(k + 1, j, arr, dp);
        ans = max(ans, a+c);
	}
	return dp[i][j] = ans;
}

int maxCoins(vector<int>& nums){
	int n = nums.size();
    
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    
    return burstBalloon(1, n, nums, dp); 
}

int main(){

}