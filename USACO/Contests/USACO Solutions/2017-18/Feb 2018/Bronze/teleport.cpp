#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a,b,x,y,ans1,ans2,ans3;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    freopen("teleport.in","r",stdin);
    freopen("teleport.out","w",stdout);
    cin >> a >> b >> x >> y;
    ans1=abs(a-b); 
    ans2=abs(a-x)+abs(b-y);
    ans3=abs(a-y)+abs(b-x);
    cout << min(ans1,min(ans2,ans3));
    return 0;
}

