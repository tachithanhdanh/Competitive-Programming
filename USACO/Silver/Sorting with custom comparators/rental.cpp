#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//vectors
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()

//pairs
#define f first
#define s second
#define mp make_pair

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	return;
}

const int maxN=1e5+10;
int N,M,R,c[maxN],r[maxN],q,p,pos1,pos2,n,milk,gallons; ll ans,res; 
vector<pair<int,int>> stores,qp;

bool comp(const pair<int,int> &p1, const pair<int,int> &p2){
	return p1.f>p2.f;
}

int main(){
	setIO("rental");
	cin >> N >> M >> R;
	for (int i=0;i<N;++i){
		cin >> c[i];
	}
	for (int i=0;i<M;++i){
		cin >> q >> p;
		stores.pb(mp(p,q));
	}
	for (int i=0;i<R;++i){
		cin >> r[i];
	}
	sort(c,c+N,greater<int>());
	sort(r,r+R,greater<int>());
	sort(all(stores),comp);
	int iStore=0,iRent=0,i=0;
	while(i<N){
		int litres=c[i];
		int moneyT=0,curI=iStore;
		int last=0;
		while (curI<M){
			int rest=min(stores[curI].s,litres);
			moneyT+=stores[curI].f*rest;
			litres-=rest;
			if (litres==0){
				last=rest;
				break;
			}
			else{
				++curI;
			}
		}
		if (iRent>=R || moneyT>r[iRent]){
			ans+=moneyT;
			iStore=curI;
			if (iStore<M) stores[iStore].s-=last;
			++i;
		}
		else{
			ans+=r[iRent]; ++iRent; --N;
		}
	}
	cout << ans;
	return 0;
}
