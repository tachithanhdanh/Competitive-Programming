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
const int maxn = 25;

//variables used for the current problem
int n; ll ans,cnt; vi a,b; bool flag;

void solve(){
    cin >> n;
    a.rsz(n); b.rsz(n);
    trav(i,a) cin >> i;
    trav(i,b) cin >> i;
    sort(all(a)); sort(all(b));
    if (n<=8){
        do{
        flag = true;
        F0R(i,n){
            flag = flag && a[i]<=b[i];
        }
        ans+=flag;
        } while(next_permutation(all(a)));
        cout << ans;
    }
    else{
        F0R(i,n){
            if (a[i]>b[i]){
                cout << 0; return;
            }
        }
        ans = 1;
        F0R(i,n){
            cnt = 1;
            FOR(j,i+1,n){
                if (a[i]<=b[j] && a[j]<=b[i]){
                    ++cnt;
                }
            }
            ans *= cnt;
        }
        cout << ans;
    }
    return;
}

int main(){
    setIO();
    solve();
    return 0;
}
