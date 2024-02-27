#include<bits/stdc++.h>
using namespace std;

// ⭐️ Two Sum --> Brute : check each pair Sum whether it is equal to targets or not

// Better(optimal for returning indexes!) -> storing the element and checking whether (target-element) previously exits!
vector<int> twoSum(vector<int>& arr, int target) {
    int n = arr.size();
    map<int,int>mp;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(mp.find(target-arr[i]) != mp.end()){
            ans.push_back(mp[target - arr[i]]);
            ans.push_back(i);
        }
        mp[arr[i]] = i;
    }
    return ans;
}

// Optimal --> Two pointer approach! (If array is sorted and we have to return only true/false!)
string read(int n, vector<int> book, int target){
    sort(book.begin(),book.end());
    int s = 0;
    int e = n-1;
    while(s <= e){
        if(book[s]+book[e] == target){
            return "YES";
        }else if(book[s]+book[e] < target){
            s++;
        }else{
            e--;
        }
    }
    return "NO";
}

// ⭐️ Sort 0s,1s,and 2s (Dutch National Algorithm!)
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int m = 0;
    int h = n-1;
    while(m <= h){
        if(nums[m] == 0){
            swap(nums[l],nums[m]);
            l++;
            m++;
        }else if(nums[m] == 1){
            m++;
        }else{
            swap(nums[m],nums[h]);
            h--;
        }
    }
}

// Similar question on above algorithm --> Move all negatives to left side of the array!

// ⭐️ Majority element (Mooore's Voting Algorithm!)
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int el;
    for(int i=0;i<n;i++){
        if(count == 0){
            el = nums[i];
            count++;
        }else if(el == nums[i]){
            count++;
        }else{
            count--;
        }
    }
    int c1 = 0;
    for(int i=0;i<n;i++){
        if(el == nums[i]){
            c1++;
        }
    }
    if(c1 > n/2){
        return el;
    }else{
        return -1;
    }
}

// ⭐️ Maximum Subarray Sum (Kadane's Algorithm!)
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    int sum =0;
    for(int i=0;i<n;i++){
        sum += nums[i];
        maxi = max(maxi,sum);
        sum = max(0,sum);
    }
    return maxi;
}

// Do Try --> Rearrange elements by sign!

// Duplicate Number -->
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.

int findDuplicate(vector<int>& nums) { 
    while(nums[0] != nums[nums[0]]){
        swap(nums[0],nums[nums[0]]);
    }
    return nums[0];
}

// ⭐️ Best time to Buy and Sell Stock
int maxProfit(vector<int>& prices){
    int mini = prices[0];
    int cost, profit = 0;
    for(int i = 1; i < prices.size(); i++){
        cost = prices[i]-mini;
        profit = max(profit,cost);
        mini = min(prices[i],mini);
    }
    return profit;
}

// ⭐️ Next Permutation
vector<int> nextPermutation(vector<int> &arr) {
    int n = arr.size();
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind = i;
            break;
        }
    }
    for(int i = n-1;i>ind && ind != -1;i--){
        if(arr[ind]<arr[i]){
            swap(arr[ind],arr[i]);
            break;
        }
    }
    if(ind == -1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    reverse(arr.begin()+ind+1,arr.end());
    return arr;
}

// Leaders in an Array (Elements which are maximum to all its righter elements!)
vector<int> superiorElements(vector<int>&a) { 
    vector<int>ans;
    int maxi = INT_MIN;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// ⭐️ Longest consecutive sequence!
int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int longest = INT_MIN;
    int maxi = 0; 
    int count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]-1 == longest){
            count++;
            longest = nums[i];
        }else if(nums[i] != longest){
            count = 1;
            longest = nums[i];
        }
        maxi = max(count,maxi);
    }
    return maxi;
}

int main(){

}