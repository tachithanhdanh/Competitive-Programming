#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

void solve(){
    int n; cin >> n;
    int a=0,sum=0,maxnum=0;
    while(n){
        ++a;
        maxnum=max(maxnum,n%10);
        sum+=n%10;n/=10;
    }
    cout << a << endl << maxnum << endl << sum << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
