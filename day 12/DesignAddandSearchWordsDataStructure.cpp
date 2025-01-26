class WordDictionary {
public:
    unordered_map<int, unordered_set<string>>mpp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int len = word.size();
        mpp[len].insert(word);
    }
    
    bool search(string word) {
        int n = word.length();
        if (mpp.find(n) == mpp.end()) return false;

        if (word.find('.') == string::npos) {
            return mpp[n].find(word) != mpp[n].end();
        }

        for (auto it: mpp[n]) {
            if (isEqual(it, word)) return true;
        }
        return false;
    }
    bool isEqual(const string& s , const string& word) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (word[i] != '.' && word[i] != s[i]) return false;
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
