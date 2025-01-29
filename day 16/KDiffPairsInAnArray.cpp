class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for (auto it: nums) mpp[it]++;
        int cnt = 0;
        for (auto it: mpp) {
           int num = it.first;
           int freq = it.second;
           if ((k == 0 && freq > 1) || (k > 0 && mpp.find(num + k) != mpp.end()))
            cnt++;
        }
        return cnt;
    }
};
