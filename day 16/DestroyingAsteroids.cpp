class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        long long temp = mass;
        for (int i = 0; i < n; i++) {
            if (temp >= a[i]) {
                temp += a[i];
            }
            else return false;
        }
        return true;
    }
};
