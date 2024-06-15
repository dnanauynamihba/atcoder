#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

std::string solve() {
    std::string s, t; std::cin >> s >> t;
    
    if(s == "AtCoder" && t == "Land") return "Yes";
    return "No";    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst = 1;
    while(tst--) std::cout << solve();
    
    return 0;
}

// g++ -std=c++20 <filename>.cpp
