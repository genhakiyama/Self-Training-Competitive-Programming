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

const int MAXN = 2e5;
int arr[MAXN + 2] , ans[MAXN + 2] = {};
int n;

vector<int> edge[MAXN + 2] ;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }

    cin >> n;
    vector<int> compress;

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        compress.push_back(arr[i]);
    }

    sort(compress.begin() , compress.end()); 
    compress.resize(unique(compress.begin() , compress.end()) - compress.begin());

    for(int i = 1; i <= n; ++i){
        arr[i] = upper_bound(compress.begin() , compress.end() , arr[i]) - compress.begin();
        edge[arr[i]].push_back(i);
    }

    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    
    memset(ans , 0 , sizeof(ans));

    for(int i = sz(compress); i >= 1; --i){
        for(int x : edge[i]){
            auto right = s.upper_bound(x);
            auto left = s.lower_bound(x); --left;
            ans[x] = max(ans[*right] , ans[*left]) + 1;
        }
        for(int x : edge[i]) s.insert(x);
    }

    cout << *max_element(ans + 1 , ans + n + 1);

    return 0;
}