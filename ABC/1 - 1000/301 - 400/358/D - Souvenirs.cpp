#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using ll = long long;

void solve() {
    int N, M; std::cin >> N >> M;
    
    std::vector<int> A(N), B(M);
    for(int& i: A) std::cin >> i;
    for(int& i: B) std::cin >> i;
    
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    ll cost = 0;
    
    int i = 0, j = 0;
    while(i < N && j < M) {
        if(A[i] >= B[j]) {
            cost += A[i];
            ++i;
            ++j;
        }
        else ++i;
    }
    
    std::cout << ((j != M)? -1: cost);
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
