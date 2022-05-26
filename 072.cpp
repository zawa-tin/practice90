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

int h, w;
vs grid;
vvi G;
vvi dp;

int f(int y, int x) {
    return y * w + x;
}

void make() {
    vi d = {-1, 1};
    rep(y, h) rep(x, w) {
        if (grid[y][x] == '#') continue;
        fore(dx, d) if (0 <= x + dx and x + dx < w) if (grid[y][x + dx] == '.') G[f(y, x)].push_back(f(y, x + dx));
        fore(dy, d) if (0 <= y + dy and y + dy < h) if (grid[y + dy][x] == '.') G[f(y, x)].push_back(f(y + dy, x));
    }
}

void rec(int now, int start, int st) {
    if (st != 0 and now == start) return;
    fore(x, G[now]) {
        if ((st >> x) & 1) continue;
        chmax(dp[start][st | (1 << x)], dp[start][st] + 1);
        rec(x, start, st | (1 << x));
    } 
}

void solve() {
    G = vvi(h*w);
    make();
    dp = vvi(h*w, vi(1 << (h*w), 0));
    rep(i, h * w) rec(i, i, 0);
    int ans = -1;
    rep(i, h*w) rep(j, 1 << (h*w)) if ((j >> i) & 1) chmax(ans, dp[i][j]);
    cout << (ans < 3 ? -1 : ans) << newl;
}

int main() {
    cin >> h >> w;
    grid = vs(h); fore(x, grid) cin >> x;
    solve();
}
