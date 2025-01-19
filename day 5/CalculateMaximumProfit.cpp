class Solution {
public:
    int solve (int buy, int ind, int n, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind == n || k == 0) return 0;
        if (dp[ind][buy][k] != -1) return dp[ind][buy][k];
        if (buy == 0) {
            int b = -prices[ind] + solve(1, ind + 1, n, k, prices, dp);
            int nb = solve (0, ind + 1, n, k, prices, dp);
            return dp[ind][buy][k] = max(b, nb);
        }
        else {
            int s = prices[ind] + solve(0, ind + 1, n, k - 1, prices, dp);
            int ns = solve(1, ind + 1, n, k, prices, dp);
            return dp[ind][buy][k] = max(s, ns);
        }

    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 0, n, k, prices, dp);
    }
};
