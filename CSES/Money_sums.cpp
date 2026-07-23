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
    vector<int> arr(n + 2 , 0);
    int tot = 0;
    for(int i = 1; i <= n; ++i) cin >> arr[i] , tot += arr[i];
    sort(arr.begin() + 1 , arr.begin() + n + 1);
    vector<int> pos_sum(tot + 2 , 0);

    pos_sum[0] = 1;
    vector<int> ans;
    for(int i =1; i <= n ; ++i){
        for(int sum = tot; sum >= arr[i]; --sum) maximize(pos_sum[sum] , pos_sum[sum - arr[i]]);
    }

    for(int i = 1; i <= tot; ++i) if (pos_sum[i]) ans.push_back(i);
    
    cout << sz(ans) << '\n';
    for(auto& x : ans) cout << x << ' ';
    
}
