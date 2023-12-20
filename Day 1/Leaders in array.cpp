// Leaders in an array
/*

An element is a leader if it is strictly greater than all the elements to its right side.

 Approach -
 
 Initialize Variables:

Initialize an empty vector res to store the leaders.
Traverse Array from Right to Left:

Start iterating from the rightmost element (i = n-1) to the leftmost element (i = 0).
Initialize max_from_right to the rightmost element (a[n-1]).
Check for Leaders:

For each element at index i, check if it is greater than or equal to max_from_right.
If true:
Update max_from_right to the current element.
Add the current element to the vector res (as it is a leader).
Reverse the Vector:

After the loop, reverse the vector res to maintain the original order of leaders.
Return Result:

Return the vector res containing the leaders.


*/

//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    
class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> res;
        int max_from_right = a[n-1];
        for (int i = n-1; i >= 0; i--)
        {
            if (a[i] >= max_from_right)
            {
                max_from_right = a[i]; 
                res.push_back(max_from_right); 
            }
        }
        reverse(res.begin(), res.end()); 
        return res;
    }
};

   

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends

