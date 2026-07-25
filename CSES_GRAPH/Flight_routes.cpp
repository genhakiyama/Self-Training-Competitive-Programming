#include<bits/stdc++.h>
using namespace std;

template<class T1 , class T2> 
    bool minimize(T1 &x , T2 y){
        if (x > y) return x = y , true;
        return false;
    }

const int MAXN = (int) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
    }

    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        edge[v[i]].push_back(i);
    }

    return 0;
}