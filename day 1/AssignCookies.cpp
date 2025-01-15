class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0, n = g.size(), m = s.size(), cnt = 0;
        while (l < m && r < n) {
            if (s[l] >= g[r]) {
                cnt++; r++; l++;
            }
            else l++;
        }
        return cnt;
    }
};
