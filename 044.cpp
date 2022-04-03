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
    int n, q; cin >> n >> q;
    vi a(n); fore(x, a) cin >> x;

    int shift = 0;

    rep(_, q) {
        int t, x, y; cin >> t >> x >> y;
        x--, y--;
        if (t == 1) {
            int swpx = x - shift;
            int swpy = y - shift;
            while(swpx < 0) swpx += n;
            while(swpy < 0) swpy += n;
            swap(a[swpx % n], a[swpy % n]);
        }
        if (t == 2) {
            shift++;
        }
        if (t == 3) {
            int val = x - shift;
            while(val < 0) val += n;
            cout << a[val % n] << newl;
        }
    }
}

/*
    あるある問題
*/