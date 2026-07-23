#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((x).size())

const int MAXN = (int) 18;

long long dp[MAXN + 2][2][10] = {};

long long calc(string &st , int cur_pos , bool start , int last_char , bool last_c){
    if (cur_pos == -1) return 1;
    if (dp[cur_pos][start][last_char] != -1 && last_c == 0) return dp[cur_pos][start][last_char];
    int r = 9;
    long long ans = 0;

    if (last_c) r = (int)st[cur_pos] - '0'; 

    for(int i = 0; i <= r; ++i){
        if (i == last_char && start) continue;
        ans += calc(st , cur_pos - 1 , start | (i != 0) , i , last_c & (i == r));
    }

    if (last_c == 0) dp[cur_pos][start][last_char] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ; 

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    long long a , b; cin >> a >> b;
    --a;

    string left = to_string(a) , right = to_string(b);
    memset(dp , -1 , sizeof (dp));

    reverse(left.begin() , left.end()); 
    reverse(right.begin() , right.end());

    long long ans = calc(right , sz(right) - 1 , 0 , 0 , 1) - calc(left , sz(left) - 1 , 0 , 0 , 1);

    cout << ans;

    return 0;
}