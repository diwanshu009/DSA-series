#include<bits/stdc++.h>
using namespace std;

// 1. fixed window size
   // -->  first negative element in k-size window
vector<int> firstNegative(vector<int> &arr, int n, int k) {
	vector<int>ans;
	deque<int>q;
	for(int i=0;i<k;i++){
		if(arr[i]<0){
			q.push_back(i);
		}
	}
	for(int i=k;i<n;i++){
		if(q.empty()){
			ans.push_back(0);
		}else{
			ans.push_back(arr[q.front()]);
		}
		while((!q.empty()) && (i-q.front()>=k)){
			q.pop_front();
		}
		if(arr[i]<0){
			q.push_back(i);
		}
	}
	if(q.empty()){
		ans.push_back(0);
	}else{
		ans.push_back(arr[q.front()]);
	}
	return ans;
}

// ⭐️ Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>ans;
    deque<int>q;
    int n = nums.size();
    for(int i=0;i<k;i++){
        while(!q.empty() && nums[i]>=nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
    for(int i=k;i<n;i++){
        if(!q.empty() && i-q.front()>=k){
            q.pop_front();
        }
        while(!q.empty() && nums[i]>=nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

// 2. Two pointer Approach
vector<int> twoSum(vector<int>& num, int target) {
    vector<int>ans;
    int i = 0;
    int j = num.size()-1;
    while(i<=j){
        if(num[i]+num[j] == target){
            ans.push_back(i+1);
            ans.push_back(j+1);
            break;
        }else if(num[i]+num[j]<target){
            i++;
        }else{
            j--;
        }
    }
    return ans;
}

// 3. ⭐️ Variable size Window!
  // --> Minimum length of the Subarray having sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0;
    int j = 0;
    int len = INT_MAX;
    int sum = 0;
    while(j < nums.size()){
        sum += nums[j];
        while(sum >= target){
            len = min(len,j-i+1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if(len != INT_MAX) return len;
    return 0;
}

// Length of longest Substring without repeating characters!
int lengthOfLongestSubstring(string &s) {
    int ans = 0;
    int i = 0;
    int j = 0;
    unordered_map<char,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        while(mp[s[j]]>1){
            mp[s[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}

// 4. Optimised Sliding Window! (External Data Strcuture)
   // --> ⭐️ Minimum Window Substring (HARD)
string minWindow(string s, string t) {
    unordered_map<char,int>patMap;
    unordered_map<char,int>strMap;
    if(s.size() < t.size()) return "";
    int i = 0;
    int start = 0;
    int len2 = t.size();
    int len = INT_MAX;
    string ans;
    for(int i=0;i<t.size();i++){
        patMap[t[i]]++;
    }
    int count = 0;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        strMap[ch]++;
        if(strMap[ch] <= patMap[ch]){
            count++;
        }
        if(count == len2){
            while(strMap[s[start]] > patMap[s[start]] || patMap[s[start]] <= 0){
                if(strMap[s[start]] > patMap[s[start]]){
                    strMap[s[start]]--;
                }
                start++;
            }
            if(i-start+1 < len){
                len = i-start+1;
                ans = s.substr(start,len);
            }
        }
    }
    if(len != INT_MAX) return ans;
    return "";
}

int main(){

}