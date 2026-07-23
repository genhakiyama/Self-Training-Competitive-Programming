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
        for(int j = 0; j < numcol; ++j) cin >> arr[i][j];
    }

    

    return 0;
}