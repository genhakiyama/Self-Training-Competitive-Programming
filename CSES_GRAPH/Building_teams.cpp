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
vector<int> edge[MAXN];
int vis[MAXN + 2];
int n , m;

bool dfs(int u , int depth){
    vis[u] = (depth % 2 == 0 ? 1 : 2);
    for(auto& v : edge[u]){
        if (vis[v] != -1 && vis[u] == vis[v]) return false;
        if (vis[v] == -1 && dfs(v , depth + 1) == false) return false;
    }
    return true;
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
    for(int i = 1; i <= m; ++i){
        int u , v;
        cin >> u >> v;
        edge[u].push_back(v) , 
        edge[v].push_back(u);
    }

    memset(vis , -1 , sizeof(vis));

    for(int i = 1; i <= n; ++i){
        if (vis[i] == -1 && dfs(i , 0) == false){
            return cout << "IMPOSSIBLE" , 0;
        }
    }

    for(int i = 1; i <= n; ++i) cout << vis[i] << ' ';

    return 0;
}