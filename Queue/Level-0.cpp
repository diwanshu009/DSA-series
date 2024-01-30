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
		// can also check whether the queue is full or not!
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

// circular queue
class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value){
        if((front == 0 && rear == size -1) || ( (rear+1)%size == front) ){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear]= value;
        return true;
    }

    int dequeue(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
};

int main(){

}