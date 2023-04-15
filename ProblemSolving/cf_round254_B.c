#include<bits/stdc++.h>
using namespace std;

const int mx=112;
bool vis[mx];
vector<int> adj[mx];

int cnt=1;
void dfs(int u){
    //cout << "U is "<<u << "\n";
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v]){
            cnt*=2;
            dfs(v);
        }
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    for(int i=1;i<=n;i++){
    vis[i]=false;
    }
    for(int i=1;i<=e;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
           // cout << cnt<<"\n";
        }
    }
    cout << cnt << "\n";
}
