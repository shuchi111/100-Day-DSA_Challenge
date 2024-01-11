//solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maximumDifferenceBetweenNodeAndAncestorDfs(TreeNode* root, int maxVal, int minVal)
    {
        if(root == nullptr)
            return 0;

        int returnVal = std::max(std::abs(root->val - maxVal), std::abs(root->val - minVal));

        if(root->val > maxVal)
        {
            maxVal = root->val;
        }
        else if(root->val < minVal)
        {
            minVal = root->val;
        }

        int leftSide = maximumDifferenceBetweenNodeAndAncestorDfs(root->left, maxVal, minVal);
        int rightSide = maximumDifferenceBetweenNodeAndAncestorDfs(root->right, maxVal, minVal);

        returnVal = std::max(leftSide, returnVal);
        returnVal = std::max(rightSide, returnVal);

        return returnVal;
    }

    int maxAncestorDiff(TreeNode* root) {
        
        int returnVal = maximumDifferenceBetweenNodeAndAncestorDfs(root, root->val, root->val);

        return returnVal;
    }
};
