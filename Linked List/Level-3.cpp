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

// ⭐️ design a browser history! --> 

// class Node {
//     public:
//     string data;
//     Node *next, *prev;
//     Node() : data(0), next(NULL), prev(NULL) {}
//     Node(string x) : data(x), next(NULL), prev(NULL) {}
//     Node(string x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
// };

// class Browser{
//     Node* curr;
//     public:
//     Browser(string &homepage){
//         curr = new Node(homepage);
//     }

//     void visit(string &url){
//         Node* newNode = new Node(url);
//         curr->next = newNode;
//         newNode->prev = curr;
//         curr = newNode;
//     }

//     string back(int steps){
//         while(steps){
//             if(curr->prev){
//                 curr = curr->prev;
//             }else{
//                 break;
//             }
//             steps--;
//         }
//         return curr->data;
//     }

//     string forward(int steps){
//         while(steps){
//             if(curr->next){
//                 curr = curr->next;
//             }else{
//                 break;
//             }
//             steps--;
//         }
//         return curr->data;
//     }
// };

int main(){

}