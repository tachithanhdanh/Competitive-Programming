#include <bits/stdc++.h>
using namespace std

int cnt1[101],cnt2[101],a,f=1000,s=1000,ans; bool cnt[10001];

void dfs(int k){
	if (k==5){
		cnt[f]=true;
		return;
	}
	for (int i=0;i<101;++i){
		if (k&1){
			if (cnt1[i]){
				--cnt1[i]; ++cnt2[i];
				s+=i; f-=i;
				dfs(k+1);
				++cnt1[i]; --cnt2[i];
				s-=i; f+=i;
			}
		}
		else {
			if (cnt2[i]){
				--cnt2[i]; ++cnt1[i];
				s-=i; f+=i;
				dfs(k+1);
				++cnt2[i]; --cnt1[i];
				s+=i; f-=i;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("backforth.in", "r", stdin); 
	freopen("backforth.out", "w", stdout);
	for (int i=0;i<10;++i){
		cin >> a; ++cnt1[a];
	}
	for (int i=0;i<10;++i){
		cin >> a; ++cnt2[a];
	}
	dfs(1);
	for (int i=0;i<10001;++i){
		ans+=cnt[i];
	}
	cout << ans;
	return 0;
}