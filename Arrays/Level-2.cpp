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

// ⭐️ 3 Sum (Better Approach!)
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>>st;
    unordered_map<int,bool>mp;
    for(int i=0;i<nums.size();i++){
        mp.clear();
        for(int j=i+1;j<nums.size();j++){
            int el = -(nums[i]+nums[j]);
            if(mp.find(el)!=mp.end()){
                vector<int>v = {nums[i],nums[j],el};
                sort(v.begin(),v.end());
                st.insert(v);
            }
            mp[nums[j]] = 1;
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

// Optimal Approach (S.C = O(1)!)
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = nums.size()-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum > 0){
                k--;
            }else if(sum < 0){
                j++;
            }else{
                vector<int>temp = {nums[i],nums[j],nums[k]};
                j++;
                k--;
                ans.push_back(temp);
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;
}

// ⭐️ 4 Sum (Optimal Approach), S.C = O(1)!
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<nums.size();j++){
            if(j!=i+1 && nums[j]==nums[j-1]) continue;
            int k = j+1;
            int l = nums.size()-1;
            while(k<l){
                long long sum = nums[i]+nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum < target){
                    k++;
                }else if(sum > target){
                    l--;
                }else{
                    vector<int>v = {nums[i],nums[j],nums[k],nums[l]};
                    k++;
                    l--;
                    ans.push_back(v);
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}
