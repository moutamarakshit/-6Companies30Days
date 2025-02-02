class Solution {
public:
    void solve(vector<int>& temp, vector<vector<int>>& ans, int n, int ind, int sum, int k) {
        if (temp.size() == k) {
            if (sum == n) ans.push_back(temp);
            return;
        }
        for (int i = ind + 1; i <= 9; i++) {
            if (sum + i > n) break;
            temp.push_back(i);
            solve(temp, ans, n, i, sum + i, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        if (n < k) return ans;
        vector<int>temp;
        solve(temp, ans, n, 0, 0, k);
        return ans;
    }
};
