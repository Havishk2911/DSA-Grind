class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        // Precompute LCMs of all non-empty subsets, with overflow guard
        auto lcm = [](long long a, long long b) -> long long {
            long long g = __gcd(a, b);
            // guard against overflow: if a/g would exceed safe bound, cap it
            if (a / g > (long long)2e9 / b) return (long long)4e18; // effectively "infinity"
            return a / g * b;
        };
        
        // count(mid) = numbers in [1, mid] divisible by at least one coin
        auto count = [&](long long mid) -> long long {
            long long total = 0;
            // iterate over all 2^n - 1 non-empty subsets
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = __builtin_popcount(mask);
                bool overflowed = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        l = lcm(l, coins[i]);
                        if (l > mid) { overflowed = true; break; }
                    }
                }
                if (overflowed) continue;
                long long cnt = mid / l;
                if (bits % 2 == 1) total += cnt;
                else total -= cnt;
            }
            return total;
        };
        
        long long lo = 1, hi = (long long)(*min_element(coins.begin(), coins.end())) * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};