#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const bool debug = false;
#define ll long long 
#define BIT(mask , x) (((mask) >> (x)) & (1))
#define MASK(x) (ll)((1) << (x))
#define sz(x) (int)(x).size()
const int inf = (int)1e9;

template<class T1 , class T2>
	bool maximize(T1 &x , T2 y){
		if (x < y) return x = y , true;
		return false;
	}
	
template<class T1 , class T2>
	bool minimize(T1 &x , T2 y){
		if (x > y) return x = y  , true; 
		return false;
	}


	int add(int a , int b){
		return (a + b >= MOD ? a + b - MOD : a + b);
	}
	int mul(int a , int b){
		return (1ll * a * b) % MOD;
	}

const int MAXN = 1e6 + 5;

int dp[MAXN + 2][3] = {};

void solve(){
	int n; cin >> n;
	cout << add(dp[n][0] , dp[n][1]) << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0) ; 

	#define name "main"
	if (fopen(name".inp","r")){
		freopen(name".inp","r",stdin);
	}

	dp[1][1] = dp[1][0] = 1;

	for(int i = 2; i <= MAXN; ++i){
		dp[i][0] = add(mul(4 , dp[i - 1][0]) , dp[i - 1][1]);
		dp[i][1] = add(mul(2 , dp[i - 1][1]) , dp[i - 1][0]);
	}

	int tt; cin >> tt;
	while(tt--) solve();

	return 0;
}