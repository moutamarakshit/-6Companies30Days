class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n - 1, moves = 0;
        while (low < high) {
            moves += nums[high] - nums[low];
            low++, high--;
        }
        return moves;
    }
};
