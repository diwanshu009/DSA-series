#include<bits/stdc++.h>
using namespace std;

// ⭐️ Thode hard sawal!

// ⭐️ Aggressive Cows!
bool help(vector<int>&stalls,int mid,int k){
    int count = 1;
    int dist = stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-dist>=mid){
            count++;
            dist = stalls[i];
        }
        if(count==k){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(),stalls.end());
    int s = 0;
    int n = stalls.size();
    int e = stalls[n-1]-stalls[0];
    int mid = s+(e-s)/2;
    while(s<=e){
        if(help(stalls,mid,k)){
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return e;
}

// ⭐️ Book Allocation!
bool isPossible(vector<int>& arr,int n,int m,int mid){
    int student = 1;
    int pageSum = 0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i] > mid){
            student++;
            if(arr[i]>mid|| student>m){
                return false;
            }
            pageSum = arr[i];
        }else{
            pageSum += arr[i];
        }
    }
    return true;
}
    
int allocateBooks(vector<int>& arr, int n, int m) {
    int s = 0; // m--> no. of students!
    int e = 0; // n--> no. of books!
    for(int i=0;i<n;i++){
        e += arr[i];
    }
    int mid = s+(e-s)/2;
    if(n<m){
        return -1;
    }
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
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