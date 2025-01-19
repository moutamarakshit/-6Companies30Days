class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string>ans;
        if (n <= 10) return ans;
        unordered_map<string, int>mpp;
        for (int i = 0; i <= n - 10; i++) {
            mpp[s.substr(i, 10)]++;
        }
        for (auto it: mpp) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
