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

const int MAXN = (int) 20;
int n; 
int arr[MAXN + 2];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    int x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    vector<pair<int , long long>> dp(MASK(n) , {inf , inf});
    dp[0] = {1 , 0};

    for(int mask = 0; mask < MASK(n); ++mask){
        for(int i = 0; i < n; ++i) {
            if (!BIT(mask , i)){
                int nxt_mask = MASK(i) | mask;
                pair<int,long long> nxt = dp[mask];
                if (nxt.second + arr[i] > x) nxt.second = arr[i] , nxt.first++; else nxt.second += arr[i];
                dp[nxt_mask] = min(dp[nxt_mask] , nxt);
            }
        }
    }

    cout << dp[MASK(n) - 1].first;
    return 0;
}