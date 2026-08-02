#include<bits/stdc++.h>
using namespace std;

const int MAXN = (int) 1e5;
const int MAXM = (int) 2e5;

int n , m;
int deg[MAXN + 2];
vector<int> edge[MAXN + 2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a , b; cin >> a >> b;
        deg[b]++;
        edge[a].push_back(b);
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) if (deg[i] == 0) q.push(i);
    vector<int> topo;
    while (q.size()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto& v : edge[u]){
            --deg[v];
            if (deg[v] == 0) q.push(v);
        }
    }
    for(int i = 1; i <= n; ++i) if (deg[i] != 0) return cout << "IMPOSSIBLE" , 0;
    for(auto& x : topo) cout << x << ' ';
}