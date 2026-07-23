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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    int n; cin >> n;
    vector<int> arr(n + 1 , 0);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    vector<vector<ll>> player1(n + 1 , vector<ll>(n + 1 , -inf));
    vector<vector<ll>> player2(n + 1 , vector<ll>(n + 1 , -inf));

    
    for(int i = 1; i <= n; ++i) player2[i][i] = 0 ;
    for(int length = 1; length <= n; ++length){
        for(int l = 1; l + length - 1 <= n; ++l){
            int r = l + length - 1;
            player1[l][r] = (l == r ? arr[l] : max(player2[l + 1][r] + arr[l] , player2[l][r - 1] + arr[r]));
            player2[l][r] = (l == r ? 0 : min(player1[l + 1][r] , player1[l][r - 1]));
        }
    }

    cout << player1[1][n];

    return 0;
}