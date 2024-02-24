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

int main(){

}