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

struct PP{
    int first , second , p;
}; 

PP arr[MAXN + 2];
int n; 

class Segment_tree{
    public:
        vector<long long> range;
        
        void init(int n){
            range.resize(n * 4 + 2 , 0);

            return;
        }

        void update(int id , int l , int r , int p , long long val){
            if (l == r) maximize(range[id] , val);
            else{
                int m = (l + r) / 2;
                if (p <= m) update(id * 2 , l , m , p , val); 
                    else update(id * 2 + 1 , m + 1 , r , p , val);
                range[id] = max(range[id * 2] , range[id * 2 + 1]);
            }
            return;
        }

        long long Get(int id , int  l , int r , int u , int v){
            if (l > v || r < u) return 0;
            if (u <= l && r <= v) return range[id];
            int m = (l + r) / 2;
            return max(Get(id * 2 , l , m , u , v) , Get(id * 2 + 1 , m + 1 , r , u , v));
        }
};

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
        cin >> arr[i].first >> arr[i].second >> arr[i].p;
        compress.push_back(arr[i].first);
        compress.push_back(arr[i].second);
    }
    sort(compress.begin() , compress.end());
    compress.resize(unique(compress.begin() , compress.end()) - compress.begin());

    for(int i = 1; i <= n; ++i) {
        arr[i].first = upper_bound(compress.begin() , compress.end() , arr[i].first) - compress.begin();
        arr[i].second = upper_bound(compress.begin() , compress.end() , arr[i].second) - compress.begin();
    }

    sort(arr + 1 , arr + n + 1 , [&](PP x , PP y){
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;   
    });

    Segment_tree st;
    st.init(sz(compress));
    
    for(int i = 1; i <= n; ++i) {
        long long k = st.Get(1 , 1 , sz(compress) , 1 , arr[i].first - 1) + arr[i].p;
        st.update(1 , 1 , sz(compress) , arr[i].second , k);
    }

    cout << st.range[1];
    

    return 0;
}