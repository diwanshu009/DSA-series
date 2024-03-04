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

// ⭐️ Count the number of subarrays with given xor K
int subarraysWithSumK(vector < int > a, int b) {
    int ans = 0;
    int c = 0;
    unordered_map<int,int>mp;
    mp[0]++;
    for(int i=0;i<a.size();i++){
        c = c^a[i];
        ans += mp[c^b];
        mp[c]++;
    }
    return ans;
}

// ⭐️ Merge Overlapping Intervals!
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	vector<vector<int>>ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++){
		if(ans.empty() || arr[i][0]>ans.back()[1]){
			ans.push_back(arr[i]);
		}else{
			ans.back()[1] = max(ans.back()[1],arr[i][1]);
		}
	}
	return ans;
}

// Merge two Sorted arrays without using extra space!
// Approach 1: Using Two pointers!
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int i = a.size()-1;
    int j = 0;
    int n = a.size();
    int m = b.size();
    while(i>=0 && j<m){
        if(a[i]>b[j]){
            swap(a[i],b[j]);
        }
        i--;
        j++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}

// ⭐️ Approach 2: Gap Method, T.C = O(log(n+m)*(n+m)), S.C = O(1)
void swapIfGreater(vector<long long>&a,vector<long long>&b,int i,int j){
    if(a[i]>b[j]){
        swap(a[i],b[j]);
    }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size();
    int m = b.size();
    int len = n+m;
    int gap = (len/2) + (len%2);
    while(gap>0){
        int left = 0;
        int right = left+gap;
        while(right<len){
            if(left<n && right>=n){
                swapIfGreater(a,b,left,right-n);
            }else if(left>=n){
                swapIfGreater(b,b,left-n,right-n);
            }else{
                swapIfGreater(a,a,left,right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }
}

// ⭐️ Find the missing and repeating number!
// Approach 1 : Using Math! --> T.C = O(N),S.C = O(1), Approach 2 : Using XOR! (Bit manipulation!)
vector<int> repeatedNumber(const vector<int> &arr) {
    int n = arr.size();
    long long sum = 0;
    long long s2 = 0;
    long long sN = (long long)n*(n+1)/2;
    long long s2N = (long long)n*(n+1)*(2*n+1)/6;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        s2 += (long long)arr[i] * arr[i];
    }
    long long val1 = sum - sN; // x-y
    long long  val2 = s2 - s2N; // x2 - y2
    val2 = val2/val1; // x+y
    int x = (val1+val2)/2;
    int y = x-val1;
    return {x,y};
}

// Do Try --> Count Inversions (merge Sort me, ans += mid-left+1 krdo if element present in 2nd array is smaller!)

// ⭐️ Reverse pairs (HARD!) 
int ans = 0;

void merge(vector<int>&arr,int s,int mid ,int e){
    vector<int>temp;
    int left = s;
    int right = mid+1;
    int i = left;
    int j = right;
    while(i<=mid){
        if(j<=e && arr[i]>(long long)2*arr[j]){
            j++;
        }else{
            ans += j-right;
            i++;
        }
    }
    while(left<=mid && right<=e){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=e){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=s;i<=e;i++){
        arr[i] = temp[i-s];
    }
}

void help(vector<int>&arr,int s,int e){
    if(s>=e) return;
    int mid = s+(e-s)/2;
    help(arr,s,mid);
    help(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int reversePairs(vector<int>& arr) {
    help(arr,0,arr.size()-1);
    return ans;
}

// ⭐️ Maximum product Subarray!
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int s = 1;
    int p = 1;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        if(p==0) p = 1;
        if(s==0) s = 1;
        p *= nums[i];
        s *= nums[n-i-1];
        ans = max(ans,max(p,s));
    }
    return ans;
}