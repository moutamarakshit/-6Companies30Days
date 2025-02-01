class Solution {
public:
    map<vector<int>, int>mpp;
    // needs: price
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = 0, n = needs.size();
        if (mpp.find(needs) != mpp.end()) return mpp[needs];
        for (int i = 0; i < n; i++) {
            ans += (price[i] * needs[i]); // if we're not using any offer
        }
        for (int i = 0; i < special.size(); i++) {
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (special[i][j] > needs[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                for (int j = 0; j < n; j++) {
                    needs[j] -= special[i][j];
                }
                int price2 = special[i].back() + shoppingOffers(price, special, needs);
                ans = min(ans, price2);

                for (int j = 0; j < n; j++) {
                    needs[j] += special[i][j]; // backtrack
                }
            }
        }
        return mpp[needs] = ans;
    }
};
