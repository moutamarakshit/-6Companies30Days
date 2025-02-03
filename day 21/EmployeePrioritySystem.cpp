class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        unordered_map<string, vector<int>>mpp; // name , hours
        for (auto it: a) {
            int h = stoi(it[1].substr(0, 2));
            int m = stoi(it[1].substr(2, 2));
            mpp[it[0]].push_back(h * 60 + m);
        }
        vector<string>ans;
        for (auto it: mpp) {
            string emp = it.first;
            vector<int>temp = it.second;
            int k = temp.size();
            if (k < 3) continue;
            sort(temp.begin(), temp.end());
            bool flag = false;
            for (int i = 0; i < k - 2; i++) {
                if (temp[i + 2] < temp[i] + 60) {
                    flag = true;
                    break;
                }
            }
            if (flag) ans.push_back(emp);
        }
        return ans;
    }
};
