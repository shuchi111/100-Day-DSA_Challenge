//872. Leaf-Similar Trees
/*

Algorithm:

1. Define a recursive function collectLeafValues to traverse the tree and collect leaf node values.
2. In the function, if the current node is a leaf node, add its value to the leafValues vector.
3. Recursively call the function for the left and right children of the current node.
4. Initialize two vectors leafValues1 and leafValues2.
5. Call collectLeafValues for both root1 and root2.
6. Return true if leafValues1 is equal to leafValues2, otherwise return false.

  */



//Solution
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        function<void(TreeNode*, vector<int>&)> collectLeafValues =
            [&](TreeNode* root, vector<int>& leafValues) {
                if (!root) {
                    return;
                }
                if (!root->left && !root->right) {
                    leafValues.push_back(root->val);
                }
                collectLeafValues(root->left, leafValues);
                collectLeafValues(root->right, leafValues);
            };

        vector<int> leafValues1, leafValues2;
        collectLeafValues(root1, leafValues1);
        collectLeafValues(root2, leafValues2);

        return leafValues1 == leafValues2;
    }
};
