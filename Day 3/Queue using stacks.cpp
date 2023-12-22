// Queue using two stacks
/*

Input:
5
1 2 1 3 2 1 4 2

Output: 
2 3



Algorithm:
1. Push Operation (push):
Push the given element onto s1.
Pop Operation (pop):
i. If both s1 and s2 are empty, return -1.
ii. If s2 is not empty, pop the top element from s2 and return it.
iii. If s2 is empty but s1 is not:
Transfer all elements from s1 to s2 one by one.
Pop the top element from s2 and return it.
*/

//solution

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}

// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code 
        if(s1.size()==0){
            return -1;
        }
        while(!s1.empty()){
            int val1=s1.top();
            s1.pop();
            s2.push(val1);
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            int val2=s2.top();
            s2.pop();
            s1.push(val2);
        }
        return ans;
      
}
