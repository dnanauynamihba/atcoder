#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

void solve() {
    int N, M; std::cin >> N >> M;
    
    std::vector<std::string> v(N);
    for(std::string& s: v) std::cin >> s;
    
    int ans = N;
    std::vector<int> bits(M, 0);
    for(int mask = (1 << N) - 1; ~mask; --mask) {
        std::fill(bits.begin(), bits.end(), 0);
        
        for(int i = 0; i < N; i++) {
            if(mask & (1 << i)) {
                for(int j = 0; j < M; j++) {
                    bits[j] = (v[i][j] == 'o')? 1: bits[j];
                }
            }
        }
        if(std::count(bits.begin(), bits.end(), 1) == M) {
            ans = std::min(ans, __builtin_popcount(mask));
        }
    }
    
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst = 1;
    while(tst--) solve();
    
    return 0;
}

// g++ -std=c++20 <filename>.cpp
