#include <bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef short int si;
typedef long double ld;
typedef double db;
typedef unsigned int ui;
typedef unsigned short int usi;
using namespace std;
void solve(){
    int n,k,a; cin >> n >> k;
    while(n--){
        --k;
        cin >> a;
        if(k) cout << a << " ";
    }   return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
