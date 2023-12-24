//  Print all nodes that don't have sibling
/*

Given a Binary Tree of size N, find all the nodes which don't have any sibling. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order.

Two nodes are said to be siblings if they are present at the same level, and their parents are same.

Note: Root node can not have a sibling so it cannot be included in our answer.

Example 1:

Input :
       37
      /   
    20
    /     
  113 

Output: 20 113
Explanation: 20 and 113 dont have any siblings.


Algorithm -

*/

//solution
// 20/70 test cesses passed

//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void solve(Node *root,vector<int>&v){
    if(!root)return;
    if(!root->left and root->right)
    v.push_back(root->right->data);
    if(!root->right and root->left)
    v.push_back(root->left->data);
    solve(root->left,v);
    solve(root->right,v);
}
vector<int> noSibling(Node* node)
{
    vector<int>ans;
    solve(node,ans);
    sort(ans.begin(),ans.end());
    if(ans.empty())return {-1};
    return ans;
}