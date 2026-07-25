#include<bits/stdc++.h>
using namespace std;

template<class T1 , class T2> 
    bool minimize(T1 &x , T2 y){
        if (x > y) return x = y , true;
        return false;
    }

const long long inf = (long long) 1e18;
const int MAXN = (int) 2500;
const int MAXM = (int) 5000;

vector<int> edge[MAXN + 2];
int n , m;
int u[MAXM + 2] , v[MAXM + 2] , w[MAXM + 2] ;
int trace[MAXN + 2];
bool vis[MAXN + 2] = {};

vector<long long> bellman_ford(vector<long long> dp){
    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= m; ++j){
            if (minimize(dp[v[j]] , dp[u[j]] + w[j])) {
                trace[v[j]] = u[j];
            }
        }
    }
    return dp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
    }

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        if (u[i] == v[i] && w[i] < 0) {
            cout << "YES\n";
            cout << u[i] << ' ' << u[i];
            return 0;
        }
        edge[u[i]].push_back(i);
    }

    memset(trace , -1 , sizeof(trace));
    memset(vis , false , sizeof(vis));

    vector<long long> ans(n + 2 , inf);
    ans = bellman_ford(ans);
    vector<long long> temp = bellman_ford(ans);

    int end_point = -1;

    for(int i = 1; i <= n; ++i) {
        if (temp[i] < ans[i]){
            end_point = i;
            break;
        }
    }

    if (end_point == -1) return cout << "NO" , 0;
    cout << "YES\n";

    vector<int> path;
    int start_point = -1;
    do{
        vis[end_point] = true;
        path.push_back(end_point);
        if (vis[trace[end_point]]) {
            start_point = trace[end_point];
            break;
        }
        end_point = trace[end_point];
    } while (true);

    bool write = false;
    swap(start_point , end_point);
    reverse(path.begin() , path.end());

    for(auto& x : path) {
        if (x == start_point) write = true;
        if (write) cout << x << ' ';
        if (x == end_point) write = false;
    }
    cout << start_point;

    return 0;
}