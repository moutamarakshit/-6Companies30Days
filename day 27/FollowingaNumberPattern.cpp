string printMinNumberForPattern(string S){
        int n = S.length();
        string ans;
        stack<int>st;
        for (int i = 0; i <= n; i++) {
            st.push(i + 1);
            if (S[i] == 'I' || i == n) {
                while (!st.empty()) {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
