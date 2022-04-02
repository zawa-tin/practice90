#include <bits/stdc++.h>

// 032
// https://atcoder.jp/contests/typical90/tasks/typical90_af

// clang-format off

using namespace std;
#define all(a) a.begin(), a.end()
#define int long long
#define over_load_(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for (int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for (int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for (int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for (int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for (int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for (int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define fore(i, a) for (auto &i : a)
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b)
{
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b)
{
    return a > b and (a = b, true);
}
constexpr char newl = '\n';

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vp = vector<pair<int, int>>;
using vs = vector<string>;

signed main() {
    int n; cin >> n;
    vvi a(n, vi(n));
    fore(y, a) fore(x, y) cin >> x;
    int m; cin >> m;
    vector<set<int>> G(n);
    rep(_, m) {
        int x, y; cin >> x >> y;
        G[x - 1].insert(y - 1);
        G[y - 1].insert(x - 1);
    }

    vi index(n);
    rep(i, n) index[i] = i;

    int ans = INT_MAX;

    do {
        // 仲が悪いか
        bool ok = true;
        rep(i, n - 1) if (G[index[i]].count(index[i + 1])) {
            ok = false;
            break;
        }
        if (not ok) continue;

        int time = 0;

        rep(i, n) time += a[index[i]][i];

        chmin(ans, time);

    } while(next_permutation(all(index)));

    if (ans == INT_MAX) cout << -1 << newl;
    else cout << ans << newl;
}

/*
    順列全探索
    解説
    順列全探索
*/