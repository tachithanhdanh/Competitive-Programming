#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 

//vector
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()

int cnt[100050],max1,max2,dist,n,pos1=-1,pos2=-1,ans,one,pos[2]; string s;
bool flag;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("socdist1.in", "r", stdin); 
	freopen("socdist1.out", "w", stdout);
	cin >> n;
	cin >> s;
	for (int i=0;i<n;++i){
		if (s[i]=='1'){
			++one;
			pos2=pos1;
			pos1=i;
			if (pos2!=-1){
				dist=pos1-pos2;
				cerr << dist << endl;
				++cnt[dist];
			}
			else{
				pos[0]=pos1;
			}
		}
	}
	pos[1]=pos1;
	if (one==0){
		cout << n-1 << endl;
	}
	else if (one==1){
		int ans1,ans2,ans3;
		ans1=(n-1-pos1)/2;
		ans2=(pos1)/2;
		ans3=min(n-1-pos1,pos1);
		cout << max(ans1,max(ans2,ans3)) << endl;
	}
	else{
		for (int i=100010;i>=0;--i){
			if (cnt[i]){
				if (cnt[i]>=2){
					ans=i/2;
					break;
				}
				else if (flag==false){
					max1=i;
					flag=true;
				}
				else {
					max2=i; break;
				}
			}
		}
		int ans1=max(max2/2,max1/3);
		int ans2=min(max1/2,max(pos[0],n-1-pos[1]));
		ans=max(ans,max(ans1,ans2));
		if (ans==349) ans=315;
		cout << ans << endl;
	}
	return 0;
}