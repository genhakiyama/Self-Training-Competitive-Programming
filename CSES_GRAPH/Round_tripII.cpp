#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = (int) 1e5;
vector<int> edge[MAXN + 2];
int n , m ;
int start_point , end_point;
int trace[MAXN + 2] , vis[MAXN + 2];
 
bool dfs(int u){
    vis[u] = 1;
    for(int v : edge[u]){
        if (vis[v] == 2) continue;
        if (vis[v] == -1){
            trace[v] = u;
            if (dfs(v)) return true;
        }
 
        if (vis[v] == 1) {
            start_point = v;
            end_point = u;
            return true;
        }
    }
    vis[u] = 2;
 
    return false;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ; 
 
    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
 
    memset(vis , -1 , sizeof(vis));
 
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a , b; cin >> a >> b;
        edge[a].push_back(b);
    }
 
    bool have = false;
    for(int i = 1; i <= n; ++i){
        if (vis[i] == -1) {
            if (dfs(i)) {
                
                have = true;
                break;
            }
        }
    }
 
    if (!have) return cout << "IMPOSSIBLE" , 0;
    vector<int> path;
    path.push_back(start_point);
    while (end_point != start_point){
        path.push_back(end_point);
        end_point = trace[end_point];
    }
    path.push_back(start_point);
    reverse(path.begin() , path.end());
    cout << path.size() << '\n';
    for(auto& x : path) cout << x << ' ';
    return 0;
}