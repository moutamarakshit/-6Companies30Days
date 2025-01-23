class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;

        int n = nums.size();
        int m = nums[0].size();
        for (auto it: queries) {
            int k = it[0];
            int trim = it[1];
            
            vector<pair<string, int>>vec;
            for (int i = 0; i < n; i++) {
                string str = nums[i].substr(m - trim);
                vec.push_back({str, i});
            }

            sort(vec.begin(), vec.end(), [] (pair<string, int>& a, pair<string, int>&b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });

            ans.push_back(vec[k - 1].second);
        }
        return ans;
    }
};
