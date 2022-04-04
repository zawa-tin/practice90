#include <bits/stdc++.h>

// 044
// https://atcoder.jp/contests/typical90/tasks/typical90_ar

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
    vi a(n), b(n), c(n);
    fore(x, a) cin >> x;
    fore(x, b) cin >> x;
    fore(x, c) cin >> x;

    vi ma(46, 0), mb(46, 0), mc(46, 0);

    fore(x, a) ma[x % 46]++;
    fore(x, b) mb[x % 46]++;
    fore(x, c) mc[x % 46]++;

    ll ans = 0;

    rep(i, 46) rep(j, 46) rep(k, 46) {
        if ((i + j + k) % 46 == 0) ans += ma[i] * mb[j] * mc[k];
    }

    cout << ans << newl;
}

/*
    教訓 似たような変数名を作らない！！
    ma mb mcは最悪
*/