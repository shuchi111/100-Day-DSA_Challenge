/*
Example:
Example 1:

Input:
s = "Bawds jog, flick quartz, vex nymph"
Output: 
1
Explanation: 
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.

Algorithm:
1. Create an array arr of size 26, initialized to all zeros. This array will be used to track the occurrence of each letter in the alphabet.
2. Iterate through each character in the input string s.
3. For each non-space character, update the corresponding index in the array arr based on the ASCII value of the character.
If the character is an uppercase letter ('A' to 'Z'), subtract 65 from its ASCII value to get the index.
If the character is a lowercase letter ('a' to 'z'), subtract 97 from its ASCII value to get the index.
Set the value at the calculated index in arr to 1.
4. After processing all characters, check if there is any index in arr that still has a value of 0. If any index has a value of 0, then the string is not a pangram.
5. If all indices have a value of 1, return true, indicating that the string is a pangram.

Panagram Number:
ere's an example of a pangram: "The quick brown fox jumps over a lazy dog." This sentence contains every letter of the alphabet at least once.

  */

//solution 
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!= ' ')
            {
              if(s[i]-65 < 26)
              {
                    
                    
                    int j=s[i]-65;
                    arr[j]=1;
              }
              else 
              {
                    int j=s[i]-97;
                    arr[j]=1;
              }
            }
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0)
                return 0;
        }
        return 1;
        
        
    }
};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends
