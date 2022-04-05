#include <bits/stdc++.h>

// 076
// https://atcoder.jp/contests/typical90/tasks/typical90_bx

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
    vi a(n); fore(x, a) cin >> x;

    ll goal = 0; fore(x, a) goal += x;

    if (goal % 10 != 0) {
        cout << "No\n";
        return 0;
    }

    goal /= 10;

    int right = 0;
    int sum = 0;
    rep(left, 2 * n) {
        // 伸ばす
        while(right < 2 * n and sum + a[right % n] <= goal) {
            sum += a[right % n];
            right++;
        }

        // 判定する
        if (sum == goal) {
            cout << "Yes\n";
            return 0;
        }

        // 縮める準備
        if (left == right) right++;
        else sum -= a[left % n];
    }

    cout << "No\n";
}

/*
    尺取り
    ループ範囲はテキトー
*/