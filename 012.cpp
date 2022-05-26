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

class dsu {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

public:
    dsu(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0 ; i < n ; i++) parent[i] = i;
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    } 

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int h, w;
vvi grid;
dsu uf(h*w);

int f(int y, int x) {
    return y*w + x;
}

void solve() {
    vi d = {-1, 1};
    int q; cin >> q;
    if (q == 1) {
        int y, x; cin >> y >> x;
        y--; x--;
        grid[y][x] = 1;
        fore(dx, d) if (0 <= x + dx and x + dx < w) if (grid[y][x + dx] == 1) uf.merge(f(y, x), f(y, x + dx));
        fore(dy, d) if (0 <= y + dy and y + dy < h) if (grid[y + dy][x] == 1) uf.merge(f(y, x), f(y + dy, x));
    }
    if (q == 2) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        bool ok = true;
        if (!grid[y1][x1]) ok = false;
        if (!grid[y2][x2]) ok = false;
        if (!uf.same(f(y1, x1), f(y2, x2))) ok = false;
        cout << (ok ? "Yes" : "No") << newl;
    }
}

int main() {
    cin >> h >> w;
    uf = dsu(h*w);
    grid = vvi(h, vi(w, 0));
    int q; cin >> q;
    rep(_, q) {
        solve();
    }
}
