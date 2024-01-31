#include<bits/stdc++.h>
using namespace std;

// queue reversal (using stack or recursion)

// reverse first k elements in queue (using stack)

// interleave queue
void interleave(queue<int> &q){
    queue<int>a;
    int k = q.size()/2;
    int count = 0;
    while(count<=k){
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


int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    interleave(q);
    while(q.size()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}