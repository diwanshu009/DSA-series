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

/* ⭐️ Important note :  1. The time complexity of unordered_map operations is O(1) on average. S.C. = O(N)
2. The time complexity of map operation (for 1 element) is O(log n) as elements are arranged in sorted manner, S.C = O(N)

int main(){

}