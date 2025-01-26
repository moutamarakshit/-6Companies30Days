class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int>dp(n + 1, n);
        dp[0] = 0;
        unordered_set<string>st(dictionary.begin(), dictionary.end());
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (st.find(s.substr(j, i - j)) != st.end()) { // index, len including index
                    dp[i] = min(dp[i], dp[j]); // say, j = 0, dp[i] = 0 but if we dont take the min
                    // it'll be overwritten
                }
            }
            dp[i] = min(dp[i], dp[i - 1] + 1); // either keep the updated correct value or increase the number
        }
       return dp[n];
    }
};
