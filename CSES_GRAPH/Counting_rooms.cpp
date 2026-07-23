#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int inf = 1e9 + 7;
const bool debug = false;
#define ll long long 
#define BIT(mask , x) (((mask) >> (x)) & (1))
#define MASK(x) (ll)((1) << (x))
#define sz(x) (int)(x).size()

template<class T1 , class T2>
	bool maximize(T1 &x , T2 y){
		if (x < y) return x = y , true;
		return false;
	}
	
template<class T1 , class T2>
	bool minimize(T1 &x , T2 y){
		if (x > y) return x = y  , true; 
		return false;
	}

const int dx[] = {0 , 0 , 1 , -1};
const int dy[] = {-1 , 1 , 0 , 0};
const int MAXN = 1000;
bool used[MAXN][MAXN];
vector<pair<int,int>> edge[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    
    int numrow , numcol;
    cin >> numrow >> numcol;

    vector<vector<char>> arr(numrow , vector<char>(numcol));
    
    for(int i = 0; i < numrow; ++i){
        for(int j = 0; j < numcol; ++j){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < numrow; ++i){
        for(int j = 0; j < numcol; ++j){
            if (arr[i][j] == '.') {
                for(int t = 0; t < 4; ++t){
                    int nxt_i = i + dx[t] , nxt_j = j + dy[t];
                    if (nxt_i >= 0 && nxt_j >= 0 && nxt_i < numrow && nxt_j < numcol && arr[nxt_i][nxt_j] == '.'){
                        edge[i][j].push_back({nxt_i , nxt_j});
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < numrow; ++i){
        for(int j = 0; j < numcol; ++j){
            if (arr[i][j] == '.' && !used[i][j]) {
                queue<pair<int,int>> q;
                ++ans;
                q.push({i , j});
                while (q.size()){
                    int u = q.front().first;
                    int v = q.front().second;
                    q.pop();

                    for(auto& x : edge[u][v]){
                        if (!used[x.first][x.second]) {
                            q.push(x);
                            used[x.first][x.second] = true;
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}