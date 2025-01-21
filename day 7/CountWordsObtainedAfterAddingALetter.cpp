class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = startWords.size();
        set<string> st;
        for (int i = 0; i < n; i++) {
            string word = startWords[i];
            sort(word.begin(), word.end());
            st.insert(word);
        }
        int m = targetWords.size(), cnt = 0;
        for (int i = 0; i < m; i++) {
            string word = targetWords[i];
            sort(word.begin(), word.end());
            for (int i = 0; i < word.size(); i++) {
                string temp = word.substr(0, i) + word.substr(i + 1);
                if (st.find(temp) != st.end()) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
