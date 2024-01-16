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

// ⭐️ Tortoise algorithm questions!

// -> Middle of a LL (same question -> delete middle of LL!)
Node* middleNode(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Detect a loop in LL
bool detectCycle(Node *head){
	Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

// Starting point of loop in LL (similar question -> length of loop in LL!)
Node *firstNode(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

// remove loop in a LL!
Node *removeLoop(Node *head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            break;
        }
    }
    if(slow!=fast){
        return head;
    }
    prev = slow;
    while(prev->next!=slow){
        prev = prev->next;
    }
    prev->next = NULL;
    return head;
}

// Remove Nth node from end of list
Node* removeNthFromEnd(Node* head, int n) {
    Node* start = new Node(-1);
    start->next = head;
    Node* slow = start;
    Node* fast = start;
    while(n--){
        fast=fast->next;
    }
    while(fast && fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
}

int main(){

}