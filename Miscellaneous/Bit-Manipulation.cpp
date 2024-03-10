#include<bits/stdc++.h>
using namespace std;

// swap 2 numbers -->
void swap(int a,int b){
    a = a^b;
    b = a^b;
    a = a^b;
    cout << a << " " << b << endl;
}

// get the ith-bit! (0-based), for 1-based we will use i = i-1
void get(int n,int i){
    n = n >> i;
    cout << (n&1) << endl;
}

// set i-th bit!
void set(int n,int i){
    int f = 1 << i;
    cout << (n|f) << endl;
}

// clear the i-th bit
void clear(int n,int i){
    int f = 1 << i;
    int b = ~f;
    cout << (n&b) << endl;
}

// toggle the i-th bit! (reverse the i-th bit)
void toggle(int n,int i){
    int f = 1<<i;
    cout << (n^f) << endl;
}

// Remove the last set bit! (rightmost)
void remove(int n){
    cout << (n&(n-1)) << endl;
}

// count the number of set bits!
int count(int n){
    // Approach 1 : T.C = O(log N)
    // int count = 0;
    // while(n>1){
    //     if(n&1){
    //         count++;
    //     }
    //     n = n >> 1;
    // }
    // return count;

    // ⭐️ Approach 2 : T.C = O(No. of Set Bits)
    int count = 0;
    while(n!=0){
        count++;
        n = n&(n-1);
    }
    return count;
}

// check if the number is power of 2 or not!
bool check(int n){
    return (n&(n-1))==0;
}

// Minimum Bit flips bits to convert number!
int minBitFlips(int start, int goal) {
    int count = 0;
    int n = start^goal;
    while(n!=0){
        count++;
        n = n&(n-1);
    }
    return count;
}

// clear last i bits!
void clearLast(int n,int i){
    int mask = (-1)<<i;
    cout << (n&mask) << endl;
}

// Do Try --> single number (there is only one element which is appearing one time and other are 2 times!)

// Single Number 2


int main(){
    
}