#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int left , right ;
    int h;

    Node(){
        key = left = right = h = -1;
    }
};

struct AVL_tree{
    vector<Node> tree;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    freopen("main.inp","r",stdin);
    freopen("main.out","w",stdout);

    int n; cin >> n;

}