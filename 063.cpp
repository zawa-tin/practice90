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

void main_() {
    int h, w; cin >> h >> w;
    vvi ps(h, vi(w)); for (auto& y : ps) for (auto& x : y) cin >> x;

    int ans = 0;
    for (int bit = 0 ; bit < (1 << h) ; bit++) {
        vi use;
        for (int i = 0 ; i < h ; i++) if (bit & (1 << i)) use.emplace_back(i);
        map<int, int> mp;
        for (int i = 0 ; i < w ; i++) {
            set<int> st;
            for (auto u : use) st.emplace(ps[u][i]);
            if (st.size() == 1) mp[*st.begin()] += use.size();
        }

        int t = 0;
        for (auto [x, c] : mp) chmax(t, c);
        chmax(ans, t);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    main_();

    return 0;
}
