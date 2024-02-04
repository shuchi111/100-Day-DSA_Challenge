//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* reverse(Node* head) {
        if (head == NULL || head->next == NULL) return head;
            
        Node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
 
        return rest;
    }
    Node* helper(Node* head1, Node* head2){
        Node* ans = new Node(-1);
        Node* head = ans;
        int carry = 0, curr;
        
        while(head1 || head2){
            if(head2 && !head1) return NULL;
            
            curr = head1->data - carry - (head2 ? head2->data : 0);
            carry = 0;
            if(curr<0){
                carry=1;
                curr+=10;
            }
            
            head->next = new Node(curr);
            head = head->next;
            
            if(head1) head1 = head1->next;
            if(head2) head2 = head2->next;
        }
        return carry ? NULL : reverse(ans->next);
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        while(head1 && head1->data==0) head1=head1->next;
        while(head2 && head2->data==0) head2=head2->next;
        
        Node* rev1 = reverse(head1);
        Node* rev2 = reverse(head2);
        
        Node* ans1 = helper(rev1, rev2);
        Node* ans2 = helper(rev2, rev1);
        
        while(ans1 && ans1->data==0) ans1=ans1->next;
        while(ans2 && ans2->data==0) ans2=ans2->next;
        
        return ans1 ? ans1 : ans2 ? ans2 : new Node(0);
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends
