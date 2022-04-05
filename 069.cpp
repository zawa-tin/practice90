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

const ll mod = 1000000007;

long long modpow(int n, int m, int mod)
{
    long long res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = res * n % mod;
        n = n * n % mod;
        m >>= 1;
    }

    return res;
}

ll solve(ll n, int k) {
    if (n == 1) return k;
    if (n == 2 and k == 2) return 2;
    if (k < 3) return 0;
    ll res = ((k % mod) * ((k - 1) % mod)) % mod;
    if (n == 2) return res;

    ll p = modpow(k - 2, n - 2, mod);
    res *= p;
    res %= mod;

    return res; 
}

signed main() {
    ll n; cin >> n;
    int k; cin >> k;
    
    cout << solve(n, k) << newl;
}

/*
    2分累乗法
    コーナーケースの実装下手
*/