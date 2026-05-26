#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str; cin >> str;;
    vector<pair<char, int>> cnt(26);
    int maxSize = (str.size() + 1) / 2;
    for (int i = 0; i < 26; ++i) {
        cnt[i].first = i + 'a';
    }
    for (auto& i : str) {
        cnt[i-'a'].second++;
        if (cnt[i-'a'].second > maxSize) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    sort(cnt.begin(), cnt.end(), [&](pair<char, int>& a, pair<char, int>& b) {
        if (a.first == b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });
    int r = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i].second != 0) {
            r = i;
        }
    }
    string tmp, ans(str.size(), ' ');
    for (auto& i : cnt) {
        for (int j = 0; j < i.second; ++j) {
            tmp += i.first;
        }
    }
    // cout << tmp << endl;
    int idx = 0;
    for (int i = 0; i < str.size(); i+=2) {
        ans[i] = tmp[idx++];
    }
    for (int i = 1; i < str.size(); i+=2) {
        ans[i] = tmp[idx++];
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}