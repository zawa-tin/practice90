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

ll to_decimal(string x) {
    ll res = 0;
    ll now = 1;
    rrep(i, x.size()) {
        res += now * (int)(x[i] - '0');
        now *= 8;
    }
    return res;
}

string to_nine(ll x) {
    string res;
    while(x > 0) {
        res.push_back((char)((x % 9) + '0'));
        x /= 9;
    }
    reverse(all(res));
    return res;
}

ll change_five(string s) {
    fore(x, s) if (x == '8') x = '5';
    return stoll(s);
}

signed main() {
    string n; cin >> n;
    int k; cin >> k;
    if (n == "0") {
        cout << 0 << newl;
        return 0;
    }
    rep(i, k) n = to_string(change_five(to_nine(to_decimal(n))));
    cout << n << newl;
}

/*
    コーナーケースつらたん
*/