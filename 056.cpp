#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <atcoder/modint>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/scc>

#define int long long
#define all(x) begin(x), end(x)

using namespace std;
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vp = vector<pii>;
using vs = vector<string>;

void debug(vector<int> a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

void debug(vector<vector<int>> a) {
    for (auto y : a) debug(y);
}

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b and (a = b, true);}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b and (a = b, true);}

// inline bool in(int y, int x) {return 0 <= x and x < w and 0 <= y and y < h;}

const int supl = 1e18 - 100;

void main_() {
    int n, s; cin >> n >> s;
    vector<int> as(n), bs(n);
    for (int i = 0 ; i < n ; i++) cin >> as[i] >> bs[i];

    vvi dp(n + 1, vi(s + 1, 0));
    vector<vector<char>> rec(n + 1, vector<char>(s + 1, '\0'));
    dp.front().front() = 1;
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j <= s ; j++) if (dp[i][j]) {
        if (j + as[i] <= s) {
            dp[i + 1][j + as[i]] = 1;
            rec[i + 1][j + as[i]] = 'A';
        }
        if (j + bs[i] <= s) {
            dp[i + 1][j + bs[i]] = 1;
            rec[i + 1][j + bs[i]] = 'B';
        }
    }
    
    if (dp.back().back()) {
        function<void(int, int)> f = [&](int i, int j) -> void {
            if (rec[i][j] == '\0') return;
            if (rec[i][j] == 'A') f(i - 1, j - as[i - 1]);
            if (rec[i][j] == 'B') f(i - 1, j - bs[i - 1]);
            cout << rec[i][j];
        };
        f(n, s);
        cout << endl;
    }
    else cout << "Impossible" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    main_();

    return 0;
}
