class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), ans = 0;
        for (int i = 0, l = 0; i < n; i++) {
            maxCost -= abs(s[i] - t[i]);
            while (maxCost < 0) {
                maxCost += abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
