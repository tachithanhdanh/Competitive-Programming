#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef short int si;
typedef long double ld;
typedef double db;
using namespace std;
void solve(){
    ull ans=1;int n; cin >> n;
    for (int i=1;i*i<=n;++i){
        if (n%i==0){
            if(i*i==n){
                ans*=i;
            }
            else {
                ans*=(i*(n/i));
            }
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
