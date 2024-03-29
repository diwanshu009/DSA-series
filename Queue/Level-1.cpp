#include<bits/stdc++.h>
using namespace std;

// queue reversal (using stack or recursion)

// reverse first k elements in queue (using stack)

// interleave queue
void interleave(queue<int> &q){
    queue<int>a;
    int k = q.size()/2;
    int count = 0;
    while(count<k){
        int el = q.front();
        q.pop();
        a.push(el);
        count++;
    }
    while(a.size()){
        int el = a.front();
        a.pop();
        q.push(el);
        int el2 = q.front();
        q.pop();
        q.push(el2);
    }
    if(q.size()&1){
        int el = q.front();
        q.pop();
        q.push(el);
    }
}

// first negative element in k-size window
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

// first non-repeating character in a stream
string firstNonRepeatingChar(string s) {
    vector<int>arr(26,0);
    queue<char>q;
    string ans = "";
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        arr[ch-'a']++;
        q.push(ch);
        while(!q.empty()){
            if(arr[q.front()-'a']>1){
                q.pop();
            }else{
                ans += q.front();
                break;
            }
        }
        if(q.empty()){
            ans += "#";
        }
    }
    return ans;  
}

// ⭐️ Gas Station / Circular Tour
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0;
    int balance = 0;
    int deficit = 0;
    for(int i=0;i<gas.size();i++){
        balance += gas[i]-cost[i];
        if(balance < 0){
            deficit += balance;
            balance =0;
            start = i+1;
        }
    }
    if(deficit + balance >= 0){
        return start;
    }else{
        return -1;
    }
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

// Implement queue using stack (With the help of 2 stacks)!
// Implement stack using queue!
// ⭐️ Sum of Min and Max elements of all Subarrays of size K (Simliar approach done in sliding window pattern) !

// k queues in an array (Do try!)

int main(){
    
}