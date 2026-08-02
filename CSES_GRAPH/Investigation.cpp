#include<bits/stdc++.h>
using namespace std;

template<class T1, class T2>
    bool maximize(T1 &a , T2 b){
        if (a < b) return a = b , true;
        return false;
    }

template<class T1, class T2>
    bool minimize(T1 &a , T2 b){
        if (a > b) return a = b , true;
        return false;
    }

const int MAXN = (int) 1e5;
const int MOD = (int) 1e9 + 7;
    int add(int a , int b){
        return (a + b >= MOD ? a + b - MOD : a + b);
    }
int n , m;
vector<pair<int , int>> edge[MAXN + 2];
long long dist[MAXN + 2];
int cnt_max[MAXN + 2] , cnt_min[MAXN + 2] , cnt[MAXN + 2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a , b , c; 
        cin >> a >> b >> c;
        edge[a].push_back({b , c});
    }

    vector<int> topo;
    memset(dist , 0x3f , sizeof(dist));
    priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
    pq.push({0 , 1});
    dist[1] = 0;

    while (pq.size()){
        int u = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();

        if (cost != dist[u]) continue;
        topo.push_back(u);
        for(auto& v : edge[u]){
            if (minimize(dist[v.first] , dist[u] + v.second)) pq.push({dist[v.first] , v.first});
        }
    }

    memset(cnt_min , 0x3f , sizeof(cnt_min));
    memset(cnt_max , -0x3f , sizeof(cnt_max));
    cnt[1] = 1; cnt_min[1] = cnt_max[1] = 0;

    for(int u : topo) {
        for(auto& v : edge[u]){
            if (dist[u] + v.second == dist[v.first]){
                cnt[v.first] = add(cnt[v.first] , cnt[u]);
                minimize(cnt_min[v.first] , cnt_min[u] + 1);
                maximize(cnt_max[v.first] , cnt_max[u] + 1);
            }
        }
    }

    cout << dist[n] << ' ' << cnt[n] << ' ' << cnt_min[n] << ' ' << cnt_max[n];

    return 0;
}