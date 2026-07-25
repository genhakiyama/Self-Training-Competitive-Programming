#include<bits/stdc++.h>
using namespace std;

template<class T1 , class T2> 
    bool minimize(T1 &x , T2 y){
        if (x > y) return x = y , true;
        return false;
    }


const int MAXN = (int) 1e5;
const int MAXM = (int) 2e5;

vector<pair<int,int>> edge[MAXN * 2 + 2];
int n , m;
long long dist[MAXN * 2 + 2] = {};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
    }

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a , b , c;
        cin >> a >> b >> c;
        edge[a].push_back({b , c});
        edge[a].push_back({b + n , c / 2});
        edge[a + n].push_back({b + n , c});
    }

    priority_queue<pair<long long , int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;
    pq.push({dist[1] , 1});
    while (pq.size()){
        int u = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();
        if (cost != dist[u]) continue;

        for(auto v : edge[u]){
            if (minimize(dist[v.first] , dist[u] + v.second)){
                pq.push({dist[v.first] , v.first});
            }
        }
    }

    cout<< dist[2*n];

    return 0;
}