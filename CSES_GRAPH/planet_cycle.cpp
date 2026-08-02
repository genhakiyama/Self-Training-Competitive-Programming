#include<bits/stdc++.h>
using namespace std;

#define BIT(mask , x) (((mask) >> (x)) & (1))
#define MASK(x) ((long long)(1)<<(x))

const int MAXN = (int) 2e5;

vector<int> edge[MAXN + 2] , rev_edge[MAXN + 2];
int vis[MAXN + 2] , trace[MAXN + 2] , viss[MAXN + 2];
int n , q , start_point , end_point;
int  h[MAXN + 2] , val[MAXN + 2] , sz[MAXN + 2] = {};
bool cycle[MAXN + 2] = {};

bool finding_cycle(int u){
    vis[u] = 1;
    for(int v : edge[u]){
        if (vis[v] == 2) continue;
        if (vis[v] == -1) {
            trace[v] = u;
            if (finding_cycle(v)) {
                vis[u] = 2;
                return true;
            }
        }
        if (vis[v] == 1) {
            start_point = v;
            end_point = u;
            vis[u] = 2;
            return true;
        }
    }
    vis[u] = 2;
    return false;
}

void dfs(int u , int par){
    viss[u] = true;
    if (!cycle[u]) {
            if (cycle[par]) val[u] = par; else val[u] = val[par];
            h[u] = h[par] + 1;
        }
    for(int v : rev_edge[u]) if (!viss[v]) dfs(v , u);
    return ;
}

void trace_cycle(){
    if (start_point == -1) return;
    vector<int> path;
    while (start_point != end_point) {
        path.push_back(end_point);
        cycle[end_point] = true;
        end_point = trace[end_point];
    }
    path.push_back(start_point);
    cycle[start_point] = true;
    reverse(path.begin() , path.end());
    for(int i = 0; i < path.size(); ++i) val[path[i]] = i , vis[path[i]] = 2;
    for(int i = 0; i < path.size(); ++i) sz[path[i]] = path.size();
    dfs(path[0] , 0);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;
    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    cin >> n ;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        edge[i].push_back(x) , 
        rev_edge[x].push_back(i);
    }
    memset(vis , -1 , sizeof(vis));
    for(int i = 1; i <= n; ++i) if (vis[i] == -1) {
        if (finding_cycle(i)) {
            trace_cycle();
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        if (cycle[i]) cout << sz[i]; 
            else cout << h[i] + sz[val[i]] ;
        cout << ' ';
    }
}