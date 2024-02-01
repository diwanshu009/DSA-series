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

int main(){
    
}