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

// ⭐️ Painter partition / Split array - Largest Sum
bool isPossible(vector<int>&boards,int mid,int k){
    int painters = 1;
    long long sum = 0;
    for(int i=0;i<boards.size();i++){
        if(sum+boards[i]>mid){
            painters++;
            if(painters>k || boards[i]>mid){
                return false;
            }
            sum = boards[i];
        }else{
            sum += boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k){
    int s = 0;
    int e = 0;
    for(int i=0;i<boards.size();i++){
        e += boards[i];
        s = max(s,boards[i]);
    }
    int mid = s+(e-s)/2;
    while(s<=e){
        if(isPossible(boards,mid,k)){
            e = mid-1;
        }else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

// ⭐️ Median of 2 sorted arrays!
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2) return findMedianSortedArrays(b, a);
    int n = n1 + n2; 
    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

// ⭐️ Find the peak element in a 2-D array!
int help(vector<vector<int>>&mat,int n,int mid){
    int maxi = -1;
    int index = -1;
    for(int i=0;i<n;i++){
        if(mat[i][mid]>maxi){
            maxi = mat[i][mid];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &mat){
    vector<int>ans;
    int s = 0;
    int e = mat[0].size()-1;
    int m = mat[0].size();
    int n = mat.size();
    int mid = s+(e-s)/2;
    while(s<=e){
        int maxIndex = help(mat,n,mid);
        int left = mid-1>=0 ? mat[maxIndex][mid-1] : -1;
        int right = mid+1<m ? mat[maxIndex][mid+1] : -1;
        if(mat[maxIndex][mid]>left && mat[maxIndex][mid]>right){
            return {maxIndex,mid};
        }else if(mat[maxIndex][mid]<left && mat[maxIndex][mid]>right){
            e = mid-1;
        }else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return {-1,-1};
}

int main(){

}