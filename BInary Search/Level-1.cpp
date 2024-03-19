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
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+= ceil((double)piles[i]/(double)mid);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=INT_MIN;
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

int main(){

}