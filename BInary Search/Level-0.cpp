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

// ⭐️ implement lower bound
int lowerBound(vector<int> arr, int n, int x) {
	int ans = n;
	int s = 0;
	int e = n-1;
	int mid = s+(e-s)/2;
	while(s<=e){
		if(arr[mid]>=x){
			ans = mid;
			e = mid-1;
		}else{
			s = mid+1;
		}
		mid = s+(e-s)/2;
	}
	return ans;
}

// Do try --> first, last occurence of a key!

// ⭐️ Search in a rotated and sorted Array I !
int search(vector<int>& arr, int key) {
    int s=0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }else if(arr[s]<=arr[mid]){
            if(arr[s]<=key && key <=arr[mid]){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }else{
            if(arr[mid]<=key && key <= arr[e]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

// ⭐️ Search in a rotated and sorted Array II !
bool searchInRotated(vector<int>& nums, int target) {
    int n = nums.size();
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        mid = s+(e-s)/2;
        if(nums[mid] == target){
            return true;
        }if(nums[s] == nums[mid] && nums[mid] == nums[e]){
            s++;
            e--;
            continue;
        }else if(nums[s]<=nums[mid]){
            if((nums[s]<=target) && (target<=nums[mid])){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }else{
            if((nums[mid]<=target) && (target<=nums[e])){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
    }
    return false;
}

// ⭐️ Find Minimum in a Rotated and Sorted Array!
int findMin(vector<int>& arr){
	int s = 0;
	int e = arr.size()-1;
	int mid = s+(e-s)/2;
	int ans = INT_MAX;
	while(s<=e){
		if(arr[s]<=arr[mid]){
			ans = min(ans,arr[s]);
			s = mid+1;
		}else{
			ans = min(ans,arr[mid]);
			e = mid-1;
		}
		mid = s+(e-s)/2;
	}
	return ans;
}

// No of times the array has been rotated --> Index of minimum number;

// Single element in a Sorted Array (B.S!)
int singleNonDuplicate(vector<int>& arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(mid%2!=0){
            if(arr[mid-1]==arr[mid]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }else{
            if(mid<=e && arr[mid+1]==arr[mid]){
                s = mid+1;
            }else{
                e = mid;
            }
        }
        mid = s+(e-s)/2;
    }
    return arr[s];
}

// ⭐️ Peak element -->
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
        return 0;
    }
    if(nums[0]>nums[1]){
        return 0;
    }
    if(nums[n-1]>nums[n-2]){
        return n-1;
    }
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(nums[mid]<nums[mid+1]){
            s = mid+1;
        }else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int main(){
    
}