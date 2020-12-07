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
typedef unsigned int ui;
using namespace std;

void solve(){
    int t,mn=INT_MAX,mx=INT_MIN; cin >> t; int *a= new int[t];
    for (int i=0;i<t;++i){
        cin >> a[i];
        if(a[i]>mx) mx=a[i];
        if(a[i]<mn) mn=a[i];
    }
    for (int i=0;i<t;++i){
        if (a[i]<mx && a[i]>mn) cout << a[i] << endl;
    }
    delete[]a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
