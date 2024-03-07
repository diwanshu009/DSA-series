#include<bits/stdc++.h>
using namespace std;

/* The Two Pointers Method is an important technique that is often used in competetive programming.
What is this method? The easiest way to explain it is with the example of the task "Merging two sorted arrays". */

// merging two sorted arrays!
vector<int> merge(vector<int>&a,vector<int>&b){ 
    int i = 0;
    int j = 0;
    vector<int>temp;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            temp.push_back(a[i]);
            i++;
        }else{
            temp.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        temp.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        temp.push_back(b[j]);
        j++;
    }
    return temp;
}

// calculating number of elements in array1 which are smaller than elements in array2
int inversion(vector<int>&a,vector<int>&b){ // will fix this!
    int i = 0;
    int j = 0;
    int ans = 0;
    vector<int>temp;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            temp.push_back(a[i]);
            i++;
        }else{
            ans += a.size()-i;
            temp.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        temp.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        temp.push_back(b[j]);
        j++;
    }
    return ans;
}


int main(){
    vector<int>a{1,3,4,5};
    vector<int>b{2,4,6,8};
    cout << inversion(a,b) << endl;
}