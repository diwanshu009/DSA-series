#include<bits/stdc++.h>
using namespace std;

// ⭐️ Longest common Subsequence (LCS) in a string
int lcs(string &s,string &p,int i,int j,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i] == p[j]) return dp[i][j] = 1 + lcs(s,p,i-1,j-1,dp);
    else return dp[i][j] = max(lcs(s,p,i-1,j,dp),lcs(s,p,i,j-1,dp));
}

// Learn about printing the lcs as well by dp table!

// Similar questions --> Longest common substring (if not match return 0 and catch max.)
// --> Longest Palindromic Subsequence ( find lcs( given string , reverse of given string ) )
// --> Minimum Insertion Steps to Make a String Palindrome (n-lps(string))
// --> Minimum Insertions/Deletions to Convert String ( n+m-2*lcs(s,t) )
// --> Shortest common supersequence 

// ⭐️ Distinct subsequences ( return the number of distinct subsequences of s which equals t )
int distinct(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    if(i<0 && j>=0) return 0;
    if(j<0) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
    int a = 0;
    if(s[i]==t[j]) a = distinct(s,t,i-1,j-1,dp);
    int b = distinct(s,t,i-1,j,dp);
    return dp[i][j]= a+b;
}

// ⭐️ Edit Distance
int edit(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j]= edit(s,t,i-1,j-1,dp);
    }
    int a = 1+edit(s,t,i,j-1,dp);
    int b = 1+edit(s,t,i-1,j,dp);
    int c = 1+edit(s,t,i-1,j-1,dp);
    return dp[i][j] = min(a,min(b,c));
}

// ⭐️ WildCard pattern matching 
bool f(string &s,string &p,int i,int j,vector<vector<int>>&dp){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0){
        for(int z=0;z<=j;z++){
            if(p[z]!='*'){
                return false;
            }
        }
        return true;
    }
    if(j<0 && i>=0) return false;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j] || p[j]=='?'){
        return dp[i][j]= f(s,p,i-1,j-1,dp);
    }else if(p[j]=='*'){
        return  dp[i][j]= f(s,p,i-1,j,dp) | f(s,p,i,j-1,dp);
    }
    return  dp[i][j]=0;
}

int main(){

}