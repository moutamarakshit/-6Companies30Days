class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        auto index = [&](int i) {return (2 * i + 1) % (n | 1); };
        int left = 0, right = n - 1, i = 0;
        while (i <= right) {
            if (nums[index(i)] > median) {
                swap(nums[index(i)], nums[index(left)]);
                left++, i++;
            }
            else if (nums[index(i)] == median) i++;
            else {
                swap(nums[index(i)], nums[index(right)]);
                right--;
            }
        } 
/*
       priority_queue<int>pq(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        }
        for (int i = 0; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        } */
    } 
};
