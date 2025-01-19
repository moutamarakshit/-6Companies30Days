class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mpp;
        int n = secret.size(), bulls = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) bulls++;
            else mpp[secret[i]]++;
        }
        int cows = 0;
        for (int i = 0; i < n; i++) {
            if (guess[i] != secret[i] && mpp[guess[i]] > 0) {
               cows++;
               mpp[guess[i]]--;
            }
           
        }
        string ans;
        ans += to_string(bulls);
        ans.push_back('A');
        ans += to_string(cows);
        ans.push_back('B');
        return ans;
    }
};
