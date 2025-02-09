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
    int ans = INT_MIN;
    vector<int>solve(TreeNode* node) {
        if (!node) return {INT_MAX, INT_MIN, 0};
        vector<int>leftSub = solve(node->left);
        vector<int>rightSub = solve(node->right);

        if (node->val <= leftSub[1] || node->val >= rightSub[0]) 
            return {INT_MIN, INT_MAX, 0};

        ans = max(ans, leftSub[2] + rightSub[2] + node->val);
        return {min(node->val, leftSub[0]), max(rightSub[1], node->val), leftSub[2] + rightSub[2] + node->val};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        if (ans < 0) return 0;
        else return ans;
    }
};
