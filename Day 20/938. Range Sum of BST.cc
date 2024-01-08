//938. Range Sum of BST
/*
The rangeSumBST function takes a TreeNode* pointer root representing the root of the BST, along with low and high representing the range limits.
The dfs (depth-first search) function is a recursive function that takes a TreeNode* parameter. It calculates the sum of values within the specified range in a recursive manner.
If the current node is null (!root), the function returns 0.
The function checks if the current node's value is within the range [l, r]. If true, it adds the current node's value to the sum; otherwise, it adds 0.
The function then recursively calls itself for the left and right children of the current node.
The sum of values within the specified range is obtained by summing the current node's value, the result of the recursive call on the left subtree, and the result of the recursive call on the right subtree.
The rangeSumBST function sets the range limits (l and r) and initiates the DFS from the root, returning the final sum.


*/
//Solutiom
class Solution {
    int l, r; // Variables to store the low and high range limits

    // Recursive DFS function to calculate the sum of values within the given range
    int dfs(TreeNode* root) {
        if (!root) return 0; // If the current node is null, return 0

        // Check if the current node's value is within the specified range [l, r]
        // If true, add the current node's value to the sum, otherwise, add 0
        return ((root->val >= l) && (root->val <= r)) * root->val + dfs(root->left) + dfs(root->right);
    }

public:
    // Public function to initiate the calculation
    int rangeSumBST(TreeNode* root, int low, int high) {
        l = low, r = high; // Set the range limits
        return dfs(root);   // Start DFS from the root and return the sum
    }
};
