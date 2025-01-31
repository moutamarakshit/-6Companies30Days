class Solution {
public:
   
    int longestMountain(vector<int>& nums) {
       int n = nums.size(), up = 0, down = 0, maxLen = 0;
       for (int i = 1; i < n; i++) {
        if ((down > 0 && nums[i] > nums[i - 1]) || nums[i] == nums[i - 1]) {
            up = 0, down = 0;
        }
        if (nums[i] > nums[i - 1]) up++;
        if (nums[i] < nums[i - 1]) down++;
        if (up > 0 && down > 0)
            maxLen = max(maxLen, up + down + 1);
       }
       return maxLen;
    }
};
