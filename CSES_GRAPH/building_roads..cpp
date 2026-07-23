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

vector<int> edge[MAXN + 2];
bool vis[MAXN + 2];

int n , m;

void dfs(int u){
    vis[u] = true;
    for(auto& v : edge[u]){
        if (!vis[v]) {
            dfs(v);
        }
    }

    return;
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
    for(int i = 1; i <= m ;++i){
        int u , v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> ans;

    for(int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            ans.push_back(i);
        }
    }

    cout << (int)ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); ++i) cout << ans[i - 1] << ' ' << ans[i] << '\n';

    return 0;
}