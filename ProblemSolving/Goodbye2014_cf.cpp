#include<bits/stdc++.h>
using namespace std;

const int mx=1e6+123;
bool vis[mx];
vector<int> adj[mx];


void dfs(int u){
    //cout << "U is "<<u << "\n";
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    vis[i]=false;
    }
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        int u=i,v=i+x;

        adj[u].push_back(v);
    }
    dfs(1);
    if(vis[m])cout << "YES\n";
    else cout << "NO\n";
}
