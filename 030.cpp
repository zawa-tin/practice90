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

vector<int> sieve(int n) {
    vector<int> res(n + 1, 1);
    res[0] = res[1] = 0;
    for (int i = 0 ; i <= n ; i++) if (res[i]) {
        for (int j = i + i ; j <= n ; j += i) res[j] = 0;
    }

    return res;
}

void main_() {
    int n, k; cin >> n >> k;
    auto siv = sieve(n);
    vi ps; for (int i = 0 ; i <= n ; i++) if(siv[i]) ps.emplace_back(i);
    vector<int> cnts(n + 1, 0);
    for (auto x : ps) for (int j = x ; j <= n ; j += x) cnts[j]++;
    int ans = 0;
    for (auto x : cnts) ans += x >= k;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    main_();

    return 0;
}

