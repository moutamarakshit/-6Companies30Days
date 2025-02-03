#define ll long long
class Solution {
public:
    int gcd (int a, int b) {
        if (b == 0) return a;
        return gcd (b, a % b);
    }
    int find_lcm (ll a, ll b) {
        ll temp = (a / gcd(a,b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
    int minimizeSet(int d1, int d2, int uc1, int uc2) {
        int low = 1, high = INT_MAX, lcm = find_lcm(d1, d2);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int a = mid / d1;
            int b = mid / d2;
            if (uc1 <= mid - a && uc2 <= mid - b && uc1 + uc2 <= (mid - (mid / lcm))) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};
