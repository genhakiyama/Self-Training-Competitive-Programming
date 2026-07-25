#include<bits/stdc++.h>
using namespace std;

const long long inf = (long long)1e18;
const int MAXN = (int) 2500;
const int MAXM = (int) 5000;

int u[MAXM + 2] , v[MAXM + 2] , w[MAXM + 2];
int n , m;

vector<long long> bellman_ford(vector<long long> dp){
    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[v[j]] = max(dp[v[j]] , dp[u[j]] + w[j]);
        }
    }
    return dp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ; 

    // freopen("main.inp","r",stdin);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
    }

    vector<long long> ans(n + 1 , -inf);
    ans[1] = 0;
    ans = bellman_ford(ans);
    vector<long long> tmp = bellman_ford(ans);
    cout << ans[n];
    
}