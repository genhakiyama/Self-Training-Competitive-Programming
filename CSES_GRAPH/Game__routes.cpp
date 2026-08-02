#include<bits/stdc++.h>
using namespace std;

template<class T1, class T2>
    bool maximize(T1 &a , T2 b){
        if (a < b) return a = b , true;
        return false;
    }
const int MOD = (int)1e9 + 7;
    int add(int a , int b){
        return (a + b >= MOD ? a + b - MOD : a + b);
    }
const int MAXN = (int) 1e5;
int n , m;
vector<int> edge[MAXN + 2] ;
int deg[MAXN + 2] , dp[MAXN + 2] = {} ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ; 
    
    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a , b;
        cin >> a >> b;
        edge[a].push_back(b);
        ++deg[b];
    }

    memset(dp , 0 , sizeof(dp));
    dp[1] = 1;
    queue<int> q;
    for(int i = 1; i <= n; ++i) if (deg[i] == 0) q.push(i);
    vector<int> topo;
    while (q.size()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : edge[u]) {
            --deg[v];
            dp[v] = add(dp[v] , dp[u]);
            if (deg[v] == 0) q.push(v);
        }
    }
    
    cout << dp[n];
    return 0;
}