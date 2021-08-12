#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 8;

vector<int> prime;
bool isprime[maxn];

void sieve(int n){
	isprime[2] = 1;

	for(int i = 3; i <= n; i += 2) isprime[i] = 1;
	for(long long i = 2; i <= n; ++i) if(isprime[i]){
		for(long long j = i * i; j <= n; j += i) isprime[j] = 0;
		prime.push_back(i);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	sieve(n);

	int l = 0, r = prime.size() - 1;
	while(l <= r){
		int val = prime[l] + prime[r];
		if(val == n){
			cout << prime[l] << ' ' << prime[r];
			return 0;
		}
		if(val < n) ++l;
		else --r;
	}

	cout << -1;
}