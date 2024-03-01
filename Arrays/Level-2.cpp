#include<bits/stdc++.h>
using namespace std;

// ⭐️ Pascal's Triangle!
vector<vector<int>> generate(int n) {
    vector<vector<int>>ans;
    if(n == 1) return {{1}};
    ans.push_back({1});
    for(int i=2;i<=n;i++){
        vector<int>v;
        v.push_back(1);
        int count = 1;
        for(int j=1;j<i-1;j++){
            count = count * (i-j);
            count = count/j;
            v.push_back(count);
        }
        v.push_back(1);
        ans.push_back(v);
    }
    return ans;
}

//  Majority Element (Extended Boyer Moore's Voting Algorithm!)
vector<int> majorityElement(vector<int>& nums) {
    vector<int>ans;
    int cnt1 = 0;
    int cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(cnt1 == 0 && nums[i]!= el2){
            cnt1++;
            el1 = nums[i];
        }else if(cnt2 == 0 && nums[i]!= el1){
            cnt2++;
            el2 = nums[i];
        }else if(nums[i]==el1){
            cnt1++;
        }else if(nums[i]==el2){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0;i<nums.size();i++){
        if(el1 == nums[i]) cnt1++;
        if(el2 == nums[i]) cnt2++;
    }
    if(cnt1 > nums.size()/3) ans.push_back(el1);
    if(cnt2 > nums.size()/3) ans.push_back(el2);
    return ans;
}

// ⭐️ 3 Sum
