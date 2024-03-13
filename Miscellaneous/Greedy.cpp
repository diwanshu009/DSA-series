/* Greedy algorithms are a class of algorithms that make locally optimal choices at each step with the hope of 
  finding a global optimum solution. In these algorithms, decisions are made based on the information available at the 
  current moment without considering the consequences of these decisions in the future. The key idea is to select the
  best possible choice at each step, leading to a solution that may not always be the most optimal but is often good 
  enough for many problems.
*/

#include<bits/stdc++.h>
using namespace std;

// ⭐️ N-meeting in one room
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second < b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end){
   int n = start.size();
   vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        pair<int,int>p = {start[i],end[i]};
        arr.push_back(p);
    }
    sort(arr.begin(),arr.end(),cmp);
    int ans = 1;
    int last = arr[0].second;
    for(int i=1;i<arr.size();i++){
        if(arr[i].first>last){
            ans++;
            last = arr[i].second;
        }
    }
    return ans;
}

// ⭐️ Minimum and maximum cost to buy N candies! (we are getting k candies free after buying one candy)
long long minimumCost(vector<int> &cost, int n, int k){
    long long ans = 0;
    sort(cost.begin(),cost.end());
    int i = 0;
    int j = n-1;
    while(i<=j){
        ans+=cost[i];
        i++;
        j-=k;
    }
    return ans;
}
long long maximumCost(vector<int> &cost, int n, int k){
    long long ans = 0;
    sort(cost.begin(),cost.end());
    int i = 0;
    int j = n-1;
    while(i<=j){
        ans += cost[j];
        i+=k;
        j--;
    }
    return ans;
}

// ⭐️ Fractional KnapSack problem!
bool cmp(pair<int,int>a,pair<int,int>b){
    double r1 = ((1.0)*b.first)/a.first;
    double r2 = ((1.0)*b.second)/a.second;
    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    sort(items.begin(),items.end(),cmp);
    double ans = 0;
    for(int i=0;i<items.size();i++){
        if(w>=items[i].first){
            ans += items[i].second;
            w -= items[i].first;
        }else{
            double r = ((1.0)*items[i].second)/items[i].first;
            double val = r*w;
            ans += val;
            break;
        }
    }
    return ans;
}

// ⭐️ Chocolate distibution Problem!
int findMinDiff(int n, int m, vector<int> chocolates) {
    sort(chocolates.begin(),chocolates.end());
    int i = 0;
    int j = m-1;
    int diff = INT_MAX;
    while(j<n){
        diff = min(diff,chocolates[j]-chocolates[i]);
        j++;
        i++;
    }
    return diff;
}

int main(){

}