#include<bits/stdc++.h>
using namespace std;

#define BIT(mask , x) (((mask) >> (x)) & (1))
#define MASK(x) ((long long)(1)<<(x))

const int MAXN = (int) 2e5;
const int MAXLOG = (int) 31;

int par[MAXN + 2][MAXLOG + 2];
int n , q;

int binary_jump(int u , int k){
    for(int i = 0; i < MAXLOG; ++i) if (BIT(k , i)) u = par[u][i];
    return u;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> par[i][0];
    
    for(int i = 1; i < MAXLOG; ++i){
        for(int u = 1; u <= n; ++u) par[u][i] = par[par[u][i - 1]][i - 1];
    }

    while(q--){
        int x , k; cin >> x >> k;
        cout << binary_jump(x , k) << '\n';
    }
}