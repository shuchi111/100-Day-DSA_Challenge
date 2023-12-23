// Reverse First K elements of Queue

//company - microsoft

/*

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.



Approach -
Algorithm:

1. Initialization:
Create a stack st to store the first k elements.
Create a queue ans to store the modified queue.

2. Reverse First k Elements:

Iterate k times:
Push the front element of the original queue q onto the stack st.
Pop the front element from the original queue q.

3. Rebuild the Modified Queue:
Iterate until the stack st is not empty:
Push the top element of the stack st onto the queue ans.
Pop the top element from the stack st.
Iterate until the original queue q is not empty:
Push the front element of the original queue q onto the queue ans.
Pop the front element from the original queue q.

4. Return the Modified Queue:
Return the modified queue ans.

*/
//solution
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        queue<int> ans;
        stack<int> st;
        while(k--){
            st.push(q.front());
            q.pop();
            
            
        }
        while(!st.empty()){
            
            ans.push(st.top());
            st.pop();
            
        }
        
        while(!q.empty()){
            ans.push(q.front());
            q.pop();
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends