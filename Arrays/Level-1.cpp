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

// ⭐️ Longest consecutive sequence! (Better approach) T.C = O(nlogn)
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

// Optimised approach, T.C = O(2N)
int longestConsecutive(const vector<int> &A) {
    if(A.size() == 0) return 0;
    unordered_set<int>st;
    for(int i=0;i<A.size();i++){
        st.insert(A[i]);
    }
    int maxi = 1;
    for(auto it:st){
        int count = 1;
        if(st.find(it-1) == st.end()){
            int x = it;
            while(st.find(x+1)!=st.end()){
                x = x+1;
                count++;
            }
        }
        maxi = max(count,maxi);
    }
    return maxi;
}

// 2-D Arrays! --> 

// ⭐️ Set Matrix Zeroes (Better Approach!), S.C = O(N+M)
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>row(n,0);
    vector<int>col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]|| col[j]){
                matrix[i][j]=0;
            }
        }
    }
}

// Optimal Approach!, S.C = O(1)
void setZeroes(vector<vector<int> > &arr) {
    int n = arr.size();
    int m = arr[0].size();
    int col0 = 1;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]==0){
                arr[0][j] = 0;
                if(i>0){
                    arr[i][0] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i=1;i<arr.size();i++){
        for(int j=1;j<arr[0].size();j++){
            if(arr[0][j] == 0 || arr[i][0] == 0){
                arr[i][j] = 0;
            }
        }
    }
    if(arr[0][0] == 0){
        for(int i=0;i<arr.size();i++){
            arr[i][0] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<arr[0].size();i++){
            arr[0][i] = 0;
        }
    }
}

// ⭐️ Rotate a Matrix! (rotate the image by 90 degrees, clockwise !)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<m;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

// ⭐️ Spiral Matrix!
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;
    while(top <= bottom && left <= right){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

// Do Try --> Wave Print a Matrix!

// Do Try --> Factorial of a large Number!

// ⭐️ Number of subarrays with sum K (for only +ve array --> This is the Optimal Approach!)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int ans = 0;
    int sum = 0;
    int j = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        while(sum >= k){
            if(sum == k){
                ans++;
            }
            sum -= arr[j];
            j++;
        }
    }
    return ans;
}

int main(){

}