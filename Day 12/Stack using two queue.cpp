// Stack using two queues
/*

Implement a Stack using two queues q1 and q2.

Example 1:

Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  


Approach -

Algorithm:
Push Operation (push method):
1. Move all elements from q2 to q1.
2. Push the new element (x) to q2.
3. Move all elements back from q1 to q2.
This ensures that the newly pushed element is always at the front of q2, simulating the behavior of a stack.

Pop Operation (pop method):
1. If q2 is empty, return -1 (indicating underflow).
2. Otherwise, return the front element of q2 and pop it.


*/

//solution

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */




void QueueStack :: push(int x)
{
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int temp = (q2.empty()) ? -1 : q2.front();
    if(temp != -1){
        q2.pop();
    }
    return temp;
}



