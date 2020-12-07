#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int fw[MXN];
int n;

struct segments {
    int x, y;
    bool operator < (const segments & temp) const {
        if (temp.y == y) {
            return x < temp.x;
        }
        return y < temp.y;
    } 
} seg[MXN];

void update(int x) {
    while (x < MXN) {
        fw[x]++;
        x += (x & (-x));
    }
}

int get(int x) {
    int sum = 0;
    while (x > 0) {
        sum += fw[x];
        x -= (x & (-x));
    }
    return sum;
}

int main() {
    //freopen("input.000", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> seg[i].x >> seg[i].y;
    }

    sort(seg, seg + n);
    vector < int > p;
    for(int i = 0; i < n; i++) 
        p.push_back(seg[i].x);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    long long res = 0;
    for(int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(p.begin(), p.end(), seg[i].x) - p.begin() + 1;
        res += get(pos);
        update(pos + 1);
    }

    cout << res; 
    return 0;
}