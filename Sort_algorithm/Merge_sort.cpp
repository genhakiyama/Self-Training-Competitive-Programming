#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int width = 1; width <= n; width <<=1 ){
        for(int i = 0; i < n; i += width){
            int l = i , r = min(i + width - 1 , n - 1) ;
            int m = (l + r) >> 1;
            vector<int> temp(r -l + 1 , 0);

            int left = l , right = m + 1 , k = 0;
            while (left <= m && right <= r) {
                if (a[left] <= a[right]) temp[k++] = a[left++]; else temp[k++] = a[right++];
            }

            for(; left <= m; ++left) temp[k++] = a[left];
            for(; right <= r; ++right) temp[k++] = a[right];

            for(int id = l; id <= r; ++id) a[id] = temp[id - l];
        }  
    }

    for(int i = 0; i < n; ++i) cout << a[i] << ' ';
}