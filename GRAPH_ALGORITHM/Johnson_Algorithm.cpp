#include<bits/stdc++.h>
using namespace std;

const int MAXN = (int) 2500;
const int MAXM = (int) 5000;

int u[MAXM + 2] , v[MAXM + 2] , w[MAXM + 2];
int n , m;
vector<int> edge[MAXN + 2];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ; 

    freopen("main.inp","r",stdin);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        edge[u[i]].push_back(i);
    }

    
}