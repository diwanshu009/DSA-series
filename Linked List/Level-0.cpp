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

// finding length of LL 
int findLen(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

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
    Node* prev = NULL;
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

// Delete duplicates from sorted list (good question)
Node* delDuplicate(Node* &head){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data == curr->next->data){
            Node* temp = curr ->next;
            Node* nxt_nxt = curr ->next ->next;
            free(temp);
            curr->next = nxt_nxt;
        }else {
            curr = curr->next;
        }
    }
   return head;
}

// ⭐️ reverse LL in group of size k (HARD but chindi!!)
Node* reverseKGroups(Node* &head,int k){
    if( head == NULL || head->next == NULL){
        return NULL;
    }
    int len = findLen(head);
    if(k>len){
        return head; // sometimes we have to reverse it!
    }else{
        Node* prev = NULL;
        Node* curr = head;
        Node* right;
        int i=0;
        while(i<k){
            right = curr->next;
            curr->next = prev;
            prev = curr;
            curr = right;
            i++;
        }
        if(right){
            head->next = reverseKGroups(right,k);
        }
        return prev;
    }
}

// we can also try all easy level linked list question. For e.g. -> Swap nodes in pairs, Binary LL to integer, etc.!

int main(){
    
}