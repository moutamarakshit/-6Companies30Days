class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<pair<int,int>>vec;
        for (int i = 0; i < n; i++) {
            int s = a[i] + b[i];
            vec.push_back({s, i});
        }
        int alice = 0, bob = 0;
        sort(vec.rbegin(), vec.rend());
        for (int i = 0; i < n; i++) {
            int ind = vec[i].second;
            if (i % 2) bob += b[ind];
            else alice += a[ind];
        }
        if (alice == bob) return 0;
        else return alice > bob ? 1: -1;
    }
};
