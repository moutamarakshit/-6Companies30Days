class Solution {
public:
    int ans = 0;
    int solve (vector<int>& nums1, vector<int>& nums2, int ind1, int ind2, vector<vector<int>>&dp) {
        if (ind1 < 0 || ind2 < 0) return 0;
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if (nums1[ind1] == nums2[ind2]) dp[ind1][ind2] = 1 + solve(nums1, nums2, ind1 - 1, ind2 - 1, dp);
        else dp[ind1][ind2] = 0;
        ans = max(ans, dp[ind1][ind2]);
        solve(nums1, nums2, ind1 - 1, ind2, dp);
        solve(nums1, nums2, ind1, ind2 - 1, dp);
        return dp[ind1][ind2];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
       solve(nums1, nums2, n - 1, m - 1, dp);
       return ans;

    }
};
