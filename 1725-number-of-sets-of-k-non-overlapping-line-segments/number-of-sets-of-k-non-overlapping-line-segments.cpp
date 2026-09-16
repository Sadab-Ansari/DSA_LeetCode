class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1;
        b %= MOD;
        while (e) {
            if (e & 1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1, R = 2 * k;
        long long num = 1, den = 1;
        for (int i = 0; i < R; i++) {
            num = num * (N - i) % MOD;
            den = den * (i + 1) % MOD;
        }
        return num * power(den, MOD - 2) % MOD;
    }
};