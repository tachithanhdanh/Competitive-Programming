#include <bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef short int si;
typedef long double ld;
typedef double db;
using namespace std;
void solve(){
    fl a,b,c,d,e; cin >> a >> b >> c >> d >> e ;
    fl ans=(fl)(a*2+b*3+c+d+e*2)/9;
    cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(1);
    cout << ans << endl;
    if (ans>=8.0) cout << "GIOI" << endl;
    else if(ans<8.0 && ans>=6.5) cout << "KHA" << endl;
    else if(ans<6.5 && ans>=5.0) cout << "TB" << endl;
    else if (ans<5.0) cout << "YEU" << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
