class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int>temp;
            int cnt = 0;
            for (int j = i; j < n; j++) {
                temp.push_back(nums[j]); // since atmost k = 0-k
                if (nums[j] % p == 0) cnt++;
                if (cnt > k) break;
                st.insert(temp);
            }
        }
        return st.size();
    }
};
