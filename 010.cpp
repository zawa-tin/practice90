#include <bits/stdc++.h>

// 010
// https://atcoder.jp/contests/typical90/tasks/typical90_j

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
    vi s1(n + 1, 0), s2(n + 1, 0);
    rep(i, 1, n + 1) {
        s1[i] += s1[i - 1];
        s2[i] += s2[i - 1];
        int c, p; cin >> c >> p;
        if (c == 1) s1[i] += p;
        else s2[i] += p;
    }

    int q; cin >> q;
    rep(_, q) {
        int l, r; cin >> l >> r;
        cout << s1[r] - s1[l - 1] << " " << s2[r] - s2[l - 1] << newl;
    }
}

/*
自分の解法
1組と2組それぞれに累積和配列を作り、空きの学籍番号には値0を入れておく
解説
同じ
*/