#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;
const int mod = 998244353;

std::vector<i64> fact, invf;

i64 qexp(i64 a, i64 b, i64 m) {
    i64 res = 1;
    while(b) {
        if(b % 2) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    
    return res;
}

void precompute(int n) {
    fact.assign(n + 1, 1); 
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
 
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], mod - 2, mod);
    
    for(int i = n - 1; i > 0; i--)
        invf[i] = invf[i + 1] * (i + 1) % mod;
}

i64 nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invf[r] % mod * invf[n - r] % mod;
}

void solve() {
    int N; std::cin >> N;
    
    std::vector<int> C(27);
    for(int i = 1; i <= 26; i++) std::cin >> C[i];
    
    precompute(N);
    
    std::vector<std::vector<i64>> dp(27, std::vector<i64>(N + 1));
    
    dp[0][0] = 1;
    for(int i = 1; i <= 26; i++) {
        int freq = C[i];
        for(int j = 0; j <= freq; j++) {
            for(int k = 0; j + k <= N; k++) {
                dp[i][j + k] = (dp[i][j + k] % mod) + (nCr(j + k, j) * dp[i - 1][k]) % mod;
            }
        }
    }
    
    i64 ans = 0;
    for(int i = 1; i <= N; i++) ans = (ans + dp[26][i]) % mod;
    
    std::cout << ans;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst = 1;
    while(tst--) solve();
    
    return 0;
}
