/* Stack is a linear data structure that follows a particular order (LIFO) in which the operations are performed!

Implementaion : 1. Using STL( #include<stack> )
2. Using Classes( using arrays and Linked Lists! )

*/

#include<bits/stdc++.h>
using namespace std;

// implementation of stack using classes!
class Stack {
    public:

    int size;
    int topp;
    int* arr;

    Stack(int size) {
        arr = new int[size];
        this->topp=-1;
        this->size = size;
    }

    void push(int num) {
        if(topp!=size-1){
            topp++;
            arr[topp] = num;
        }
    }

    int pop() {
        if(topp==-1){
            return -1;
        }
        return arr[topp--];
    }
    
    int top() {
        if(topp==-1){
            return -1;
        }
        return arr[topp];
    }
    
    int isEmpty() {
        if(topp==-1){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(topp==size-1){
            return 1;
        }
        return 0;
    }
};

// Implement two stacks using an array!

// middle element in a stack!
int middle(stack<int>&st,int size){
    if(size/2+1 == st.size()){
        return st.top();
    }
    int temp = st.top();
    st.pop();
    return middle(st,size);
    st.push(temp);
}

// inserting the element to the bottom of the stack!
void bottom(stack<int>&st,int target){
    if(st.size()==0){
        st.push(target);
        return;
    }
    int temp = st.top();
    st.pop();
    bottom(st,target);
    st.push(temp);
}

// reversing the stack!
void reverse(stack<int>&st){
    if(st.size()==0){
        return;
    }
    int temp = st.top();
    st.pop();
    reverse(st);
    bottom(st,temp);
}

int main(){
    
}