//  Array to BST

/*
Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST). Find the preorder traversal of height balanced BST. If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.
Height balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Example 1:

Input: nums = {1, 2, 3, 4}
Output: {2, 1, 3, 4}
Explanation: 
The preorder traversal of the following 
BST formed is {2, 1, 3, 4}:
           2
         /   \
           1     3
               \
                4
 

Example 2:

Input: nums = {1,2,3,4,5,6,7}
Ouput: {4,2,1,3,6,5,7}
Explanation: 
The preorder traversal of the following
BST formed is {4,2,1,3,6,5,7} :
        4
       / \
      2   6
     / \  / \
    1   3 5  7




Approach -

Algorithm:

1. Input: nums (sorted array representing the BST nodes).
2. Initialize an empty vector res.
3. Define a helper function solve:
If l > r, return.
Calculate mid as (l + r) / 2.
Add nums[mid] to the result vector res.
Recursively call solve for the left half (l, mid-1) and the right half (mid+1, r).
4. Call the solve function with the initial parameters (nums, res, 0, nums.size()-1).
5. Return the result vector res.
*/

// solution

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void solve(vector<int> nums,vector<int> &res,int l,int r)
   {
       if(l>r) return ;
       int mid = (l+r)/2;
       
       res.push_back(nums[mid]);
       
       solve(nums,res,l,mid-1);
       solve(nums,res,mid+1,r);
   }
    vector<int> sortedArrayToBST(vector<int>& nums) {
       vector<int> res;
       solve(nums,res,0,nums.size()-1);
       return res;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
