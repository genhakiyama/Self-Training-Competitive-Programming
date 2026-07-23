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
 
const int MAXN = (int) 1e5;
const int MAXM = (int) 2e5;
vector<pair<int , int>> edge[MAXN + 2];
int n , m , end_point , start_point;
int vis[MAXN + 2];
bool used[MAXM + 2];
 
bool dfs(int u){
    for(pair<int , int> v : edge[u]){
        if (used[v.second]) continue;
        if (vis[v.first] != -1){
            start_point = v.first;
            end_point = u;
            return true;
        }

        if (vis[v.first] == -1){
            vis[v.first] = u;
            used[v.second] = true;
            if (dfs(v.first)) return true;
        }           
    }
 
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
 
    cin >> n >> m;
    memset(vis , -1 , sizeof(vis));
    
    for(int i = 1; i <= m; ++i){
        int u , v; cin >> u >> v;
        edge[u].push_back({v , i});
        edge[v].push_back({u , i});
    }
 
    bool kt = false;
 
    for(int i = 1; i <= n && !kt; ++i) {
        if (vis[i] == -1){
            vis[i] = i;
            if (dfs(i)) kt = true;
        }
    }
 
    if (!kt) return cout << "IMPOSSIBLE" , 0;
    vector<int> ans; 
    ans.push_back(start_point);
    while (end_point != start_point){
        ans.push_back(end_point);
        end_point = vis[end_point];
    }
    ans.push_back(start_point);
    reverse(ans.begin() , ans.end());
    
    cout << ans.size() << '\n';
    for(auto& x : ans) cout << x << ' ';
 
    return 0;
}