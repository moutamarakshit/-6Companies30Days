class Solution {
public:
    int res = 0;

    bool isPalindrome(string& s) {
        int  j = s.length() - 1, i = 0;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }  
        return true;
    }

    void dfs(int ind, string& s, string& s1, string& s2, int n) {
        if (ind >= n) {
            if (isPalindrome(s1) && isPalindrome(s2)) {
                res = max(res, (int)s1.length() * (int)s2.length());
            }
                return;

        }
        s1.push_back(s[ind]);
        dfs(ind + 1, s, s1, s2, n); // s[ind] is in s1
        s1.pop_back();

        s2.push_back(s[ind]);
        dfs(ind + 1, s, s1, s2, n); // s[ind] is in s2, disjoint this way
        s2.pop_back();

        dfs(ind + 1, s, s1, s2, n); // in neither, since this is a subsqn
    }
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        int n = s.length();
        dfs(0, s, s1, s2, n);
        return res;
    }
};
