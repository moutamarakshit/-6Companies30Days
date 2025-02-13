pair<string, int>solve(vector<vector<pair<string, int>>>& dp, vector<int>& arr, int i, int j) {
        if (i == j) {
            string st = "";
            st += 'A' + i - 1;
            return {st, 0};
        }
        if (dp[i][j].second != -1) return dp[i][j];
        
        int ans = INT_MAX;
        string s = "";
        for (int k = i; k < j; k++) {
            auto first = solve(dp, arr, i, k);
            auto sec = solve(dp, arr, k + 1, j);
            int temp = arr[i - 1] * arr[k] * arr[j] + first.second + sec.second;
            string str = "(" + first.first + sec.first + ")";
            if (temp < ans) {
                ans = temp;
                s = str; 
            }
        }
        return dp[i][j] = {s, ans};
    }
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<pair<string, int>>>dp(n, vector<pair<string, int>>(n, {"", -1}));
        auto it =  solve(dp, arr, 1, n - 1);
        return it.first;
    }
