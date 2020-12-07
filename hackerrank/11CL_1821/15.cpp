#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Another solution
/*int GCD(int a,int b){
    if (b==0) return a;
    else if (a==0) return b;
    else {
        while (b){
            int temp; temp=b;
            b=a%b; a=temp;
        }   return a;
    }
}
void solve(){
    int a,b; cin >> a >> b;
    cout << GCD(a,b);
} */

int main() {
    int a,b; cin >> a >> b;
    cout << __gcd(a,b);
    return 0;
}