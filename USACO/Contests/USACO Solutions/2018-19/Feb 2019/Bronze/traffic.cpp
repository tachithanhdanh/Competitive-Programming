#include <bits/stdc++.h>
using namespace std;

//constant initialization
const int mod=1e9+7;

//variables used for the current problem
int N,A[100],B[100],a,b; string T[100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("traffic.in", "r", stdin); 
	freopen("traffic.out", "w", stdout);
	cin >> N;
	for (int i=0;i<N;++i) cin >> T[i] >> A[i] >> B[i];
	a=-mod; b=mod;
	for (int i=N-1;i>-1;--i){
		if (T[i]=="none") { a=max(a,A[i]); b=min(b,B[i]); }
		if (T[i]=="off") { a+=A[i]; b+=B[i]; }
		if (T[i]=="on") { a-=B[i]; b-=A[i]; a=max(0,a); }
	}
	cout << a << " " << b << '\n';
	a=-mod; b=mod;
	for (int i=0;i<N;++i){
		if (T[i]=="none") { a=max(a,A[i]); b=min(b,B[i]); }
		if (T[i]=="off") { a-=B[i]; b-=A[i]; a=max(a,0); }
		if (T[i]=="on") { a+=A[i]; b+=B[i]; }
	}
	cout << a << " " << b;
	return 0;
}