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

const int MAXN = (int) 2e5;
vector<int> compress;
int arr[MAXN + 2];
int n;

    int add(int a , int b){
        return (a + b >= MOD ? a + b - MOD : a + b);
    }

class Fenwick{
    public:
        vector<int> bit;
        int n;

        void init(int _n){
            n = _n;
            bit.assign(n + 2 , 0);
        }

        void update(int pos , int val){
            for(; pos <= n; pos += pos & (-pos)) bit[pos] = add(bit[pos] , val);
            return;
        }

        int Get(int pos){
            int ans = 0;
            for(; pos ; pos -= pos & (-pos)) ans = add(ans , bit[pos]);
            return ans;
        }
};
Fenwick bit;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);

    #define name "main"
    if (fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w+",stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        compress.push_back(arr[i]);
    }
    sort(compress.begin() , compress.end());
    compress.resize(unique(compress.begin() , compress.end()) - compress.begin());

    bit.init(sz(compress));

    for(int i = 1; i <= n; ++i) {
        arr[i] = upper_bound(compress.begin() , compress.end() , arr[i]) - compress.begin();
        int k = add(1 , bit.Get(arr[i] - 1));
        bit.update(arr[i] , k);
    }
    cout << bit.Get(sz(compress));
}