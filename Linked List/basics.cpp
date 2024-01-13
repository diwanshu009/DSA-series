#include<bits/stdc++.h>
using namespace std;

// LinkedList can be defined as the collection of nodes where each node contains a data field and a reference to next node!
// It is also a linear data structure but elements are not stored in contiguous manner!
// It is of 4 types : Apne aap padh lena!!
// Magic line ⭐️ : LinkedList is Hindi!!

// Structure of node
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

// 1. How to take input from user and create a beautiful linked list!

//-->  Node* head = new Node(-1);
//     Node* temp = head;
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         int element;
//         cin >> element;
//         Node* newNode = new Node(element);
//         temp->next = newNode;
//         temp = newNode;
//     }
//     Node* curr = head;
//     while(curr){
//         cout << curr->data << " ";
//         curr = curr->next;
//     }
//     cout << endl;

// 2. Insertion at head, tail or at any position!
// 3. Deletion at head, tail or at any position!

// --> Problem solving starts!

// how to reverse a linked list!
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr = head;
    Node* right;
    while(curr){
        right = curr->next;
        curr->next = prev;
        prev = curr;
        curr = right;
    }
    return prev;
}

int main(){
    
}