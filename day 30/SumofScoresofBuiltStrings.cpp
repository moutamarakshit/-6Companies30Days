class Solution {
public:
    long long sumScores(string s) {
        int n = s.length();
        vector<long long>z = Zfunc(s);
        long long sum = accumulate(z.begin(), z.end(), (long long)s.size());
        return sum;
    }
    vector<long long>Zfunc(string& s) {
        int n = s.length(), l = 0, r = 0;
        vector<long long>z(n);
        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && s[r] == s[r - l]) r++;
                z[i] = r - l;
                r--;
            }
            else {
                int k = i - l;
                if (z[k] < r - i + 1) {
                    z[i] = z[k];
                }
                else {
                    l = i;
                    while (r < n && s[r] == s[r - l]) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
};
