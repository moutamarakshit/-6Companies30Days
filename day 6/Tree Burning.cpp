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
    void makeAdjList(TreeNode* root, unordered_map<int, vector<int>>& mpp) {
        if (!root) return;
        if (root->left) {
            mpp[root->val].push_back(root->left->val);
            mpp[root->left->val].push_back(root->val);
        }
        if (root->right) {
            mpp[root->val].push_back(root->right->val);
            mpp[root->right->val].push_back(root->val);
        }
        makeAdjList(root->left, mpp);
        makeAdjList(root->right, mpp);
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root->left && !root->right) return 0;
        unordered_map<int, vector<int>>mpp;
        makeAdjList(root, mpp);
        int t = 0;
        queue<pair<int,int>>q;
        q.push({start,0});
        unordered_set<int>st;
        st.insert(start);
        while (!q.empty()) { 
            int node = q.front().first;;
            t = q.front().second;
            q.pop();
            for (auto it: mpp[node]) {
                if (st.find(it) == st.end()) {
                    st.insert(it);
                    q.push({it, t + 1});
                }
            }
        }
        return t;
    }
};
