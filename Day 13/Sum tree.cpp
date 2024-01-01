// Sum tree
/*

Example 1:

Input:
    3
  /   \    
 1     2

Output: 1
Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.


Approach -


*/
//Solution
User
Keshav Prasad
4 days ago

class Solution
{
    public:
    
    pair<int, bool> solve(Node *root){
        if(!root) return {0, true};
        if(!root->left && !root->right) return {root->data, true};
        
        pair<int, bool> leftPart = solve(root->left);
        pair<int, bool> rightPart = solve(root->right);
        
        int currVal = root->data;
        int totalVal = leftPart.first + rightPart.first + currVal;
        bool isSum = leftPart.first + rightPart.first == currVal && leftPart.second && rightPart.second;
        
        return {totalVal, isSum};
    }
    
    bool isSumTree(Node* root)
    {
        return solve(root).second;
    }
};