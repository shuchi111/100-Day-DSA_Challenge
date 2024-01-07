//Reverse a Linked List in groups of given size

/*

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.


1. Structure: Define a node structure for the linked list.

2. Print Function: Implement a function to print linked list elements.

3. Reverse Helper (Recursive):
Base case: If k == 1, reverse the current group and update pointers.
Recursively reverse the next group, adjusting pointers accordingly.
Reverse Function:

Create a dummy node and initialize tail.
Iterate through the list, reverse each group using the helper, and update tail.

4. Main Program:

Read the number of test cases t.
For each test case:
Read n (size of linked list) and create the linked list.
Read k (group size).
Reverse the linked list in groups of size k.
Print the modified linked list.
*/
//Solution
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/


    class Solution
{
    public:
    // Helper recursive function which will reverse the given number of nodes
    // And return new head, new tail and pointer to the next node from where we start reversing the list again
    node *reverseHelper (node *head, int k, int v, node **nextOccurance, node **newTail) {
        node *temp;
        
        // If k==1, then we don't need to reverse the list as reverse by itself
        // So the result would be the same
        if (k == 1){
            *nextOccurance = head->next;
            *newTail = head;
            return head;
        }
        
        // When v becomes equal to k or nextOccurance/ head comes as NULL
        if (head == NULL || v == k){
            return head;
        }
        
        // Pass nextOccurance = NULL, to stop while loop in reverseIt function
        if (head->next == NULL){
            *nextOccurance = NULL;
            *newTail = head;
            return head;
        }
        
        temp = reverseHelper(head->next, k, ++v, nextOccurance, newTail);
        
        // So that the nextOccurance will not change while back tracking
        if(v == k) {
            *nextOccurance = temp->next;
        }
        
        // Reverse the nodes
        head->next->next = head;
        head->next = NULL;
        
        // New tail
        *newTail = head;

        // New head
        return temp;
    }
    
    struct node *reverseIt (struct node *head, int k)
    {
        node *newTail, *nextOccurance = head;
        node *dummy = new node(-1);
        node *tail = dummy;
        
        while (nextOccurance != NULL) {
            tail->next = reverseHelper(nextOccurance, k, 1, &nextOccurance, &newTail);
            tail = newTail;
        }
        
        return dummy->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends


