#include <bits/stdc++.h>

// 004
// https://atcoder.jp/contests/typical90/tasks/typical90_d

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
    vvi a(h, vi(w));
    fore(y, a) fore(x, y) cin >> x;

    vi yokosum(h);
    rep(i, h) {
        ll sum = 0;
        fore(x, a[i]) sum += x;
        yokosum[i] = sum;
    }

    vi tatesum(w);
    rep(i, w) {
        ll sum = 0;
        rep(j, h) sum += a[j][i];
        tatesum[i] = sum;
    }

    rep(i, h) {
        rep(j, w) cout << yokosum[i] + tatesum[j] - a[i][j] << " ";
        cout << newl;
    }
}

/*
自分の解法
横縦の総和を前処理で求めておいて包除原理でsumを求める
解説
同じ
*/