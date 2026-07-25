#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int inf = 1e9 + 7;
const bool debug = false;
	
template<class T1 , class T2>
	bool minimize(T1 &x , T2 y){
		if (x > y) return x = y  , true; 
		return false;
	}

const int dx[] = {0 , 0 , 1 , -1};
const int dy[] = {1 , -1 , 0 , 0};

vector<vector<int>> bfs(vector<vector<char>> &arr , int numrow , int numcol , vector<pair<int , int>> &source){
    vector<vector<int>> ans(numrow , vector<int>(numcol , inf));
    queue<pair<int , int>> q;
    
    for(auto& x : source){
        ans[x.first][x.second] = 0;
        q.push(x);
    }
    while (q.size()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for(int t = 0; t < 4; ++t){
            int nxt_u = u + dx[t];
            int nxt_v = v + dy[t];
            if (nxt_u >= 0 && nxt_v >= 0 && nxt_u < numrow && nxt_v < numcol && arr[nxt_u][nxt_v] != '#') {
                if (ans[nxt_u][nxt_v] != inf) continue;
                ans[nxt_u][nxt_v] = ans[u][v] + 1;
                q.push({nxt_u , nxt_v});
            }
        }
    }

    return ans;
}
  
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);
 
    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
    }

    int numrow , numcol; 
    cin >> numrow >> numcol;
    
    vector<vector<char>> arr(numrow , vector<char>(numcol));
    vector<pair<int,int>> monster;
    pair<int,int> start_point;

    for(int i = 0; i < numrow; ++i){
        for(int j = 0; j < numcol; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'M') monster.push_back({i , j});
            if (arr[i][j] == 'A') start_point = {i , j};
        }
    }

    vector<vector<int>> mon_steps = bfs(arr , numrow , numcol , monster);
    vector<vector<int>> step(numrow , vector<int>(numcol , inf));
    vector<vector<pair<int , int>>> trace(numrow , vector<pair<int , int>>(numcol));
    
    queue<pair<int , int>> q;
    q.push(start_point);
    step[start_point.first][start_point.second] = 0;
 
    while (q.size()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
 
        for(int t = 0; t < 4; ++t){
            int nxt_u = u + dx[t];
            int nxt_v = v + dy[t];
            if (nxt_u >= 0 && nxt_v >= 0 && nxt_u < numrow && nxt_v < numcol && arr[nxt_u][nxt_v] != '#') {
                if (step[nxt_u][nxt_v] != inf) continue;
                step[nxt_u][nxt_v] = step[u][v] + 1;
                if (step[nxt_u][nxt_v] >= mon_steps[nxt_u][nxt_v]) continue;
                trace[nxt_u][nxt_v] = {u , v};
                q.push({nxt_u , nxt_v});
            }
        }
    }
 
   int need_step = inf;
    pair<int , int> end_point;
 
    for(int i = 0; i < numrow; ++i){
        for(int j = 0; j < numcol; ++j) {
            if (i != 0 && i != numrow - 1 && j != 0 && j != numcol - 1) continue;
            if (step[i][j] < mon_steps[i][j]){
                need_step = step[i][j];
                end_point = {i , j};
            }
        }
    }
    
    if (need_step == inf) return cout << "NO" , 0;
    cout << "YES\n";
    cout << need_step << '\n';
    vector<char> ans;
    while (end_point != start_point){
        pair<int , int> temp = trace[end_point.first][end_point.second];
        if (temp.first == end_point.first - 1) ans.push_back('D');
        if (temp.first == end_point.first + 1) ans.push_back('U');
        if (temp.second == end_point.second - 1) ans.push_back('R');
        if (temp.second == end_point.second + 1) ans.push_back('L');
        end_point = temp;
    }
    reverse(ans.begin() , ans.end());
    for(auto& x : ans) cout << x;
}