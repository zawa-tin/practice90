#include <bits/stdc++.h>

// 052
// https://atcoder.jp/contests/typical90/tasks/typical90_az

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

const ll mod = 1000000007;

vvi dices;
vvi dp;

// y番目のサイコロのx番目が最後の積の時の値
ll rec(int y, int x) {
    if (dp[y][x] != -1) return dp[y][x];

    ll res = 0;
    rep(i, 6) {
        res += rec(y - 1, i);
        res %= mod;
    }

    res *= dices[y][x];
    res %= mod;
    dp[y][x] = res;
    return res;
}

signed main() {
    int n; cin >> n;
    dices = vvi(n, vi(6));
    fore(y, dices) fore(x, y) cin >> x;
    dp = vvi(n, vi(6, -1));
    rep(i, 6) dp[0][i] = dices[0][i];

    ll ans = 0;
    rep(i, 6) {
        ans += rec(n - 1, i);
        ans %= mod;
    }
    cout << ans << newl;
}

/*
    メモ化再帰
*/