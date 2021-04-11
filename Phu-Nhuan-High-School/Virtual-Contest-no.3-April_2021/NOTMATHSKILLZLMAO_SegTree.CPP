#include <bits/stdc++.h>
using namespace std;

typedef long long lol;
typedef pair<int, int> ii;
typedef pair<lol, lol> ll;

struct segmentTree{
    vector<lol> tree;
    int size;

    segmentTree(int n){
        size = round(pow(2, ceil(log2(n))));
        tree.assign(2 * size + 5, 0);
    }

    void update(int pos, lol val){
        pos += size;
        tree[pos] = val;
        for(pos /= 2; pos > 0; pos /= 2) tree[pos] = __gcd(tree[pos * 2], tree[pos * 2 + 1]);
    }

    lol gcd(int l, int r){
        l += size;
        r += size;
        lol ans = tree[l];
        while(l <= r){
            if(l % 2 == 1) ans = __gcd(ans, tree[l++]);
            if(r % 2 == 0) ans = __gcd(ans, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    segmentTree it(n);

    for(int i = 0; i < n; ++i){
        lol temp;
        cin >> temp;
        it.update(i, temp);
    }

    lol ans = INT_MIN;
    for(int i = 0; i + k - 1 < n; ++i){
        ans = max(ans, it.gcd(i, i + k - 1));
    }

    cout << ans;
}