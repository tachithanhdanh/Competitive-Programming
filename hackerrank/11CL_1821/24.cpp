#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <sstream>
#define endl "\n"
#define vi vector<int>
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
    //Write your code here.
    int n,sum=0; cin >> n; vi a(n);
    for (int i=0;i<n;++i){
        cin >> a[i];sum+=a[i];
    }
    int minsum=sum,s1=0,s2=0,k,t=0;
    for (int i=0;i<n;++i){
        s1=0; s2=0; k=n-1;
        for(int j=i;j<n;++j){
            ++t;
            s1+=a[j];s2+=a[j];
            minsum=min(minsum,sum-s1);
            minsum=min(minsum,s2);
        }
    }
    cout << minsum << endl; //<< t;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
