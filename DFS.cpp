#include<bits/stdc++.h>
using namespace std;

const int mx=112;
bool vis[mx];
vector<int> adj[mx];

void dfs(int u){
    vis[u]=1;
    for(auto v:adj[mx]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){

}
