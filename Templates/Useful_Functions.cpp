void setIO(string name =""){
//Compile with those flags and to get the fastest performance
//g++.exe -std=c++11 -DLOCAL ${file} -o ${file_base_name}.exe -Wl,--stack,268435456 -O2 && ${file_base_name}.exe
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifdef LOCAL
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
	return;
}

//documentation: https://codeforces.com/blog/entry/65543
//Briefer version: https://cs.wmich.edu/~rhardin/cs111/debug.htm
//for printing variables when debugging
#ifdef LOCAL
#define debug(x) cout << (#x) << " is " << (x) << endl
#else
#define debug(x)
#endif // LOCAL

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7;
const ll maxn=1e7+10;

//variables used for the current problem
int n; ll x,m; 
//bool prime[maxn];
vector<bool> prime(maxn,true);
vi p((int)6e5);

ll sqrt(const ll &n) {
	assert(n>=0);
	if (n==1 || !n) return n;
	ll m=sqrt((double)n);
	for (ll i=m-2;i<=m+2;++i){
		if (i*i==n) return i;
	}
	return -1;
}

//Documentation: https://drive.google.com/file/d/1hSe9exLvXgzDtRlVLi3rRCIUE9w9EkmW/view
void sieve() {
	//memset(prime,true,sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2 * 2; i < maxn; i += 2) prime[i] = false;
	for (int i = 3 * 3; i < maxn; i += 3) prime[i] = false;
	for (int i = 5; i * i < maxn; i += 6) {
		if (prime[i]) for (int j = i * i; j < maxn; j += i) prime[j] = false;
		if (prime[i+2]) for (int j = (i+2) * (i+2); j < maxn; j += i + 2) prime[j] = false;
	}
	return;
}

void more_effective_sieve(){
	p[0] = 2; p[1] = 3;
	int pos = 2;
	for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t) {
		bool f = true;
		for (int j : p) {
			if (j * j > i) break;
			if (i % j == 0) {
				f = false; break;
			}
		}
		if (f) {
			p[pos] = i; ++pos;
		}
	}
	return;
}

//Documentation: https://drive.google.com/file/d/1hSe9exLvXgzDtRlVLi3rRCIUE9w9EkmW/view
//Time complexity O(sqrt(N)/3)
vector<pi> prime_factorization (int n) {
	vector<pi> factors;
	int cnt = 0;
	while (!(n&1)) n >>= 1, ++cnt;
	if (cnt) factors.pb(mp(2,cnt));
	cnt = 0;
	while (n % 3 == 0) {
		n /= 3; ++cnt;
	}
	if (cnt) factors.pb(mp(3,cnt));
	cnt = 0;
	for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				n /= i; ++cnt;
			}
			factors.pb(mp(i,cnt));
		}
	}
	return factors;
}

//Time complexity: O(sqrt(N)/6)
bool isPrime (ll n) {
	if (n<2) return false;
	if (n==2 || n==3 || n==5 || n==7) return true;
	if (!(n&1) || !(n%3)) return false;
	for (ll i=6; (i-1) * (i-1) <= n; i += 6) 
		if ( n % (i-1) == 0 || n % (i+1) == 0)
			return false; 
	return true;
}
	
/* Iterative Function to calculate (x^y) in O(log y) */
//https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
ll fast_pow_without_mod (ll x, uint y) 
{ 
	ll res = 1; // Initialize result 
	while (y > 0) { 
		// If y is odd, multiply x with result 
		if (y & 1) 
			res = res * x; 
		// n must be even now 
		y = y >> 1; // y = y/2 
		x = x * x; // Change x to x^2 
	} 
	return res; 
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
//https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
ll fast_pow_with_mod (ll x, uint y)  
{  
	ll res = 1; // Initialize result  
	x = x % MOD; // Update x if it is more than or equal to p 
	if (x == 0) return 0; // In case x is divisible by p; 
	while (y > 0)  
	{  
		// If y is odd, multiply x with result  
		if (y & 1) res = (res*x) % MOD;
		// y must be even now  
		y = y >> 1; // y = y/2  
		x = (x*x) % MOD;  
	}  
	return res;  
}  

//https://cp-algorithms.com/algebra/module-inverse.html#toc-tgt-2
//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
//https://vnoi.info/wiki/algo/math/modular-inverse.md#t%C3%ADnh-t%E1%BA%A5t-c%E1%BA%A3-ngh%E1%BB%8Bch-%C4%91%E1%BA%A3o-modulo-m
//https://usaco.guide/gold/modular/#modular-inverse
ll modular_inverse (ll x) {
	return fast_pow_with_mod(x,MOD-2);
}

// https://nguyenvanhieu.vn/thuat-toan-tim-uoc-chung-lon-nhat/#cach-3-tim-ucln-su-dung-giai-thuat-euclid
int GCD (int a, int b) {
	while (b){
		swap(a,b);
		b=b%a;
	}
	return a;
}

ll LCM (int a, int b) {
	return 1LL*a*b/GCD(a,b);
}	

//Set min-max value.
//Explantation: https://codeforces.com/blog/entry/78833
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)
