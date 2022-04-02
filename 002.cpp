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

bool judge(string s) {
    stack<char> stk;
    fore(x, s) {
        if (x == '(') stk.push('(');
        else if (x == ')') {
            if (stk.empty()) return false;
            stk.pop();
        }
        else return false;
    }
    return stk.empty();
}

signed main() {
    int n; cin >> n;
    vs ans;
    rep(bit, (1 << n)) {
        string s;
        rep(i, n) {
            if (bit & (1 << i)) s += '(';
            else s += ')';
        }
        if (judge(s)) ans.push_back(s);
    }
    sort(all(ans));
    fore(x, ans) cout << x << newl;
}

/*
    僕の解法
    ビット全探索
    スタックで()のペアを作れなかったら良くない文字列
    解説
    '('の数-')'をの累積が0以上であれば良い文字列
*/