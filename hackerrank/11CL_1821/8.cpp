#include <iostream>
#include <string>
#include <vector>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//#include <cnetdb>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <cstdarg>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <sstream>
#include <numeric>
#include <iterator>
#include <utility>
#include <stack>
#include <functional>
#include <deque>
#include <complex>
#include <bitset>
#include <list>
#include <array>
#include <regex>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <typeinfo>
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
    int a,b,c;
    cin >> a >> b >> c;
    if ( a<0 || b<0 || c<0 ) cout << -1;
    else if (a+b<=c || a+c<=b || b+c<=a) cout << -1;
    else {
        cout << a+b+c;
        fl p=(fl)(a+b+c)/2; fl s=sqrt(p*(p-(fl)a)*(p-(fl)b)*(p-(fl)c));
        cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(1);
        cout << endl << s;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
