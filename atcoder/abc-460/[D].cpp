#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    int DIRS[8][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}};
    queue<pair<int, int>> que;
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
        for (int j = 0; j < w; ++j)
            if (g[i][j] == '#') {
                que.push({i, j});
            }
    }
    int times = 0;
    while (times < 100) {
        int si = que.size();
        auto bG = g;
        while (si--) {
            auto [i, j] = que.front();
            for (auto& [mx, my] : DIRS) {
                int x = i + mx, y = j + my;
                if (x >= 0 && y >= 0 && x < h && j < w && bG[x][y] == '.') {
                    g[x][y] = '#';
                    que.push({x,y});
                }
            }
            g[i][j] = '.';
        }
        times++;
    }
    // for (int i = 0; i < 190; ++i) {
    //     // backup old
    //     auto bG = g;
    //     for (int i = 0; i < h; ++i) {
    //         for (int j = 0; j < w; ++j) {
    //             int cnt = 0;
    //             if (g[i][j] == '#') {
    //                 g[i][j] = '.';
    //                 continue;
    //             }
    //             for (auto& [mx, my] : DIRS) {
    //                 int x = i + mx, y = j + my;
    //                 if (x >= 0 && y >= 0 && x < h && j < w && bG[x][y] == '#') {
    //                     cnt++;
    //                 }
    //             }
    //             if (cnt != 0) g[i][j] = '#';
    //         }
    //     }
    //     // printf("第%lld轮结束\n", i+1);
    // }
    for (auto& i : g) {
        cout << i << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*

3 3
###
###
##.
5 7
.#.....
.......
..#....
.......
....#..

第1轮结束
#.#....
####...
.#.#...
.#####.
...#.#.
第2轮结束
.#.##..
....#..
#.#.###
#.....#
###.#.#
第3轮结束
#.#..#.
####.##
.#.#...
.#####.
...#.#.
第4轮结束
.#.##.#
....#..
#.#.###
#.....#
###.#.#
*/