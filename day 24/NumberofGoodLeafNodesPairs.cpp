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
    int ans = 0;
    vector<int> solve(TreeNode* root, int distance) {
        vector<int>cnt(distance + 1, 0);
        // number of leaf nodes at distance i
        if (!root) return cnt;
        // if it's a leaf node, it's 1 edge away from its parents
        if (!root->left && !root->right) {
            cnt[1] = 1;
            return cnt;
        }
        vector<int>left = solve(root->left, distance);
        vector<int>right = solve(root->right, distance);
        
        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance; j++) {
                if (i + j <= distance)
                    ans += (left[i] * right[j]);
            }
        }

        vector<int>current(distance + 1, 0);
        for (int i = 1; i < distance; i++) {
            current[i + 1] = left[i] + right[i];
        }
        return current;
    }
    int countPairs(TreeNode* root, int distance) {
        solve(root, distance);
        return ans;
    }
};
