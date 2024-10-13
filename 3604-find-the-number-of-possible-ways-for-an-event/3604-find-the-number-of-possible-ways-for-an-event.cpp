class Solution {
public:
    int mod = 1e9 + 7;

    int powMod(int a, int b) {
        long long result = 1;

        while (b > 0) {
            if (b % 2) result = (result * a) % mod;
            a = (a * 1LL * a) % mod;
            b /= 2;
        }

        return result;
    }

    int numberOfWays(int n, int x, int y) {
        vector<vector<long long>> stirling(n + 1, vector<long long>(x + 1, 0));
        vector<long long> fac(x + 1), invfac(x + 1);
        vector<long long> ypow(x + 1);

        // Stirling numbers initialization
        stirling[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                stirling[i][j] = (stirling[i - 1][j - 1] + j * 1LL * stirling[i - 1][j]) % mod;
            }
        }

        // Factorial and Inverse Factorial initialization
        fac[0] = fac[1] = 1;
        for (int i = 2; i <= x; i++) {
            fac[i] = (fac[i - 1] * 1LL * i) % mod;
        }

        // Calculate inverse factorial using Fermat's little theorem
        invfac[x] = powMod(fac[x], mod - 2);
        for (int i = x - 1; i >= 0; i--) {
            invfac[i] = (invfac[i + 1] * 1LL * (i + 1)) % mod;
        }

        // Precompute powers of y
        ypow[0] = 1;
        for (int i = 1; i <= x; i++) {
            ypow[i] = (ypow[i - 1] * 1LL * y) % mod;
        }

        // Lambda for combinations
        auto combination = [&fac, &invfac, this](int n, int r) -> int {
            if (r > n || r < 0) return 0;
            return (fac[n] * 1LL * invfac[r] % mod) * invfac[n - r] % mod;
        };

        long long ans = 0;

        // Final calculation of the number of ways
        for (int i = 1; i <= x; i++) {
            long long comb = combination(x, i);
            long long res = (comb * ypow[i]) % mod;
            res = (res * stirling[n][i]) % mod;
            res = (res * fac[i]) % mod;

            ans = (ans + res) % mod;
        }

        return ans;
    }
};


// Notes: 


/*

here we are using the concept of stirling number of 2nd kind
with some permutation and combination game.

*/