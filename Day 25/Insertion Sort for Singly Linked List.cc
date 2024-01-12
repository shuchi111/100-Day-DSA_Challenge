//Insertion Sort for Singly Linked List
/*
Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 
11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.


1. If the input linked list is empty or has only one node, return the head as the sorted linked list.
2. Create a dummy node and set it as the head of the sorted linked list.
3. Initialize temp as the head of the input linked list and it as the node next to temp.
4. Iterate through the input linked list until it is not null.
Inside the loop, create a new node curr and set it as it.
Update it to the next node.
Set the next of curr to null.
Initialize prev as the dummy node.
Iterate through the sorted linked list until temp is not null.
If the data of temp is greater than or equal to the data of curr, break the loop.
Update temp to the next node.
Update prev to the next node.
Set the next of prev to curr.
Set the next of curr to temp.
Update temp to the head of the sorted linked list.
Update it to the next node.
5. Return the next of the dummy node as the head of the sorted linked list.

*/

//Solution

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/


    
    class Solution
{
    public:
    Node* insertionSort(struct Node* head){
        //code here
        if(!head || !head->next) return head;
        
        Node* dummy=new Node(-1);
        dummy->next=head;
        Node* temp=head;
        Node* it=head->next;
        head->next=NULL;
        
        while(it){
            Node* curr=it;
            Node* next=curr->next;
            curr->next=NULL;
            
            Node* prev=dummy;
            while(temp){
                if(temp->data >= curr->data) break;
                temp=temp->next;
                prev=prev->next;
            }
            prev->next=curr;
            curr->next=temp;
            
            temp=dummy->next;
            it=next;
        }
        
        return dummy->next;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
