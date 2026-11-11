class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto calc = [&](long long k) {
            return k * costBoth
                 + max(0LL, (long long)need1 - k) * cost1
                 + max(0LL, (long long)need2 - k) * cost2;
        };
        long long lo = min(need1, need2), hi = max(need1, need2);
        return min({calc(0), calc(lo), calc(hi)});
    }
};