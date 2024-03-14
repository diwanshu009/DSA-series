#include<bits/stdc++.h>
using namespace std;

/* Binary Search is defined as a searching algorithm used in a sorted array by repeatedly dividing the search interval
   in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity 
   to O(log N). 
*/

int binarySearch(vector<int>&arr,int key){
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int main(){
    
}