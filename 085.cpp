#include <bits/stdc++.h>

// clang-format off
// 085

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

ll k;
vll divs;

void make() {
    for (ll i = 1 ; i*i <= k ; i++) if (k % i == 0) {
        divs.push_back(i);
        if (i == k / i) continue;
        divs.push_back(k / i);
    }
    sort(all(divs));
}

void solve() {
    make();
    int count = 0;
    for (int i = 0 ; i < divs.size() and divs[i] < 1000000 and divs[i]*divs[i]*divs[i] <= k ; i++)
        for (int j = i ; j < divs.size() and divs[j] < 1000000000 and k / (divs[i]*divs[j]) >= divs[j]; j++)
            if (k % (divs[i] * divs[j]) == 0) count++;

    cout << count << newl;
}

int main() {
    cin >> k;
    solve();
}
