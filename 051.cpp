#pragma GCC target("avx2")
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

vvi make(int n) {
    vi a(n); for (auto& x : a) cin >> x;
    
    vvi res(n + 1);
    for (int bit = 0 ; bit < (1 << n) ; bit++) {
        int t = 0;
        for (int i = 0 ; i < n ; i++) if (bit & (1 << i)) t += a[i];
        res[__builtin_popcount(bit)].emplace_back(t);
    }

    for (auto& y : res) sort(all(y));

    return res;
}

void main_() {
    int n, k, p; cin >> n >> k >> p;
    auto f = make(n / 2), b = make((n + 1) / 2);
    // debug(f);
    // cout << endl;
    // debug(b);
    int ans = 0;
    for (int i = 0 ; i < f.size() ; i++) {
        if (k - i >= b.size()) continue;
        if (i > k) break;
        for (auto x : f[i]) {
            if (x > p) break;
            ans += upper_bound(all(b[k - i]), p - x) - begin(b[k - i]);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    main_();

    return 0;
}

