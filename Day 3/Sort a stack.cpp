//Sort a stack 
/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1

Algorithm:
Sort Operation (sort):
1. Create a min-heap (priority queue) to store the elements in ascending order.
2. While the original stack (s) is not empty:
Pop the top element from s.
Push the popped element into the min-heap.
3. While the min-heap is not empty:
Pop the top element from the min-heap.
Push the popped element back into the original stack (s)


*/
//Solution 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void SortedStack :: sort()
{
   //Your code here
  priority_queue <int, vector<int>, greater<int>> pq;
  while(!s.empty())
  {
      int curr = s.top();
      s.pop();
      pq.push(curr);
  }
  while(!pq.empty())
  {
      int curr = pq.top();
      pq.pop();
      s.push(curr);
  }
};

