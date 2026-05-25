#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << ": " << x << "\n"
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    bool seen1[27][27], seen2[27][27];
    memset(seen1, 0, sizeof(seen1));
    memset(seen2, 0, sizeof(seen1));
    unordered_set<char> uni1, uni2;
    for (auto& i : s1) {
        for (auto& j : uni1) {
            seen1[j-'a'][i-'a'] = true;
        }
        uni1.insert(i);
    }
    for (auto& i : s2) {
        for (auto& j : uni2) {
            seen2[j-'a'][i-'a'] = true;
        }
        uni2.insert(i);
    }
    for (int i = 0; i <= 26; ++i) {
        for (int j = 0; j <= 26; ++j) {
            if (seen1[i][j] == seen2[i][j] && seen1[i][j]) {
                putchar('a'+i);
                putchar('a'+j);
                putchar('\n');
                return ;
            }
        }
    }
    cout << "HENG!" << endl;
}

signed main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}