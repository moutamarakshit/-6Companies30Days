class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int  n = arr.size();
       int sum = n * (n + 1) / 2;
       int sumSqn = (n * (2 * n + 1) * (n + 1)) / 6;
       for (int i = 0; i < n; i++) {
           sumSqn -= arr[i] * arr[i];
           sum -= arr[i];
       }
       int c = sumSqn / sum;
       int mis = (sum + c) / 2;
       int rep = c - mis;
       return {rep, mis};
    }
};


// another approach
/* class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int n = arr.size();
        int rep, mis = n;
        for (auto it: arr) {
            mpp[it]++;
            if (mpp[it] > 1) {
                rep = it;
                //break;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (mpp[i] == 0) {
                mis = i;
                break;
            }
        }
        return {rep, mis};
    }
}; */
