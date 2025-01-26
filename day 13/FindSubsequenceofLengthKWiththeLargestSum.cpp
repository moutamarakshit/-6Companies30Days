class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            if (pq.size() > k) pq.pop();
        }

        vector<pair<int,int>>vec;
        while (!pq.empty()) {
            vec.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }
        sort(vec.begin(), vec.end()); 

        vector<int>ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = vec[i].second;
        }
        return ans;
    }
};
