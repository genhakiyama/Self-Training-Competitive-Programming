#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0 , 0 , 1 , -1};
const int dy[] = {-1 , 1 , 0 , 0};
const char letter[] = {'L' , 'R' , 'D' , 'U'};
const int MAXN = 1000;
int used[MAXN][MAXN];

struct PP{
    int first , second ;
    char c;
};

vector<PP> edge[MAXN][MAXN];

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
    vector<vector<PP>> trace(numrow , vector<PP>(numcol));
    memset(used , -1 , sizeof(used));

    pair<int,int> start_point , end_point;

    for(int i = 0 ; i < numrow; ++i){
        for(int j = 0; j < numcol; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'A') start_point = {i , j};
            if (arr[i][j] == 'B') end_point = {i , j};
        }
    }

    for(int i = 0; i < numrow; ++i){
        for(int j = 0; j < numcol; ++j) {
            if (arr[i][j] != '#') {
                for(int t = 0; t < 4; ++t){
                    int nxt_i = i + dx[t] , nxt_j = j + dy[t];
                    if (nxt_i >= 0 && nxt_j >= 0 && nxt_i < numrow && nxt_j < numcol && arr[nxt_i][nxt_j] != '#'){
                        edge[i][j].push_back({nxt_i , nxt_j , letter[t]});
                    }
                }
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(start_point);
    used[start_point.first][start_point.second] = 0;
    while (q.size()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
 
        for(auto& x : edge[u][v]){
            if (used[x.first][x.second] == -1) {
                q.push({x.first , x.second});
                trace[x.first][x.second] = {u , v , x.c};
                used[x.first][x.second] = used[u][v] + 1;;
            }
        }
    }
    
    if (used[end_point.first][end_point.second] == -1) {
        return cout << "NO" , 0;
    }
    cout << "YES\n";
    cout << used[end_point.first][end_point.second] << '\n';
    vector<char> ans;
    while (end_point != start_point){
        int u = trace[end_point.first][end_point.second].first;
        int v = trace[end_point.first][end_point.second].second;
        ans.push_back(trace[end_point.first][end_point.second].c);
        end_point = {u , v};
    }
    reverse(ans.begin() , ans.end());
    for(auto& x : ans) cout << x;
}