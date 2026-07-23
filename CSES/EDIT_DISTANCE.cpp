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

const int MAXN = 5e3 + 2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        // freopen(name".out","w",stdout);
    }
    
    string s1 , s2; cin >> s1 >> s2;
    s1 = '#' + s1 , s2 = '#' + s2;
    int n = sz(s1) - 1 , m = sz(s2) - 1;

    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , inf));
    
    dp[0][0] = 0;

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            if (i && j) dp[i][j] = dp[i - 1][j - 1] + (s1[i] != s2[j]);
            if (i - 1 >= 0) minimize(dp[i][j] , dp[i - 1][j] + 1);
            if (j - 1 >= 0) minimize(dp[i][j] , dp[i][j - 1] + 1);
        }
    }

    cout << dp[n][m];

}