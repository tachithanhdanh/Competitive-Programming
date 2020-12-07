#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double d;
typedef float f;
using namespace std;
void solve(){ 
    f t,v,a; cin >> t >> v >> a;
    cout.setf(ios::fixed); cout.setf(ios::showpoint);
    cout.precision(1);
    cout << (t*2+v*2+a)/5;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    solve(); return 0;
}