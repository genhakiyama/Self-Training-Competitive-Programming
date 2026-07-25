#include<bits/stdc++.h>
using namespace std;

const int MAXN = (int) 2e5;

int u[MAXN + 2] , v[MAXN + 2] , c[MAXN + 2];
vector<int> edge[MAXN + 2];    
int n , m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0);

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
    }

    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> c[i];
        edge[u[i]].push_back(i);
    }

    vector<long long> dp(n + 1 , (long long)1e18);

    priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
    
    dp[1] = 0;
    pq.push({dp[1] , 1});
    while (pq.size()){
        int source = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();
        if (cost != dp[source]) continue;

        for(int id : edge[source]){
            int to = source ^ u[id] ^ v[id];
            if (dp[to] <= dp[source] + c[id]) continue;
            dp[to] = dp[source] + c[id];
            pq.push({dp[to] , to});
        }
    }

    for(int i = 1; i <= n; ++i) cout << dp[i] << ' ';
}