#include<bits/stdc++.h>
#include<climits.h>

// Array is the list of elements of same type placed in a contiguous manner. They are always passed by Reference!

// Basics--> Largest No. in array, Reverse an array (Two pointer approach), Linear Search

/* Set (store elements in a sorted manner!) insertion (for 1 element) -> T.C = O(logN), S.C = O(N), whereas
   Unordered Set stores element in an unordered manner (not Sorted/Random) , so its T.C = O(1), S.C = O(N) */

// Tip --> First think about the brute force solution and then try to optimise it further (In an interview also!)

// ⭐️ Second largest in an array (Similarly, Second Smallest in an array)
int largest(vector<int>& arr){
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(a[i]>largest){
            slargest = largest;
            largest = a[i];
        }
        if(a[i]<largest && a[i]>slargest){
            slargest = a[i];
        }
    }
    return slargest;
}

// ⭐️ Remove duplicates from Sorted Array!
int removeDuplicates(vector<int>& nums) { // (Two pointer approach!)
    int n = nums.size();
    int i = 0;
    int j = 1;
    while(j<n){
        if(nums[i]!= nums[j]){
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return i+1;
}

// ⭐️ Left rotate an array by K places! (first do try for one place only)
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(),nums.begin()+(nums.size()-k));
    reverse(nums.begin()+(nums.size()-k),nums.end());
    reverse(nums.begin(),nums.end());

}

// ⭐️ Moves Zeroes to end!
void moveZeroes(vector<int>& nums) {
    int i = 0;
    int j = 0;
    while(j<nums.size()){
        if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
}

// Do Try --> Merge 2 sorted Arrays (union of 2 sorted arrays) without using set Data structure!
// Do Try --> Intersection of 2 sorted Arrays in T.C = O(n+m), S.C = O(1)!

// ⭐️ Missing Number
int missingNumber(vector<int>& nums) { // Method 1: Using XOR (Slightly Better!) , Method 2:  Missing number = n*(n+1)/2 - arraySum
    int a = 0;
    int b = 0;
    for(int i=0;i<nums.size();i++){
        a = a ^ (i+1);
        b = b ^ nums[i];
    }
    return a^b;
}

// Do Try --> Maximum Consecutive Ones!

// Do Try --> Find the number that appear once and others twice (Using XOR it can be easily done, ans = ans ^ arr[i])!

/* ⭐️ Important note :  1. The time complexity of unordered_map operations (for 1 element) is O(1) on average, 
                        But if collision occurs, it can reach upto O(N) as well!  S.C. = O(N)
2. The T.C of map operation (for 1 element) is O(log n) as elements are arranged in sorted manner, S.C = O(N) */

// ⭐️ Longest Subarray with sum K --> (Method 1: Generating all subarrays and matching with K with max. length!)

//  --> Method 2 : With the help of Prefix Sum (only for positives and negatives ✅, this will be the optimal solution)
// It is not the optimal approach if we are having only positive numbers in the array!

int longestSubarrayWithSumK(vector<int> a, long long k) {
    unordered_map<long long,int>mp;
    long long s = 0;
    int len = 0;
    for(int i=0;i<a.size();i++){
        s += a[i];
        if(s == k){
            len = max(len,i+1);
        }
        if(mp.find(s-k) != mp.end()){
            len = max(len,i-mp[s-k]);
        }
        if(mp.find(s) == mp.end()){
            mp[s] = i;
        }
    }
    return len;
}

// --> Method 3 : Using sliding Window Pattern! // T.C. = O(2N), S.C = O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = a[0];
    int i = 0;
    int j = 0;
    int len = 0;
    while(j < a.size()){
        while(i<=j && sum > k){
            sum -= a[i];
            i++;
        }
        if(sum == k){
            len = max(len,j-i+1);
        }
        j++;
        if(j < a.size()) sum += a[j];
    }
    return len;
}

// ⭐️ Prefix Sum concept (Helpful)!
// Range Sum (using prefix Sum approach!)
vector<int> rangeSum(vector<int> &arr, vector<vector<int>> &queries){
    vector<int>ans;
    vector<int>prefix(arr.size(),0);
    int s = 0;
    for(int i=0;i<arr.size();i++){
        s += arr[i];
        prefix[i] = s;
    }
    for(int i=0;i<queries.size();i++){
        int l = queries[i][0]-1; // As 1st element means 0th index!
        int r = queries[i][1]-1;
        ans.push_back(prefix[r]-prefix[l-1]);
    }
    return ans;
}

// Range Sum 2-D (Prefix Sum)
vector<int> findSubmatrixSum(vector<vector<int>> &arr, vector<vector<int>> &queries) {
    vector<vector<int>>prefix = arr;
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum = 0;
        for(int j=0;j<arr[0].size();j++){
            sum += arr[i][j];
            prefix[i][j] = sum;
        }
    }
    for(int i=1;i<prefix.size();i++){
        for(int j=0;j<prefix[0].size();j++){
            prefix[i][j] += prefix[i-1][j];
        }
    }
    // we have calculated the prefix sum 2-D array by above operations!
    vector<int>ans;
    for(int i=0;i<queries.size();i++){
        int s = 0;
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        s += prefix[x2][y2];
        if(x1>0) s -= prefix[x1-1][y2]; 
        if(y1>0) s -= prefix[x2][y1-1];
        if(x1>0 && y1>0) s += prefix[x1-1][y1-1];
        ans.push_back(s);
    }
    return ans;
}

int main(){

}