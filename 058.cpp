#include <bits/stdc++.h>

// clang-format off

using namespace std;
#define all(a) a.begin(), a.end()
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

long long pow2(int x) {return x * x;}
bool isupper(char c) {return ('A' <= c and c <= 'Z');}
bool islower(char c) {return ('a' <= c and c <= 'z');}
bool isnumber(char c) {return ('0' <= c and c <= '9');}

// O(logX)
int getdigit(long long x) {
    int res = 0;
    while(x > 0) {
        res++;
        x /= 10;
    }
    return res;
}

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vp = vector<pair<int, int>>;
using vs = vector<string>;

const ll sup = LONG_LONG_MAX / 2 - 1;
const double pi = 3.141592653589793;

vi G;
vll ti;
int n;
ll k;

int f(int x) {
    int res = x;
    while(x > 0) {
        res += x % 10;
        x /= 10;
    }
    return (res % 100000);
}

int rec(int now, ll remin) {
    if (remin == 0) return now;
    if (ti[now] == -1) {
        ti[now] = remin;
    }
    else {
        remin %= (ti[now] - remin);
        if (remin == 0) return now;
    }
    return rec(G[now], remin - 1);
}

void solve() {
    G = vi(100000);
    rep(i, 100000) G[i] = f(i); 
    ti = vll(100000, -1);
    int ans = rec(n, k);
    cout << ans << newl;
}

int main() {
    cin >> n >> k;
    solve();
}
