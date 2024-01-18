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

int findLen(Node* &head){
    int len =0;
    Node* temp = head;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

// Medium Level questions!

// intersection of two linked lists!
Node* findIntersection(Node* firstHead, Node* secondHead){
    Node* a = firstHead;
    Node* b = secondHead;
    while(a!=b){
        a = a==NULL ? secondHead : a->next;
        b = b==NULL ? firstHead : b->next;
    }
    return a;
}

// check palindrome!
bool isPalindrome(Node* &head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp1 = head;
    Node* curr = slow->next;
    Node* prev = NULL;
    while(curr){
        Node* right = curr->next;
        curr->next = prev;
        prev = curr;
        curr = right;
    }
    slow->next = NULL;
    Node* temp2 = prev;
    while(temp1 && temp2){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

// odd-even Linked List!
Node* segregateEvenOdd(Node* &head){
    if(head==NULL || head->next==NULL) return head;
    Node* s;
    Node* a = NULL; // for even nodes!
    Node* s2;
    Node* b = NULL; // for odd nodes!
    Node* temp = head;
    while(temp){
        if(temp->data%2==0){
            if(a==NULL){
                s = temp;
                a = s;
            }else{
                a->next = temp;
                a = temp;
            }
        }else{
            if(b==NULL){
                s2= temp;
                b = s2;
            }else{
                b->next = temp;
                b = temp;
            }
        }
        temp = temp->next;
    }
    a->next = s2;
    b->next = NULL;
    return s; // first even nodes,then odd nodes!
}

// ⭐️ add two numbers!
Node* addTwoNumbers(Node* num1, Node* num2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;
    while(num1!=NULL || num2!=NULL || carry){
        int sum =0;
        if(num1){
            sum+=num1->data;
            num1=num1->next;
        }
        if(num2){
            sum+=num2->data;
            num2 = num2->next;
        }
        sum += carry;
        carry = sum/10;
        Node* newNode= new Node(sum%10);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}

// rotate a Linked List!
Node* rotate(Node* &head, int k){
    if(k==0 || head==NULL){
        return head;
    }
    int len = findLen(head);
    k = k%len;
    Node* temp = head;
    while(k--){
        temp = head;
        while(temp->next->next){
            temp=temp->next;
        }
        Node* curr=temp->next;
        curr->next=head;
        temp->next= NULL;
        head = curr;
    }
    return head;
}

// ⭐️ Merge Sort in Linked List!
Node* findMid(Node* &head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* &a,Node* &b){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(a && b){
        if(a->data<=b->data){
            temp->next = a;
            temp = a;
            a = a->next;
        }else{
            temp->next = b;
            temp = b;
            b = b->next;
        }
    }
    if(a){
        temp->next=a;
    }
    if(b){
        temp->next=b;
    }
    return dummy->next;
}

Node* sortList(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next=NULL;
    left = sortList(left);
    right = sortList(right);
    Node* ans = merge(left,right);
    return ans;
}

int main(){

}