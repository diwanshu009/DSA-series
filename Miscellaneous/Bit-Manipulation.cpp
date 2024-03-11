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

// ⭐️ check if the number is power of 2 or not!
bool check(int n){
    return (n&(n-1))==0;
}

// ⭐️ Minimum Bit flips bits to convert number!
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

// clear bits in a range ⭐️
int resetAllBitsInRange(int n, int l, int r) { // 1-based given!
	l = l-1;
	r = r-1;
	int a = -1 << (l+1);
	int b = (1 << r)-1;
	int mask = a|b;
	return (n&mask);
}

// ⭐️ Tip: Mask banao answer pao!

// Do Try --> single number (there is only one element which is appearing one time and other are 2 times!)

// Make subsequences using bitwise operators! --> T.C = O(2^N *N)
vector<string> getSubsequences(string& s) {
    vector<string>ans;
    int n = s.size();
    int m = 1<<n;
    for(int i=0;i<m;i++){
        string temp = "";
        for(int j=0;j<n;j++){
            int mask = 1<<j;
            if(i&mask){
                temp += s[j];
            }
        }
        if(temp.size()>0){
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// Single Number 2 (Find the number that is appearing once in the array where every other element appears 3 times!)
int singleNumber2(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    for(int i=0;i<nums.size();i++){
        ones = (ones^nums[i])&(~twos);
        twos = (twos^nums[i])&(~ones);
    }
    return ones;
}

// ⭐️ Single Number 3 (Find the 2 numbers that are appearing once where every others element appears 2 times!)
vector<int> singleNumber3(vector<int>& nums) {
    int b1 = 0;
    int b2 = 0;
    long long int xorr = 0;
    for(int i=0;i<nums.size();i++){
        xorr ^= nums[i];
    }
    long long int rightmost = (xorr&(xorr-1))^xorr;
    for(int i=0;i<nums.size();i++){
        if(nums[i]&rightmost){
            b1^=nums[i];
        }else{
            b2^=nums[i];
        }
    }
    return {b1,b2};
}

// ⭐️ Divide two numbers using bitwise operators!
int divideTwoInteger(int n, int d) {
	if(n==d) return 1;
    bool sign = true;
    if(n<0 && d>0) sign = false;
    if(n>0 && d<0) sign = false;
    long long int a = abs(n);
    long long int b = abs(d);
    int ans = 0;
    while(a>=b){
        int count = 0;
        while(a>=(b<<(count+1))){
            count++;
        }
        ans += 1<<count;
        a -= b<<count;
    }
    if(ans == (1<<31) && sign) return INT_MAX;
    if(ans == (1<<31) && !sign) return INT_MIN;
    return sign?ans:-ans;
} 

// ⭐️ Xor of given numbers in range!
int xorr(int n){
    if(n%4 == 1){
        return 1;
    }else if(n%4 == 2){
        return n+1;
    }else if(n%4 == 3){
        return 0;
    }else{
        return n;
    }
}

int findXOR(int L, int R){
    int a = xorr(L);
    int b = xorr(R);
    return a^b^L;
}

int main(){
    
}