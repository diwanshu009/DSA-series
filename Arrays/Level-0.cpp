#include<bits/stdc++.h>
#include<climits.h>

// Array is the list of elements of same type placed in a contiguous manner. They are always passed by Reference!

// Basics--> Largest No. in array, Reverse an array (Two pointer approach), Linear Search
// Set insertion --> T.C = O(NlogN) , S.C = O(N)!

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

int main(){

}