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


    int add(int a , int b){
        return (a + b >= MOD ? a + b - MOD : a + b);
    }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    
    int numrow , numcol; cin >> numrow >> numcol;

    vector<int> possible;
    vector<vector<int>> edge(MASK(numrow));
    //... checking possible mask
        for(int mask = 0; mask < MASK(numrow) ;++mask){
            vector<int> vec;
            vec.push_back(-1);  
            for(int tmp = mask; tmp; tmp &= (tmp - 1)){
                vec.push_back(__builtin_ctz(tmp));
            }       
                
            vec.push_back(numrow);
            bool kt = true;
            for(int i = 1; i < vec.size(); ++i){
                if ((vec[i] - vec[i - 1] - 1) % 2 != 0){
                    kt = false;
                    break;
                }
            }
            
            if (kt) possible.push_back(mask);
        }

        for(int t1 = 0; t1 < MASK(numrow); ++t1) {
            for(int t2 : possible) {
                if ((t1 & (t1 ^ t2)) == 0) edge[t1].push_back(t1 ^ t2);
            }
        }

    
    vector<int> dp(MASK(numrow) , 0);
    vector<int> ndp(MASK(numrow) , 0);
   
    
    for(int x : possible) dp[x] = 1;
    
    for(int layer = 2; layer <= numcol; ++layer){
        
        for(int t1 = 0; t1 < MASK(numrow); ++t1){
            if (!dp[t1]) continue;
            for(int x : edge[t1]) ndp[x] = add(ndp[x] , dp[t1]);
        }

        for(int t1 = 0; t1 < MASK(numrow); ++t1){
            dp[t1] = ndp[t1];
            ndp[t1] = 0;
        }
    }

    cout << dp[0];
    

    return 0;
}