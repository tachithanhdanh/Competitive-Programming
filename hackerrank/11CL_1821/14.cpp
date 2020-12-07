#include <bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef short int si;
typedef long double ld;
typedef double db;
typedef unsigned int ui;
using namespace std;
bool isPrime(int n){
    if (n<2) return false;
    else if (n==2 || n==3 || n==5) return true;
    else if (!(n&1)) return false;
    else{
        for(int i=2;i*i<=n;++i){
            if (!(n%i)) return false;
        }   return true;
    }
}
void solve(){
    int n; cin >> n;
    if(isPrime(n)) cout <<  "so nguyen to";
    else cout << "khong la so nguyen to";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
