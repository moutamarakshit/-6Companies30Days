class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int sp, int ep, int k, vector<vector<int>>& dp) {
        if (k == 0) {
            if (sp == ep) return 1;
            else return 0;
        }
        if (dp[sp][k] != -1) return dp[sp][k];

        int steps = 0;
        steps += solve(sp + 1, ep, k - 1, dp);
        steps %= mod;
        steps += solve(sp - 1, ep, k - 1, dp);
        steps %= mod;
        return dp[sp][k] = steps;
    }
    int numberOfWays(int sp, int ep, int k) {
        sp += k; // to avoid negative index when moving left
        ep += k; // to balance the start and end
        vector<vector<int>>dp(3001, vector<int> (1001, -1));
        return solve (sp, ep, k, dp);
    }
};
