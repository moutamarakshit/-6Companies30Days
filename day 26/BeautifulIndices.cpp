class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length(), x = a.length(), y = b.length();
        vector<int>aIn, bIn;
        for (int i = 0; i <= n - x; i++) {
            if (s.substr(i, x) == a) aIn.push_back(i);
        }
        for (int i = 0; i <= n - y; i++) {
            if (s.substr(i, y) == b) bIn.push_back(i);
        }
        vector<int>ans;
        for (int i = 0; i < aIn.size(); i++) {
            for (int j = 0; j < bIn.size(); j++) {
                if (abs(aIn[i] - bIn[j]) <= k) {
                    ans.push_back(aIn[i]);
                    break; // if i works once, check for the next i
                }
                    
            }
        }
        return ans;
    }
};
