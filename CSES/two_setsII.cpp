#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int inf = 1e9 + 7;
const bool debug = false;
#define ll long long 
#define BIT(mask , x) (((mask) >> (x)) & (1))
#define MASK(x) (ll)((1) << (x))
#define sz(x) (int)(x).size()

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

int add(int x , int y){
        return (x + y >= MOD ? x + y - MOD : x + y);
    }

int mul(int x , int y){
    return (ll)x * y % MOD;
}

int power(int a , int b){
    int res = 1;
    for(; b; b >>= 1 , a = mul(a , a)){
        if (b & 1) res = mul(res , a);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    int n; cin >> n;
    int tot = n * (n + 1) / 2;
    
    vector<int> ways(tot + 1 , 0);
    
    if (tot % 2 != 0) return cout << 0 , 0;

    tot /= 2;

    ways[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int sum = tot; sum >= i; --sum){
            ways[sum] = add(ways[sum] , ways[sum - i]);
        }
    }

    cout << mul(ways[tot] , power(2 , MOD - 2));

    return 0;
}