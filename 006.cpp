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
    string s; cin >> s;

    map<char, set<int>> mp;
    int right = n - k + 1;
    int left = 0;
    for (int i = 0 ; i < right ; i++) {
        mp[s[i]].emplace(i);
    }

    // for (auto [x, st] : mp) {
    //     cout << x;
    //     for (auto v : st) cout << v << ' ';
    //     cout << endl;
    // }

    string ans;
    for (int _ = 0 ; _ < k ; _++) {
        int nxt = *mp.begin()->second.begin();
        ans.push_back(s[nxt]);
        for (int i = left ; i <= nxt ; i++) {
            mp[s[i]].erase(i);
            if (!mp[s[i]].size()) mp.erase(s[i]);
        }

        left = nxt + 1;
        mp[s[right]].emplace(right);
        ++right;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    main_();

    return 0;
}
