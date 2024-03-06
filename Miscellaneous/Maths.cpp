#include<bits/stdc++.h>
using namespace std;

// Counting Divisors! (Better approach) T.C = O(sqrt(n))!
int divisors(int n){
    int count = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if(i!=n/i){
                count++;
            }
        }
    }
    return count;
}

// ⭐️ More better approach! T.C = O(nlog(n)), (printing no. of divisors from 1 to n)
void divisor(int n){
    vector<int>div(n+1,1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){ // In this, we are getting the numbers which will be divided by i in single iteration!
            div[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout << div[i] << " ";
    }
}

// program to check for prime no. (Brute)
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

// ⭐️ Sieve of Eratostheness! (Optimal approach to check prime) --> primes upto 'n'
vector<int> findAllPrimes(int n) { // T.C = O (nlog(log (n))) --> almost linear!
    vector<int>ans;
    long long int b = n;
    vector<int>prime(b+1,1);
    for(int i=2;i<=b;i++){
        if(!prime[i])continue;
        ans.push_back(i);
        for(int j=i*i;j<=b;j+=i){ // multiples of prime will never be primes!
            prime[j] = 0;
        }
    }
    return ans;
}

// ⭐️ Greatest commmon divisor of two numbers (Euclidean Algorithm!) // a<b
int gcd(int a,int b){ // T.C = O(log max(a,b)), In c++, we use __gcd(a,b) to implement this!
    if(a==0){ 
        return b;
    }
    return gcd(b%a,a);
}

// ⭐️ Binary Exponentian (T.C= O(log(b)))
int binPow(int a,int b,int m){ 
    if(b==0){
        return a%m;
    }
    if(b%2==0){
        int t = binPow(a,b/2,m);
        return ( (long long) t * t % m);
    }else{
        int t = binPow(a,((b-1)/2),m);
        t = ((long long) t*t%m);
        return ((long long) a*t %m);
    }
}

int main(){
    
}
