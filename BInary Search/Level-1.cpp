#include<bits/stdc++.h>
using namespace std;

// ⭐️ Binary Search on Search Space (Answers)!

// Find square root of a number!
int sqrt(int n) {
    long long int s = 0;
    long long int e = n;
    long long int ans = -1;
    long long int mid = s+(e-s)/2;
    while(s<=e){
        mid = s+(e-s)/2;
        long long int sqr = mid*mid;
        if(sqr==n){
            return mid;
        }else if(sqr<n){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}

// ⭐️ koko eating bananas!
long long help(int mid,vector<int>&piles){
    long long hours = 0;
    for(int i=0;i<piles.size();i++){
        hours += ceil((double)piles[i]/(double)mid);
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int s = 1;
    int e = INT_MIN;
    for(int i=0;i<piles.size();i++){
        if(piles[i]>e){
            e = piles[i];
        }
    }
    int mid = s+(e-s)/2;
    while(s<=e){
        if(help(mid,piles)<=h){
            e = mid-1;
        }else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

// ⭐️ minimum no. of days to make m bouqets
int help(vector<int>&arr,int mid,int k){
	int count = 0;
	int day = 0;
	for(int i=0;i<arr.size();i++){
		 if(arr[i]<=mid){
			 count++;
		 }else{
			  day += (count/k);
			  count = 0;
		 }
	}
	day += (count/k);
	return day;
}

int roseGarden(vector<int> arr, int k, int m){
	if(k*m>arr.size()) return -1;
	int s = INT_MAX;
	int e = INT_MIN;
	for(int i=0;i<arr.size();i++){
		s = min(arr[i],s);
		e = max(arr[i],e);
	}
	int mid = s+(e-s)/2;
	while(s<=e){
		if(help(arr,mid,k)>=m){
			e = mid-1;
		}else{
			s = mid+1;
		}
		mid = s+(e-s)/2;
	}
	return s;
}

// Similar question --> Find the Smallest Divisor Given a Threshold

// ⭐️ Capacity to ship packages within D days!
int help(vector<int>&weights,int mid){
    int day = 1;
    int load = 0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>mid){
            day++;
            load = weights[i];
        }else{
            load += weights[i];
        }
    }
    return day;
}

int shipWithinDays(vector<int>& weights, int days) {
    int s = INT_MIN;
    int e = 0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]>s){
            s = weights[i];
        }
        e+= weights[i];
    }
    int mid = s+(e-s)/2;
    while(s<=e){
        if(help(weights,mid)<=days){
            e = mid-1;
        }else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int main(){

}