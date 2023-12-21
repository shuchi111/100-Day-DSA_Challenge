//Reverse a linked list
/*
Problem -
Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Approach -
Initialization:

Initialize three pointers, current, prev, and forward.
current points to the current node being processed.
prev points to the previous node in the reversed list.
forward is used to store current->next for later use.
Iterative Reversal:

Use a while loop to traverse the original linked list until current becomes NULL.
Inside the loop:
Store current->next in forward.
Update current->next to point to the previous node (prev).
Move prev to current and current to forward.
Return Head of Reversed List:

After the loop, the prev pointer is pointing to the new head of the reversed list.
Return prev as the head of the reversed linked list.

*/

//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
   struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* current = head;
        Node* prev = NULL;
        
        while(current != NULL){
            Node* forward = current->next; //storing the current->next for later use
            current->next = prev;
            prev = current;
            current = forward;
        }
        
        return prev;
    }


    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        if(n!=0)
        {
            cin>>firstdata;
            head = new Node(firstdata);
            tail = head;
        }
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends