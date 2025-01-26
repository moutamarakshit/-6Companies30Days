class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for (auto it: nums) {
            pq.push(it);
        }
        for (int i = 0; i < k; i++) {
            int x = pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }
        long long ans = 1, MOD = 1e9 + 7;
        while (!pq.empty()) {
            ans = (ans % MOD * pq.top() % MOD) % MOD;
            pq.pop();
        }
        return (int)ans;
    }
};
