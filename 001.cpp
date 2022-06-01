// 001
#include <bits/stdc++.h>
using namespace std;

int l;
int n;
int k;
vector<int> a;
vector<int> len;

long long sum;

void init() {
    a.insert(a.begin(), 0);
    a.push_back(l);
    for (int i = 1 ; i < n + 2 ; i++) len.emplace_back(a[i] - a[i - 1]);
}

bool judge(int p) {
    sum = l;
    int cnt = 0;
    int now = 0;
    for (int i = 0 ; i < n ; i++) {
        if (cnt == k) break;
        now += len[i]; sum -= len[i];
        if (now >= p) {
            now = 0;
            cnt++;
        }
    }

    if (cnt < k) return false;
    return sum >= p;
}

int solve() {
    int left = 0, right = l + 1;
    init();
    while(right - left > 1) {
        int mid = left + (right - left) / 2;
        if (judge(mid)) left = mid;
        else right = mid;
    }
    return left;
}

int main() {
    cin >> n >> l;
    cin >> k;
    a = vector<int>(n); for (auto & x : a) cin >> x;
    cout << solve() << endl;
}
