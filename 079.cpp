#include <bits/stdc++.h>

// 079
// https://atcoder.jp/contests/typical90/tasks/typical90_ca

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
    int h, w; cin >> h >> w;
    vvi a(h, vi(w)), b(h, vi(w));

    fore(y, a) fore(x, y) cin >> x;
    fore(y, b) fore(x, y) cin >> x;

    ll ans = 0;

    rep(y, h - 1) rep(x, w - 1) {
        int val = b[y][x] - a[y][x];
        ans += abs(val);
        a[y][x] += val;
        a[y + 1][x] += val;
        a[y + 1][x + 1] += val;
        a[y][x + 1] += val;
    }

    rep(y, h) rep(x, w) if (a[y][x] != b[y][x]) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n" << ans << newl;
}

/*
    左上から決定していった
*/