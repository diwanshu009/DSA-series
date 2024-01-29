/* Queue is a linear data structure that follows a particular order (FIFO) in which the operations are performed on 
    different ends!

Implementaion : 1. Using STL( #include<queue> )
2. Using Classes( using arrays and Linked Lists! )

*/

#include<bits/stdc++.h>
using namespace std;

// implementation of queue using arrays with classes!
class Queue {

	int front, rear;
	vector<int> arr;

    public:

	Queue(){
		front = -1;
		rear = -1;
		arr.resize(100001);
	}

	void enqueue(int e){
		if(front == -1 || rear == -1){
			front = 0;
			rear = 0;
		}
		arr[rear] = e;
		rear++;
	}
    
	int dequeue(){
		if(front == rear || front == -1){
			return -1;
		}
		int ans = arr[front];
		front++;
		return ans;
	}
};

int main(){

}