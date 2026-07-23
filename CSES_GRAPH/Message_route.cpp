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
int vis[MAXN + 2];

int n , m;

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
        int u , v; cin >> u >> v;
        edge[u].push_back(v) , 
        edge[v].push_back(u);
    }

    memset(vis , -1 , sizeof(vis));

    queue<int> q;
    vis[1] = 0;
    q.push(1);
    
    while (q.size()){
        int u = q.front(); q.pop();

        for(auto& v : edge[u]){
            if (vis[v] == -1) {
                vis[v] = u;
                q.push(v);
            }
        }
    }

    if (vis[n] == -1) return cout << "IMPOSSIBLE" , 0;
    vector<int> ans;
    while (n != 1){
        ans.push_back(n);
        n = vis[n];
    }
    ans.push_back(1);
    reverse(ans.begin() , ans.end());
    cout << sz(ans) << '\n';
    for(auto& x : ans) cout << x << ' ';

    return 0;
}