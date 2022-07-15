#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <atcoder/modint>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/scc>

#define int long long
#define all(x) begin(x), end(x)

using namespace std;
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvc = vector<vector<char>>;

void debug(vector<int> a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

void debug(vector<vector<int>> a) {
    for (auto y : a) debug(y);
}

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b and (a = b, true);}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b and (a = b, true);}

const int supl = LONG_LONG_MAX - 100;

void main_() {
    int h, w; cin >> h >> w;
    pii start;
    pii goal;
    cin >> start.first >> start.second >> goal.first >> goal.second;
    start.first--;
    start.second--;
    goal.first--;
    goal.second--;
    vs grid(h);
    for (auto& s : grid) cin >> s;
    
    // int d[] = {-1, 1};
    auto f = [&](int y, int x) -> int {
        return 4*(y*w + x);
    };
    auto in = [&](int y, int x) -> bool {
        return 0 <= x and x < w and 0 <= y and y < h;
    };
    auto reach = [&](int y, int x) -> bool {
        return in(y, x) and grid[y][x] == '.';
    };
    auto make = [&]() -> vvp {
        vvp res(4*h*w);
        for (int y = 0 ; y < h ; y++) for (int x = 0 ; x < w ; x++) if (reach(y, x)) {
            if (reach(y - 1, x)) {
                res[f(y, x) + 1].emplace_back(f(y - 1, x), 1);
                res[f(y, x) + 1].emplace_back(f(y - 1, x) + 1, 0);
                res[f(y, x) + 1].emplace_back(f(y - 1, x) + 2, 1);
            }
            if (reach(y + 1, x)) {
                res[f(y, x) + 3].emplace_back(f(y + 1, x), 1);
                res[f(y, x) + 3].emplace_back(f(y + 1, x) + 2, 1);
                res[f(y, x) + 3].emplace_back(f(y + 1, x) + 3, 0);
            }
            if (reach(y, x - 1)) {
                res[f(y, x)].emplace_back(f(y, x - 1), 0);
                res[f(y, x)].emplace_back(f(y, x - 1) + 1, 1);
                res[f(y, x)].emplace_back(f(y, x - 1) + 3, 1);
            }
            if (reach(y, x + 1)) {
                res[f(y, x) + 2].emplace_back(f(y, x + 1) + 1, 1);
                res[f(y, x) + 2].emplace_back(f(y, x + 1) + 2, 0);
                res[f(y, x) + 2].emplace_back(f(y, x + 1) + 3, 1);
            }
        }
        return res;
    };
    auto bfs = [&](vvp G) -> int {
        deque<int> deq;
        vi dist(4*h*w, supl);
        for (int i = 0 ; i < 4 ; i++) {
            deq.emplace_back(f(start.first, start.second) + i);
            dist[f(start.first, start.second) + i] = 0;
        }
        while (deq.size()) {
            int v = deq.front();
            deq.pop_front();
            for (auto [x, c] : G[v]) {
                if (chmin(dist[x], dist[v] + c)) {
                    if (c) deq.emplace_back(x);
                    else deq.emplace_front(x);
                }
            }
        }
        int res = supl;
        for (int i = 0 ; i < 4 ; i++) chmin(res, dist[f(goal.first, goal.second) + i]);
        // for (auto d : dist) cout << d << ' ';
        // cout << endl;
        return res;
    };
    cout << bfs(make()) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    main_();

    return 0;
}
