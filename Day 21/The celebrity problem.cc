// the celebrity problem 
/*


Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 


Algorithm:

1. Create a check array to track potential celebrities (initialize with 1).
2. For each person (i) in the party:
If already marked as not a celebrity, continue.
Check if i knows anyone (M[i][j] is 1 for some j). If yes, mark i as not a celebrity and break the loop.
If i doesn't know anyone, mark all others who know i as not a celebrity.
Check if everyone else knows i. If not, mark i as not a celebrity.
If i passes all checks, return i as a potential celebrity.
3. If no potential celebrity found, return -1.


  */



//Solution

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

    //Function to find if there is a celebrity in the party or not.
    class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    //nice code darling 
    int celebrity(vector<vector<int> >& M, int n) 
    {
       vector<int> check(n,1);
       for(int i=0;i<n;i++){
           //pehle row
           if(!check[i]) continue;
           bool flag=true;
           int save=i;
           for(int j=0;j<n;j++){
               if(i==j) continue;
               if(M[i][j]){
                   check[i]=0;
                   flag=false;
                   break;
               }
               check[j]=0;
           }
           if(!flag) continue;
           //column
            for(int j=0;j<n;j++){
               if(i==j) continue;
               if(!M[j][i]){
                   check[i]=0;
                   flag=false;
                   break;
               }
               check[j]=0;
           }
           
           if(flag) return i;
       }
       return -1;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
