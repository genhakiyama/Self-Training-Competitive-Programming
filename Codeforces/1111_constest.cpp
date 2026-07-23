#include<bits/stdc++.h>
using namespace std;

const bool debug = false;

const int MOD = 998244353;
#define ll long long 
#define BIT(mask , x) (((mask) >> (x)) & (1))
#define MASK(x) (ll)((1) << (x))
#define sz(x) (int)(x).size()
const int INF = (int)1e9;

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


void solve(){
    int n; cin >> n;
    vector<int> arr(n + 2 , 0) , brr(n + 2 , 0);
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= n; ++i) cin >> brr[i];
    
    int match_zero = 0 , match_ones = 0;
    int ones = 0 , zero = 0;
    
    for(int i = 1; i <= n; ++i) {
    	if (arr[i] != brr[i]){
    		if (arr[i] == 0) zero++; else ones++;
		}
		else {
			match_zero += arr[i] == 0;
			match_ones += arr[i] == 1;
		}
	}
	
	if (arr == brr) return void(cout << 0 << '\n');
	if (ones > 0){
		if (ones % 2 == 0) cout << 2 << '\n'; else cout << 1 << '\n';
		return ;
	}
	if (match_zero == 0 || match_ones == 0) return void(cout << -1 << '\n');
	cout << 2 << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0) ; 
	
	#define name "main"
	if (fopen(name".inp" , "r")){
		freopen(name".inp","r",stdin);
        // freopen(name".out","w",stdout);
	}
	
	int tt ; cin >> tt;
    while (tt--) solve();
	
	return 0;
}
