class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int,int>mpp;
        for (int i = 0, l = 0; i < n; i++) {
            mpp[nums[i]]++;
            if (mpp[nums[i]] > k) {
                while (nums[l] != nums[i]) { // delete everything until the first occurance of the
                // repeating element comes
                    mpp[nums[l]]--; // delete first/one occurance of the repeating element
                    l++;
                }
                mpp[nums[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
