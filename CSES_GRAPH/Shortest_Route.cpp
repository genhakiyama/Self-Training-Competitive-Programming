#include<bits/stdc++.h>
using namespace std;

const int N = 500;
    long long edge[N + 2][N + 2];
    int n , m , q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ; 

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
    }

    cin >> n >> m >> q;

    memset(edge , 0x3f , sizeof(edge));

    for(int i = 1; i <= n; ++i) edge[i][i] = 0;

    for(int i = 1; i <= m; ++i) {
        int u , v; 
        cin >> u >> v;
        long long w; cin >> w;

        edge[u][v] = min(edge[u][v] , w);
        edge[v][u] = min(edge[v][u] , w);
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                edge[i][j] = min(edge[i][j] , edge[i][k] + edge[k][j]);
            }
        }
    }

    while(q--){
        int a , b; cin >> a >> b;
        if (edge[a][b] == edge[0][0]) cout << -1 << '\n'; else cout << edge[a][b] << '\n';
    }
}