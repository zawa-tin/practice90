#include <bits/stdc++.h>

// 055
// https://atcoder.jp/contests/typical90/tasks/typical90_bc

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

int calc(int x, int y, int mod) {
    return ((x % mod) * (y % mod)) % mod;
}

signed main() {
    int n, p, q; cin >> n >> p >> q;
    vi a(n); fore(x, a) cin >> x;
    int ans = 0;
    rep(i, n - 4) rep(j, i + 1, n - 3) rep(k, j + 1, n - 2) rep(l, k + 1, n - 1) rep(m, l + 1, n) {
        int val = calc(a[i], a[j], p);
        val = calc(val, a[k], p);
        val = calc(val, a[l], p);
        val = calc(val, a[m], p);
        if (val == q) ans++;
    }

    cout << ans << newl;
}

/*
    僕の解法
    なんか通って笑う
    解説
    NC5は定数倍が1/120で小さいからN=100で全然セーフ
*/