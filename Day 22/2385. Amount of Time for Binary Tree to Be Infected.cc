//Solution
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
const int N = 100001;
vector<int>adj[N];
class Solution {
public:
    void makeNewTreeOfRootAsStart(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            makeNewTreeOfRootAsStart(root->left);
        }
        if (root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            makeNewTreeOfRootAsStart(root->right);
        }
    }
    void dfs(int root, int par, vector<int>&dp) {
        dp[root] = 1;
        for (auto child : adj[root]) {
            if (child == par)
                continue;
            dfs(child, root, dp);
            dp[root] = max(dp[root], 1 + dp[child]);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        // re-rooting root to start
        for (int j = 0; j < N; j ++)
            adj[j].clear();
        makeNewTreeOfRootAsStart(root);
        vector<int>dp(N, 0);
        int par = 0;
        dfs(start, par, dp);
        return dp[start] - 1;
    }
};

