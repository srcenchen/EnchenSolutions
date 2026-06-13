#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> Y(n + 1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        Y[x] = y;
    }
    int count = 0;
    int min_y = n + 1; 
    for (int x = 1; x <= n; ++x) {
        int curY = Y[x];
        if (curY < min_y) {
            count++;
            min_y = curY; 
        }
    }
    cout << count << "\n";
    return 0;
}