#include<bits/stdc++.h>
using namespace std;

// ⭐️ Longest repeating character replacement!
int characterReplacement(string s, int k) { // e.g s = "ABABABBA", k=1 -> ans = 4
    unordered_map<char,int>mp;
    int i = 0;
    int j = 0;
    int maxi = 0;
    int ans = 0;
    while(j < s.size()){
        mp[s[j]]++;
        maxi = max(maxi,mp[s[j]]);
        while((j-i+1)-maxi>k){
            mp[s[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}

// Find all anagrams in a String!
bool comp(unordered_map<char,int>&mp,unordered_map<char,int>&mp2){
    for(auto i:mp2){
        if(i.second>0 && mp[i.first] != mp2[i.first]){
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    if(p.size() > s.size()) return {};
    unordered_map<char,int>mp;
    unordered_map<char,int>mp2;
    vector<int>ans;
    for(int i=0;i<p.size();i++){
        mp[p[i]]++;
    }
    int i = 0;
    int j = 0;
    while(j<s.size()){
        mp2[s[j]]++;
        if(j-i+1 == p.size()){
            if(comp(mp,mp2)){
                ans.push_back(i);
            }
            mp2[s[i]]--;
            i++;
        }
        j++;
    }
    return ans;
}

int main(){

}