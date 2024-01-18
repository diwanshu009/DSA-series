// This level can overwhelm you, so first make sure you have gone through previous levels!

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* right;
    while(curr){
        right = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = right;
    }
    return prev;
}

// ⭐️ add one number to a LinkedList!
Node* addOne(Node* &head){
    Node* curr = reverse(head);
    Node* temp = curr;
    int carry = 1;
    Node* dummy = new Node(-1);
    Node* ongo = dummy;
    while(temp || carry){
        if(temp==NULL && carry){
            ongo->next = new Node(carry);
            ongo = ongo->next;
            break;
        }
        int sum = temp->data+carry;
        carry = sum/10;
        sum = sum%10;
        Node* newNode = new Node(sum);
        ongo->next = newNode;
        ongo = ongo->next;
        temp = temp->next;
    }
    Node* ans = reverse(dummy->next);
    return ans;
}

// flatten a Linked List!


// clone a LinkedList with random and next pointers!


// design a browser history!


int main(){

}