class Solution {
public:
    vector<int>res;
    void solve(int ind, int n, vector<int>&ans, vector<int>& nums, vector<int>& dp) {
        if (ind >= n) {
            if (res.size() < ans.size()) {
                res = ans;
            }
            return;
        }

        if ((ans.empty() || nums[ind] % ans.back() == 0) && (dp[ind] < (int)ans.size() + 1)) {
            dp[ind] = (int)ans.size() + 1;
            ans.push_back(nums[ind]);
            solve(ind + 1, n, ans, nums, dp);
            ans.pop_back();
        }
        solve (ind + 1, n, ans, nums, dp);

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        vector<int>dp(nums.size(), -1);
        solve(0, nums.size(), ans, nums, dp);
        return res;
    }
};
