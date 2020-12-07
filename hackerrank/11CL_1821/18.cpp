#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
bool traidau(int a,int b){
    if (a>0 && b>0) return false;
    else if (a<0 && b<0) return false;
    else return true;
}

void solve(){
    int a,b,cnt=0;
    cin >> b;
    while(cin >> a){
        if(!a) break;
        if(traidau(a,b)) ++cnt;
        b=a;
    }
    cout << cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
