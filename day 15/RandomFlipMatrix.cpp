class Solution {
public:
    int totalr, totalc, r = 0, c = 0;
    Solution(int m, int n) {
        totalr = m, totalc = n;
    }
    
    vector<int> flip() {
        c++;
        if (c == totalc) {
            c = 0;
            r++;
        }
        if (r == totalr) {
            r = 0;
            c = 0;
        }
        return {r, c};
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
