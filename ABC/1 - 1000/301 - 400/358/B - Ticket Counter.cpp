#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

void solve() {
    int N, A; std::cin >> N >> A;
    
    std::vector<int> T(N);
    for(int& i: T) std::cin >> i;
    
    int t = 0, i = 0;
    while(i < N) {
        t = std::max(t, T[i++]);
        std::cout << t + A << '\n';
        t += A;
    }
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
