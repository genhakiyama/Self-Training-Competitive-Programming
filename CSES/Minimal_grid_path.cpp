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

    
 
    vector<vector<int>> arr(n + 1 , vector<int>(n + 1 , 0));
    vector<vector<bool>> used(n + 1 , vector<bool>(n + 1 , false));
    vector<vector<pair<int,int>>> layer(2 * n + 1);
    used[1][1] = true;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char c; cin >> c;
            arr[i][j] = (int)c - 'A';
        }
    }

    int turn = 0;

    for(int i = 1; i <= n; ++i) {
        ++turn;
        int x = 1 , y = i;
        while (y >= 1){
            layer[turn].push_back({x++ , y--});
        }
    }

    for(int i = 2; i <= n; ++i){
        ++turn;
        int x = n , y = i;
        while (y <= n){
            layer[turn].push_back({x-- , y++});
        }
    }

    used[1][1] = true;
    for(int i = 1; i <= turn; ++i){
        int ans = 35;
        for(auto& x : layer[i]){
            if (used[x.first][x.second]) minimize(ans , arr[x.first][x.second]);
        }
        cout << char(ans + 'A');
        for(auto& x : layer[i]){
            if (used[x.first][x.second] && arr[x.first][x.second] == ans) {
                if (x.first + 1 <= n) used[x.first + 1][x.second] = true;
                if (x.second + 1 <= n) used[x.first][x.second + 1] = true;
            }
        }
    }
}
