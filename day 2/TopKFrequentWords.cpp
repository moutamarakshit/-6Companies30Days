class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        for (auto it: words) {
            mpp[it]++;
        }
        auto cmp = [](const pair<int,string>& a, const pair<int,string>& b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<int,string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for (auto it: mpp) {
            pq.push({it.second, it.first});
        }
        vector<string>ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
            if (k == 0) break;
        }
        return ans;
    }
};
