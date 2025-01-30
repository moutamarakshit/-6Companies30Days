class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] < nums[left + 1]) left++;
        while (right > 0 && nums[right] > nums[right - 1]) right--;
        ans = (left == n - 1) ? 0: (n - right) + 1;
        for (int i = 0; i <= left; i++) {
            int valid = upper_bound(nums.begin() + right, nums.end(), nums[i]) - nums.begin();
            ans += n - valid + 1;
        }
        return ans;
    }
};
