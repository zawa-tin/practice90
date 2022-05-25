#include <bits/stdc++.h>

// 026
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

int n;
vvi p;

void solve() {
    vvi grid(1001, vi(1001, 0));
    fore(y, p) {
        grid[y[0]][y[1]]++;
        grid[y[2]][y[3]]++;
        grid[y[2]][y[1]]--;
        grid[y[0]][y[3]]--;
    }

    vvi accum(1002, vi(1001, 0));
    rep (y, 1001) rep (x, 1001) accum[y][x + 1] = accum[y][x] + grid[y][x];
    rep (x, 1001) rep (y, 1001) accum[y + 1][x] += accum[y][x];

    vi ans(n + 1, 0);
    fore(y, accum) fore(x, y) ans[x]++;

    rep(i, 1, n + 1) cout << ans[i] << newl;
}

int main() {
    cin >> n;
    p = vvi(n, vi(4));
    fore(y, p) cin >> y[1] >> y[0] >> y[3] >> y[2];
    solve();
}
