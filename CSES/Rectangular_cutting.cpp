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

const int MAXN = (int) 500;
int dp[MAXN + 2][MAXN + 2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

	int numrow , numcol; cin >> numrow >> numcol;
	
	
	vector<vector<int>> dp(numrow + 1 , vector<int>(numcol + 1 , inf));	

	for(int i = 1; i <= min(numrow , numcol); ++i) dp[i][i] = 1;

	for(int i = 1; i <= numrow; ++i){
		for(int j = 1; j <= numcol; ++j)
		{
			for(int t = 1; t <= j; ++t){
				int k = j - t;
				minimize(dp[i][j] , dp[i][t] + dp[i][k]);
			}

			for(int t = 1; t <= i; ++t) {
				int k = i - t;
				minimize(dp[i][j] , dp[t][j] + dp[k][j]);
			}

		}
	}

	cout << dp[numrow][numcol] - 1;

    
}