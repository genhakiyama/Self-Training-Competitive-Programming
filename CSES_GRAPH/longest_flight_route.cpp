#include<bits/stdc++.h>
using namespace std;

template<class T1, class T2>
    bool maximize(T1 &a , T2 b){
        if (a < b) return a = b , true;
        return false;
    }

const int MAXN = (int) 1e5;
int n , m;
vector<int> edge[MAXN + 2] ;
vector<pair<int , pair<int,int>>> new_edge[MAXN + 2];
map<int , bool> mp[MAXN + 2];
int deg[MAXN + 2] , dp[MAXN + 2] = {} ;
int trace[MAXN + 2] = {};

//...
    bool del[MAXN + 2];
    int low[MAXN + 2] = {} , num[MAXN + 2] = {} , ID[MAXN + 2] = {};
    vector<int> order ;
    vector<int> bag[MAXN + 2];
    int times = 0 , scc = 0;

    void tarjan(int u){
        order.push_back(u);
        low[u] = num[u] = ++times;
        for(int v : edge[u]){
            if (del[v]) continue;
            if (!low[v]){
                tarjan(v);
                low[u] = min(low[u] , low[v]);
            } else low[u] = min(low[u] , num[v]);
        }

        if (low[u] == num[u]){
            int v;
            ++scc;
            do{
                v = order.back(); order.pop_back();
                ID[v] = scc;
                del[v] = true;
                bag[scc].push_back(v);
            } while (v != u);
        }
    }

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

    memset(dp , -0x3f , sizeof(dp));
    dp[1] = 0;
    queue<int> q;
    for(int i = 1; i <= n; ++i) if (deg[i] == 0) q.push(i);
    vector<int> topo;
    while (q.size()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : edge[u]) {
            --deg[v];
            if (maximize(dp[v] , dp[u] + 1)) {
                trace[v] = u;
            }
            if (deg[v] == 0) q.push(v);
        }
    }
    if (dp[n] < 0) return cout << "IMPOSSIBLE" , 0;
    vector<int>ans;
    while (n != 1) {
        ans.push_back(n);
        n = trace[n];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(auto& x : ans) cout << x << ' ';
    return 0;
}