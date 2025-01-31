string encode(string s) {
        int n = s.length(), cnt = 1;
        string ans;
        char el = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == el) {
                cnt++;
            }
            else {
                ans.push_back(el);
                ans += to_string(cnt);
                cnt = 1;
                el = s[i];
            }
        }
        ans.push_back(el);
        ans += to_string(cnt);
        
        return ans;
    }
