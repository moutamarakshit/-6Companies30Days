class Solution {
public:
    void solve(string& digits, vector<string>&vec, int ind, string& temp, vector<string>& ans) {
        if (ind >= digits.length()) {
            ans.push_back(temp);
            return;
        }
        string value = vec[digits[ind] - '0'];
        int s = value.size();
        for (int i = 0; i < s; i++) {
            temp.push_back(value[i]);
            solve (digits, vec, ind + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string>vec = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        vector<string>ans;
        solve(digits, vec, 0, temp, ans);
        return ans;
    }
};
