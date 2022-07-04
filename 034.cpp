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
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;

    int ans = 0;
    map<int, int> mp;
    int right = 0;
    for (int left = 0 ; left < n ; left++) {
        while(right < n and (mp.size() < k or (mp.size() <= k and mp.count(a[right])))) {
            mp[a[right]]++;
            right++;
        }

        // for (auto x : mp) cout << x.first << ' ';
        // cout << endl;
        chmax(ans, right - left);
        
        if (left != right) {
            mp[a[left]]--;
            if (!mp[a[left]]) mp.erase(a[left]);
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
