#include<bits/stdc++.h>
using namespace std;

const int mx=112;
int level[mx];
vector<int> adj[mx];
queue<int> que;


void bfs(int s){
    memset(level,-1,sizeof(level));
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(auto v: adj[u]){
            if(level[v]==-1){
                level[v]=level[u]+1;
                 que.push(v);
            }

        }
    }

}
int main(){
    int t;
    cin >> t;
    while(t--){
    for(int i=0;i<mx;i++)adj[i].clear();
    int n,e;
    cin >> n >> e;

    for(int i=1;i<=e;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    cout << level[n]<<"\n";
    }
}
