vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // sort contact for lexicographical order in answer
        sort (contact, contact + n);
        int m = s.length();
        vector<vector<string>> ans(m);
        for (int i = 0; i < m; i++) {
            string word = s.substr(0, i + 1);
            for (int j = 0; j < n; j++) {
                // instead of using a set, we'll just skip since we've sorted it too
                if (j > 0 && contact[j] == contact[j - 1]) continue;
                // first check to avoid run time error
                if (contact[j].size() >= i + 1 && contact[j].substr(0, i + 1) == word) {
                    ans[i].push_back(contact[j]);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (ans[i].empty()) ans[i].push_back("0");
        }
        return ans;
    }
