#include<bits/stdc++.h>
using namespace std;
using pll = pair<long long , int>;

template<class T1 , class T2>
    bool minimize(T1 &a , T2 b){
        if (a > b) return a = b , true; 
        return false;
    }

const int MAXN = (int) 1e5;
const int MAXM = (int) 2e5;

int n , m , k;;
vector<pair<int , int>> edge[MAXN + 2];
int cur_size[MAXN + 2];
long long dist[MAXN + 2][10] = {};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ; 

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) {
        int a , b , c;
        cin >> a >> b >> c;
        edge[a].push_back({b , c});
    }

    priority_queue<pll , vector<pll> , greater<pll>> pq;
    memset(dist , 0x3f , sizeof dist);
    
    pq.push({0 , 1});
    
    while (pq.size()){
        int u = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();
        if (cur_size[u] == k || !minimize(dist[u][cur_size[u]] , cost)) continue;
        cur_size[u]++;

        for(auto& v : edge[u]){
            int t = cur_size[v.first];
            if (t == k) continue;
            pq.push({cost + v.second , v.first});        
        }
    }

    for(int i = 0; i < k; ++i) cout << dist[n][i] << ' ';

    return 0;
}