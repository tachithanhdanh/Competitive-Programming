#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back()

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

//loops
#define trav(a,x) for(auto& a : x)
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define F0R(i,a) FOR(i,0,a)

void setIO(){
    cin.tie(0)->ios::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL
}

//constant initialization
const int maxn = 1e3+10;

//variables used for the current problem
int n,even,odd,a,ans;

void solve(){
    cin >> n;
    F0R(i,n){
        cin >> a; (a&1? ++odd : ++even);
    }
    while (odd || even){
        if (ans&1){
            if (odd==2 && !even) break;
            if (odd) --odd;
            else break;
            //cout << ans << " " << odd << endl;
        }
        else{
            if (even) --even;
            else{
                if (odd>=2) odd-=2;
                else break;
                //cout << ans << " " << odd << endl;
            }
        }
        ++ans;
    }
    cout << ans;
    return;
}

int main(){
    setIO();
    solve();
    return 0;
}
