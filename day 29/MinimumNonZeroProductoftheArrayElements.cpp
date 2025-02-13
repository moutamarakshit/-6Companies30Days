#define ll long long
int mod = 1e9 + 7;
class Solution {
public:
    int minNonZeroProduct(int p) {
        // think of p = 4, 2^4 = 16, so nums include 1...15
        // 2 - 7 can be converted to 1, so total 1-7 will be 1 : n/2 numbers
        // 8-14 will coonverted to 14, and 15 will be 15, n/2 numbers of n - 1 and 1 n
        // (n-1)^n/2*n
        ll val = pow(2, p);
        val--;
        ll ans = power(val - 1, val / 2);
        return (ans * (val % mod)) % mod;
    }
    ll power(ll n, ll p) {
        if (p == 0) return 1;
        if (p == 1) return n % mod;

        ll temp = power(n, p / 2);
        if (p % 2 == 0) {
            return ((temp % mod)* (temp % mod)) % mod;
        }
        else {
            temp = (temp % mod) * (temp % mod);
            n %= mod;
            return ((temp % mod) * (n % mod)) % mod;
        }
    }
};
