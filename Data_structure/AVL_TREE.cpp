/* AVL TREE */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int par , left , right;
    int h; // height;

    Node(){
        key = par = left = right = h = -1;
    }
};

struct Heaps{
    vector<Node> tree;
    int root;
    Heaps() {
        tree.push_back(Node());
        root = 0;   
    }

    int new_node(){
        tree.push_back(Node()); 
        return (int)tree.size() - 1;
    }

    int is_heavy(int id){
        int left = tree[id].left , right = tree[id].right;
        if (left == -1) left = 0; else left = tree[left].h;
        if (right == -1) right = 0; else right = tree[right].h;

        if (left > right) return 0; // left  = 0
        if (right > left) return 1; // right = 1
        return -1;
    }

    int height(int id){
        int left = tree[id].left , right = tree[id].right;
        if (left == -1) left = 0; else left = tree[left].h;
        if (right == -1) right = 0; else right = tree[right].h;
        return max(left , right) + 1;
    }

    void update_grandparent(int grandparent , int parent , int grand_child){
        if (grandparent == -1) return;
        if (tree[grandparent].left == parent){
            tree[grandparent].left = grand_child;
        }
        else tree[grandparent].right = grand_child;
    }

    void update_par(int cur , int par){
        if (cur == -1) return;
        tree[cur].par = par;
        return;
    }

    void insert(int val){
        int cur_node = root , old_ver = -1;
        vector<int> path;

        //... path from root to the leaf (inserting node)

        while (tree[cur_node].key != -1){
            path.push_back(cur_node);
            old_ver = cur_node;
            if (val < tree[cur_node].key){
                if (tree[cur_node].left == -1) tree[cur_node].left = new_node();
                cur_node = tree[cur_node].left; 
            }
            else {
                if (tree[cur_node].right == -1) tree[cur_node].right = new_node();
                cur_node = tree[cur_node].right;
            }
        }
        path.push_back(cur_node);
        tree[cur_node].key = val , tree[cur_node].par = old_ver;

        //... rotation

        reverse(path.begin() , path.end());
        int rorated_index = -1;

        for(int i = 0; i < path.size(); ++i){
            int id = path[i];
            int left = tree[id].left , right = tree[id].right;
            if (left == -1) left = 0; else left = tree[left].h;
            if (right == -1) right = 0; else right = tree[right].h;
            tree[id].h = max(left , right) + 1;
            if (abs(left - right) > 1) {
                rorated_index = i;
                break;
            }
        }

        if (rorated_index == -1) return; // ... No roration is needed

        int index = rorated_index - 1;
        int k = path[index] , par = tree[k].par;
        int heavy_par = is_heavy(par) , heavy = is_heavy(k);

        

        if (heavy == heavy_par){
            tree[k].par = tree[par].par;
            update_grandparent(tree[par].par , par , k);
            if (heavy == 1) {
                update_par(tree[k].left , par);
                tree[par].right = tree[k].left;
                tree[k].left = par;
            }
            else {
                update_par(tree[k].right , par);
                tree[par].left = tree[k].right;
                tree[k].right = par;
            }
            tree[par].par = k;
            tree[par].h = height(par) , tree[k].h = height(k);
            if (tree[k].par == -1) root = k;
        }
        else {
            if (heavy == 0){
                
                int x = tree[k].left;
                update_grandparent(tree[par].par , par , x);
                update_par(k , x);
                tree[x].par = tree[par].par;
                
                if (tree[x].right == -1) tree[k].left = -1 , tree[par].right = tree[x].left; 
                    else tree[k].left = tree[x].right , tree[par].right = -1;

                tree[x].left = par , tree[x].right = k;

                tree[par].h = height(par);
                tree[k].h = height(k);
                tree[x].h = height(x);
                
                if (tree[x].par == -1) root = x;
            }
            else {
                int x = tree[k].right;
                update_grandparent(tree[par].par , par , x);
                update_par(k , x);
                tree[x].par = tree[par].par;
                
                if (tree[x].right == -1) tree[k].right = tree[x].left , tree[par].left = -1; 
                    else tree[par].left = tree[x].right , tree[k].right = -1;

                tree[x].left = k , tree[x].right = par;

                tree[par].h = height(par);
                tree[k].h = height(k);
                tree[x].h = height(x);
                if (tree[x].par == -1) root = x;
            }
        }

        return ;
    }

    void print(int x){
        cout << tree[x].key << '\n';
        if (tree[x].left != -1) cout << "LEFT CHILD : " << tree[tree[x].left].key << '\n';
        if (tree[x].right != -1) cout << "RIGHT CHILD : " << tree[tree[x].right].key << '\n';

        if (tree[x].left != -1) print(tree[x].left);
        if (tree[x].right != -1) print(tree[x].right);
    }
};

Heaps heap = Heaps();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("main.inp","r",stdin);
    freopen("main.out","w+",stdout);

    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;  cin >> x;
        heap.insert(x);
        if (i < n) continue;
        // cout << "TURN : " << i << '\n';
        heap.print(heap.root);
    }
    
    

    return 0;
}