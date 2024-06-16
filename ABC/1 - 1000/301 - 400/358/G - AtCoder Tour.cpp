#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

std::vector<int> dx = {0, 1, -1, 0, 0};
std::vector<int> dy = {0, 0, 0, -1, 1};

void solve() {
    int H, W, K; std::cin >> H >> W >> K;
    int sx, sy; std::cin >> sx >> sy;
    --sx; --sy;
    
    i64 A[50][50];
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }
    int z = std::min(K, H * W);
    
    i64 dp[50][50][2], tot;
    std::fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp)/sizeof(dp[0][0][0]), -1LL);
    dp[sx][sy][0] = 0;
    tot = A[sx][sy] * K;
    
    for(int k = 1; k <= z; k++) {
        for(int x = 0; x < H; x++) {
            for(int y = 0; y < W; y++) {
                int tx, ty;
                for(int s = 0; s < 5; s++) {
                    tx = x + dx[s];
                    ty = y + dy[s];
                    
                    if(tx < 0 || tx == H || ty < 0 || ty == W) continue;
                    if(dp[x][y][!(k & 1)] != -1) {
                        dp[tx][ty][k & 1] = 
                        std::max(dp[tx][ty][k & 1], dp[x][y][!(k & 1)] + A[tx][ty]);
                            
                        tot = std::max(tot, dp[tx][ty][k & 1] + 1LL * A[tx][ty] * (K - k));
                    }
                }
            }
        }
    }
    
    std::cout << tot;
}

signed main() {
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

// g++ -std=c++20 <filename>.cpp
