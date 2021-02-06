#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 

int n,dist;

int ans() {
	int minspeed;
	cin >> minspeed;
	int lhstravel = 0;
	int rhstravel = 0;
	int timeused = 0;
	for(int currspeed = 1;; currspeed++) {
		lhstravel += currspeed;
		timeused++;
		if(lhstravel + rhstravel >= dist) return timeused;
		if(currspeed >= minspeed) {
			rhstravel += currspeed;
			timeused++;
			if(lhstravel + rhstravel >= dist) return timeused;
		}
	}
}

void solve(){
	cin >> dist >> n;
	for (int i=0;i<n;++i){
		cout << ans() << endl;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("race.in", "r", stdin); 
	freopen("race.out", "w", stdout);
	solve();
	return 0;
}