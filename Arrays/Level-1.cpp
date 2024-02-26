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

int main(){

}