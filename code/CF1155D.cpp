#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

void solve () {
    int n;
    cin >> n;

    i64 x;
    cin >> x;

    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<array<i64, 3>> dp(n + 1, {0ll, 0ll, 0ll});
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = max(a[i], dp[i - 1][0] + a[i]);
        dp[i][1] = max(a[i] * x, max(dp[i - 1][0] + a[i] * x, dp[i - 1][1] + a[i] * x));
        dp[i][2] = max(a[i], max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]));
    }

    i64 mx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Task = 1;
    // cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}