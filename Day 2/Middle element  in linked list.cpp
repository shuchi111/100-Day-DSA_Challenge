/*
Find middle element of linked list



Algorithm of code -
1. Initialize Pointers:
Initialize two pointers, slow and fast, both pointing to the head of the linked list.

2. Traverse the List:
Iterate through the linked list using the following conditions:
Move slow one step at a time (slow = slow->next).
Move fast two steps at a time (fast = fast->next->next).

3.Find the Middle Node:
When the fast pointer reaches the end of the linked list (fast or fast->next is NULL), the slow pointer will be at the middle node.

4.Return the Middle Node's Data:
Return the data of the middle node (slow->data).

Approach -
Take two pointer -
Fast- 2 move 
Slow - 1 move
And move it according to below
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        Node* slow = head;
        Node* fast = head;
        while( fast && fast-> next){
            slow = slow-> next;
            fast = fast-> next->next;
            
        }
        return slow->data;
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends