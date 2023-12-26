// common element
/*

Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both the lists and return the list in sorted order. Duplicates may be there in the output list.

Example:

Input:
n = 5
v1[] = {3, 4, 2, 2, 4}
m = 4
v2[] = {3, 2, 2, 7}
Output:
2 2 3
Explanation:
The common elements in sorted order are {2 2 3}

Approach -

1. Function Definition:
common_element(v1, v2) takes two vectors v1 and v2.
Returns a vector containing common elements of v1 and v2.

2. Initialization:
Initialize an empty vector x.
Initialize a map map to store the frequency of elements in v1.
 Count Frequency in v1:
Iterate over elements of v1 and increment the count in map for each element.

3. Check for Common Elements:
Iterate over elements of v2.
If the count of the element in map is greater than or equal to 1, add the element to vector x, and decrement the count in map.

4. Sort the Result:
Sort vector x in ascending order.

5. Return Result:
Return the sorted vector x.

6. Main Function:
Call common_element with input vectors.
Print or return the result as needed.

7. Output:
Vector x contains common elements of v1 and v2.



*/
//solution
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        vector<int> x;
        map<int,int> map;
        for(int i=0;i<v1.size();map[v1[i++]]++);
        for(int i=0;i<v2.size();i++) if(map[v2[i]]>=1)  x.push_back(v2[i]),map[v2[i]]--;
        sort(x.begin(),x.end());
        return x;
   // Your code here
        
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}
// } Driver Code Ends


