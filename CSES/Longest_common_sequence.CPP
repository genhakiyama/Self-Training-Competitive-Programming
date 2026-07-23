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
        freopen(name".out","w+",stdout);
    }

    int n , m ; cin >> n >> m;
    vector<int> arr(n + 1 , 0) , brr(m + 1 , 0);
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= m; ++i) cin >> brr[i];

    vector<vector<int>> f(n + 1 , vector<int>(m + 1 , 0));
    vector<vector<pair<int,int>>> trace(n + 1 , vector<pair<int,int>>(m + 1 , {0, 0}));


    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if (arr[i] == brr[j]) f[i][j] = f[i - 1][j - 1] + 1 , trace[i][j] = {i - 1 , j - 1};
            if (maximize(f[i][j] , f[i - 1][j])) trace[i][j] = {i - 1 , j};
            if (maximize(f[i][j] , f[i][j - 1])) trace[i][j] = {i , j - 1};
        }
    }

    cout << f[n][m];
    vector<int> ans;
    while (f[n][m] > 0){
        int temp_n , temp_m;
        int cur = f[n][m];
        
        temp_n = trace[n][m].first;
        temp_m = trace[n][m].second;

        if (f[temp_n][temp_m] != cur) ans.push_back(arr[n]);

        swap(temp_n , n) , swap(temp_m , m);
    }
    reverse(ans.begin() , ans.end()); cout << '\n';
    for(auto& x : ans) cout << x << ' ';
}